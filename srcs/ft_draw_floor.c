/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:14 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
