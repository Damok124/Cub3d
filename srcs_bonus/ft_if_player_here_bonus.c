/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_player_here_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:44 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_if_player_here(t_vars *vars, int y, int x)
{
	if (ft_strchr("NSWE", vars->context->map[y][x]))
		return (1);
	return (0);
}
