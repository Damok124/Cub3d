/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_setup_dot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:13:39 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_to_space(char **buffer)
{
	while (*buffer && ((**buffer >= '0' && **buffer <= '9') || \
		(**buffer >= 'A' && **buffer <= 'F')))
		*buffer += 1;
}

void	ft_fdf_to_hexa(char **buffer)
{
	if (*buffer && **buffer == ',')
		*buffer += 3;
}

void	ft_fdf_to_comma(char **buffer)
{
	if (*buffer && (**buffer == '+' || **buffer == '-'))
		*buffer += 1;
	while (*buffer && (**buffer >= '0' && **buffer <= '9'))
		*buffer += 1;
}

void	ft_fdf_to_z(char **buffer)
{
	while (*buffer)
	{
		while (*buffer && **buffer == ' ')
			*buffer += 1;
		return ;
	}
}

t_spot	ft_fdf_setup_dot(char **buffer, int x, int y, t_vars *vars)
{
	t_spot			dot;
	unsigned int	col;

	col = 0;
	ft_fdf_to_z(buffer);
	dot.x = (float)x;
	dot.y = (float)y;
	dot.z = ((float)ft_atoi(*buffer) * 2);
	ft_fdf_to_comma(buffer);
	if (**buffer == ',')
	{
		ft_fdf_to_hexa(buffer);
		col = ft_fdf_btou(*buffer, "0123456789ABCDEF");
		dot.red = (col >> 16) & 0xFF;
		dot.green = (col >> 8) & 0xFF;
		dot.blue = col & 0xFF;
		ft_fdf_to_space(buffer);
	}
	else
	{
		dot.red = vars->red;
		dot.green = vars->green;
		dot.blue = vars->blue;
	}
	return (dot);
}
