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
	char	*path_t_NO;
	char	*path_t_SO;
	char	*path_t_WE;
	char	*path_t_EA;
	t_rgb	floor;
	t_rgb	ceiling;
	char	**map;
}	t_context;

void	ft_cub3d(t_context *context)
{
	(void)context;
}

t_context	*ft_cub3d_parsing(char **argv)
{
	t_context	*context;

	context = (t_context *)malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->path_t_NO = NULL;
	context->path_t_SO = NULL;
	context->path_t_WE = NULL;
	context->path_t_EA = NULL;
	context->map = NULL;
	(void)argv;
	return (context);
}

void	ft_unset_context(t_context *context)
{
	ft_true_free((void **)&context->path_t_NO);
	ft_true_free((void **)&context->path_t_SO);
	ft_true_free((void **)&context->path_t_WE);
	ft_true_free((void **)&context->path_t_EA);
	ft_full_free((void **)context->map);
	ft_true_free((void **)&context);
}

int	main(int ac, char **argv)
{
	t_context	*context;

	if (ac == 2)
	{
		context = ft_cub3d_parsing(argv);
		if (context)
		{
			ft_cub3d(context);
			ft_unset_context(context);
		}
		else
			perror("FAILURE.\n");
	}
	write(2, "Wrong arguments.\n", 17);
	return (0);
}
