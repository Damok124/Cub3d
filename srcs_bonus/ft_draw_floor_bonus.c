/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:10 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_floor(t_context *context, t_vars *vars)
{
	int	x;
	int	color;
	int	y;

	color = (context->floor.red << 16) + (context->floor.green << 8) \
		+ (context->floor.blue);
	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}
