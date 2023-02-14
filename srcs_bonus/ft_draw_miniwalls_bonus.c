/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_miniwalls_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_miniwalls(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->context->map[y])
	{
		x = 0;
		while (vars->context->map[y][x])
		{
			if (ft_strchr("1A", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, WALL_COLOR);
			else if (ft_strchr("D", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, CLOSE_COLOR);
			x++;
		}
		y++;
	}
}
