/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_environment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_environment(t_vars *vars, t_rays *rays)
{
	rays->r_id = 0;
	rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	ft_angle_adjustement(&rays->r_angle);
	while (rays->r_id < WINDOW_WIDTH)
	{
		rays->a_tan = -1 / tan(rays->r_angle);
		rays->n_tan = -tan(rays->r_angle);
		ft_horizontal_axis_intersection(vars, rays);
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
		ft_vertical_axis_intersection(vars, rays);
		ft_wall_identification(vars->position, rays);
		rays->wall_type = WALL;
		ft_3d_display(vars, rays);
		ft_angle_adjustement(&rays->r_angle);
		rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		rays->r_id++;
	}
}
