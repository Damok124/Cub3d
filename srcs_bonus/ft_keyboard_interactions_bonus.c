/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_interactions_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:58 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_keyboard_interactions(t_vars *vars)
{
	static int	i;

	if (vars->keys->left_arr == 1 || vars->keys->right_arr == 1)
		ft_rotation(vars);
	if (vars->keys->w == 1 || vars->keys->s == 1)
		ft_foreward_backward(vars);
	if (vars->keys->a == 1 || vars->keys->d == 1)
		ft_left_right(vars);
	if (vars->keys->e == 1)
	{
		i++;
		if (i != 1)
			return ;
		ft_map_door(vars);
	}
	else
		i = 0;
}
