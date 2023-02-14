/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_are_digits_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_strs_are_digits(char **strs)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (strs && strs[++i])
	{
		while (strs[i][++j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (0);
		}
		j = -1;
	}
	return (1);
}
