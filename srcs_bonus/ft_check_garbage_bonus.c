/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_garbage_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:44 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_garbage(t_lines *content, int *err_no)
{
	while (content && !(*err_no))
	{
		if (content->type == '0' && content->line && content->line[0] != '\0')
			*err_no = ERR_UNEXPECTED_MENTIONS;
		content = content->next;
	}
	if (*err_no)
		return (0);
	return (1);
}
