/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_vars_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:43 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_unset_vars(t_vars *vars, t_checker *checker)
{
	t_context	*context;

	context = vars->context;
	ft_destroy_img_safely(context->north->tex_img, vars);
	ft_destroy_img_safely(context->south->tex_img, vars);
	ft_destroy_img_safely(context->east->tex_img, vars);
	ft_destroy_img_safely(context->west->tex_img, vars);
	if (checker->ani)
		ft_destroy_ani(vars);
	if (checker->door)
		ft_destroy_img_safely(context->door->tex_img, vars);
	ft_destroy_img_safely(vars->minimap->img, vars);
	ft_destroy_img_safely(vars->mlx_datas->img, vars);
	mlx_destroy_window(vars->mlx_datas->mlx, vars->mlx_datas->win);
	mlx_destroy_display(vars->mlx_datas->mlx);
	ft_unset_context(context, checker);
	ft_true_free((void **)&vars->minimap);
	ft_true_free((void **)&vars->mlx_datas->mlx);
	ft_true_free((void **)&vars->keys);
	ft_true_free((void **)&vars->mlx_datas);
	ft_true_free((void **)&vars->position);
	ft_true_free((void **)&vars->rays);
	ft_true_free((void **)&vars);
}
