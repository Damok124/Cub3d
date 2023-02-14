/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_identification_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:46 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_wall_identification(t_player *position, t_rays *rays)
{
	double	px;
	double	py;

	px = position->player_x;
	py = position->player_y;
	if (ft_distance(px, py, rays->impact_x, rays->impact_y) \
		> ft_distance(px, py, rays->short_x, rays->short_y))
	{
		if (rays->short_y < py)
			rays->wall_direction = NORTH;
		else
			rays->wall_direction = SOUTH;
	}
	else
	{
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
		if (rays->short_x > px)
			rays->wall_direction = EAST;
		else
			rays->wall_direction = WEST;
	}
	rays->ray_len = ft_distance(px, py, rays->short_x, rays->short_y);
}
