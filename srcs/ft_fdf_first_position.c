/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_first_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:58:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 15:31:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_first_position(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	j = 0;
	space = vars->spacing;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			matrix[j][i].x = i * space - (((vars->len -1) * space)) / 2;
			matrix[j][i].y = j * space - (((vars->rows - 1) * space)) / 2;
			i++;
		}
		i = 0;
		j++;
	}
}
