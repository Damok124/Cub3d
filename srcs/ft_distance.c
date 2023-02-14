/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:11 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_distance(double ax, double ay, double bx, double by)
{
	double	ret;

	ret = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (ret);
}
