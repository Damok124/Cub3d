/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	*ft_get_player_position(t_vars *vars, char orientation)
{
	t_player	*position;
	int			x;
	int			y;

	y = -1;
	position = (t_player *)malloc(sizeof(t_player));
	if (!position)
		return (NULL);
	while (vars->context->map[++y])
	{
		x = -1;
		while (vars->context->map[y][++x])
		{
			if (ft_if_player_here(vars, y, x))
			{
				position->view_angle = ft_get_first_angle(orientation);
				position->pdx = cos(position->view_angle) * 5;
				position->pdy = sin(position->view_angle) * 5;
				position->player_x = x * SQ_SIZE + (SQ_SIZE / 2);
				position->player_y = y * SQ_SIZE + (SQ_SIZE / 2);
			}
		}
	}
	return (position);
}
