/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:01:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_grid(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			if (i != (vars->len -1) && j != (vars->rows - 1))
			{
				ft_link(vars, matrix[j][i], matrix[j][i + 1]);
				ft_link(vars, matrix[j][i], matrix[j + 1][i]);
			}
			else if (i == (vars->len - 1) && j != (vars->rows - 1))
				ft_link(vars, matrix[j][i], matrix[j + 1][i]);
			else if (i != (vars->len - 1) && j == (vars->rows - 1))
				ft_link(vars, matrix[j][i], matrix[j][i + 1]);
			if (ft_pix_is_visible(matrix[j][i].x, matrix[j][i].y))
				ft_print_dot(vars, matrix[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
}
