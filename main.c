/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 18:55:49 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_if_player(t_vars *vars, int y, int x)
{
	if (ft_strchr("NSWE", vars->map[y][x]))
		return (1);
	return (0);
}

float	ft_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	button_down(int keycode, t_vars *vars)
{
	if (keycode == 'a')
		vars->key.a = 1;
	if (keycode == 's')
		vars->key.s = 1;
	if (keycode == 'd')
		vars->key.d = 1;
	if (keycode == 'w')
		vars->key.w = 1;
	if (keycode == 'e')
		vars->key.e = 1;
	return (keycode);
}

int	button_up(int keycode, t_vars *vars)
{
	if (keycode == 'a')
		vars->key.a = 0;
	if (keycode == 's')
		vars->key.s = 0;
	if (keycode == 'd')
		vars->key.d = 0;
	if (keycode == 'w')
		vars->key.w = 0;
	if (keycode == 'e')
		vars->key.e = 0;
	return (keycode);
}

int	main(int ac, char **argv)
{
	int			err_no;
	t_context	*context;

	context = NULL;
	err_no = 0;
	if (ac == 2 && ft_check_extension(argv[1], ".cub"))
	{
		context = ft_cub3d_parsing(argv, &err_no);
		if (context)
		{
			ft_cub3d(context);
			ft_unset_context(context);
		}
		else
			printf("Error.\n");
	}
	else
	{
		write(2, "Wrong arguments.\n", 17);
		return (0);
	}
	// int fd;
	// int i;
	// fd = open("map.cub",O_RDWR);
	// vars.map = malloc(sizeof(char *) * 15);
	// if(!vars.map)
		// return (1);
	// context->vars.map_height = 15;
	// i = 0;
	// vars.map[i] = get_next_line(fd);
	// vars.map_lenght = ft_strlen(vars.map[i]);
	// while(vars.map[i])
	// {
		// vars.map[i + 1] = get_next_line(fd);
		// i++;
	// }
	// vars.map_height = i - 1;

}
