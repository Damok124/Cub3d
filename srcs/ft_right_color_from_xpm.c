/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_color_from_xpm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_right_color_from_xpm(t_textures *wall, double step, \
	double rank)
{
	double	coeff;
	char	*color;
	int		y;
	int		x;

	coeff = (double)(*wall->tex_width / sizeof(int)) / (double)SQ_SIZE;
	x = (*wall->tex_width / sizeof(int)) - \
		((int)(rank * coeff) % (*wall->tex_width / sizeof(int))) - 1;
	y = *(wall->tex_height) * step;
	color = wall->tex_addr + (y * *(wall->tex_width) \
		+ x * (wall->bppixels / 8));
	return (color);
}
