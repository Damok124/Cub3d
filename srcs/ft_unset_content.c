/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:14 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_unset_content(t_lines *content)
{
	t_lines	*tmp;

	if (content)
	{
		while (content)
		{
			tmp = content;
			content = content->next;
			ft_true_free((void **)&tmp->line);
			ft_true_free((void **)&tmp);
		}
	}
}
