/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_around_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:14 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_player_around(t_vars *vars, int x, int y)
{
	if (y == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else if (y == (int)vars->position->player_y / 64
		&& x - 1 == (int)vars->position->player_x / 64)
		return (1);
	else if (y == (int)vars->position->player_y / 64
		&& x + 1 == (int)vars->position->player_x / 64)
		return (1);
	else if (y - 1 == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else if (y + 1 == (int)vars->position->player_y / 64
		&& x == (int)vars->position->player_x / 64)
		return (1);
	else
		return (0);
}
