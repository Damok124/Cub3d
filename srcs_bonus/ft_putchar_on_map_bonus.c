/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_on_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:23 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_putchar_on_map(t_vars *vars, int x, int y, int type)
{
	char	**map;

	map = vars->context->map;
	if (type == DOOR)
		map[y][x] = 'O';
	else
		map[y][x] = 'D';
	return (1);
}
