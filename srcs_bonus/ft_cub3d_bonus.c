/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_cub3d(t_vars *vars)
{
	t_mlx_datas	*md;

	md = vars->mlx_datas;
	if (md->img)
		mlx_destroy_image(md->mlx, md->img);
	md->img = mlx_new_image(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	md->addr = mlx_get_data_addr(md->img, &md->bits_per_pixel, \
		&md->line_length, &md->endian);
	ft_draw_ceilling(vars->context, vars);
	ft_draw_floor(vars->context, vars);
	ft_keyboard_interactions(vars);
	ft_animate_frames(&vars->context->frames);
	ft_draw_environment(vars, vars->rays);
	ft_draw_minimap(vars);
	mlx_put_image_to_window(md->mlx, md->win, md->img, 0, 0);
	return (1);
}
