/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_collision(t_vars *vars, t_margin *margin, int i)
{
	t_player	*pos;
	int			coeff_x;
	int			coeff_y;

	pos = vars->position;
	coeff_x = i;
	if (pos->pdx < 0)
		coeff_x = -i;
	coeff_y = i;
	if (pos->pdy < 0)
		coeff_y = -i;
	margin->ipx_add_xo = (pos->player_x + coeff_x) / SQ_SIZE;
	margin->ipx_sub_xo = (pos->player_x - coeff_x) / SQ_SIZE;
	margin->ipy_add_yo = (pos->player_y + coeff_y) / SQ_SIZE;
	margin->ipy_sub_yo = (pos->player_y - coeff_y) / SQ_SIZE;
}
