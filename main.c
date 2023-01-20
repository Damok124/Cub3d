/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/21 00:24:48 by alprival         ###   ########.fr       */
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
	if (keycode == XK_Escape)
		vars->key.esc = 1;
	if (keycode == XK_space && vars->key.weapon == 1)
		vars->key.weapon = 0;
	else if (keycode == XK_space)
		vars->key.weapon = 1;
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
}
