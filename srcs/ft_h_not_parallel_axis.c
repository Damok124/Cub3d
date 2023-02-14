/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_not_parallel_axis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_h_not_parallel_axis(t_vars *vars, int coeff, t_rays *rays)
{
	double	corr;

	if (coeff > 0)
		corr = SQ_SIZE;
	else
		corr = -0.0001;
	rays->impact_y = (((int)vars->position->player_y >> 6) << 6) + corr;
	rays->impact_x = (vars->position->player_y - rays->impact_y) \
		* rays->a_tan + vars->position->player_x;
	rays->yo = SQ_SIZE * coeff;
	rays->xo = -rays->yo * rays->a_tan;
}
