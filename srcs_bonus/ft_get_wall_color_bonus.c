/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wall_color_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:38 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

unsigned int	ft_get_wall_color(t_textures *texture, double step, \
	t_rays *rays)
{
	if (rays->wall_direction == NORTH)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_x, LEFT));
	else if (rays->wall_direction == SOUTH)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_x, RIGHT));
	else if (rays->wall_direction == WEST)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_y, RIGHT));
	else if (rays->wall_direction == EAST)
		return (ft_get_color_from_xpm(texture, step, \
			rays->short_y, LEFT));
	return (0);
}
