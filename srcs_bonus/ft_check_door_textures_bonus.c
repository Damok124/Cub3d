/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door_textures_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:38 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_door_textures(t_lines *content, int *err_no)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (content && content->type != 'D')
		content = content->next;
	if (content && content->type == 'D' && !(*err_no))
	{
		path = ft_strtrim(content->line + 2, " ");
		if (!ft_check_extension(path, ".xpm"))
			*err_no = ERR_BAD_TEXTURE_FILE;
		ft_true_free((void **)&path);
	}
	if (*err_no)
		return (0);
	return (1);
}
