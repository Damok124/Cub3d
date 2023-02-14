/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_last_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_one_last_map(t_lines *content, int *err_no)
{
	while (content && content->type != 'M')
		content = content->next;
	if (!content)
	{
		*err_no = ERR_MISSING_MAP;
		return (0);
	}
	while (content && content->type == 'M')
		content = content->next;
	if (content)
	{
		*err_no = ERR_SOMETHING_BELOW_MAP;
		return (0);
	}
	return (1);
}
