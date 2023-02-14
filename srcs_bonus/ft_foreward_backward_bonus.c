/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreward_backward_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_foreward_backward(t_vars *vars)
{
	if (vars->keys->s == 1)
	{
		vars->position->player_x -= vars->position->pdx;
		if (ft_map_wall(vars))
			vars->position->player_x += vars->position->pdx;
		vars->position->player_y -= vars->position->pdy;
		if (ft_map_wall(vars))
			vars->position->player_y += vars->position->pdy;
	}
	if (vars->keys->w == 1)
	{
		vars->position->player_x += vars->position->pdx;
		if (ft_map_wall(vars))
			vars->position->player_x -= vars->position->pdx;
		vars->position->player_y += vars->position->pdy;
		if (ft_map_wall(vars))
			vars->position->player_y -= vars->position->pdy;
	}
}
