/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_rotation_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:37:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_rotation_z(t_vars *vars, t_spot **matrix, double angle)
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
			matrix[j][i].x = cos(angle) * x + -sin(angle) * y + 0 * z;
			matrix[j][i].y = sin(angle) * x + cos(angle) * y + 0 * z;
			matrix[j][i].z = 0 * x + 0 * y + 1 * z;
			i++;
		}
		i = 0;
		j++;
	}
}
