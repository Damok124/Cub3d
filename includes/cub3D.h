/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:48:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/17 19:17:33 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include <math.h>
# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "ft_printf.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#define IMG 32			//size_image
#define SPEED 2			//speed
#define RSPEED 0.06 		//rotation speed
#define DR 0.0174533 	// one degree in radian
#define PI 3.1415926535
#define DOF 64
#define P2 PI / 2
#define FLOOR 0xFFFFFF
#define CEILING 0x000000
#define P3 3 * PI /2 


typedef struct s_lines {
	char			*line;
	int				index;
	int				len;
	char			type;
	struct s_lines	*next;
}	t_lines;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;



typedef struct t_keys {
	int w;
	int a;
	int d;
	int s;
}					t_keys;

typedef struct s_rays {
	int				r;
	int				mx;
	int				my;
	int				dof;
	int				orientation;
	float			rx;
	float			ry;
	float			ra;
	float			xo;
	float			yo;
	float			hx;
	float			hy;
	float			vx;
	float			vy;
	float			sx;
	float			sy;
	float			aTan;
	float			distH;
	unsigned int	color;
	float			distT;
	float			distV;
	float			nTan;
}					t_rays;


typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	float			py;
	float			px;
	float			pdx;
	float			pdy;
	float			pa;
	char			**map;
	int				map_height;
	int				map_lenght;
	t_keys 			key;
	t_rays			rays;
}					t_vars;

typedef struct s_context {
	char	*path_t_NO;
	char	*path_t_SO;
	char	*path_t_WE;
	char	*path_t_EA;
	t_rgb	floor;
	t_rgb	ceiling;
	char	player_orient;
	char	**map;
	t_vars	vars;
}	t_context;


/////////////////////////
//	cub3d
/////////////////////////


void	ft_vertical_line(t_vars *vars, t_rays *rays);
void	ft_horizontal_line(t_vars *vars, t_rays *rays);
int		ft_display(t_context *context);
void	ft_draw_ray_hit(t_vars *vars, t_rays *rays, unsigned int color);
void	ft_draw_map(t_vars *vars);
void	ft_draw_squarre(t_vars *vars, int y, int x, int color);
int		ft_if_player(t_vars *vars, int y, int x);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	ft_3d_display(t_vars *vars, t_rays *rays);
void	ft_ang_rays(t_rays *rays);
void	ft_draw_player(t_vars *vars);
int		ft_move_keycode(int keycode, t_vars *vars);
void	ft_pars_pos_player(t_vars *vars);
int		ButtonUp(int keycode, t_vars *vars);
int		ButtonDown(int keycode, t_vars *vars);
void	ft_init(t_context *context);
void	ft_draw_rays(t_context *context);
float	ft_dist(float ax, float ay, float bx, float by);


/////////////////////////
//	cub3d parsing
/////////////////////////

t_context	*ft_cub3d_parsing(char **argv);
void		ft_show_content(t_lines *content);
void		ft_unset_context(t_context *context);
char		ft_get_player_orientation(t_lines *content);
t_rgb		ft_get_rgb(t_lines *content, char type);
void		ft_get_textures_paths(t_context **context, t_lines *content);
int			ft_check_if_flawless(char **map);
char		**ft_get_map(t_lines *lst);
int			ft_get_map_size(t_lines *lst);
void		ft_square_shaped_dotted_map(t_lines *content);
t_lines		*ft_add_empty_map_line(int max, t_lines *next);
void		ft_spotted_spaces(char *str);
char		*ft_line_to_standard(char *str, int	max);
int			ft_check_content(t_lines *content);
int			ft_just_enough_args(t_lines *content, int *tab);
void		ft_unset_content(t_lines *content);
t_context	*ft_init_t_context(void);
t_lines		*ft_get_all_lines(char *filename);
t_lines		*ft_setup_lst(int size, int fd, int index);
char		ft_define_line_type(char *str, int	len);
char		ft_type_specifier(char *str, int target_size);
char		ft_find_valid_nswe(char *str);
char		ft_find_valid_fc(char *str);
int			ft_strs_are_digits(char **strs);
int			ft_file_lines_counter(char *filename);
void		ft_check_lst_lines(t_lines *lst);
void		ft_show_strs(char **map);
void		ft_cub3d(t_context *context);
int			ft_potential_map_line(char *str, int len);
int			ft_one_last_map(t_lines *content);
int			ft_only_one_position(t_lines *content);
int			ft_get_greatest_len(t_lines *content);
char		**ft_strsdup(char **src);

/////////////////////////
//	INTERACTIONS
/////////////////////////
int				ft_keypress(int key, t_vars *vars);
char			ft_base_key(int *tab, int key);
int				ft_click_cross(t_vars *vars);
int				ft_manual_color(t_vars *vars, int key);

#endif
