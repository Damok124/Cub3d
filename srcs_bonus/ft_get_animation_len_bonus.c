/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_animation_len_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_get_animation_len(t_lines *content)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (content && content->type != 'A')
		content = content->next;
	if (content && content->type == 'A')
	{
		while (content->line && (content->line[i] + 3) == ' ')
			i++;
		ret = ft_count_strs(content->line + i + 3, ';');
	}
	return (ret);
}
