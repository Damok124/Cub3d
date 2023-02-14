/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_3d_display(t_vars *vars, t_rays *rays)
{
	double	line_height;
	double	line_start;
	double	line_end;
	double	ratio;
	double	ca;

	ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	ca = vars->position->view_angle - rays->r_angle;
	ft_angle_adjustement(&ca);
	rays->ray_len *= cos(ca);
	line_height = ((SQ_SIZE * (WINDOW_HEIGHT)) / rays->ray_len) * ratio;
	line_start = ((WINDOW_HEIGHT) / 2) - (line_height / 2);
	line_end = line_start + line_height;
	ft_print_column(vars, line_start, line_end, rays);
}
