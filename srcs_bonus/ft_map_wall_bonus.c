/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_map_wall(t_vars *vars)
{
	int		player_x;
	int		player_y;
	char	**map;

	map = vars->context->map;
	player_y = (int)vars->position->player_y;
	player_x = (int)vars->position->player_x;
	if (ft_strchr("1AD", map[(player_y + 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1AD", map[(player_y - 22) / 64][(player_x - 22) / 64])
		|| ft_strchr("1AD", map[(player_y - 22) / 64][(player_x + 22) / 64])
		|| ft_strchr("1AD", map[(player_y + 22) / 64][(player_x - 22) / 64]))
		return (1);
	return (0);
}
