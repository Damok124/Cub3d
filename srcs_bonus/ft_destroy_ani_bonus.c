/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_ani_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_destroy_ani(t_vars *vars)
{
	t_context	*context;
	int			i;

	context = vars->context;
	i = 0;
	while (context->animated[i])
	{
		ft_destroy_img_safely(context->animated[i]->tex_img, vars);
		i++;
	}
}
