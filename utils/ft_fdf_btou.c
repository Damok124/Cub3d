/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_btou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:31:05 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:50:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_fdf_btou(const char *nptr, char *base)
{
	unsigned int	ret;
	int				i;
	int				len;

	len = ft_strlen(base);
	i = 0;
	ret = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '+')
			nptr++;
		while (*nptr && (*nptr != ' ' && *nptr != '\n'))
		{
			ret *= len;
			while (base[i] != *nptr)
				i++;
			ret += i;
			i = 0;
			nptr++;
		}
	}
	return (ret);
}
