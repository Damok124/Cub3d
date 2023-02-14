/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:30:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_set_minimap(t_vars *vars)
{
	vars->minimap->width = vars->context->map_length * SQ_SIZE;
	vars->minimap->height = vars->context->map_height * SQ_SIZE;
}
