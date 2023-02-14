/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_animated_texture_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:35 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_animated_texture(t_textures **animated)
{
	int	i;

	i = 0;
	while (animated && animated[i])
	{
		if (!animated[i]->tex_img)
			return (0);
		i++;
	}
	return (1);
}
