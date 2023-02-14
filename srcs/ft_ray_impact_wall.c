/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_impact_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_ray_impact_wall(t_vars *vars, int dov, t_rays *ray)
{
	while (ray->dov < dov)
	{
		ray->tmp_rx = (int)(ray->impact_x) >> 6;
		ray->tmp_ry = (int)(ray->impact_y) >> 6;
		if (ray->tmp_rx >= 0 && ray->tmp_ry >= 0
			&& ray->tmp_rx < vars->context->map_length
			&& ray->tmp_ry < vars->context->map_height
			&& ray->tmp_ry < WINDOW_HEIGHT
			&& ray->tmp_rx < WINDOW_WIDTH
			&& (ft_strchr("1", vars->context->map[ray->tmp_ry][ray->tmp_rx])))
			ray->dov = dov;
		else
		{
			ray->impact_x += ray->xo;
			ray->impact_y += ray->yo;
			ray->dov += 1;
		}
	}
}
