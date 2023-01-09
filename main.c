/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 17:49:00 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_fdf_setup_matrix(t_vars *vars, t_spot **matrix)
{
	ft_fdf_first_position(vars, matrix);
	ft_fdf_rotation_z(vars, matrix, 3.14159265 * 45 / 180);
	ft_fdf_rotation_x(vars, matrix, 3.14159265 * 60 / 180);
	ft_fdf_last_position(vars, matrix);
	ft_print_grid(vars, matrix);
}

void	ft_fdf(char *filename)
{
	t_vars	*vars;
	t_spot	**matrix;

	vars = ft_fdf_initvars(filename);
	if (!vars)
	{
		ft_printf("Map error.\n");
		return ;
	}
	matrix = ft_map_to_matrix(vars, filename);
	mlx_key_hook(vars->win, ft_keypress, vars);
	mlx_hook(vars->win, ON_DESTROY, DestroyAll, ft_click_cross, vars);
	mlx_loop_hook(vars->mlx, ft_frame, vars);
	ft_fdf_setup_matrix(vars, matrix);
	mlx_loop(vars->mlx);
	ft_fdf_free_matrix(matrix, vars);
	ft_end_mlx(&vars);
}

int	ft_fdf_error_management(int ac, char **argv)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv[1]);
	if (ac != 2 || len < 5)
		return (1);
	if (!ft_check_extension(argv[1], ".fdf"))
		return (2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (3);
	close(fd);
	return (0);
}


void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **argv)
{
	t_vars	img;
	int px;
	int py;
	char	map[10][10] = {	"..........",
							".11111111.",
							".10000001.",
							".10000001.",
							".10000001.",
							".10000001.",
							".10000001.",
							".10000001.",
							".11111111.",
							".........."};

	(void)map;
	px = 300;
	py = 300;
	(void)ac;
	(void)argv;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, px, py, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
