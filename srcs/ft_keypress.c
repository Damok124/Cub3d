/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:57:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/20 20:38:46 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_keypress(int key, t_vars *vars)
{
	if (key == XK_Escape)
		mlx_loop_end(vars->mlx);
	else if(key == 101 && vars->key.e == 0)
		vars->key.e = 1;
	else if(key == 101 && vars->key.e == 1)
		vars->key.e = 0;
	// else if ((key >= 48 && key <= 57) || (key >= 97 && key <= 102) || \
	// 	(key >= 65429 && key <= 65438))
	// 	ft_manual_color(vars, key);
	return (1);
}
