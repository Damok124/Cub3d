#include "cub3D.h"

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

void	ft_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->mlx_datas->addr + (y * vars->mlx_datas->line_length \
		+ x * (vars->mlx_datas->bits_per_pixel / 8));
	if (x >= 0 && y >= 0 && x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
		*(unsigned int *)dst = color;
}

char	*ft_right_color_from_xpm(t_textures *wall, double step, \
	double rank)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	coeff = (double)(*wall->tex_width / sizeof(int)) / (double)SQ_SIZE;
	x = (*wall->tex_width / sizeof(int)) - \
		((int)(rank * coeff) % (*wall->tex_width / sizeof(int))) - 1;
	y = *(wall->tex_height) * step;
	color = wall->tex_addr + (y * *(wall->tex_width) \
		+ x * (wall->bppixels / 8));
	return (color);
}

char	*ft_left_color_from_xpm(t_textures *wall, double step, \
	double rank)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	coeff = (double)(*wall->tex_width / sizeof(int)) / (double)SQ_SIZE;
	x = (int)(rank * coeff) % (*wall->tex_width / sizeof(int));
	y = *(wall->tex_height) * step;
	color = wall->tex_addr + (y * *(wall->tex_width) \
		+ x * (wall->bppixels / 8));
	return (color);
}

unsigned int	ft_get_color_from_xpm(t_textures *wall, double step, \
	double rank, int read_from)
{
	if (read_from == RIGHT)
		return (*(unsigned int *)ft_right_color_from_xpm(wall, step, rank));
	else
		return (*(unsigned int *)ft_left_color_from_xpm(wall, step, rank));
}

unsigned int	ft_get_color_from_xpm_door(t_textures *wall, \
	double rank, int read_from, t_vars *vars)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	coeff = (double)(*wall->tex_width / sizeof(int)) / (double)SQ_SIZE;
	if (read_from == RIGHT)
		x = (*wall->tex_width / sizeof(int)) - \
			((int)(rank * coeff) % (*wall->tex_width / sizeof(int))) - 1;
	else
		x = (int)(rank * coeff) % (*wall->tex_width / sizeof(int));
	y = *(wall->tex_height) * vars->context->step + \
		(vars->context->frames_door * 2);
	if (y >= *(wall->tex_height))
		return (0xff00ff);
	color = wall->tex_addr + (y * *(wall->tex_width) \
		+ x * (wall->bppixels / 8));
	return (*(unsigned int *)color);
}

unsigned int	ft_get_door_color(t_textures *texture, \
	t_rays *rays, t_vars *vars)
{
	if (rays->wall_direction == NORTH)
		return (ft_get_color_from_xpm_door(texture, \
			rays->short_x, LEFT, vars));
	else if (rays->wall_direction == SOUTH)
		return (ft_get_color_from_xpm_door(texture, \
			rays->short_x, RIGHT, vars));
	else if (rays->wall_direction == WEST)
		return (ft_get_color_from_xpm_door(texture, \
			rays->short_y, RIGHT, vars));
	else if (rays->wall_direction == EAST)
		return (ft_get_color_from_xpm_door(texture, \
			rays->short_y, LEFT, vars));
	return (0);
}

unsigned int	ft_get_wall_color(t_textures *texture, double step, \
	t_rays *rays, t_vars *vars)
{
	if (rays->wall_direction == NORTH && rays->wall_type != DOOR_ANIMATION)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_x, LEFT));
	else if (rays->wall_direction == SOUTH && rays->wall_type != DOOR_ANIMATION)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_x, RIGHT));
	else if (rays->wall_direction == WEST && rays->wall_type != DOOR_ANIMATION)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_y, RIGHT));
	else if (rays->wall_direction == EAST && rays->wall_type != DOOR_ANIMATION)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_y, LEFT));
	else
		return (ft_get_door_color(texture, rays, vars));
}

