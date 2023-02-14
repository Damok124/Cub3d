/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicates_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:39 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_check_duplicates(char *path, int *err_no, char c)
{
	int	i;

	i = 1;
	while (path && path[0] && path[i])
	{
		if (path[0] == c || (path[i] == c && path[i - 1] == c))
		{
			if (c == ',')
				*err_no = ERR_FLOOR_CEILLING_FORMAT;
			if (c == ';')
				*err_no = ERR_WRONG_FORMAT_ANI;
		}
		i++;
	}
}
