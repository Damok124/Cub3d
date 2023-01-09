/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:48:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 01:07:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
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

typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*hexcolor;
	int				red;
	int				green;
	int				blue;
	int				rows;
	int				len;
	int				spacing;
}					t_vars;

typedef struct s_spot {
	float			x;
	float			y;
	float			z;
	int				red;
	int				green;
	int				blue;
}					t_spot;

/////////////////////////
//	INTERACTIONS
/////////////////////////
int				ft_keypress(int key, t_vars *vars);
char			ft_base_key(int *tab, int key);
int				ft_click_cross(t_vars *vars);
int				ft_manual_color(t_vars *vars, int key);
/////////////////////////
//	OCTANTS
/////////////////////////
int				ft_get_octant(int x1, int x2, int y1, int y2);
int				ft_get_octant2(int x1, int x2, int y1, int y2);
void			ft_trace_oct5(t_vars *vars, t_spot a, t_spot b);
void			ft_trace_oct6(t_vars *vars, t_spot a, t_spot b);
void			ft_trace_oct7(t_vars *vars, t_spot a, t_spot b);
void			ft_trace_oct8(t_vars *vars, t_spot a, t_spot b);
/////////////////////////
//	PRINTING
/////////////////////////
void			ft_print_grid(t_vars *vars, t_spot **matrix);
void			ft_print_dot(t_vars *vars, t_spot dot);
int				ft_link(t_vars *vars, t_spot a, t_spot b);
void			ft_pixel_put(t_vars *vars, int x, int y);
int				ft_renew_image(t_vars *vars);
int				ft_frame(t_vars	*vars);
/////////////////////////
//	CHECKING
/////////////////////////
int				ft_pix_is_visible(int x, int y);
int				ft_fdf_lencheck(t_vars *vars, char *str);
/////////////////////////
//	DATAS
/////////////////////////
int				ft_fdf_getlen(char *str);
int				ft_fdf_rowcount(char *filename);
void			ft_fdf_initcol(t_vars *vars);
char			*ft_standard_buffer(char *buffer);
t_spot			**ft_map_to_matrix(t_vars *vars, char *filename);
t_spot			*ft_fdf_init_rows(char **buffer, t_vars *vars, int y);
t_spot			ft_fdf_setup_dot(char **buffer, int x, int y, t_vars *vars);
int				ft_fdf_spacing(t_vars *vars);
t_vars			*ft_fdf_initvars(char *filename);
void			ft_fdf_get_col(t_vars *vars, t_spot a, t_spot b, double ratio);
/////////////////////////
//	DOTS POSITION
/////////////////////////
void			ft_fdf_first_position(t_vars *vars, t_spot **matrix);
void			ft_fdf_last_position(t_vars *vars, t_spot **matrix);
void			ft_fdf_rotation_z(t_vars *vars, t_spot **matrix, double angle);
void			ft_fdf_rotation_x(t_vars *vars, t_spot **matrix, double angle);
/////////////////////////
//	MATHEMATICS
/////////////////////////
double			ft_hypotenuse(int a, int b);
unsigned int	ft_fdf_btou(const char *nptr, char *base);
/////////////////////////
//	ENDING
/////////////////////////
void			ft_fdf_free_matrix(t_spot **matrix, t_vars *vars);
void			ft_end_mlx(t_vars **vars);

#endif
