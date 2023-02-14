/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_content_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_lines	*ft_fill_content(int size, int fd, int index)
{
	t_lines	*elem;
	char	*buffer;

	elem = NULL;
	buffer = NULL;
	if (size)
	{
		buffer = get_next_line(fd);
		elem = (t_lines *)malloc(sizeof(t_lines));
		if (!elem)
			return (NULL);
		buffer[ft_strlen(buffer) - 1] = '\0';
		elem->index = index;
		elem->line = buffer;
		elem->len = ft_strlen(buffer);
		elem->type = ft_define_line_type(buffer, ft_strlen(buffer));
		--size;
		++index;
		elem->next = ft_fill_content(size, fd, index);
	}
	if (++size && --index == 0)
		buffer = get_next_line(fd);
	return (elem);
}
