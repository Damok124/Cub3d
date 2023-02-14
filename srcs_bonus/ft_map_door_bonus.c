/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_map_door(t_vars *vars)
{
	int			player_x;
	int			player_y;
	double		player_angle;

	player_x = (int)(vars->position->player_x / SQ_SIZE);
	player_y = (int)(vars->position->player_y / SQ_SIZE);
	player_angle = vars->position->view_angle;
	if (ft_open_door(vars, player_x, player_y, player_angle))
		return ;
	else
		ft_close_door(vars, player_x, player_y, player_angle);
}
