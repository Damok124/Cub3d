/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_flawless.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:52 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_if_flawless(char **map, int *err_no)
{
	int	i;
	int	j;
	int	size;
	int	len;

	i = 0;
	size = ft_strslen(map);
	len = ft_strlen(map[0]);
	while (++i < (size - 1))
	{
		j = 0;
		while (++j < (len - 1))
		{
			if (ft_strchr("NSWE0", map[i][j]))
			{
				if (map[i - 1][j] == '.' || map[i + 1][j] == '.' \
					|| map[i][j - 1] == '.' || map[i][j + 1] == '.')
				{
					*err_no = ERR_MAP_NOT_CLOSED;
					return (0);
				}
			}
		}
	}
	return (1);
}
