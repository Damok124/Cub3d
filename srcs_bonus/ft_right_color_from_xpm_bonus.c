/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_color_from_xpm_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:30:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
