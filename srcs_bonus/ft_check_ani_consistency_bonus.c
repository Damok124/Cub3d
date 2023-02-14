/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ani_consistency_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_ani_consistency(t_lines *content, int *err_no)
{
	int	i;

	i = 0;
	if (!ft_check_type_in_content(content, 'A') && !(*err_no))
	{
		while (content && content->type != 'M')
			content = content->next;
		while (content && content->type == 'M')
		{
			while (content->line && content->line[i])
			{
				if (content->line[i] == 'A')
					*err_no = ERR_NO_ANI_CONSISTENCY;
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
