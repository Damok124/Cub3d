#include "cub3D.h"

#define ERR_BAD_FD 1
#define ERR_MISSING_START_POSITION 2
#define ERR_TOO_MUCH_START_POSITION 3
#define ERR_MISSING_MAP 4
#define ERR_SOMETHING_BELOW_MAP 5
#define ERR_MISSING_TEXTURE_PATHS 6
#define ERR_TOO_MUCH_TEXTURE_PATHS 7
#define ERR_MISSING_SURFACES 8
#define ERR_TOO_MUCH_SURFACES 9
#define ERR_MAP_NOT_CLOSED 10
#define ERR_UNREADABLE_PATH 11
#define ERR_EMPTY_FILE 12
#define ERR_TEXTURE_INIT_FAILED 13
#define ERR_MALLOC_CONTEXT 14
#define ERR_BAD_TEXTURE_FILE 15

#define LEFT 1
#define RIGHT -1

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4
#define WALL 5
#define DOOR 6
#define ANIMATION 7

#define IMG 64			//size_image
#define SCALING 2
#define SPEED 5		//speed
#define RSPEED 0.06 		//rotation speed
#define RADIAN 0.0174533 	// one degree in radian
#define PI 3.1415926535
#define DOV 2000
#define COLLISION 20

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_lines {
	char			*line;
	int				index;
	int				len;
	char			type;
	struct s_lines	*next;
}					t_lines;

typedef struct s_margin {
	int	ipx_add_xo;
	int	ipx_sub_xo;
	int	ipy_add_yo;
	int	ipy_sub_yo;
}		t_margin;

typedef struct s_keys {
	int	left_arr;
	int	right_arr;
	int	w;
	int	a;
	int	s;
	int	d;
	int	e;
	int	esc;
}		t_keys;

typedef struct s_rays {
	int				r_id;//banque nombre de rayons
	double			short_x;//banque - valeur la plus petite entre le player et l'impact
	double			short_y;//banque - valeur la plus petite entre le player et l'impact
	unsigned int	color;//banque - type de mur (ou couleur pour l'instant)
	double			ray_len;//banque - taille du rayon (et donc la taille du mur)
	int				dov;//deep of view
	int				tmp_rx;//variable temporaire de x
	int				tmp_ry;//variable temporaire de y
		double			impact_x;//point d'impact x
	double			impact_y;//point d'impact y
	double			r_angle;//angle du rayon
	double			xo;
	double			yo;
	double			a_tan;
	double			n_tan;
	int				wall_direction;
	int				wall_type;
}					t_rays;

typedef struct s_mlx_datas
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_datas;

typedef struct s_player
{
	double		player_x;
	double		player_y;
	double		pdx;//voir plus tard
	double		pdy;//voir plus tard
	double		view_angle;//direction du champs de vision
}				t_player;

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_textures {
	char	*path;
	void	*tex_img;
	char	*tex_addr;
	int		*tex_height;
	int		*tex_width;
	int		bppixels;
	int		endian;
}			t_textures;

typedef struct s_context {
	t_textures	*north;
	t_textures	*south;
	t_textures	*west;
	t_textures	*door;
	t_textures	*animated[3];
	t_textures	*east;
	t_rgb		floor;
	t_rgb		ceiling;
	char		**map;
	int			frames;
	int			map_height;
	int			map_length;
	char		orientation;
}				t_context;

typedef struct s_vars {
	t_context	*context;
	t_mlx_datas	*mlx_datas;
	t_player	*position;
	t_keys		*keys;
	t_rays		*rays;
}				t_vars;

void	ft_angle_adjustement(double *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}

double	ft_distance(double ax, double ay, double bx, double by)
{
	double	ret;

	ret = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (ret);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->mlx_datas->addr + (y * vars->mlx_datas->line_length \
		+ x * (vars->mlx_datas->bits_per_pixel / 8));
	if (x >= 0 && y >= 0 && x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
		*(unsigned int *)dst = color;
}

unsigned int	ft_get_color_from_xpm(t_textures *wall, double step, \
	double rank, int read_from)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	if (read_from == RIGHT)
	{
		coeff = (double)(*wall->tex_width / sizeof(int)) / (double)IMG;
		x = (*wall->tex_width / sizeof(int)) - \
			((int)(rank * coeff) % (*wall->tex_width / sizeof(int)));
		y = *(wall->tex_height) * step;
		color = wall->tex_addr + (y * *(wall->tex_width) \
			+ x * (wall->bppixels / 8));
	}
	else
	{
		coeff = (double)(*wall->tex_width / sizeof(int)) / (double)IMG;
		x = (int)(rank * coeff) % (*wall->tex_width / sizeof(int));
		y = *(wall->tex_height) * step;
		color = wall->tex_addr + (y * *(wall->tex_width) \
			+ x * (wall->bppixels / 8));
	}
	return (*(unsigned int *)color);
}

void	ft_get_wall_color(t_textures *texture,t_vars *vars, double step, unsigned int *col)
{

	if (vars->rays->wall_direction == NORTH)
	*col = ft_get_color_from_xpm(texture, step, \
		vars->rays->short_x, LEFT);
	else if (vars->rays->wall_direction == SOUTH)
	*col = ft_get_color_from_xpm(texture, step, \
		vars->rays->short_x, RIGHT);
	else if (vars->rays->wall_direction == WEST)
	*col = ft_get_color_from_xpm(texture, step, \
		vars->rays->short_y, RIGHT);
	else if (vars->rays->wall_direction == EAST)
	*col = ft_get_color_from_xpm(texture, step, \
		vars->rays->short_y, LEFT);
}

void	ft_print_type(double step, unsigned int *col, t_vars *vars)
{
	if (vars->rays->wall_type == DOOR)
		ft_get_wall_color(vars->context->door, vars, step ,col);
	else if (vars->rays->wall_type == ANIMATION)
		ft_get_wall_color(vars->context->animated[vars->context->frames], vars, step ,col);
	else if (vars->rays->wall_direction == NORTH)
		ft_get_wall_color(vars->context->north, vars, step ,col);
	else if (vars->rays->wall_direction == SOUTH)
		ft_get_wall_color(vars->context->south, vars, step ,col);
	else if (vars->rays->wall_direction == WEST)
		ft_get_wall_color(vars->context->west, vars, step ,col);
	else if (vars->rays->wall_direction == EAST)
		ft_get_wall_color(vars->context->east, vars, step ,col);
}

