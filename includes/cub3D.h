/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:48:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:35:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

# include <math.h>
# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "ft_printf.h"

# define ERR_BAD_FD 1
# define ERR_MISSING_START_POSITION 2
# define ERR_TOO_MUCH_START_POSITION 3
# define ERR_MISSING_MAP 4
# define ERR_SOMETHING_BELOW_MAP 5
# define ERR_MISSING_TEXTURE_PATHS 6
# define ERR_TOO_MUCH_TEXTURE_PATHS 7
# define ERR_MISSING_SURFACES 8
# define ERR_TOO_MUCH_SURFACES 9
# define ERR_MAP_NOT_CLOSED 10
# define ERR_UNREADABLE_PATH 11
# define ERR_EMPTY_FILE 12
# define ERR_TEXTURE_INIT_FAILED 13
# define ERR_MALLOC_CONTEXT 14
# define ERR_BAD_TEXTURE_FILE 15
# define ERR_FLOOR_CEILLING_FORMAT 16
# define ERR_WRONG_FORMAT_SURFACES 18
# define ERR_UNEXPECTED_MENTIONS 21

# define PLAYER_COLOR 0x20FF15
# define RAY_COLOR 0xFFDF00
# define SPACE_COLOR 0x302010
# define START_COLOR 0x504030
# define WALL_COLOR 0xA090A0
# define EXT_COLOR 0

# define LEFT 1
# define RIGHT -1

# define X 0
# define Y 1

# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define WALL 5

# define SQ_SIZE 64
# define SCALING 4
# define MINIZONE 9
# define SPEED 5
# define RSPEED 0.06
# define RADIAN 0.0174533
# define PI 3.1415926535
# define DOV 2000
# define COLLISION 20

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

typedef struct s_checker {
	int			ani;
	int			door;
}					t_checker;

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
	int				r_id;
	double			short_x;
	double			short_y;
	unsigned int	color;
	double			ray_len;
	int				dov;
	int				tmp_rx;
	int				tmp_ry;
	double			impact_x;
	double			impact_y;
	double			r_angle;
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
	double		pdx;
	double		pdy;
	double		view_angle;
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
	t_textures	*east;
	t_rgb		floor;
	t_rgb		ceiling;
	char		**map;
	double		step;
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

void			ft_angle_adjustement(double *angle);
double			ft_distance(double ax, double ay, double bx, double by);
void			ft_mlx_pixel_put(t_vars *vars, int x, int y, int color);
char			*ft_right_color_from_xpm(t_textures *wall, double step, \
					double rank);
char			*ft_left_color_from_xpm(t_textures *wall, double step, \
					double rank);
unsigned int	ft_get_color_from_xpm(t_textures *wall, double step, \
					double rank, int read_from);
unsigned int	ft_get_wall_color(t_textures *texture, double step, \
					t_rays *rays);
void			ft_print_type(double step, unsigned int *col,
					t_vars *vars, t_rays *rays);
void			ft_print_column(t_vars *vars, int line_start,
					int line_end, t_rays *rays);
void			ft_3d_display(t_vars *vars, t_rays *rays);
void			ft_ray_impact_wall(t_vars *vars, int dov, t_rays *ray);
void			ft_deep_of_view_explorer(t_vars *vars, int dov, t_rays *rays);
void			ft_parallel_axis(t_vars *vars, int dov, t_rays *rays);
void			ft_h_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays);
void			ft_v_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays);
void			ft_horizontal_axis_intersection(t_vars *vars, t_rays *rays);
void			ft_vertical_axis_intersection(t_vars *vars, t_rays *rays);
void			ft_wall_identification(t_player *position, t_rays *rays);
void			ft_draw_environment(t_vars *vars, t_rays *rays);
void			ft_rotation(t_vars *vars);
int				ft_map_wall(t_vars *vars);
void			ft_foreward_backward(t_vars *vars);
void			ft_left_right(t_vars *vars);
void			ft_keyboard_interactions(t_vars *vars);
void			ft_draw_ceilling(t_context *context, t_vars *vars);
void			ft_draw_floor(t_context *context, t_vars *vars);
int				ft_cub3d(t_vars *vars);
int				ft_click_cross(void *mlx_ptr);
int				ft_hold_key(int keycode, t_vars *vars);
int				ft_release_key(int keycode, t_vars *vars);
void			ft_hooks_activation(t_vars *vars);
int				ft_if_player_here(t_vars *vars, int y, int x);
double			ft_get_first_angle(char orientation);
t_player		*ft_get_player_position(t_vars *vars, char orientation);
t_keys			*ft_init_keys(void);
t_vars			*ft_init_vars(t_context *context);
void			ft_set_texture(t_textures *data, t_mlx_datas *md);
void			ft_get_textures_paths(t_context *context, t_lines *content);
void			ft_get_full_textures(t_context *context, t_mlx_datas *md, \
					int *err_no);
t_vars			*ft_get_vars(t_context *context, int *err_no);
int				ft_file_lines_counter(int fd);
int				ft_potential_map_line(char *str, int len);
int				ft_strs_are_digits(char **strs);
int				ft_atoi_rgb_safe(const char *nptr, int *check);
char			ft_check_valid_fc(char *str);
char			ft_check_valid_nswe(char *str);
char			ft_check_valid_animation(char *str);
char			ft_check_valid_door(char *str);
char			ft_type_specifier(char *str, int target_type);
char			ft_define_line_type(char *str, int len);
t_lines			*ft_fill_content(int size, int fd, int index);
t_lines			*ft_init_content(char *filename, int *err_no);
t_textures		*ft_init_t_textures(void);
t_context		*ft_init_t_context(int *err);
void			ft_unset_content(t_lines *content);
int				ft_just_enough_surfaces(t_lines *content, \
					int *tab, int *err_no);
void			ft_enough_paths_err_no(int *tab, int *err_no);
int				ft_just_enough_paths(t_lines *content, int *tab, int *err_no);
int				ft_one_last_map(t_lines *content, int *err_no);
int				ft_only_one_position(t_lines *content, int *err_no);
void			ft_check_one_texture(char *path, int *err_no);
void			ft_check_duplicates(char *path, int *err_no, char c);
int				ft_check_format_punctuation(t_lines *content, int *err_no);
int				ft_check_format_textures(char *path, t_lines *content, \
					int *err_no, int i);
int				ft_check_type_in_content(t_lines *content, char type);
int				ft_check_garbage(t_lines *content, int *err_no);
int				ft_check_content(t_lines *content, int *err_no);
int				ft_get_greatest_len(t_lines *content);
char			*ft_line_to_standard(char *str, int max);
void			ft_spotted_spaces(char *str);
t_lines			*ft_add_empty_line_to_map(int max, t_lines *next);
void			ft_square_shaped_dotted_map(t_lines *content);
int				ft_get_map_size(t_lines *lst);
char			**ft_get_map(t_lines *lst);
int				ft_check_if_flawless(char **map, int *err_no);
t_rgb			ft_get_rgb(t_lines *content, char type);
char			ft_get_player_orientation(t_lines *content);
void			ft_destroy_ani_context(t_textures **animated);
void			ft_unset_context(t_context *context);
t_context		*ft_cub3d_bonus_parsing(char **av, int *err_no);
void			ft_print_cub3d_error_2(int err_no);
void			ft_print_cub3d_error_1(int err_no);
void			ft_destroy_img_safely(t_textures *texture, t_vars *vars);
void			ft_unset_vars(t_vars *vars);
void			ft_init_cub3d(t_vars *vars, t_context *context, int err_no);
int				main(int ac, char **argv);

#endif
