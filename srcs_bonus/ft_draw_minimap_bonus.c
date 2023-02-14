/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:11 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_minimap(t_vars *vars)
{
	if (vars->minimap->img)
		mlx_destroy_image(vars->mlx_datas->mlx, vars->minimap->img);
	vars->minimap->img = mlx_new_image(vars->mlx_datas->mlx, \
		vars->minimap->width, vars->minimap->height);
	vars->minimap->addr = mlx_get_data_addr(vars->minimap->img, \
		&vars->minimap->bits_per_pixel, &vars->minimap->line_length, \
		&vars->minimap->endian);
	ft_draw_miniwalls(vars);
	ft_draw_rays_minimap(vars, vars->rays);
	ft_draw_minispaces(vars);
	ft_draw_player(vars);
	ft_put_minimap_on_display(vars, vars->position, vars->minimap);
}
