/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:08 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotation(t_vars *vars)
{
	if (vars->keys->left_arr || vars->keys->right_arr)
	{
		if (vars->keys->left_arr == 1)
			vars->position->view_angle -= RSPEED;
		if (vars->keys->right_arr == 1)
			vars->position->view_angle += RSPEED;
		ft_angle_adjustement(&vars->position->view_angle);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
	}
}
