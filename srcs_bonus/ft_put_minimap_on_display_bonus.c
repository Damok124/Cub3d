/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_minimap_on_display_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_put_minimap_on_display(t_vars *vars, t_player *pos, t_minimap *mini)
{
	t_minitools	t;
	char		*col;

	t.i = 0;
	ft_init_minitools(&t, pos);
	while (t.start_x + t.i < t.target_x)
	{
		t.j = 0;
		while (t.start_y + t.j < t.target_y)
		{
			if ((t.start_x + t.i) >= 0 && t.start_y + t.j >= 0 && t.start_x \
				+ t.i <= mini->width && t.start_y + t.j <= mini->height)
			{
				col = mini->addr + ((t.start_y + t.j) * (mini->line_length)) \
					+ ((t.start_x + t.i) * (mini->bits_per_pixel / 8));
				ft_mlx_pixel_put(vars, t.i + (SQ_SIZE / SCALING), \
					t.j + (SQ_SIZE / SCALING), *(unsigned int *)col);
			}
			else
				ft_mlx_pixel_put(vars, t.i + (SQ_SIZE / SCALING), \
					t.j + (SQ_SIZE / SCALING), EXT_COLOR);
			t.j++;
		}
		t.i++;
	}
}
