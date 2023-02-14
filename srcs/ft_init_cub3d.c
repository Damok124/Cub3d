/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_cub3d(t_vars *vars, t_context *context, int err_no)
{
	vars = ft_get_vars(context, &err_no);
	if (context && vars && !err_no)
	{
		ft_hooks_activation(vars);
		mlx_loop_hook(vars->mlx_datas->mlx, ft_cub3d, vars);
		mlx_loop(vars->mlx_datas->mlx);
		ft_unset_vars(vars);
	}
	else
	{
		ft_unset_vars(vars);
		ft_print_cub3d_error_1(err_no);
	}
}