void	ft_print_type(double step, unsigned int *col,
	t_vars *vars, t_rays *rays)
{
	t_context	*context;

	context = vars->context;
	if (rays->wall_type == DOOR || rays->wall_type == DOOR_ANIMATION)
		*col = ft_get_wall_color(context->door, step, rays, vars);
	else if (rays->wall_type == ANIMATION)
		*col = ft_get_wall_color(context->animated[context->frames / 4], \
			step, rays, vars);
	else if (rays->wall_direction == NORTH)
		*col = ft_get_wall_color(context->south, step, rays, vars);
	else if (rays->wall_direction == SOUTH)
		*col = ft_get_wall_color(context->north, step, rays, vars);
	else if (rays->wall_direction == WEST)
		*col = ft_get_wall_color(context->east, step, rays, vars);
	else if (rays->wall_direction == EAST)
		*col = ft_get_wall_color(context->west, step, rays, vars);
}

void	ft_print_column(t_vars *vars, int line_start,
		int line_end, t_rays *rays)
{
	unsigned int	col;
	int				pixel;

	pixel = 0;
	while ((line_start + pixel) < line_end \
			&& (vars->context->step * rays->short_y * 0.8) < WINDOW_HEIGHT)
	{
		pixel++;
		vars->context->step = ((double)pixel / (double)(line_end - line_start));
		ft_print_type(vars->context->step, &col, vars, rays);
		if (col != 0xff00ff)
			ft_mlx_pixel_put(vars, rays->r_id, (line_start + pixel), col);
	}
}

void	ft_print_door(t_vars *vars, int line_start, int line_end, t_rays *rays)
{
	unsigned int	col;
	int				pixel;

	pixel = 0;
	while ((line_start + pixel) < line_end \
			&& (vars->context->step * rays->short_y * 0.8) < WINDOW_HEIGHT)
	{
		pixel++;
		vars->context->step = ((double)pixel / (double)(line_end - line_start));
		ft_print_type(vars->context->step, &col, vars, rays);
		if (col != 0xff00ff)
			ft_mlx_pixel_put(vars, rays->r_id, (line_start + pixel), col);
	}
}

void	ft_3d_display(t_vars *vars, t_rays *rays)
{
	double	line_height;
	double	line_start;
	double	line_end;
	double	ratio;
	double	ca;

	ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	ca = vars->position->view_angle - rays->r_angle;
	ft_angle_adjustement(&ca);
	rays->ray_len *= cos(ca);
	line_height = ((SQ_SIZE * (WINDOW_HEIGHT)) / rays->ray_len) * ratio;
	line_start = ((WINDOW_HEIGHT) / 2) - (line_height / 2);
	line_end = line_start + line_height;
	if (rays->door == 1 && rays->wall_type == DOOR_ANIMATION)
		ft_print_door(vars, line_start, line_end, rays);
	else
		ft_print_column(vars, line_start, line_end, rays);
}

void	ft_ray_impact_wall(t_vars *vars, int dov, t_rays *ray)
{
	while (ray->dov < dov)
	{
		ray->tmp_rx = (int)(ray->impact_x) >> 6;
		ray->tmp_ry = (int)(ray->impact_y) >> 6;
		if (ray->tmp_rx >= 0 && ray->tmp_ry >= 0
			&& ray->tmp_rx < vars->context->map_length
			&& ray->tmp_ry < vars->context->map_height
			&& ray->tmp_ry < WINDOW_HEIGHT
			&& ray->tmp_rx < WINDOW_WIDTH
			&& (ft_strchr("1DA", vars->context->map[ray->tmp_ry][ray->tmp_rx])))
			ray->dov = dov;
		else
		{
			ray->impact_x += ray->xo;
			ray->impact_y += ray->yo;
			ray->dov += 1;
		}
	}
}

void	ft_ray_impact_door(t_vars *vars, int dov, t_rays *ray)
{
	while (ray->dov < dov)
	{
		ray->tmp_rx = (int)(ray->impact_x) >> 6;
		ray->tmp_ry = (int)(ray->impact_y) >> 6;
		if (ray->tmp_rx >= 0 && ray->tmp_ry >= 0
			&& ray->tmp_rx < vars->context->map_length
			&& ray->tmp_ry < vars->context->map_height
			&& ray->tmp_ry < WINDOW_HEIGHT
			&& ray->tmp_rx < WINDOW_WIDTH
			&& ft_strchr("1DEAe", vars->context->map[ray->tmp_ry][ray->tmp_rx]))
			ray->dov = dov;
		else
		{
			ray->impact_x += ray->xo;
			ray->impact_y += ray->yo;
			ray->dov += 1;
		}
	}
}

