/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_unset_context(t_context *context)
{
	if (context)
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
		ft_true_free((void **)&context);
	}
}
