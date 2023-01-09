/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_spacing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:49:39 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_spacing(t_vars *vars)
{
	int	final;
	int	height;
	int	width;
	int	wspace;
	int	hspace;

	height = WINDOW_HEIGHT * 90 / 100;
	width = WINDOW_WIDTH * 80 / 100;
	hspace = (height / (vars->rows - 1));
	wspace = (width / (vars->len - 1)) / 1.4;
	final = (ft_min(hspace, wspace));
	if (final < 2)
		final = 2;
	return (final);
}
