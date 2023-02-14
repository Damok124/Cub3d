/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_angle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_get_first_angle(char orientation)
{
	double	axis;

	axis = 0;
	if (orientation == 'E')
		axis = 0;
	else if (orientation == 'N')
		axis = 3 * PI / 2;
	else if (orientation == 'W')
		axis = PI;
	else if (orientation == 'S')
		axis = PI / 2;
	return (axis);
}
