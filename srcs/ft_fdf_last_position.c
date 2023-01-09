/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_last_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:58:58 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_last_position(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			matrix[j][i].x += (WINDOW_WIDTH / 2);
			matrix[j][i].y += (WINDOW_HEIGHT / 2);
			i++;
		}
		i = 0;
		j++;
	}
}
