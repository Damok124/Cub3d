/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_close_door(t_vars *vars, int x, int y, double ang)
{
	char	**map;

	map = vars->context->map;
	if (map[y - 1][x] == 'O' && ang > (M_PI * 5) / 4 && ang < (7 * M_PI) / 4
		&& ((int)(vars->position->player_y) % SQ_SIZE) > (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x, y - 1, DOOR_CLOSED);
	else if (map[y + 1][x] == 'O' && ang > M_PI / 4 && ang < (3 * M_PI) / 4
		&& ((int)(vars->position->player_y) % SQ_SIZE) < (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x, y + 1, DOOR_CLOSED);
	else if (map[y][x + 1] == 'O' && (ang > (7 * M_PI) / 4 || ang < M_PI / 4)
		&& ((int)(vars->position->player_x) % SQ_SIZE) < (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x + 1, y, DOOR_CLOSED);
	else if (map[y][x - 1] == 'O' && ang > (3 * M_PI) / 4 \
		&& ang < (5 * M_PI) / 4 && ((int)(vars->position->player_x) \
		% SQ_SIZE) > (SQ_SIZE / 2))
		ft_putchar_on_map(vars, x - 1, y, DOOR_CLOSED);
}
