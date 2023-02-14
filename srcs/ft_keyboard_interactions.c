/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_interactions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_keyboard_interactions(t_vars *vars)
{
	if (vars->keys->left_arr == 1 || vars->keys->right_arr == 1)
		ft_rotation(vars);
	if (vars->keys->w == 1 || vars->keys->s == 1)
		ft_foreward_backward(vars);
	if (vars->keys->a == 1 || vars->keys->d == 1)
		ft_left_right(vars);
}
