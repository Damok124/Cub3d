/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rgb_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_rgb	ft_get_rgb(t_lines *content, char type)
{
	char	*tmp;
	char	**groups;
	t_rgb	colors;

	colors.red = 0;
	colors.green = 0;
	colors.blue = 0;
	tmp = NULL;
	groups = NULL;
	while (content && content->type != type)
		content = content->next;
	if (content && content->type == type)
	{
		tmp = ft_strtrim(content->line + 1, " ");
		groups = ft_split(tmp, ',');
		ft_true_free((void **)&tmp);
		colors.red = ft_atoi(groups[0]);
		colors.green = ft_atoi(groups[1]);
		colors.blue = ft_atoi(groups[2]);
		ft_full_free((void **)groups);
	}
	return (colors);
}
