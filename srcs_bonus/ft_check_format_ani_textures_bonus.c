/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_ani_textures_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:40 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_format_ani_textures(char *path, t_lines *content, int *err, int i)
{
	char	**paths;

	paths = NULL;
	while (content && !(*err))
	{
		i = -1;
		if (content->type == 'A' )
		{
			path = ft_strtrim(content->line + 3, " ");
			paths = ft_split(path, ';');
			ft_true_free((void **)&path);
			while (paths[++i])
				ft_check_one_texture(paths[i], err);
			ft_full_free((void **)paths);
		}
		content = content->next;
	}
	if (*err)
		return (0);
	return (1);
}
