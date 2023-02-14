/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type_in_content_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_type_in_content(t_lines *content, char type)
{
	while (content && content->type != type)
		content = content->next;
	if (!content)
		return (0);
	return (1);
}
