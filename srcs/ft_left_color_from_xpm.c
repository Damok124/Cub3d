/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_color_from_xpm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:50 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_left_color_from_xpm(t_textures *wall, double step, \
	double rank)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	coeff = (double)(*wall->tex_width / sizeof(int)) / (double)SQ_SIZE;
	x = (int)(rank * coeff) % (*wall->tex_width / sizeof(int));
	y = *(wall->tex_height) * step;
	color = wall->tex_addr + (y * *(wall->tex_width) \
		+ x * (wall->bppixels / 8));
	return (color);
}
