/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:19:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_dot(t_vars *vars, t_spot dot)
{
	unsigned int	color;
	char			*dst;

	color = (dot.red << 16) + (dot.green << 8) + (dot.blue);
	dst = vars->addr + ((int)dot.y * vars->line_length + (int)dot.x * \
		(vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
