/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_from_xpm_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

unsigned int	ft_get_color_from_xpm(t_textures *wall, double step, \
	double rank, int read_from)
{
	if (read_from == RIGHT)
		return (*(unsigned int *)ft_right_color_from_xpm(wall, step, rank));
	else
		return (*(unsigned int *)ft_left_color_from_xpm(wall, step, rank));
}
