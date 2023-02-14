/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ani_textures_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:46 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_textures	**ft_init_ani_textures(t_lines *content)
{
	t_textures	**texture;
	int			i;
	int			size;
	char		**paths;

	i = 0;
	paths = ft_get_animated_textures(content);
	size = ft_get_animation_len(content);
	texture = (t_textures **)malloc(sizeof(t_textures *) * (size + 1));
	if (!texture)
		return (NULL);
	texture[size] = NULL;
	while (i < size)
	{
		texture[i] = ft_init_t_textures();
		i++;
	}
	i = 0;
	while (i < size)
	{
		texture[i]->path = ft_strdup(paths[i]);
		i++;
	}
	ft_full_free((void **)paths);
	return (texture);
}
