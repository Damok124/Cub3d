/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minispaces_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:12 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_minispaces(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->context->map[y])
	{
		x = 0;
		while (vars->context->map[y][x])
		{
			if (vars->context->map[y][x] == '0')
				ft_draw_square_minimap(vars, y, x, SPACE_COLOR);
			else if (ft_strchr("NSWE", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, START_COLOR);
			else if (ft_strchr("O", vars->context->map[y][x]))
				ft_draw_square_minimap(vars, y, x, OPEN_COLOR);
			x++;
		}
		y++;
	}
}
