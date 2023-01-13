/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/13 20:11:09 by alprival         ###   ########.fr       */
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

int		ft_if_player(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'E' || vars->map[y][x] == 'N' || vars->map[y][x] == 'S' || vars->map[y][x] == 'W')
		return (1);
	return (0);
}

float	ft_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}	

int	ButtonDown(int keycode, t_vars *vars)
{
	if	(keycode == 'a')
		vars->key.a = 1;
	if	(keycode == 's')
		vars->key.s = 1;
	if	(keycode == 'd')
		vars->key.d = 1;
	if	(keycode == 'w')
		vars->key.w = 1;
	return(keycode);
}

int	ButtonUp(int keycode, t_vars *vars)
{
	if	(keycode == 'a')
		vars->key.a = 0;
	if	(keycode == 's')
		vars->key.s = 0;
	if	(keycode == 'd')
		vars->key.d = 0;
	if	(keycode == 'w')
		vars->key.w = 0;
	return(keycode);
}

int	main(int ac, char **argv)
{
	t_vars	vars;
	
	int fd;
	int i;
	fd = open("map.cub",O_RDWR);
	vars.map = malloc(sizeof(char *) * 11);
	if(!vars.map)
		return (1);
	vars.map_height = 11;
	i = 0;
	vars.map[i] = get_next_line(fd);
	vars.map_lenght = ft_strlen(vars.map[i]);
	while(vars.map[i])
	{
		vars.map[i + 1] = get_next_line(fd);
		i++;
	}
	vars.map_height = i - 1;
	ft_init(&vars);
	(void)ac;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map_lenght -1) * 2 * IMG, vars.map_height * IMG, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
						&vars.endian);
	mlx_hook(vars.win, 2, 1L << 0, ButtonDown, &vars);
	mlx_hook(vars.win, 3, 1L << 1, ButtonUp, &vars);
	mlx_loop_hook(vars.mlx, ft_display, &vars);
	mlx_loop(vars.mlx);
}
