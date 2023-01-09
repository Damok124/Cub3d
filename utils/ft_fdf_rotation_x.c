/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_rotation_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:37:35 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_rotation_x(t_vars *vars, t_spot **matrix, double angle)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			x = matrix[j][i].x;
			y = matrix[j][i].y;
			z = matrix[j][i].z;
			matrix[j][i].x = 1 * x + 0 * y + 0 * z;
			matrix[j][i].y = 0 * x + cos(angle) * y + -sin(angle) * z;
			matrix[j][i].z = 0 * x + sin(angle) * y + cos(angle) * z;
			i++;
		}
		i = 0;
		j++;
	}
}
