/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_print_type(double step, unsigned int *col,
	t_vars *vars, t_rays *rays)
{
	t_context	*context;
	int			frame;

	context = vars->context;
	if (rays->wall_type == DOOR)
		*col = ft_get_wall_color(context->door, step, rays);
	else if (rays->wall_type == ANIMATION)
	{
		frame = context->frames % vars->context->nb_anim;
		*col = ft_get_wall_color(context->animated[frame], step, rays);
	}
	else if (rays->wall_direction == NORTH)
		*col = ft_get_wall_color(context->south, step, rays);
	else if (rays->wall_direction == SOUTH)
		*col = ft_get_wall_color(context->north, step, rays);
	else if (rays->wall_direction == WEST)
		*col = ft_get_wall_color(context->east, step, rays);
	else if (rays->wall_direction == EAST)
		*col = ft_get_wall_color(context->west, step, rays);
}
