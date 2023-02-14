/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_around_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:22 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_put_pixel_around(t_vars *vars, int size, unsigned int color)
{
	int	init_x;
	int	init_y;
	int	i;
	int	j;

	init_x = vars->position->player_x / SCALING - (size / 2);
	init_y = vars->position->player_y / SCALING - (size / 2);
	j = -1;
	i = -1;
	while (++j < size)
	{
		while (++i < size)
			ft_minimap_pixel_put(vars->minimap, init_x + i, init_y + j, color);
		i = -1;
	}
}
