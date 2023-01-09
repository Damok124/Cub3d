/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:57:41 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:52:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_keypress(int key, t_vars *vars)
{
	if (key == XK_Escape)
		mlx_loop_end(vars->mlx);
	else if (key == 120)
		ft_renew_image(vars);
	else if ((key >= 48 && key <= 57) || (key >= 97 && key <= 102) || \
		(key >= 65429 && key <= 65438))
		ft_manual_color(vars, key);
	return (1);
}
