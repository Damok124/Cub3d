/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_nswe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	ft_check_valid_nswe(char *str)
{
	int		i;
	char	type;

	type = '0';
	i = 2;
	if ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'S' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'W' && str[1] == 'E' && str[2] == ' ') || \
		(str[0] == 'E' && str[1] == 'A' && str[2] == ' '))
		type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 2 || !str[i])
		return ('0');
	return (type);
}
