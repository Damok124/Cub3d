/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type_in_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_type_in_content(t_lines *content, char type)
{
	while (content && content->type != type)
		content = content->next;
	if (!content)
		return (0);
	return (1);
}
