/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_initvars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:51:46 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vars	*ft_fdf_initvars(char *filename)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!vars->win)
	{
		free(vars->mlx);
		return (NULL);
	}
	ft_fdf_initcol(vars);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	vars->rows = ft_fdf_rowcount(filename);
	if (vars->rows < 2 || !ft_fdf_lencheck(vars, filename) || vars->len < 2)
	{
		ft_end_mlx(&vars);
		return (NULL);
	}
	vars->spacing = ft_fdf_spacing(vars);
	return (vars);
}
