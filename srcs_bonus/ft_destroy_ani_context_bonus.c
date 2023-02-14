/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_ani_context_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
