/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_left_right(t_vars *vars)
{
	double	angle;

	angle = vars->position->view_angle;
	if (vars->keys->a == 1)
	{
		vars->position->player_x += cos(angle - M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_x -= cos(angle - M_PI / 2) * SPEED;
		vars->position->player_y += sin(angle - M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_y -= sin(angle - M_PI / 2) * SPEED;
	}
	if (vars->keys->d == 1)
	{
		vars->position->player_x += cos(angle + M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_x -= cos(angle + M_PI / 2) * SPEED;
		vars->position->player_y += sin(angle + M_PI / 2) * SPEED;
		if (ft_map_wall(vars))
			vars->position->player_y -= sin(angle + M_PI / 2) * SPEED;
	}
}
