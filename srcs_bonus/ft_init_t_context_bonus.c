/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_context_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_context	*ft_init_t_context(t_lines *content, int *err, t_checker *checker)
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
	if (checker->door)
		context->door = ft_init_t_textures();
	if (checker->ani)
	{
		context->animated = ft_init_ani_textures(content);
		context->nb_anim = ft_get_animation_len(content);
	}
	context->map = NULL;
	if (!context->north || !context->south || !context->west || !context->east)
		*err = ERR_TEXTURE_INIT_FAILED;
	return (context);
}