void	ft_deep_of_view_explorer(t_vars *vars, int dov, t_rays *rays)
{
	if (!rays->door)
		ft_ray_impact_wall(vars, dov, rays);
	else if (rays->door == 1)
		ft_ray_impact_door(vars, dov, rays);
}

void	ft_parallel_axis(t_vars *vars, int dov, t_rays *rays)
{
	rays->impact_x = vars->position->player_x;
	rays->impact_y = vars->position->player_y;
	rays->dov = dov;
}

void	ft_h_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays)
{
	double	corr;

	if (coeff > 0)
		corr = SQ_SIZE;
	else
		corr = -0.0001;
	rays->impact_y = (((int)vars->position->player_y >> 6) << 6) + corr;
	rays->impact_x = (vars->position->player_y - rays->impact_y) \
		* rays->a_tan + vars->position->player_x;
	rays->yo = SQ_SIZE * coeff;
	rays->xo = -rays->yo * rays->a_tan;
}

void	ft_v_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays)
{
	double	corr;

	if (coeff > 0)
		corr = SQ_SIZE;
	else
		corr = -0.0001;
	rays->impact_x = (((int)vars->position->player_x >> 6) << 6) + corr;
	rays->impact_y = (vars->position->player_x - rays->impact_x) \
		* rays->n_tan + vars->position->player_y;
	rays->xo = SQ_SIZE * coeff;
	rays->yo = -rays->xo * rays->n_tan;
}

void	ft_horizontal_axis_intersection(t_vars *vars, t_rays *rays)
{
	int	dov;

	rays->dov = 0;
	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length * 2;
	else
		dov = vars->context->map_height * 2;
	if (rays->r_angle == 0 || rays->r_angle == PI)
		ft_parallel_axis(vars, dov, rays);
	else if (rays->r_angle > PI)
		ft_h_not_parallel_axis(vars, -1, rays);
	else if (rays->r_angle < PI)
		ft_h_not_parallel_axis(vars, 1, rays);
	ft_deep_of_view_explorer(vars, dov, rays);
}

