/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_initcol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:47:48 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:50:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_initcol(t_vars *vars)
{
	unsigned int	color;

	vars->hexcolor = (char *)malloc(sizeof(char) * 7);
	vars->hexcolor = ft_memset(vars->hexcolor, 'F', 6);
	vars->hexcolor[6] = '\0';
	color = ft_fdf_btou(vars->hexcolor, "0123456789ABCDEF");
	vars->red = color >> 16;
	vars->green = (color >> 8) & 0xFF;
	vars->blue = color & 0xFF;
}
