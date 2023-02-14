/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textures_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:29 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		content = content->next;
	}
}
