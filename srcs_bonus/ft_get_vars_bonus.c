/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_vars	*ft_get_vars(t_context *context, int *err_no, t_checker *checker)
{
	t_vars		*vars;
	t_mlx_datas	*md;

	vars = ft_init_vars(context);
	md = vars->mlx_datas;
	if (vars)
	{
		md->mlx = mlx_init();
		md->win = mlx_new_window(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
		md->img = mlx_new_image(md->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		md->addr = mlx_get_data_addr(md->img, &md->bits_per_pixel, \
			&md->line_length, &md->endian);
		ft_get_full_textures(vars->context, vars->mlx_datas, err_no, checker);
		ft_set_minimap(vars);
	}
	return (vars);
}
