/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init_rows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:16:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_spot	*ft_fdf_init_rows(char **buffer, t_vars *vars, int y)
{
	t_spot	*row;
	int		x;

	x = 0;
	row = (t_spot *)malloc(sizeof(t_spot) * vars->len);
	while (x < vars->len)
	{
		row[x] = ft_fdf_setup_dot(buffer, x, y, vars);
		x++;
	}
	return (row);
}
