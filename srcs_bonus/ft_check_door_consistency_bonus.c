/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door_consistency_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_door_consistency(t_lines *content, int *err_no)
{
	int	i;

	i = 0;
	if (!ft_check_type_in_content(content, 'D') && !(*err_no))
	{
		while (content && content->type != 'M')
			content = content->next;
		while (content && content->type == 'M')
		{
			while (content->line && content->line[i])
			{
				if (ft_strchr("DO", content->line[i]))
					*err_no = ERR_NO_DOOR_CONSISTENCY;
				i++;
			}
			i = 0;
			content = content->next;
		}
	}
	if (*err_no)
		return (0);
	return (1);
}
