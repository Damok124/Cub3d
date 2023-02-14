/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm_wall_type_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_confirm_wall_type(t_rays *r, char **map, int x, int y)
{
	if (map[y / SQ_SIZE][x / SQ_SIZE] == 'D')
		r->wall_type = DOOR;
	else if (map[y / SQ_SIZE][x / SQ_SIZE] == 'A')
		r->wall_type = ANIMATION;
	else
		r->wall_type = WALL;
}
