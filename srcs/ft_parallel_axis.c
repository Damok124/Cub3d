/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parallel_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:58 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_parallel_axis(t_vars *vars, int dov, t_rays *rays)
{
	rays->impact_x = vars->position->player_x;
	rays->impact_y = vars->position->player_y;
	rays->dov = dov;
}
