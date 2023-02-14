/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_pixel_put_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_minimap_pixel_put(t_minimap *minimap, int x, int y, int color)
{
	char	*dst;

	dst = minimap->addr + (y * (minimap->line_length) \
		+ x * (minimap->bits_per_pixel / 8));
	if (x >= 0 && y >= 0 && x < minimap->width && y < minimap->height)
		*(unsigned int *)dst = color;
}
