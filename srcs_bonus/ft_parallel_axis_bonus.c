/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parallel_axis_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:11 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_parallel_axis(t_vars *vars, int dov, t_rays *rays)
{
	rays->impact_x = vars->position->player_x;
	rays->impact_y = vars->position->player_y;
	rays->dov = dov;
}
