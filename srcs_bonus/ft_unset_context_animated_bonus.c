/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_context_animated_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_unset_context_animated(t_context *context, t_checker *checker)
{
	if (context && checker && checker->door)
	{
		ft_true_free((void **)&context->door->path);
		ft_true_free((void **)&context->door->tex_width);
		ft_true_free((void **)&context->door->tex_height);
		ft_true_free((void **)&context->door);
	}
	if (context && checker && checker->ani)
	{
		ft_destroy_ani_context(context->animated);
		ft_true_free((void **)&context->animated);
	}
}
