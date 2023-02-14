/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:50 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_format_textures(char *path, t_lines *content, int *err_no, int i)
{
	while (content && !(*err_no))
	{
		i = -1;
		if (ft_strchr("NSWE", content->type))
		{
			path = ft_strtrim(content->line + 3, " ");
			ft_check_one_texture(path, err_no);
			ft_true_free((void **)&path);
		}
		content = content->next;
	}
	if (*err_no)
		return (0);
	return (1);
}
