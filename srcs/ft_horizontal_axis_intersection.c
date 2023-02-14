/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_axis_intersection.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_horizontal_axis_intersection(t_vars *vars, t_rays *rays)
{
	int	dov;

	rays->dov = 0;
	if (vars->context->map_height < vars->context->map_length)
		dov = vars->context->map_length * 2;
	else
		dov = vars->context->map_height * 2;
	if (rays->r_angle == 0 || rays->r_angle == PI)
		ft_parallel_axis(vars, dov, rays);
	else if (rays->r_angle > PI)
		ft_h_not_parallel_axis(vars, -1, rays);
	else if (rays->r_angle < PI)
		ft_h_not_parallel_axis(vars, 1, rays);
	ft_deep_of_view_explorer(vars, dov, rays);
}
