/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_activation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_hooks_activation(t_vars *vars)
{
	t_mlx_datas	*md;

	md = vars->mlx_datas;
	mlx_hook(md->win, ON_DESTROY, DestroyAll, ft_click_cross, md->mlx);
	mlx_hook(md->win, 2, 1L << 0, ft_hold_key, vars);
	mlx_hook(md->win, 3, 1L << 1, ft_release_key, vars);
	mlx_hook(md->win, 6, 1L << 6, ft_mouse_interactions, vars);
}
