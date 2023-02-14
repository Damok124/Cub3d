/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_axis_intersection_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:45 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_vertical_axis_intersection(t_vars *vars, t_rays *rays)
{
	double	angle;
	int		dov;

	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length * 2;
	else
		dov = vars->context->map_height * 2;
	angle = rays->r_angle;
	rays->dov = 0;
	if (angle == (PI / 2) || angle == (3 * PI / 2))
		ft_parallel_axis(vars, dov, rays);
	else if (angle > (PI / 2) && angle < (3 * PI / 2))
		ft_v_not_parallel_axis(vars, -1, rays);
	else if (angle < (PI / 2) || angle > (3 * PI / 2))
		ft_v_not_parallel_axis(vars, 1, rays);
	ft_deep_of_view_explorer(vars, dov, rays);
}
