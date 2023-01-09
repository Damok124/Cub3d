/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_getlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:02:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_getlen(char *str)
{
	char	*tmp;
	int		i;
	int		total;

	i = 0;
	total = 0;
	tmp = ft_strtrim(str, "\n");
	str = ft_strtrim(tmp, " ");
	ft_true_free(&tmp);
	while (str && str[i])
	{
		if (str && str[i] == ' ')
			total++;
		while (str && str[i] == ' ')
			i++;
		i++;
	}
	if (total)
		total++;
	ft_true_free(&str);
	return (total);
}
