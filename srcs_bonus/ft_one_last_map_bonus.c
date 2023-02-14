/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_last_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
