/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:19:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:48:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_frame(t_vars	*vars)
{
	if (vars->addr)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}
