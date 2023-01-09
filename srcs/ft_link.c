/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:53:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_link(t_vars *vars, t_spot a, t_spot b)
{
	int	octant;

	octant = 0;
	octant = ft_get_octant(a.x, b.x, a.y, b.y);
	if (octant == 8)
		ft_trace_oct8(vars, a, b);
	else if (octant == 7)
		ft_trace_oct7(vars, a, b);
	else if (octant == 6)
		ft_trace_oct6(vars, a, b);
	else if (octant == 5)
		ft_trace_oct5(vars, a, b);
	else if (octant == 4)
		ft_trace_oct8(vars, b, a);
	else if (octant == 3)
		ft_trace_oct7(vars, b, a);
	else if (octant == 2)
		ft_trace_oct6(vars, b, a);
	else if (octant == 1)
		ft_trace_oct5(vars, b, a);
	return (1);
}
