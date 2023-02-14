/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_animation_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:48 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	ft_check_valid_animation(char *str)
{
	int		i;
	char	type;

	i = 3;
	type = str[0];
	if ((str[0] == 'A' && str[1] == 'N' && str[2] == 'I' && str[3] == ' '))
		type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 3 || !str[i])
		return ('0');
	return (type);
}
