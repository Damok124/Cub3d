/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_animated_textures_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:22 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	**ft_get_animated_textures(t_lines *content)
{
	char	**paths;
	char	*path;

	paths = NULL;
	while (content && content->type != 'A')
		content = content->next;
	if (content && content->type == 'A')
	{
		path = ft_strtrim(content->line + 3, " ");
		paths = ft_split(path, ';');
		ft_true_free((void **)&path);
	}
	return (paths);
}
