/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_interactions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_mouse_interactions(int x, int y, t_vars *vars)
{
	(void)y;
	if (x < (WINDOW_WIDTH / 2) - 20)
	{
		vars->position->view_angle -= RSPEED;
		if (vars->position->view_angle < 0)
			vars->position->view_angle += (2 * PI);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
		mlx_mouse_move(vars->mlx_datas->mlx, vars->mlx_datas->win, \
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	else if (x > (WINDOW_WIDTH / 2) + 20)
	{
		vars->position->view_angle += RSPEED;
		if (vars->position->view_angle > (2 * PI))
			vars->position->view_angle -= (2 * PI);
		vars->position->pdx = cos(vars->position->view_angle) * SPEED;
		vars->position->pdy = sin(vars->position->view_angle) * SPEED;
		mlx_mouse_move(vars->mlx_datas->mlx, vars->mlx_datas->win, \
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	return (1);
}
