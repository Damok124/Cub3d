/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_axis_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
