/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_column_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_print_column(t_vars *vars, int line_s,
		int line_e, t_rays *rays)
{
	unsigned int	col;
	int				pixel;

	vars->context->step = 0;
	pixel = 0;
	while ((line_s + pixel) < line_e - 1
		&& line_s + pixel < WINDOW_HEIGHT)
	{
		pixel++;
		if (line_s + pixel > 0)
		{
			vars->context->step = ((double)pixel / (double)(line_e - line_s));
			ft_print_type(vars->context->step, &col, vars, rays);
			if (col != 0xff00ff)
				ft_mlx_pixel_put(vars, rays->r_id, (line_s + pixel), col);
		}
	}
}
