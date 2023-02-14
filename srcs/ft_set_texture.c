/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_texture(t_textures *data, t_mlx_datas *md)
{
	data->tex_img = mlx_xpm_file_to_image(md->mlx, \
		data->path, data->tex_width, data->tex_height);
	if (data->tex_img)
		data->tex_addr = mlx_get_data_addr(data->tex_img, &data->bppixels, \
			data->tex_width, &data->endian);
	else
		data->tex_addr = NULL;
}
