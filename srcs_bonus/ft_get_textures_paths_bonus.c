/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textures_paths_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_get_textures_paths(t_context *context, t_lines *content)
{
	while (content)
	{
		if (content->type == 'N')
			context->north->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'S')
			context->south->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'W')
			context->west->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'E')
			context->east->path = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'D')
			context->door->path = ft_strtrim(content->line + 2, " ");
		content = content->next;
	}
}
