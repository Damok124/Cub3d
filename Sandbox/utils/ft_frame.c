/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:19:06 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 17:09:54 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_frame(t_vars	*vars)
{
	if (vars->addr)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}
