/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_ani_context.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:08 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_destroy_ani_context(t_textures **animated)
{
	int	i;

	i = 0;
	while (animated && animated[i])
	{
		ft_true_free((void **)&(animated[i]->tex_width));
		ft_true_free((void **)&(animated[i]->path));
		ft_true_free((void **)&(animated[i]->tex_height));
		ft_true_free((void **)&(animated[i]));
		i++;
	}
}
