/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_hold_key(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		vars->keys->w = 1;
	if (keycode == XK_Left)
		vars->keys->left_arr = 1;
	if (keycode == XK_Right)
		vars->keys->right_arr = 1;
	if (keycode == 'a')
		vars->keys->a = 1;
	if (keycode == 's')
		vars->keys->s = 1;
	if (keycode == 'd')
		vars->keys->d = 1;
	if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx_datas->mlx);
	return (keycode);
}
