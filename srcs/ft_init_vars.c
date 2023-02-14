/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:45 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		vars->keys = ft_init_keys();
		vars->position = ft_get_player_position(vars, context->orientation);
	}
	return (vars);
}
