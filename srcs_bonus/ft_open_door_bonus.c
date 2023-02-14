/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:11 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_open_door(t_vars *vars, int x, int y, double ang)
{
	char	**map;

	map = vars->context->map;
	if (map[y - 1][x] == 'D' && ang > (M_PI * 5) / 4 && ang < (7 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x, y - 1, DOOR));
	else if (map[y + 1][x] == 'D' && ang > M_PI / 4 && ang < (3 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x, y + 1, DOOR));
	else if (map[y][x + 1] == 'D' && (ang > (7 * M_PI) / 4 || ang < M_PI / 4))
		return (ft_putchar_on_map(vars, x + 1, y, DOOR));
	else if (map[y][x - 1] == 'D' && ang > (3 * M_PI) / 4
		&& ang < (5 * M_PI) / 4)
		return (ft_putchar_on_map(vars, x - 1, y, DOOR));
	return (0);
}
