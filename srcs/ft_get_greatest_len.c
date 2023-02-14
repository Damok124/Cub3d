/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_greatest_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:23 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_greatest_len(t_lines *content)
{
	int	max;

	max = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content)
	{
		if (content->len > max)
			max = content->len;
		content = content->next;
	}
	return (max);
}
