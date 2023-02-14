/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_one_position_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:10 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_only_one_position(t_lines *content, int *err_no)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				check++;
		i = -1;
		content = content->next;
	}
	if (check != 1)
	{
		if (check == 0)
			*err_no = ERR_MISSING_START_POSITION;
		else
			*err_no = ERR_TOO_MUCH_START_POSITION;
		return (0);
	}
	return (1);
}
