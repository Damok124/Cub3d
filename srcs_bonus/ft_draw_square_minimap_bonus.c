/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square_minimap_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:18 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_square_minimap(t_vars *vars, int y, int x, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < SQ_SIZE / SCALING)
	{
		i = 0;
		while (i < SQ_SIZE / SCALING)
		{
			ft_minimap_pixel_put(vars->minimap, i + (x * SQ_SIZE / SCALING), \
				j + (y * SQ_SIZE / SCALING), color);
			i++;
		}
		j++;
	}
}
