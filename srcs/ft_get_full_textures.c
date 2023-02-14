/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_full_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_full_textures(t_context *context, t_mlx_datas *md, \
	int *err_no)
{
	ft_set_texture(context->north, md);
	ft_set_texture(context->south, md);
	ft_set_texture(context->west, md);
	ft_set_texture(context->east, md);
	if (!context->north->tex_img || !context->north->tex_addr \
		|| !context->south->tex_img || !context->south->tex_addr \
		|| !context->west->tex_img || !context->west->tex_addr \
		|| !context->east->tex_img || !context->east->tex_addr)
		*err_no = ERR_BAD_TEXTURE_FILE;
}
