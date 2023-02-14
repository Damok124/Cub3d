/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ani_textures_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:33 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_ani_textures(t_lines *content, int *err_no, char *line)
{
	char	**paths;
	int		i;

	i = -1;
	paths = NULL;
	while (content && content->type != 'A')
		content = content->next;
	if (content && content->type == 'A' && !(*err_no))
	{
		line = ft_strtrim(content->line + 3, " ");
		paths = ft_split(line, ';');
		ft_true_free((void **)&line);
		if (!paths || !paths[0])
			*err_no = ERR_BAD_TEXTURE_FILE;
		else
		{
			while (paths[++i])
				if (!ft_check_extension(paths[i], ".xpm"))
					*err_no = ERR_BAD_TEXTURE_FILE;
		}
		ft_full_free((void **)paths);
	}
	if (*err_no)
		return (0);
	return (1);
}
