/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:48:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/07 18:33:28 by alprival         ###   ########.fr       */
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
#define ERR_FLOOR_CEILLING_FORMAT 16

#define PLAYER_COLOR 0x20FF15
#define RAY_COLOR 0xFFDF00
#define SPACE_COLOR 0x302010
#define START_COLOR 0x504030
#define WALL_COLOR 0xA090A0
#define CLOSE_COLOR 0xC01030
#define OPEN_COLOR 0x3050C0
#define EXT_COLOR 0

#define LEFT 1
#define RIGHT -1

#define X 0
#define Y 1

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4
#define WALL 5
#define DOOR 6
#define ANIMATION 7
#define DOOR_ANIMATION 8
#define DOOR_CLOSED 9

#define SQ_SIZE 64			//size_image
#define SCALING 4
#define MINIZONE 9
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

typedef struct s_minitools {
	int	i;
	int	j;
	int	start_x;
	int	start_y;
	int	target_x;
	int	target_y;
}		t_minitools;

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
	int				door;
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

typedef struct s_minimap
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_minimap;

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
	int			frames_door;
	int			frames;
	double 		step;
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
	t_rays		*rays_door;
	t_minimap	*minimap;
}				t_vars;

#endif
