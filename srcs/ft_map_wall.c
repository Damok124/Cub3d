/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_map_wall(t_vars *vars)
{
	int		player_x;
	int		player_y;
	char	**map;

	map = vars->context->map;
	player_y = (int)vars->position->player_y;
	player_x = (int)vars->position->player_x;
	if (ft_strchr("1", map[(player_y + 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1", map[(player_y - 22) / 64][(player_x - 22) / 64])
		|| ft_strchr("1", map[(player_y - 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1", map[(player_y + 22) / 64][(player_x - 22) / 64]))
		return (1);
	return (0);
}
