/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:44 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_textures	*ft_init_t_textures(void)
{
	t_textures	*texture;

	texture = (t_textures *)malloc(sizeof(t_textures));
	if (!texture)
		return (NULL);
	texture->path = NULL;
	texture->tex_img = NULL;
	texture->tex_addr = NULL;
	texture->bppixels = 0;
	texture->tex_width = (int *)malloc(sizeof(int));
	if (!texture->tex_width)
	{
		ft_true_free((void **)&texture);
		return (NULL);
	}
	texture->tex_height = (int *)malloc(sizeof(int));
	if (!texture->tex_height)
	{
		ft_multi_true_free((void **)&texture->tex_width, (void **)&texture, \
			NULL, NULL);
		return (NULL);
	}
	return (texture);
}
