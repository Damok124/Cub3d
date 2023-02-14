/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:51 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_minimap	*ft_init_minimap(void)
{
	t_minimap	*mini;

	mini = (t_minimap *)malloc(sizeof(t_minimap));
	if (!mini)
		return (NULL);
	mini->img = NULL;
	mini->addr = NULL;
	mini->bits_per_pixel = 0;
	mini->endian = 0;
	mini->height = 0;
	mini->line_length = 0;
	mini->width = 0;
	return (mini);
}
