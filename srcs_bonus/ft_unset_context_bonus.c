/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_context_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:42 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_unset_context(t_context *context, t_checker *checker)
{
	if (context && checker)
	{
		ft_true_free((void **)&context->north->path);
		ft_true_free((void **)&context->south->path);
		ft_true_free((void **)&context->east->path);
		ft_true_free((void **)&context->west->path);
		ft_true_free((void **)&context->north->tex_width);
		ft_true_free((void **)&context->south->tex_width);
		ft_true_free((void **)&context->east->tex_width);
		ft_true_free((void **)&context->west->tex_width);
		ft_true_free((void **)&context->north->tex_height);
		ft_true_free((void **)&context->south->tex_height);
		ft_true_free((void **)&context->east->tex_height);
		ft_true_free((void **)&context->west->tex_height);
		ft_true_free((void **)&context->north);
		ft_true_free((void **)&context->south);
		ft_true_free((void **)&context->east);
		ft_true_free((void **)&context->west);
		ft_full_free((void **)context->map);
		ft_unset_context_animated(context, checker);
		ft_true_free((void **)&context);
	}
}
