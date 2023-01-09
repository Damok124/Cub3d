/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_octant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:20:49 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 15:46:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_octant2(int x1, int x2, int y1, int y2)
{
	int	dx;
	int	dy;
	int	octant;

	dx = x2 - x1;
	dy = y2 - y1;
	octant = 0;
	if (dx <= 0 && dy <= 0)
	{
		if (-dx >= -dy)
			octant = 4;
		else
			octant = 3;
	}
	else if (dx >= 0 && dy <= 0)
	{
		if (dx >= -dy)
			octant = 1;
		else
			octant = 2;
	}
	return (octant);
}

int	ft_get_octant(int x1, int x2, int y1, int y2)
{
	int	dx;
	int	dy;
	int	octant;

	dx = x2 - x1;
	dy = y2 - y1;
	octant = 0;
	if (dx >= 0 && dy >= 0)
	{
		if (dx >= dy)
			octant = 8;
		else
			octant = 7;
	}
	else if (dx <= 0 && dy >= 0)
	{
		if (-dx >= dy)
			octant = 5;
		else
			octant = 6;
	}
	else
		octant = ft_get_octant2(x1, x2, y1, y2);
	return (octant);
}
