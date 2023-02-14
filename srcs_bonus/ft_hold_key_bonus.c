/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:40 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	if (keycode == 'e')
		vars->keys->e = 1;
	return (keycode);
}
