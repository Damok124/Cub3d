/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_context.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:43 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_context	*ft_init_t_context(int *err)
{
	t_context	*context;

	context = (t_context *)malloc(sizeof(t_context));
	if (!context)
	{
		*err = ERR_MALLOC_CONTEXT;
		return (NULL);
	}
	context->north = ft_init_t_textures();
	context->south = ft_init_t_textures();
	context->west = ft_init_t_textures();
	context->east = ft_init_t_textures();
	context->map = NULL;
	if (!context->north || !context->south || !context->west || !context->east)
		*err = ERR_TEXTURE_INIT_FAILED;
	return (context);
}
