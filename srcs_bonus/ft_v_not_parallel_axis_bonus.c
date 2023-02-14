/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_not_parallel_axis_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:44 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_v_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays)
{
	double	corr;

	if (coeff > 0)
		corr = SQ_SIZE;
	else
		corr = -0.0001;
	rays->impact_x = (((int)vars->position->player_x >> 6) << 6) + corr;
	rays->impact_y = (vars->position->player_x - rays->impact_x) \
		* rays->n_tan + vars->position->player_y;
	rays->xo = SQ_SIZE * coeff;
	rays->yo = -rays->xo * rays->n_tan;
}
