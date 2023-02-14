/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceilling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:12 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_ceilling(t_context *context, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	color = (context->ceiling.red << 16) + (context->ceiling.green << 8) \
		+ (context->ceiling.blue);
	y = 0;
	while (y < WINDOW_HEIGHT / 2)
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
