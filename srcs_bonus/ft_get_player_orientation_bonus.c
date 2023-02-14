/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_orientation_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	ft_get_player_orientation(t_lines *content)
{
	int	i;

	i = -1;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				return (content->line[i]);
		i = -1;
		content = content->next;
	}
	return ('N');
}
