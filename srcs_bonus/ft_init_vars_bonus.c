/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_vars	*ft_init_vars(t_context *context)
{
	t_vars		*vars;

	vars = NULL;
	if (context)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (!vars)
			return (NULL);
		vars->mlx_datas = (t_mlx_datas *)malloc(sizeof(t_mlx_datas));
		if (!vars->mlx_datas)
			return (NULL);
		vars->rays = (t_rays *)malloc(sizeof(t_rays));
		if (!vars->rays)
			return (NULL);
		vars->context = context;
		vars->context->frames = 0;
		vars->keys = ft_init_keys();
		vars->minimap = ft_init_minimap();
		vars->position = ft_get_player_position(vars, context->orientation);
	}
	return (vars);
}
