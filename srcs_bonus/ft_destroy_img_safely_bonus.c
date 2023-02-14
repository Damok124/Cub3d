/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_img_safely_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:06 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_destroy_img_safely(t_textures *texture, t_vars *vars)
{
	if (texture)
		mlx_destroy_image(vars->mlx_datas->mlx, texture);
}
