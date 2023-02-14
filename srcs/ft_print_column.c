/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:01 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_column(t_vars *vars, int line_start,
		int line_end, t_rays *rays)
{
	unsigned int	col;
	int				pixel;

	vars->context->step = 0;
	pixel = 0;
	while ((line_start + pixel) < line_end - 1
		&& line_start + pixel < WINDOW_HEIGHT)
	{
		pixel++;
		if (line_start + pixel > 0)
		{
			vars->context->step = \
				((double)pixel / (double)(line_end - line_start));
			ft_print_type(vars->context->step, &col, vars, rays);
			if (col != 0xff00ff)
				ft_mlx_pixel_put(vars, rays->r_id, (line_start + pixel), col);
		}
	}
}