void	ft_vertical_axis_intersection(t_vars *vars, t_rays *rays)
{
	double	angle;
	int		dov;

	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length * 2;
	else
		dov = vars->context->map_height * 2;
	angle = rays->r_angle;
	rays->dov = 0;
	if (angle == (PI / 2) || angle == (3 * PI / 2))
		ft_parallel_axis(vars, dov, rays);
	else if (angle > (PI / 2) && angle < (3 * PI / 2))
		ft_v_not_parallel_axis(vars, -1, rays);
	else if (angle < (PI / 2) || angle > (3 * PI / 2))
		ft_v_not_parallel_axis(vars, 1, rays);
	ft_deep_of_view_explorer(vars, dov, rays);
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

void	ft_minimap_pixel_put(t_minimap *minimap, int x, int y, int color)
{
	char	*dst;

	dst = minimap->addr + (y * (minimap->line_length) \
		+ x * (minimap->bits_per_pixel / 8));
	if (x >= 0 && y >= 0 && x < minimap->width && y < minimap->height)
		*(unsigned int *)dst = color;
}

void	ft_confirm_wall_type(t_rays *r, char **map, int x, int y)
{
	if (map[y / SQ_SIZE][x / SQ_SIZE] == 'D')
		r->wall_type = DOOR;
	else if (map[y / SQ_SIZE][x / SQ_SIZE] == 'E' \
		|| map[y / SQ_SIZE][x / SQ_SIZE] == 'e')
		r->wall_type = DOOR_ANIMATION;
	else if (map[y / SQ_SIZE][x / SQ_SIZE] == 'A')
		r->wall_type = ANIMATION;
	else
		r->wall_type = WALL;
}

void	ft_animate_frames_door(int *frames)
{
	static int	j;

	if (!j)
		j = 1;
	if (*frames == 59)
		j = -1;
	else if (*frames == 1)
		j = 1;
	*frames += j;
}

void	ft_animate_frames(int *frames)
{
	static int	j;

	if (!j)
		j = 1;
	if (*frames > 10 && j == 1)
		j = -1;
	else if (*frames < 1 && j == -1)
		j = 1;
	*frames += j;
}

void	ft_draw_environment(t_vars *vars, t_rays *rays)
{
	rays->r_id = 0;
	rays->door = 0;
	rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	ft_angle_adjustement(&rays->r_angle);
	while (rays->r_id < WINDOW_WIDTH)
	{
		rays->a_tan = -1 / tan(rays->r_angle);
		rays->n_tan = -tan(rays->r_angle);
		ft_horizontal_axis_intersection(vars, rays);
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
		ft_vertical_axis_intersection(vars, rays);
		ft_wall_identification(vars->position, rays);
		ft_confirm_wall_type(rays, vars->context->map, \
			(int)rays->short_x, (int)rays->short_y);
		ft_3d_display(vars, rays);
		ft_angle_adjustement(&rays->r_angle);
		rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		rays->r_id++;
	}
}

void	ft_draw_door(t_vars *vars, t_rays *rays)
{
	rays->r_id = 0;
	rays->door = 1;
	rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	ft_angle_adjustement(&rays->r_angle);
	while (rays->r_id < WINDOW_WIDTH)
	{
		rays->a_tan = -1 / tan(rays->r_angle);
		rays->n_tan = -tan(rays->r_angle);
		ft_horizontal_axis_intersection(vars, rays);
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
		ft_vertical_axis_intersection(vars, rays);
		ft_wall_identification(vars->position, rays);
		ft_confirm_wall_type(rays, vars->context->map, \
			(int)rays->short_x, (int)rays->short_y);
		ft_3d_display(vars, rays);
		ft_angle_adjustement(&rays->r_angle);
		rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		rays->r_id++;
	}
}

void	ft_pixel_around_impacts(t_vars *vars, int size, unsigned int color)
{
	int	init_x;
	int	init_y;
	int	i;
	int	j;

	init_x = vars->rays->short_x / SCALING - (size / 2);
	init_y = vars->rays->short_y / SCALING - (size / 2);
	j = -1;
	i = -1;
	while (++j < size)
	{
		while (++i < size)
			ft_minimap_pixel_put(vars->minimap, init_x + i, init_y + j, color);
		i = -1;
	}
}

void	ft_draw_ray_hit(t_vars *vars, unsigned int color, t_rays *rays)
{
	t_player	*pos;

	pos = vars->position;
	if (ft_distance(pos->player_x, pos->player_y,
			rays->impact_x, rays->impact_y)
		< ft_distance(pos->player_x, pos->player_y,
			rays->short_x, rays->short_y))
	{
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
	}
	ft_pixel_around_impacts(vars, 3, color);
}

void	ft_draw_rays_minimap(t_vars *vars, t_rays *rays)
{
	vars->rays->r_id = 0;
	vars->rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	while (vars->rays->r_id < WINDOW_WIDTH)
	{
		ft_angle_adjustement(&vars->rays->r_angle);
		vars->rays->a_tan = -1 / tan(vars->rays->r_angle);
		vars->rays->n_tan = -tan(vars->rays->r_angle);
		ft_horizontal_axis_intersection(vars, rays);
		vars->rays->short_x = vars->rays->impact_x;
		vars->rays->short_y = vars->rays->impact_y;
		ft_vertical_axis_intersection(vars, rays);
		ft_draw_ray_hit(vars, RAY_COLOR, rays);
		vars->rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		vars->rays->r_id++;
	}
}

void	ft_put_pixel_around(t_vars *vars, int size, unsigned int color)
{
	int	init_x;
	int	init_y;
	int	i;
	int	j;

	init_x = vars->position->player_x / SCALING - (size / 2);
	init_y = vars->position->player_y / SCALING - (size / 2);
	j = -1;
	i = -1;
	while (++j < size)
	{
		while (++i < size)
			ft_minimap_pixel_put(vars->minimap, init_x + i, init_y + j, color);
		i = -1;
	}
}

void	ft_draw_player(t_vars *vars)
{
	int				size;
	unsigned int	color;

	size = SQ_SIZE / SCALING / 4;
	color = PLAYER_COLOR;
	if (!size)
		size = 1;
	ft_put_pixel_around(vars, size, color);
}

void	ft_draw_square_minimap(t_vars *vars, int y, int x, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < SQ_SIZE / SCALING)
	{
		i = 0;
		while (i < SQ_SIZE / SCALING)
		{
			ft_minimap_pixel_put(vars->minimap, i + (x * SQ_SIZE / SCALING), \
				j + (y * SQ_SIZE / SCALING), color);
			i++;
		}
		j++;
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
				ft_draw_square_minimap(vars, y, x, SPACE_COLOR);
			else if (ft_strchr("NSWE", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, START_COLOR);
			else if (ft_strchr("O", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, OPEN_COLOR);
			x++;
		}
		y++;
	}
}

void	ft_init_minitools(t_minitools *tools, t_player *pos)
{
	tools->start_x = ((pos->player_x) - ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->start_y = ((pos->player_y) - ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->target_x = ((pos->player_x) + ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->target_y = ((pos->player_y) + ((MINIZONE * SQ_SIZE / 2))) / SCALING;
}

void	ft_put_minimap_on_display(t_vars *vars, t_player *pos, t_minimap *mini)
{
	t_minitools	t;
	char		*col;

	t.i = 0;
	ft_init_minitools(&t, pos);
	while (t.start_x + t.i < t.target_x)
	{
		t.j = 0;
		while (t.start_y + t.j < t.target_y)
		{
			if ((t.start_x + t.i) >= 0 && t.start_y + t.j >= 0 && t.start_x \
				+ t.i <= mini->width && t.start_y + t.j <= mini->height)
			{
				col = mini->addr + ((t.start_y + t.j) * (mini->line_length)) \
					+ ((t.start_x + t.i) * (mini->bits_per_pixel / 8));
				ft_mlx_pixel_put(vars, t.i + (SQ_SIZE / SCALING), \
					t.j + (SQ_SIZE / SCALING), *(unsigned int *)col);
			}
			else
				ft_mlx_pixel_put(vars, t.i + (SQ_SIZE / SCALING), \
					t.j + (SQ_SIZE / SCALING), EXT_COLOR);
			t.j++;
		}
		t.i++;
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
			if (ft_strchr("1A", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, WALL_COLOR);
			else if (ft_strchr("D", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, CLOSE_COLOR);
			x++;
		}
		y++;
	}
}

void	ft_draw_minimap(t_vars *vars)
{
	if (vars->minimap->img)
		mlx_destroy_image(vars->mlx_datas->mlx, vars->minimap->img);
	vars->minimap->img = mlx_new_image(vars->mlx_datas->mlx, \
		vars->minimap->width, vars->minimap->height);
	vars->minimap->addr = mlx_get_data_addr(vars->minimap->img, \
		&vars->minimap->bits_per_pixel, &vars->minimap->line_length, \
		&vars->minimap->endian);
	ft_draw_miniwalls(vars);
	ft_draw_rays_minimap(vars, vars->rays);
	ft_draw_minispaces(vars);
	ft_draw_player(vars);
	ft_put_minimap_on_display(vars, vars->position, vars->minimap);
}

int	ft_mouse_interactions(int x, int y, t_vars *vars)
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
	if (ft_strchr("1ADeE", map[(player_y + 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1ADeE", map[(player_y - 22) / 64][(player_x - 22) / 64])
		|| ft_strchr("1ADeE", map[(player_y - 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1ADeE", map[(player_y + 22) / 64][(player_x - 22) / 64]))
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
	margin->ipx_add_xo = (pos->player_x + coeff_x) / SQ_SIZE;
	margin->ipx_sub_xo = (pos->player_x - coeff_x) / SQ_SIZE;
	margin->ipy_add_yo = (pos->player_y + coeff_y) / SQ_SIZE;
	margin->ipy_sub_yo = (pos->player_y - coeff_y) / SQ_SIZE;
}

int	ft_putchar_on_map(t_vars *vars, int x, int y, int type)
{
	char	**map;

	map = vars->context->map;
	if (type == DOOR)
	{
		vars->context->frames_door = 1;
		map[y][x] = 'E';
	}
	else
	{
		vars->context->frames_door = 59;
		map[y][x] = 'e';
	}
	return (1);
}

int	ft_open_door(t_vars *vars, int x, int y, double ang)
{
	char	**map;

	map = vars->context->map;
	if (map[y - 1][x] == 'D' && ang > (M_PI * 5) / 4 && ang < (7 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x, y - 1, DOOR));
	else if (map[y + 1][x] == 'D' && ang > M_PI / 4 && ang < (3 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x, y + 1, DOOR));
	else if (map[y][x + 1] == 'D' && (ang > (7 * M_PI) / 4 || ang < M_PI / 4))
		return (ft_putchar_on_map(vars, x + 1, y, DOOR));
	else if (map[y][x - 1] == 'D' && ang > (3 * M_PI) / 4
		&& ang < (5 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x - 1, y, DOOR));
	return (0);
}

void	ft_close_door(t_vars *vars, int x, int y, double ang)
{
	char	**map;

	map = vars->context->map;
	if (map[y - 1][x] == 'O' && ang > (M_PI * 5) / 4 && ang < (7 * M_PI) / 4
		&& ((int)(vars->position->player_y) % SQ_SIZE) > (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x, y - 1, DOOR_CLOSED);
	else if (map[y + 1][x] == 'O' && ang > M_PI / 4 && ang < (3 * M_PI) / 4
		&& ((int)(vars->position->player_y) % SQ_SIZE) < (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x, y + 1, DOOR_CLOSED);
	else if (map[y][x + 1] == 'O' && (ang > (7 * M_PI) / 4 || ang < M_PI / 4)
		&& ((int)(vars->position->player_x) % SQ_SIZE) < (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x + 1, y, DOOR_CLOSED);
	else if (map[y][x - 1] == 'O' && ang > (3 * M_PI) / 4 \
		&& ang < (5 * M_PI) / 4 && ((int)(vars->position->player_x) \
		% SQ_SIZE) > (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x - 1, y, DOOR_CLOSED);
}

void	ft_map_door(t_vars *vars)
{
	char		**map;
	int			player_x;
	int			player_y;
	double		player_angle;

	player_x = (int)(vars->position->player_x / SQ_SIZE);
	player_y = (int)(vars->position->player_y / SQ_SIZE);
	player_angle = vars->position->view_angle;
	map = vars->context->map;
	if (ft_open_door(vars, player_x, player_y, player_angle))
		return ;
	else
		ft_close_door(vars, player_x, player_y, player_angle);
}

void	ft_keyboard_interactions(t_vars *vars)
{
	static int	i;

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
		ft_map_door(vars);
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
			ft_mlx_pixel_put(vars, x, y, color);
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
			ft_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_player_around(t_vars *vars, int x, int y)
{
	if (y == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else if (y == (int)vars->position->player_y / 64
		&& x - 1 == (int)vars->position->player_x / 64)
		return (1);
	else if (y == (int)vars->position->player_y / 64
		&& x + 1 == (int)vars->position->player_x / 64)
		return (1);
	else if (y - 1 == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else if (y + 1 == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else
		return (0);
}

int	ft_parse_map_to_close(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->context->map_height)
	{
		x = 0;
		while (x < vars->context->map_length)
		{
			if (vars->context->map[y][x] == 'E')
			{
				vars->context->map[y][x] = 'O';
				return (1);
			}
			else if (vars->context->map[y][x] == 'e')
			{
				vars->context->map[y][x] = 'D';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_door_animation(t_vars *vars)
{
	static int	i;

	if (vars->keys->e || (vars->context->frames_door > 0
			&& vars->context->frames_door < 60))
	{
		ft_animate_frames_door(&vars->context->frames_door);
		i++;
		ft_draw_door(vars, vars->rays_door);
	}
	if (i > 1)
		i++;
	if (i / 60 && (vars->context->frames_door == 59
			|| vars->context->frames_door == 1))
	{
		if (ft_parse_map_to_close(vars))
		{
			vars->context->frames_door = 0;
			i = 0;
		}
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
	ft_draw_ceilling(vars->context, vars);
	ft_draw_floor(vars->context, vars);
	ft_keyboard_interactions(vars);
	ft_animate_frames(&vars->context->frames);
	ft_draw_environment(vars, vars->rays);
	ft_door_animation(vars);
	ft_draw_minimap(vars);
	mlx_put_image_to_window(md->mlx, md->win, md->img, 0, 0);
	return (1);
}

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
}

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
				position->player_x = x * SQ_SIZE + (SQ_SIZE / 2);
				position->player_y = y * SQ_SIZE + (SQ_SIZE / 2);
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
	keys->e = 0;
	keys->left_arr = 0;
	keys->right_arr = 0;
	return (keys);
}

void	ft_set_minimap(t_vars *vars)
{
	vars->minimap->width = vars->context->map_length * SQ_SIZE;
	vars->minimap->height = vars->context->map_height * SQ_SIZE;
	printf("vars->minimap->width %d\n", vars->minimap->width);
	printf("vars->minimap->height %d\n", vars->minimap->height);
}

t_minimap	*ft_init_minimap(void)
{
	t_minimap	*mini;

	mini = (t_minimap *)malloc(sizeof(t_minimap));
	if (!mini)
		return (NULL);
	mini->img = NULL;
	mini->addr = NULL;
	mini->bits_per_pixel = 0;
	mini->endian = 0;
	mini->height = 0;
	mini->line_length = 0;
	mini->width = 0;
	return (mini);
}

t_vars	*ft_init_vars(t_context *context)
{
	t_vars		*vars;

	vars = NULL;
	if (context)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (!vars)
			return (NULL);
		vars->mlx_datas = (t_mlx_datas *)malloc(sizeof(t_mlx_datas));
		if (!vars->mlx_datas)
			return (NULL);
		vars->rays = (t_rays *)malloc(sizeof(t_rays));
		if (!vars->rays)
			return (NULL);
		vars->rays_door = (t_rays *)malloc(sizeof(t_rays));
		if (!vars->rays_door)
			return (NULL);
		vars->context = context;
		vars->context->frames_door = 0;
		vars->context->frames = 0;
		vars->keys = ft_init_keys();
		vars->minimap = ft_init_minimap();
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
	data->tex_img = mlx_xpm_file_to_image(md->mlx, \
		data->path, data->tex_width, data->tex_height);
	data->tex_addr = mlx_get_data_addr(data->tex_img, &data->bppixels, \
		data->tex_width, &data->endian);
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
	context->door->path = ft_strdup("./textures/t_gungeon_door.xpm");
	context->animated[0]->path = ft_strdup("./textures/flame1.xpm");
	context->animated[1]->path = ft_strdup("./textures/flame2.xpm");
	context->animated[2]->path = ft_strdup("./textures/flame3.xpm");
}

void	ft_get_full_textures(t_context *context, t_mlx_datas *md, int *err_no)
{
	ft_set_texture(context->north, md);
	ft_set_texture(context->south, md);
	ft_set_texture(context->west, md);
	ft_set_texture(context->east, md);
	ft_set_texture(context->door, md);
	ft_set_texture(context->animated[0], md);
	ft_set_texture(context->animated[1], md);
	ft_set_texture(context->animated[2], md);
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
		ft_set_minimap(vars);
	}
	return (vars);
}

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
	while (str[i] && ft_strchr(" 01NSWEADO", str[i]))
		i++;
	if (i && i == len)
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

int	ft_atoi_rgb_safe(const char *nptr, int *check)
{
	long int	i;
	int			k;

	i = 0;
	k = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '-')
			k = -1;
		else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
			k = 1;
		if (*nptr == '-' || *nptr == '+')
			nptr++;
		while (*nptr && *nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i += *nptr - '0';
			if ((k * i) > 255 || (k * i) < 0)
				*check = 0;
			nptr++;
		}
	}
	return (i * k);
}

char	ft_check_valid_fc(char *str)
{
	int		i;
	char	type;
	char	**colors;

	type = str[0];
	i = 1;
	while (str[i] == ' ')
		i++;
	if (i == 1 || !str[i])
		return ('0');
	colors = ft_split(str + i, ',');
	if (ft_strslen(colors) == 3 && ft_strs_are_digits(colors))
	{
		ft_atoi_rgb_safe(colors[0], &i);
		ft_atoi_rgb_safe(colors[1], &i);
		ft_atoi_rgb_safe(colors[2], &i);
		if (i)
		{
			ft_full_free((void **)colors);
			return (type);
		}
	}
	ft_full_free((void **)colors);
	return ('0');
}

char	ft_check_valid_nswe(char *str)
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

char	ft_check_valid_animation(char *str)
{
	int		i;
	char	type;

	i = 2;
	type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 2 || !str[i])
		return ('0');
	return (type);
}

char	ft_check_valid_door(char *str)
{
	int		i;
	char	type;

	i = 2;
	if ((str[0] == 'D' && str[1] == 'R' && str[2] == ' '))
		type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 2 || !str[i])
		return ('0');
	return (type);
}

char	ft_type_specifier(char *str, int target_type)
{
	char	type;

	type = '0';
	if (target_type == 1)
		type = ft_check_valid_fc(str);
	else if (target_type == 2)
		type = ft_check_valid_nswe(str);
	else if (target_type == 3)
		type = ft_check_valid_door(str);
	else if (target_type == 4)
		type = ft_check_valid_animation(str);
	return (type);
}

char	ft_define_line_type(char *str, int len)
{
	char	type;

	type = '0';
	if (len)
	{
		if (ft_potential_map_line(str, len))
			type = 'M';
		else if (ft_strchr("FC", str[0]) && len > 2)
			type = ft_type_specifier(str, 1);
		else if (ft_strchr("D", str[0]) && len > 3)
			type = ft_type_specifier(str, 3);
		else if (ft_strchr("A", str[0]) && len > 2)
			type = ft_type_specifier(str, 4);
		else if (ft_strchr("NSWE", str[0]) && len > 3)
			type = ft_type_specifier(str, 2);
	}
	return (type);
}

t_lines	*ft_fill_content(int size, int fd, int index)
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
		elem->next = ft_fill_content(size, fd, index);
	}
	if (++size && --index == 0)
		buffer = get_next_line(fd);
	return (elem);
}

t_lines	*ft_init_content(char *filename, int *err_no)
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
		lst = ft_fill_content(size, fd, 0);
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
	if (tab[0] != 1 || tab[1] != 1 || tab[2] != 1 || tab[3] != 1)
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
	// if (!ft_check_doors(content, err_no))
	// 	return (0);
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

char	*ft_line_to_standard(char *str, int max)
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
			if (ft_strchr("NSWE0DO", map[i][j]))
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
		printf("%c %s\n", content->type, content->line);
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

t_context	*ft_cub3d_bonus_parsing(char **argv, int *err_no)
{
	t_context	*context;
	t_lines		*content;

	context = NULL;
	content = ft_init_content(argv[1], err_no);
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
			if (!ft_check_if_flawless(context->map, err_no))
				ft_unset_context(context);
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
	else if (err_no == ERR_FLOOR_CEILLING_FORMAT)
		printf("Wrong definition of colors for floor or ceilling.\n");
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
		printf("Unexpected map content or position.\n");
	else if (err_no == ERR_MISSING_TEXTURE_PATHS)
		printf("Missing texture paths.\n");
	else if (err_no == ERR_TOO_MUCH_TEXTURE_PATHS)
		printf("Too much texture paths defined.\n");
	else if (err_no == ERR_MISSING_SURFACES)
		printf("Missing proper floor or ceilling definition.\n");
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
	ft_true_free((void **)&vars->minimap);
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
		context = ft_cub3d_bonus_parsing(argv, &err_no);
		if (!err_no)
			vars = ft_get_vars(context, &err_no);
		if (context && vars && !err_no)
		{
			ft_hooks_activation(vars);
			mlx_loop_hook(vars->mlx_datas->mlx, ft_cub3d, vars);
			mlx_loop(vars->mlx_datas->mlx);
			ft_unset_vars(vars);
		}
		else
			ft_print_cub3d_error_1(err_no);
	}
	else
		write(2, "Error.\nWrong arguments.\n", 24);
	return (0);
}
