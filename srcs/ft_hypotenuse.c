/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypotenuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:11:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_hypotenuse(int a, int b)
{
	double	c;
	double	asquare;
	double	bsquare;
	double	csquare;

	a = ft_abs(a);
	b = ft_abs(b);
	asquare = a * a;
	bsquare = b * b;
	csquare = asquare + bsquare;
	c = sqrt(csquare);
	return (c);
}
