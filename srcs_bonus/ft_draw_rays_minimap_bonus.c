/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays_minimap_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_rays_minimap(t_vars *vars, t_rays *rays)
{
	vars->rays->r_id = 0;
	vars->rays->r_angle = vars->position->view_angle - (RADIAN * 30);
	while (vars->rays->r_id < WINDOW_WIDTH)
	{
		ft_angle_adjustement(&vars->rays->r_angle);
		vars->rays->a_tan = -1 / tan(vars->rays->r_angle);
		vars->rays->n_tan = -tan(vars->rays->r_angle);
		ft_horizontal_axis_intersection(vars, rays);
		vars->rays->short_x = vars->rays->impact_x;
		vars->rays->short_y = vars->rays->impact_y;
		ft_vertical_axis_intersection(vars, rays);
		ft_draw_ray_hit(vars, RAY_COLOR, rays);
		vars->rays->r_angle += ((PI / 3 / WINDOW_WIDTH));
		vars->rays->r_id++;
	}
}
