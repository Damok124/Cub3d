/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deep_of_view_explorer_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_deep_of_view_explorer(t_vars *vars, int dov, t_rays *rays)
{
	ft_ray_impact_wall(vars, dov, rays);
}