void	ft_print_column(t_vars *vars, int line_start, int line_end)
{
	unsigned int	col;
	double			step;
	int				pixel;

	pixel = 0;
	while ((line_start + pixel) < line_end)
	{
		step = ((double)pixel / (double)(line_end - line_start));
			ft_print_type(step, &col, vars);
		if (col != 0xff00ff)
			my_mlx_pixel_put(vars, vars->rays->r_id, (line_start + pixel), col);
		pixel++;
	}
}

void	ft_3d_display(t_vars *vars, t_rays *rays)
{
	double	line_height;
	double	line_start;
	double	line_end;
	double	ca;//maybe fisheye
	double	ratio;
	ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	ca = vars->position->view_angle - rays->r_angle;
	ft_angle_adjustement(&ca);
	rays->ray_len *= cos(ca);//calcul de la taille du rayon
	line_height = ((IMG * (WINDOW_HEIGHT)) / rays->ray_len) * ratio;
	line_start = ((WINDOW_HEIGHT) / 2) - (line_height / 2);
	line_end = line_start + line_height;
	ft_print_column(vars, line_start, line_end);
}	

void	ft_deep_of_view_explorer(t_vars *vars, int dov)
{
	t_rays	*ray;

	ray = vars->rays;
	while (ray->dov < dov)
	{
		ray->tmp_rx = (int)(ray->impact_x) >> 6;
		ray->tmp_ry = (int)(ray->impact_y) >> 6;
		if (ray->tmp_rx >= 0 && ray->tmp_ry >= 0
			&& ray->tmp_rx < vars->context->map_length
			&& ray->tmp_ry < vars->context->map_height
			&& ray->tmp_ry < WINDOW_HEIGHT
			&& ray->tmp_rx < WINDOW_WIDTH
			&& (ft_strchr("1CA", vars->context->map[ray->tmp_ry][ray->tmp_rx])))
			ray->dov = dov;
		else
		{
			ray->impact_x += ray->xo;
			ray->impact_y += ray->yo;
			ray->dov += 1;
		}
	}
}

void	ft_parallel_axis(t_vars *vars, int dov)
{
	vars->rays->impact_x = vars->position->player_x;
	vars->rays->impact_y = vars->position->player_y;
	vars->rays->dov = dov;
}

void	ft_h_not_parallel_axis(t_vars *vars, int coeff)
{
	double	corr;

	if (coeff > 0)
		corr = IMG;
	else
		corr = -0.0001;
	vars->rays->impact_y = (((int)vars->position->player_y >> 6) << 6) + corr;
	vars->rays->impact_x = (vars->position->player_y - vars->rays->impact_y) \
		* vars->rays->a_tan + vars->position->player_x;
	vars->rays->yo = IMG * coeff;
	vars->rays->xo = -vars->rays->yo * vars->rays->a_tan;
}

void	ft_v_not_parallel_axis(t_vars *vars, int coeff)
{
	double	corr;

	if (coeff > 0)
		corr = IMG;
	else
		corr = -0.0001;
	vars->rays->impact_x = (((int)vars->position->player_x >> 6) << 6) + corr;
	vars->rays->impact_y = (vars->position->player_x - vars->rays->impact_x) \
		* vars->rays->n_tan + vars->position->player_y;
	vars->rays->xo = IMG * coeff;
	vars->rays->yo = -vars->rays->xo * vars->rays->n_tan;
}

void	ft_horizontal_axis_intersection(t_vars *vars)
{
	vars->rays->dov = 0;
	int dov;
	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length;
	else
		dov = vars->context->map_height;
	dov = 4000;
	if (vars->rays->r_angle == 0 || vars->rays->r_angle == PI)
		ft_parallel_axis(vars, dov);
	else if (vars->rays->r_angle > PI)
		ft_h_not_parallel_axis(vars, -1);
	else if (vars->rays->r_angle < PI)
		ft_h_not_parallel_axis(vars, 1);
	ft_deep_of_view_explorer(vars, dov);
}

void	ft_vertical_axis_intersection(t_vars *vars)
{
	double	angle;
	int dov;

	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length;
	else
		dov = vars->context->map_height;
	dov = 4000;
	angle = vars->rays->r_angle;
	vars->rays->dov = 0;
	if (angle == (PI / 2) || angle == (3 * PI / 2))
		ft_parallel_axis(vars, dov);
	else if (angle > (PI / 2) && angle < (3 * PI / 2))
		ft_v_not_parallel_axis(vars, -1);
	else if (angle < (PI / 2) || angle > (3 * PI / 2))
		ft_v_not_parallel_axis(vars, 1);
	ft_deep_of_view_explorer(vars, dov);
}

void	ft_wall_identification(t_player *position, t_rays *rays)
{
	double	px;
	double	py;

	px = position->player_x;
	py = position->player_y;
	if (ft_distance(px, py, rays->impact_x, rays->impact_y) \
		> ft_distance(px, py, rays->short_x, rays->short_y))
	{
		if (rays->short_y < py)
			rays->wall_direction = NORTH;
		else
			rays->wall_direction = SOUTH;
	}
	else
	{
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
		if (rays->short_x > px)
			rays->wall_direction = EAST;
		else
			rays->wall_direction = WEST;
	}
	rays->ray_len = ft_distance(px, py, rays->short_x, rays->short_y);
}

void	ft_if_door(t_vars *vars)
{

	if (vars->context->map[(int)vars->rays->short_y / IMG][(int)vars->rays->short_x / IMG] == 'C')
		vars->rays->wall_type = DOOR;
	else if (vars->context->map[(int)vars->rays->short_y / IMG][(int)vars->rays->short_x / IMG] == 'A')
		vars->rays->wall_type = ANIMATION;
	else
		vars->rays->wall_type = WALL;
}

void	ft_animate_frames(t_vars *vars)
{
	static int	i;
	static int	j;

	if (!j)
		j = 1;
	if (i++ / 8)
	{
		i = 0;
		vars->context->frames += j;
		if (vars->context->frames > 1 && j == 1)
			j = -1;
		else if (vars->context->frames < 1 && j == -1)
			j = 1;
	}
}
void	ft_draw_environment(t_vars *vars)
{
	vars->rays->r_id = 0;
	vars->rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	ft_angle_adjustement(&vars->rays->r_angle);
	ft_animate_frames(vars);
	while (vars->rays->r_id < WINDOW_WIDTH)
	{
		vars->rays->a_tan = -1 / tan(vars->rays->r_angle);
		vars->rays->n_tan = -tan(vars->rays->r_angle);
		ft_horizontal_axis_intersection(vars);
		vars->rays->short_x = vars->rays->impact_x;
		vars->rays->short_y = vars->rays->impact_y;
		ft_vertical_axis_intersection(vars);
		ft_wall_identification(vars->position, vars->rays);//done
		ft_if_door(vars);
		ft_3d_display(vars, vars->rays);
		ft_angle_adjustement(&vars->rays->r_angle);//done
		vars->rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		vars->rays->r_id++;
	}
}

