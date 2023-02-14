/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_potential_map_line_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_potential_map_line(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(" 01NSWEADO", str[i]))
		i++;
	if (i && i == len)
		return (1);
	return (0);
}
