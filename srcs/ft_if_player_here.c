/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_player_here.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:38 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_if_player_here(t_vars *vars, int y, int x)
{
	if (ft_strchr("NSWE", vars->context->map[y][x]))
		return (1);
	return (0);
}