void	ft_draw_ray_hit(t_vars *vars, t_rays *rays, unsigned int color)
{
	t_player	*pos;
	t_rays		*ray;

	pos = vars->position;
	ray = vars->rays;
	if (ft_distance(pos->player_x, pos->player_y, ray->impact_x, ray->impact_y)
		< ft_distance(pos->player_x, pos->player_y, ray->short_x, ray->short_y))
	{
		ray->short_x = ray->impact_x;
		ray->short_y = ray->impact_y;
	}
	if (pos->player_y > ray->short_y)
		ray->short_y -= IMG / SCALING * 5 / 100;
	if (pos->player_x > ray->short_x)
		ray->short_x -= IMG / SCALING * 5 / 100;
	my_mlx_pixel_put(vars, (rays->short_x / SCALING), \
		(rays->short_y / SCALING), color);
}

void	ft_draw_rays_minimap(t_vars *vars)
{
	vars->rays->r_id = 0;
	vars->rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	ft_angle_adjustement(&vars->rays->r_angle);
	while (vars->rays->r_id < WINDOW_WIDTH)
	{
		vars->rays->a_tan = -1 / tan(vars->rays->r_angle);
		vars->rays->n_tan = -tan(vars->rays->r_angle);
		ft_horizontal_axis_intersection(vars);
		vars->rays->short_x = vars->rays->impact_x;
		vars->rays->short_y = vars->rays->impact_y;
		ft_vertical_axis_intersection(vars);
		ft_draw_ray_hit(vars, vars->rays, 0xD0FF00);
		ft_angle_adjustement(&vars->rays->r_angle);
		vars->rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		vars->rays->r_id++;
	}
}

void	ft_draw_player(t_vars *vars)
{
	int	size;
	int	cap;
	int	round;

	size = IMG / SCALING;
	cap = size / 3;
	round = 1;
	my_mlx_pixel_put(vars, vars->position->player_x / SCALING, \
		(vars->position->player_y / SCALING), 0x00BBCCBB);
	while (cap > 1)
	{
		my_mlx_pixel_put(vars, (vars->position->player_x / SCALING) - 1, \
			vars->position->player_y / SCALING, 0x00BBCCBB);
		my_mlx_pixel_put(vars, (vars->position->player_x / SCALING) + 1, \
			vars->position->player_y / SCALING, 0x00BBCCBB);
		my_mlx_pixel_put(vars, vars->position->player_x / SCALING, \
			(vars->position->player_y / SCALING) - 1, 0x00BBCCBB);
		my_mlx_pixel_put(vars, vars->position->player_x / SCALING, \
			(vars->position->player_y / SCALING) + 1, 0x00BBCCBB);
		my_mlx_pixel_put(vars, vars->position->player_x + vars->position->pdx / SCALING, \
			( vars->position->player_y + vars->position->pdy / SCALING) + 1, 0x00BBCCBB);
		cap = cap / 2;
	}
	(void)size;
	(void)cap;
	(void)round;
}

void	ft_draw_square_minimap(t_vars *vars, int y, int x, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < IMG / SCALING)
	{
		i = 0;
		while (i < IMG / SCALING)
		{
			my_mlx_pixel_put(vars, i + (x * IMG / SCALING), \
				j + (y * IMG / SCALING), color);
			i++;
		}
		j++;
	}
}

