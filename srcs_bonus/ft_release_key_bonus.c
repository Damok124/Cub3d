/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release_key_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:26 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_release_key(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		vars->keys->w = 0;
	if (keycode == XK_Left)
		vars->keys->left_arr = 0;
	if (keycode == XK_Right)
		vars->keys->right_arr = 0;
	if (keycode == 'a')
		vars->keys->a = 0;
	if (keycode == 's')
		vars->keys->s = 0;
	if (keycode == 'd')
		vars->keys->d = 0;
	if (keycode == 'e')
		vars->keys->e = 0;
	return (keycode);
}
