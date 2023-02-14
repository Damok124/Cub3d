/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_shaped_dotted_map.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:11 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_square_shaped_dotted_map(t_lines *content)
{
	t_lines	*tmp;
	int		max;

	tmp = NULL;
	max = ft_get_greatest_len(content) + 2;
	while (content && content->type != 'M')
	{
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_line_to_map(max, content);
	while (content)
	{
		content->line = ft_line_to_standard(content->line, max);
		ft_spotted_spaces(content->line);
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_line_to_map(max, NULL);
}
