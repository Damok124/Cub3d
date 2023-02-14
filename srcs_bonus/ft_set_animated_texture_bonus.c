/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_animated_texture_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:30:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_set_animated_texture(t_textures **animated, t_mlx_datas *md)
{
	int	i;

	i = 0;
	while (animated && md && animated[i])
	{
		ft_set_texture(animated[i], md);
		i++;
	}
}
