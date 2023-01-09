/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_get_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:35:00 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_get_col(t_vars *vars, t_spot a, t_spot b, double ratio)
{
	vars->red = (b.red - a.red) * (ratio) + a.red;
	vars->red = ft_cap_color(vars->red);
	vars->green = (b.green - a.green) * (ratio) + a.green;
	vars->green = ft_cap_color(vars->green);
	vars->blue = (b.blue - a.blue) * (ratio) + a.blue;
	vars->blue = ft_cap_color(vars->blue);
}
