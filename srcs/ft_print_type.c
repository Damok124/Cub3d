/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_type(double step, unsigned int *col,
	t_vars *vars, t_rays *rays)
{
	t_context	*context;

	context = vars->context;
	if (rays->wall_direction == NORTH)
		*col = ft_get_wall_color(context->south, step, rays);
	else if (rays->wall_direction == SOUTH)
		*col = ft_get_wall_color(context->north, step, rays);
	else if (rays->wall_direction == WEST)
		*col = ft_get_wall_color(context->east, step, rays);
	else if (rays->wall_direction == EAST)
		*col = ft_get_wall_color(context->west, step, rays);
}
