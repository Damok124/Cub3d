/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_fc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	ft_check_valid_fc(char *str)
{
	int		i;
	char	type;
	char	**colors;

	type = str[0];
	i = 1;
	while (str[i] == ' ')
		i++;
	if (i == 1 || !str[i])
		return ('0');
	colors = ft_split(str + i, ',');
	if (ft_strslen(colors) == 3 && ft_strs_are_digits(colors))
	{
		ft_atoi_rgb_safe(colors[0], &i);
		ft_atoi_rgb_safe(colors[1], &i);
		ft_atoi_rgb_safe(colors[2], &i);
		if (i)
		{
			ft_full_free((void **)colors);
			return (type);
		}
	}
	ft_full_free((void **)colors);
	return ('0');
}
