# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include <math.h>
# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/includes/libft.h"
# include "ft_printf/includes/ft_printf.h"

/*
clang -Wall -Wextra -Werror -g3 full_parsing.c -Iincludes/ -Ift_printf/includes/ -Ilibft/includes/ -Imlx/ -L. -lcub3D -L./mlx -lmlx -lXext -lX11 -L./libft -lft -L./ft_printf -lft_printf -o parsing -lm
*/

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_context {
	char	*texture_NO;
	char	*texture_SO;
	char	*texture_WE;
	char	*texture_EA;
	t_rgb	floor;
	t_rgb	ceiling;
	char	**map;
}	t_context;

int	main(int ac, char **argv)
{
	(void)ac;
	(void)argv;
	return (0);
}
