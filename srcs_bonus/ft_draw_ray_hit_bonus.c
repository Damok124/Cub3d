/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ray_hit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_ray_hit(t_vars *vars, unsigned int color, t_rays *rays)
{
	t_player	*pos;

	pos = vars->position;
	if (ft_distance(pos->player_x, pos->player_y,
			rays->impact_x, rays->impact_y)
		< ft_distance(pos->player_x, pos->player_y,
			rays->short_x, rays->short_y))
	{
		rays->short_x = rays->impact_x;
		rays->short_y = rays->impact_y;
	}
	ft_pixel_around_impacts(vars, 3, color);
}
