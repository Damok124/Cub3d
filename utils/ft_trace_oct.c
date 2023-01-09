/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:23:29 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_oct8(t_vars *vars, t_spot a, t_spot b)
{
	int		x;
	int		y;
	int		eps;
	double	distance;
	double	current;

	current = 0;
	distance = ft_hypotenuse((a.x - b.x), (a.y - b.y));
	x = a.x;
	y = a.y;
	eps = 0;
	while (x <= b.x)
	{
		ft_fdf_get_col(vars, a, b, current / distance);
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y);
		eps += (b.y - a.y);
		if (eps * 2 >= (b.x - a.x))
		{
			y++;
			eps -= (b.x - a.x);
		}
		x++;
		current++;
	}
}

void	ft_trace_oct7(t_vars *vars, t_spot a, t_spot b)
{
	int		x;
	int		y;
	int		eps;
	double	distance;
	double	current;

	current = 0;
	distance = ft_hypotenuse((a.x - b.x), (a.y - b.y));
	x = a.x;
	y = a.y;
	eps = 0;
	while (y <= b.y)
	{
		ft_fdf_get_col(vars, a, b, current / distance);
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y);
		eps += (b.x - a.x);
		if (eps * 2 >= (b.y - a.y))
		{
			x++;
			eps -= (b.y - a.y);
		}
		y++;
		current++;
	}
}

void	ft_trace_oct6(t_vars *vars, t_spot a, t_spot b)
{
	int		x;
	int		y;
	int		eps;
	double	distance;
	double	current;

	current = 0;
	distance = ft_hypotenuse((a.x - b.x), (a.y - b.y));
	x = a.x;
	y = a.y;
	eps = 0;
	while (y <= b.y)
	{
		ft_fdf_get_col(vars, a, b, current / distance);
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y);
		eps += (b.x - a.x);
		if (eps * 2 <= -(b.y - a.y))
		{
			x--;
			eps -= -(b.y - a.y);
		}
		y++;
		current++;
	}
}

void	ft_trace_oct5(t_vars *vars, t_spot a, t_spot b)
{
	int		x;
	int		y;
	int		eps;
	double	distance;
	double	current;

	current = 0;
	distance = ft_hypotenuse((a.x - b.x), (a.y - b.y));
	x = a.x;
	y = a.y;
	eps = 0;
	while (x >= b.x)
	{
		ft_fdf_get_col(vars, a, b, current / distance);
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y);
		eps += -(b.y - a.y);
		if (eps * 2 <= (b.x - a.x))
		{
			y++;
			eps -= (b.x - a.x);
		}
		x--;
		current++;
	}
}
