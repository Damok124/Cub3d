/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_content_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_lines	*ft_init_content(char *filename, int *err_no)
{
	t_lines	*lst;
	int		size;
	int		fd;

	lst = NULL;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		size = ft_file_lines_counter(fd);
		close(fd);
		fd = open(filename, O_RDONLY);
		lst = ft_fill_content(size, fd, 0);
		close(fd);
	}
	else
	{
		*err_no = ERR_BAD_FD;
		return (lst);
	}
	if (!size)
		*err_no = ERR_EMPTY_FILE;
	return (lst);
}