void	ft_draw_miniwalls(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->context->map[y])
	{
		x = 0;
		while (vars->context->map[y][x])
		{
			if (vars->context->map[y][x] == '1')
				ft_draw_square_minimap(vars, y, x, 0xAAAAAA);
			else if (ft_strchr("CO", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	ft_draw_minispaces(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->context->map[y])
	{
		x = 0;
		while (vars->context->map[y][x])
		{
			if (vars->context->map[y][x] == '0')
				ft_draw_square_minimap(vars, y, x, 0);
			else if (ft_strchr("NSWE", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, 0x404040);
			x++;
		}
		y++;
	}
}

void	ft_draw_minimap(t_vars *vars)
{

	ft_draw_miniwalls(vars);
	ft_draw_rays_minimap(vars);
	ft_draw_minispaces(vars);
	ft_draw_player(vars);
}
int ft_mouse_interactions(int x, int y, t_vars *vars)
{
	(void)y;
	if (x < (WINDOW_WIDTH / 2) - 20)
	{
		vars->position->view_angle -= RSPEED;
		if (vars->position->view_angle < 0)
			vars->position->view_angle += (2 * PI);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
		mlx_mouse_move(vars->mlx_datas->mlx, vars->mlx_datas->win, \
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	else if (x > (WINDOW_WIDTH / 2) + 20)
	{
		vars->position->view_angle += RSPEED;
		if (vars->position->view_angle > (2 * PI))
			vars->position->view_angle -= (2 * PI);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
		mlx_mouse_move(vars->mlx_datas->mlx, vars->mlx_datas->win, \
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	return (1);
}

void	ft_rotation(t_vars *vars)
{
	if (vars->keys->left_arr || vars->keys->right_arr)
	{
		if (vars->keys->left_arr == 1)
			vars->position->view_angle -= RSPEED;
		if (vars->keys->right_arr == 1)
			vars->position->view_angle += RSPEED;
		ft_angle_adjustement(&vars->position->view_angle);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
	}
}

int	ft_map_wall(t_vars *vars)
{
	int		player_x;
	int		player_y;
	char	**map;

	map = vars->context->map;
	player_y = (int)vars->position->player_y;
	player_x = (int)vars->position->player_x;
	if (ft_strchr("1AC", map[(player_y + 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1AC", map[(player_y - 22) / 64][(player_x - 22) / 64])
		|| ft_strchr("1AC", map[(player_y - 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1AC", map[(player_y + 22) / 64][(player_x - 22) / 64]))
		return (1);
	return (0);
}

void	ft_foreward_backward(t_vars *vars)
{
	if (vars->keys->s == 1)
	{
		vars->position->player_x -= vars->position->pdx;
		if (ft_map_wall(vars))
			vars->position->player_x += vars->position->pdx;
		vars->position->player_y -= vars->position->pdy;
		if (ft_map_wall(vars))
			vars->position->player_y += vars->position->pdy;
	}
	if (vars->keys->w == 1)
	{
		vars->position->player_x += vars->position->pdx;
		if (ft_map_wall(vars))
			vars->position->player_x -= vars->position->pdx;
		vars->position->player_y += vars->position->pdy;
		if (ft_map_wall(vars))
			vars->position->player_y -= vars->position->pdy;
	}
}

void	ft_left_right(t_vars *vars)
{
	double	angle;

	angle = vars->position->view_angle;
	if (vars->keys->a == 1)
	{
		vars->position->player_x += cos(angle - M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_x -= cos(angle - M_PI / 2) * SPEED;
		vars->position->player_y += sin(angle - M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_y -= sin(angle - M_PI / 2) * SPEED;
	}
	if (vars->keys->d == 1)
	{
		vars->position->player_x += cos(angle + M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_x -= cos(angle + M_PI / 2) * SPEED;
		vars->position->player_y += sin(angle + M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_y -= sin(angle + M_PI / 2) * SPEED;
	}
}

// void	ft_left_right(int ipx, int ipy, t_vars *vars, t_margin *margin)
// {
// 	(void)ipx;
// 	(void)ipy;
// 	(void)margin;
// 	if (vars->keys->a == 1)
// 	{
// 		vars->position->player_x += cos(vars->position->view_angle - M_PI / 2) * SPEED;
// 		if (ft_strchr("1", vars->context->map[(int)vars->position->player_y / 64][(int)vars->position->player_x / 64]))
// 			vars->position->player_x -= cos(vars->position->view_angle - M_PI / 2) * SPEED;
// 		vars->position->player_y += sin(vars->position->view_angle - M_PI / 2) * SPEED;
// 		if (ft_strchr("1", vars->context->map[(int)vars->position->player_y / 64][(int)vars->position->player_x / 64]))
// 			vars->position->player_y -= sin(vars->position->view_angle - M_PI / 2) * SPEED;

// 	}
// 	if (vars->keys->d == 1)
// 	{
// 		vars->position->player_x += cos(vars->position->view_angle + M_PI / 2) * SPEED;
// 		if (ft_strchr("1", vars->context->map[(int)vars->position->player_y / 64][(int)vars->position->player_x / 64]))
// 			vars->position->player_x -= cos(vars->position->view_angle + M_PI / 2) * SPEED;
// 		vars->position->player_y += sin(vars->position->view_angle + M_PI / 2) * SPEED;
// 		if (ft_strchr("1", vars->context->map[(int)vars->position->player_y / 64][(int)vars->position->player_x / 64]))
// 			vars->position->player_y -= sin(vars->position->view_angle + M_PI / 2) * SPEED;
// 	}
// }

void	ft_collision(t_vars *vars, t_margin *margin, int i)
{
	t_player	*pos;
	int			coeff_x;
	int			coeff_y;
	
	pos = vars->position;
	coeff_x = i;
	if (pos->pdx < 0)
		coeff_x = -i;
	coeff_y = i;
	if (pos->pdy < 0)
		coeff_y = -i;
	margin->ipx_add_xo = (pos->player_x + coeff_x) / IMG;
	margin->ipx_sub_xo = (pos->player_x - coeff_x) / IMG;
	margin->ipy_add_yo = (pos->player_y + coeff_y) / IMG;
	margin->ipy_sub_yo = (pos->player_y - coeff_y) / IMG;
}

// void	ft_map_door(t_vars *vars)
// {
// 	char	**map;
// 	int		player_x;
// 	int		player_y;
// 	double 	view_angle;
// 	int off_set;
	
// 	view_angle = vars->position->view_angle;
// 	player_y = (int)vars->position->player_y;
// 	player_x = (int)vars->position->player_x;

// 	off_set = 0;
// 	map = vars->context->map;
// 	while(off_set < 248)
// 	{
// 		if (map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] == 'C' && view_angle > (M_PI / 2) && view_angle < M_PI)
// 			map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] = 'O';
// 		else if (map[(player_y + off_set) / IMG][(player_x + off_set) / IMG] == 'C' && view_angle > (3 * M_PI) / 2 && view_angle < (2 * M_PI))
// 			map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] = 'O';
// 		else if (map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] == 'O' && view_angle > (M_PI / 2) && view_angle < M_PI)
// 			map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] = 'C';
// 		else if (map[(player_y + off_set) / IMG][(player_x + off_set) / IMG] == 'O' && view_angle > (3 * M_PI) / 2 && view_angle < (2 * M_PI))
// 			map[(player_y - off_set) / IMG][(player_x - off_set) / IMG] = 'C';
// 		off_set++;
// 	}
// }

void	ft_map_door(t_vars *vars, t_margin *margin)
{
	char	**map;
	int off_set;
	

	off_set = 0;
	map = vars->context->map;
	while(off_set < 64)
	{
		ft_collision(vars, margin,off_set);
		if(map[margin->ipy_add_yo][margin->ipx_add_xo] == 'C')
		{
			map[margin->ipy_add_yo][margin->ipx_add_xo] = 'O';
			return ;
		}
		else if(map[margin->ipy_add_yo][margin->ipx_add_xo] == 'O')
		{
			map[margin->ipy_add_yo][margin->ipx_add_xo] = 'C';
			return ;
		}
		off_set++;
	}
}

void	ft_keyboard_interactions(t_vars *vars)
{
	static int    i = 0;
	t_margin	margin;

	if (vars->keys->left_arr == 1 || vars->keys->right_arr == 1)
		ft_rotation(vars);
	if (vars->keys->w == 1 || vars->keys->s == 1)
		ft_foreward_backward(vars);
	if (vars->keys->a == 1 || vars->keys->d == 1)
		ft_left_right(vars);
	if (vars->keys->e == 1)
	{
        i++;
        if (i != 1)
            return ;
		ft_map_door(vars, &margin);
	}
    else
        i = 0;
}

void	ft_draw_ceilling(t_context *context, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	color = (context->ceiling.red << 16) + (context->ceiling.green << 8) \
		+ (context->ceiling.blue);
	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_floor(t_context *context, t_vars *vars)
{
	int	x;
	int	color;
	int	y;

	color = (context->floor.red << 16) + (context->floor.green << 8) \
		+ (context->floor.blue);
	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_cub3d(t_vars *vars)
{
	t_mlx_datas	*md;

	md = vars->mlx_datas;
	if (md->img)
		mlx_destroy_image(md->mlx, md->img);
	md->img = mlx_new_image(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	md->addr = mlx_get_data_addr(md->img, &md->bits_per_pixel, \
		&md->line_length, &md->endian);
	ft_draw_ceilling(vars->context, vars);//done
	ft_draw_floor(vars->context, vars);//done
	ft_keyboard_interactions(vars);//done
	ft_draw_environment(vars);//done
	ft_draw_minimap(vars);//done?
	mlx_put_image_to_window(md->mlx, md->win, md->img, 0, 0);
	return (1);
}

/////////////////////////////////////////////////////////////EVENT MANAGEMENT

int	ft_click_cross(void *mlx_ptr)
{
	mlx_loop_end(mlx_ptr);
	return (0);
}

int	ft_hold_key(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		vars->keys->w = 1;
	if (keycode == XK_Left)
		vars->keys->left_arr = 1;
	if (keycode == XK_Right)
		vars->keys->right_arr = 1;
	if (keycode == 'a')
		vars->keys->a = 1;
	if (keycode == 's')
		vars->keys->s = 1;
	if (keycode == 'd')
		vars->keys->d = 1;
	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx_datas->mlx);
	if (keycode == 'e')
		vars->keys->e = 1;
	return (keycode);
}

int	ft_release_key(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		vars->keys->w = 0;
	if (keycode == XK_Left)
		vars->keys->left_arr = 0;
	if (keycode == XK_Right)
		vars->keys->right_arr = 0;
	if (keycode == 'a')
		vars->keys->a = 0;
	if (keycode == 's')
		vars->keys->s = 0;
	if (keycode == 'd')
		vars->keys->d = 0;
	if (keycode == 'e')
		vars->keys->e = 0;
	return (keycode);
}

void	ft_hooks_activation(t_vars *vars)
{
	t_mlx_datas	*md;

	md = vars->mlx_datas;
	mlx_hook(md->win, ON_DESTROY, DestroyAll, ft_click_cross, md->mlx);
	mlx_hook(md->win, 2, 1L << 0, ft_hold_key, vars);
	mlx_hook(md->win, 3, 1L << 1, ft_release_key, vars);
	mlx_hook(md->win, 6, 1L << 6, ft_mouse_interactions, vars);
	mlx_mouse_hide(md->mlx, md->win);
	///manque events open/close
}

/////////////////////////////////////////////////////////////VARS BUILDING

int	ft_if_player_here(t_vars *vars, int y, int x)
{
	if (ft_strchr("NSWE", vars->context->map[y][x]))
		return (1);
	return (0);
}

double	ft_get_first_angle(char orientation)
{
	double	axis;

	axis = 0;
	if (orientation == 'E')
		axis = 0;
	else if (orientation == 'N')
		axis = PI / 2;
	else if (orientation == 'W')
		axis = PI;
	else if (orientation == 'S')
		axis = 3 * PI / 2;
	return (axis);
}

t_player	*ft_get_player_position(t_vars *vars, char orientation)
{
	t_player	*position;
	int			x;
	int			y;

	y = -1;
	position = (t_player *)malloc(sizeof(t_player));
	if (!position)
		return (NULL);
	while (vars->context->map[++y])
	{
		x = -1;
		while (vars->context->map[y][++x])
		{
			if (ft_if_player_here(vars, y, x))
			{
				position->view_angle = ft_get_first_angle(orientation);
				position->pdx = cos(position->view_angle) * 5;
				position->pdy = sin(position->view_angle) * 5;
				position->player_x = x * IMG + (IMG / 2);
				position->player_y = y * IMG + (IMG / 2);
			}
		}
	}
	return (position);
}

t_keys	*ft_init_keys(void)
{
	t_keys	*keys;

	keys = (t_keys *)malloc(sizeof(t_keys));
	if (!keys)
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	return (keys);
}

t_vars	*ft_init_vars(t_context *context)
{
	t_vars		*vars;
	t_mlx_datas	*m_datas;
	t_rays		*rays;

	vars = NULL;
	m_datas = (t_mlx_datas *)malloc(sizeof(t_mlx_datas));
	if (!m_datas)
		return (NULL);
	rays = (t_rays *)malloc(sizeof(t_rays));
	if (!rays)
		return (NULL);
	if (context)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (!vars)
			return (NULL);
		vars->mlx_datas = m_datas;
		vars->rays = rays;
		vars->context = context;
		vars->context->frames = 0;
		vars->keys = ft_init_keys();
		vars->position = ft_get_player_position(vars, context->orientation);
	}
	return (vars);
}

void	ft_show_context(t_context *context)
{
	if (context)
	{
		printf("\nAFTER PARSING\n");
		printf("NO path : %s\n", context->north->path);
		printf("SO path : %s\n", context->south->path);
		printf("WE path : %s\n", context->west->path);
		printf("EA path : %s\n", context->east->path);
		printf("Player Orientation : %c\n", context->orientation);
		printf("floor R%d G%d B%d\n", \
			context->floor.red, context->floor.green, context->floor.blue);
		printf("ceiling R%d G%d B%d\n", context->ceiling.red, \
			context->ceiling.green, context->ceiling.blue);
		printf("map :\n");
		ft_show_strs(context->map);
		printf("end of map.\n");
	}
	else
		printf("Error.\nNo context.\n");
}

void	ft_set_texture(t_textures *data, t_mlx_datas *md)
{
	data->tex_img = mlx_xpm_file_to_image(md->mlx, data->path, data->tex_width, data->tex_height);
	data->tex_addr = mlx_get_data_addr(data->tex_img, &data->bppixels, \
		data->tex_width, &data->endian);
	printf("path : %s, w:%d, h:%d\n", data->path, *data->tex_width, *data->tex_height);
}

void	ft_get_textures_paths(t_context *context, t_lines *content)
{
	while (content)
	{
		if (content->type == 'N')
			context->north->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'S')
			context->south->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'W')
			context->west->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'E')
			context->east->path = ft_strtrim(content->line + 2, " ");
		content = content->next;
	}
	//brute bonus
	context->door->path = ft_strdup("/nfs/homes/alprival/Cube3d/textures/t_gungeon_door.xpm");
	context->animated[0]->path = ft_strdup("/nfs/homes/alprival/Cube3d/textures/flame1.xpm");
	context->animated[1]->path = ft_strdup("/nfs/homes/alprival/Cube3d/textures/flame2.xpm");
	context->animated[2]->path = ft_strdup("/nfs/homes/alprival/Cube3d/textures/flame3.xpm");
}

void	ft_get_full_textures(t_context *context, t_mlx_datas *md, int *err_no)
{
	ft_set_texture(context->north, md);
	ft_set_texture(context->south, md);
	ft_set_texture(context->west, md);
	ft_set_texture(context->east, md);
	ft_set_texture(context->door, md); // bonus
	ft_set_texture(context->animated[0], md);//bonus
	ft_set_texture(context->animated[1], md);//bonus
	ft_set_texture(context->animated[2], md);//bonus
	if (!context->north->tex_img || !context->north->tex_addr \
		|| !context->south->tex_img || !context->south->tex_addr \
		|| !context->west->tex_img || !context->west->tex_addr \
		|| !context->east->tex_img || !context->east->tex_addr)
		*err_no = ERR_BAD_TEXTURE_FILE;
}

t_vars	*ft_get_vars(t_context *context, int *err_no)
{
	t_vars		*vars;
	t_mlx_datas	*md;

	ft_show_context(context);
	vars = ft_init_vars(context);
	md = vars->mlx_datas;
	if (vars)
	{
		md->mlx = mlx_init();
		md->win = mlx_new_window(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
		md->img = mlx_new_image(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		md->addr = mlx_get_data_addr(md->img, &md->bits_per_pixel, \
			&md->line_length, &md->endian);
		ft_get_full_textures(vars->context, vars->mlx_datas, err_no);
		////////////////////////////////////////////////////////////////tester erreurs
	}
	return (vars);
}

///////////////////////////////////////////////////////////////PARSING

void	ft_check_lst_lines(t_lines *lst)
{
	int	i;

	i = 0;
	printf("check :\n");
	while (lst)
	{
		printf("%d\t%c; len %d\t;", i, lst->type, lst->len);
		printf("%s\n", lst->line);
		lst = lst->next;
		i++;
	}
	printf("end check.\n");
}

int	ft_file_lines_counter(int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		i++;
		ft_true_free((void **)&buffer);
		buffer = get_next_line(fd);
	}
	return (i);
}

int	ft_potential_map_line(char *str, int len)
{
	int	i;

	i = 0;
	// while (str[i] && ft_strchr(" 01NSWE", str[i]))/////////////////mandatory
	while (str[i] && ft_strchr(" 01CNSWEA", str[i]))////////////////bonus
		i++;
	if (i == len)
		return (1);
	return (0);
}

int	ft_strs_are_digits(char **strs)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (strs && strs[++i])
	{
		while (strs[i][++j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (0);
		}
		j = -1;
	}
	return (1);
}

char	ft_find_valid_fc(char *str)
{
	int		i;
	char	type;
	char	**colors;
	t_rgb	set;

	type = str[0];
	i = 1;
	while (str[i] == ' ')
		i++;
	if (i == 1 || !str[i])
		return ('0');
	colors = ft_split(str + i, ',');
	if (ft_strslen(colors) == 3 && ft_strs_are_digits(colors))
	{
		set.red = ft_atoi(colors[0]);
		set.green = ft_atoi(colors[1]);
		set.blue = ft_atoi(colors[2]);
		ft_full_free((void **)colors);
		if (set.red <= 255 || set.green <= 255 || set.blue <= 255)
			return (type);
	}
	ft_full_free((void **)colors);
	return ('0');
}

char	ft_find_valid_nswe(char *str)
{
	int		i;
	char	type;

	type = '0';
	i = 2;
	if ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'S' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'W' && str[1] == 'E' && str[2] == ' ') || \
		(str[0] == 'E' && str[1] == 'A' && str[2] == ' '))
		type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 2 || !str[i])
		return ('0');
	return (type);
}

char	ft_type_specifier(char *str, int target_size)
{
	char	type;

	type = '0';
	if (target_size == 1)
		type = ft_find_valid_fc(str);
	else if (target_size == 2)
		type = ft_find_valid_nswe(str);
	return (type);
}

char	ft_define_line_type(char *str, int	len)
{
	char	type;

	type = '0';
	if (len)
	{
		if (ft_strchr("FC", str[0]) && len > 2)
			type = ft_type_specifier(str, 1);
		if (ft_strchr("NSWE", str[0]) && len > 3)
			type = ft_type_specifier(str, 2);
		else if (ft_potential_map_line(str, len))
			type = 'M';
	}
	return (type);
}

t_lines	*ft_setup_lst(int size, int fd, int index)
{
	t_lines	*elem;
	char	*buffer;

	elem = NULL;
	buffer = NULL;
	if (size)
	{
		buffer = get_next_line(fd);
		elem = (t_lines *)malloc(sizeof(t_lines));
		if (!elem)
			return (NULL);
		buffer[ft_strlen(buffer) - 1] = '\0';
		elem->index = index;
		elem->line = buffer;
		elem->len = ft_strlen(buffer);
		elem->type = ft_define_line_type(buffer, ft_strlen(buffer));
		--size;
		++index;
		elem->next = ft_setup_lst(size, fd, index);
	}
	if (++size && --index == 0)
		buffer = get_next_line(fd);
	return (elem);
}

t_lines	*ft_get_all_lines(char *filename, int *err_no)
{
	t_lines	*lst;
	int		size;
	int		fd;

	lst = NULL;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		size = ft_file_lines_counter(fd);
		close(fd);
		fd = open(filename, O_RDONLY);
		lst = ft_setup_lst(size, fd, 0);
		close(fd);
	}
	else
	{
		*err_no = ERR_BAD_FD;
		return (lst);
	}
	if (!size)
		*err_no = ERR_EMPTY_FILE;
	return (lst);
}

t_textures	*ft_init_t_textures(void)
{
	t_textures	*texture;

	texture = (t_textures *)malloc(sizeof(t_textures));
	if (!texture)
		return (NULL);
	texture->path = NULL;
	texture->tex_img = NULL;
	texture->tex_addr = NULL;
	texture->bppixels = 0;
	texture->tex_width = (int *)malloc(sizeof(int));
	if (!texture->tex_width)
	{
		ft_true_free((void **)&texture);
		return (NULL);
	}
	texture->tex_height = (int *)malloc(sizeof(int));
	if (!texture->tex_height)
	{
		ft_multi_true_free((void **)&texture->tex_width, (void **)&texture, \
			NULL, NULL);
		return (NULL);
	}
	return (texture);
}

t_context	*ft_init_t_context(int *err_no)
{
	t_context	*context;

	context = (t_context *)malloc(sizeof(t_context));
	if (!context)
	{
		*err_no = ERR_MALLOC_CONTEXT;
		return (NULL);
	}
	context->north = ft_init_t_textures();
	context->south = ft_init_t_textures();
	context->west = ft_init_t_textures();
	context->door = ft_init_t_textures();
	context->east = ft_init_t_textures();
	context->animated[0] = ft_init_t_textures();
	context->animated[1] = ft_init_t_textures();
	context->animated[2] = ft_init_t_textures();
	context->map = NULL;
	if (!context->north || !context->south || !context->west || !context->east)
		*err_no = ERR_TEXTURE_INIT_FAILED;
	return (context);
}

void	ft_unset_content(t_lines *content)
{
	t_lines	*tmp;

	if (content)
	{
		while (content)
		{
			tmp = content;
			content = content->next;
			ft_true_free((void **)&tmp->line);
			ft_true_free((void **)&tmp);
		}
	}
}

int	ft_just_enough_surfaces(t_lines *content, int *tab, int *err_no)
{
	while (content && content->type != 'M')
	{
		if (content->type == 'F')
			tab[0] += 1;
		else if (content->type == 'C')
			tab[1] += 1;
		content = content->next;
	}
	if (tab[0] != 1 || tab[1] != 1)
	{
		if (tab[0] == 0 || tab[1] == 0)
			*err_no = ERR_MISSING_SURFACES;
		else
			*err_no = ERR_TOO_MUCH_SURFACES;
		return (0);
	}
	return (1);
}

int	ft_just_enough_paths(t_lines *content, int *tab, int *err_no)
{
	while (content && content->type != 'M')
	{
		if (content->type == 'N')
			tab[0] += 1;
		else if (content->type == 'S')
			tab[1] += 1;
		else if (content->type == 'W')
			tab[2] += 1;
		else if (content->type == 'E')
			tab[3] += 1;
		content = content->next;
	}
	if (tab[0] != 1 && tab[1] != 1 && tab[2] != 1 && tab[3] != 1)
	{
		if (tab[0] == 0 || tab[1] == 0 || tab[2] == 0 || tab[3] == 0)
			*err_no = ERR_MISSING_TEXTURE_PATHS;
		else
			*err_no = ERR_TOO_MUCH_TEXTURE_PATHS;
		return (0);
	}
	return (1);
}

int	ft_one_last_map(t_lines *content, int *err_no)
{
	while (content && content->type != 'M')
		content = content->next;
	if (!content)
	{
		*err_no = ERR_MISSING_MAP;
		return (0);
	}
	while (content && content->type == 'M')
		content = content->next;
	if (content)
	{
		*err_no = ERR_SOMETHING_BELOW_MAP;
		return (0);
	}
	return (1);
}

int	ft_only_one_position(t_lines *content, int *err_no)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				check++;
		i = -1;
		content = content->next;
	}
	if (check != 1)
	{
		if (check == 0)
			*err_no = ERR_MISSING_START_POSITION;
		else
			*err_no = ERR_TOO_MUCH_START_POSITION;
		return (0);
	}
	return (1);
}

int	ft_check_format_textures(t_lines *content, int *err_no)
{
	char	*path;

	path = NULL;
	while (content)
	{
		if (content->type == 'N' || content->type == 'S' \
			|| content->type == 'W' || content->type == 'E')
		{
			path = ft_strtrim(content->line + 2, " ");
			if (!ft_check_extension(path, ".xpm") || access(path, R_OK))
				*err_no = ERR_UNREADABLE_PATH;
			ft_true_free((void **)&path);
		}
		content = content->next;
	}
	if (*err_no)
		return (0);
	return (1);
}

int	ft_check_content(t_lines *content, int *err_no)
{
	if (!ft_just_enough_paths(content, (int [4]){0, 0, 0, 0}, err_no))
		return (0);
	if (!ft_check_format_textures(content, err_no))
		return (0);
	if (!ft_just_enough_surfaces(content, (int [2]){0, 0}, err_no))
		return (0);
	if (!ft_one_last_map(content, err_no))
		return (0);
	if (!ft_only_one_position(content, err_no))
		return (0);
	return (1);
}

int	ft_get_greatest_len(t_lines *content)
{
	int	max;

	max = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content)
	{
		if (content->len > max)
			max = content->len;
		content = content->next;
	}
	return (max);
}

char	*ft_line_to_standard(char *str, int	max)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char *)malloc(sizeof(char) * (max + 1));
	if (!dest)
		return (NULL);
	dest[max] = '\0';
	dest[0] = ' ';
	while (str[++i])
		dest[i + 1] = str[i];
	while (i < max - 1)
	{
		dest[i + 1] = ' ';
		i++;
	}
	ft_true_free((void **)&str);
	return (dest);
}

void	ft_spotted_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			str[i] = '.';
}

t_lines	*ft_add_empty_line_to_map(int max, t_lines *next)
{
	char	*empty_line;
	t_lines	*new;
	int		i;

	i = -1;
	new = (t_lines *)malloc(sizeof(t_lines));
	if (!new)
		return (NULL);
	empty_line = (char *)malloc(sizeof(char) * (max + 1));
	if (!empty_line)
	{
		ft_true_free((void **)&new);
		return (NULL);
	}
	empty_line[max] = '\0';
	while (++i < max)
		empty_line[i] = '.';
	new->len = max;
	new->index = 0;
	new->type = 'M';
	new->next = next;
	new->line = empty_line;
	return (new);
}

void	ft_square_shaped_dotted_map(t_lines *content)
{
	t_lines	*tmp;
	int		max;

	tmp = NULL;
	max = ft_get_greatest_len(content) + 2;
	while (content && content->type != 'M')
	{
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_line_to_map(max, content);
	while (content)
	{
		content->line = ft_line_to_standard(content->line, max);
		ft_spotted_spaces(content->line);
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_line_to_map(max, NULL);
}

int	ft_get_map_size(t_lines *lst)
{
	int	size;

	size = 0;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char	**ft_get_map(t_lines *lst)
{
	char	**map;
	int		size;
	int		i;

	i = 0;
	size = ft_get_map_size(lst);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	map[size] = NULL;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		map[i] = ft_strdup(lst->line);
		i++;
		lst = lst->next;
	}
	return (map);
}

int	ft_check_if_flawless(char **map, int *err_no)
{
	int	i;
	int	j;
	int	size;
	int	len;

	i = 0;
	size = ft_strslen(map);
	len = ft_strlen(map[0]);
	while (++i < (size - 1))
	{
		j = 0;
		while (++j < (len - 1))
		{
			if (ft_strchr("NSWE0", map[i][j]))
			{
				if (map[i - 1][j] == '.' || map[i + 1][j] == '.' \
					|| map[i][j - 1] == '.' || map[i][j + 1] == '.')
				{
					*err_no = ERR_MAP_NOT_CLOSED;
					return (0);
				}
			}
		}
	}
	return (1);
}

t_rgb	ft_get_rgb(t_lines *content, char type)
{
	char	*tmp;
	char	**groups;
	t_rgb	colors;

	colors.red = 0;
	colors.green = 0;
	colors.blue = 0;
	tmp = NULL;
	groups = NULL;
	while (content && content->type != type)
		content = content->next;
	if (content && content->type == type)
	{
		tmp = ft_strtrim(content->line + 1, " ");
		groups = ft_split(tmp, ',');
		ft_true_free((void **)&tmp);
		colors.red = ft_atoi(groups[0]);
		colors.green = ft_atoi(groups[1]);
		colors.blue = ft_atoi(groups[2]);
		ft_full_free((void **)groups);
	}
	return (colors);
}

char	ft_get_player_orientation(t_lines *content)
{
	int	i;

	i = -1;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				return (content->line[i]);
		i = -1;
		content = content->next;
	}
	return ('N');
}

void	ft_show_content(t_lines *content)
{
	printf("\nBEFORE PARSING\n");
	while (content)
	{
		printf("%s\n", content->line);
		content = content->next;
	}
}

void	ft_unset_context(t_context *context)
{
	ft_true_free((void **)&context->north->path);
	ft_true_free((void **)&context->south->path);
	ft_true_free((void **)&context->east->path);
	ft_true_free((void **)&context->west->path);
	ft_true_free((void **)&context->north->tex_width);
	ft_true_free((void **)&context->south->tex_width);
	ft_true_free((void **)&context->east->tex_width);
	ft_true_free((void **)&context->west->tex_width);
	ft_true_free((void **)&context->north->tex_height);
	ft_true_free((void **)&context->south->tex_height);
	ft_true_free((void **)&context->east->tex_height);
	ft_true_free((void **)&context->west->tex_height);
	ft_true_free((void **)&context->north);
	ft_true_free((void **)&context->south);
	ft_true_free((void **)&context->east);
	ft_true_free((void **)&context->west);
	ft_full_free((void **)context->map);
	ft_true_free((void **)&context);
}

t_context	*ft_cub3d_parsing(char **argv, int *err_no)
{
	t_context	*context;
	t_lines		*content;

	context = NULL;
	content = ft_get_all_lines(argv[1], err_no);
	ft_show_content(content);///////////////////////////////////////to remove
	if (content && ft_check_content(content, err_no))
	{
		context = ft_init_t_context(err_no);
		if (context)
		{
			ft_square_shaped_dotted_map(content);
			ft_get_textures_paths(context, content);
			context->orientation = ft_get_player_orientation(content);
			context->floor = ft_get_rgb(content, 'F');
			context->ceiling = ft_get_rgb(content, 'C');
			context->map = ft_get_map(content);
			context->map_height = ft_get_map_size(content);
			context->map_length = ft_get_greatest_len(content);
			// if (!ft_check_if_flawless(context->map, err_no))
			// 	ft_unset_context(context);
		}
	}
	ft_unset_content(content);
	return (context);
}

void	ft_print_cub3d_error_2(int err_no)
{
	if (err_no == ERR_EMPTY_FILE)
		printf("The file is empty.\n");
	else if (err_no == ERR_TEXTURE_INIT_FAILED)
		printf("Failed to malloc textures structures.\n");
	else if (err_no == ERR_MALLOC_CONTEXT)
		printf("Failed to malloc parsed datas structure.\n");
	else if (err_no == ERR_BAD_TEXTURE_FILE)
		printf("Wrong texture file content.\n");
}

void	ft_print_cub3d_error_1(int err_no)
{
	printf("Error\n");
	if (err_no == ERR_BAD_FD)
		printf("Check if existing file or your right to read it.\n");
	else if (err_no == ERR_MISSING_START_POSITION)
		printf("No starting position.\n");
	else if (err_no == ERR_TOO_MUCH_START_POSITION)
		printf("Put only one starting position.\n");
	else if (err_no == ERR_MISSING_MAP)
		printf("No map defined.\n");
	else if (err_no == ERR_SOMETHING_BELOW_MAP)
		printf("Map not at the end of file.\n");
	else if (err_no == ERR_MISSING_TEXTURE_PATHS)
		printf("Missing texture paths.\n");
	else if (err_no == ERR_TOO_MUCH_TEXTURE_PATHS)
		printf("Too much texture paths defined.\n");
	else if (err_no == ERR_MISSING_SURFACES)
		printf("Floor or ceilling undefined.\n");
	else if (err_no == ERR_TOO_MUCH_SURFACES)
		printf("Too much floor or ceilling definition.\n");
	else if (err_no == ERR_MAP_NOT_CLOSED)
		printf("This map is not closed.\n");
	else if (err_no == ERR_UNREADABLE_PATH)
		printf("Unreadable texture path.\n");
	ft_print_cub3d_error_2(err_no);
}

void	ft_unset_vars(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_datas->mlx, vars->context->north->tex_img);
	mlx_destroy_image(vars->mlx_datas->mlx, vars->context->south->tex_img);
	mlx_destroy_image(vars->mlx_datas->mlx, vars->context->east->tex_img);
	mlx_destroy_image(vars->mlx_datas->mlx, vars->context->west->tex_img);
	mlx_destroy_image(vars->mlx_datas->mlx, vars->mlx_datas->img);
	mlx_destroy_window(vars->mlx_datas->mlx, vars->mlx_datas->win);
	mlx_destroy_display(vars->mlx_datas->mlx);
	ft_unset_context(vars->context);
	ft_true_free((void **)&vars->mlx_datas->mlx);
	ft_true_free((void **)&vars->keys);
	ft_true_free((void **)&vars->mlx_datas);
	ft_true_free((void **)&vars->position);
	ft_true_free((void **)&vars->rays);
	ft_true_free((void **)&vars);
}

int	main(int ac, char **argv)
{
	int			err_no;
	t_context	*context;
	t_vars		*vars;

	err_no = 0;
	if (ac == 2 && ft_check_extension(argv[1], ".cub"))
	{
		context = ft_cub3d_parsing(argv, &err_no);
		if (!err_no)
			vars = ft_get_vars(context, &err_no);
		if (context && vars && !err_no)
		{
			ft_hooks_activation(vars);
			mlx_loop_hook(vars->mlx_datas->mlx, ft_cub3d, vars);
			mlx_loop(vars->mlx_datas->mlx);
			printf("%f-%f\n",vars->position->player_x,vars->position->player_y);
			ft_unset_vars(vars);
		}
		else
			ft_print_cub3d_error_1(err_no);
	}
	else
		write(2, "Error.\nWrong arguments.\n", 24);
	return (0);
}
