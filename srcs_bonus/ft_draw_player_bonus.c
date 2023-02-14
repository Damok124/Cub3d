/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_player(t_vars *vars)
{
	int				size;
	unsigned int	color;

	size = SQ_SIZE / SCALING / 4;
	color = PLAYER_COLOR;
	if (!size)
		size = 1;
	ft_put_pixel_around(vars, size, color);
}
