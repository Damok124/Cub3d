/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_rowcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:47:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_rowcount(char *filename)
{
	int		fd;
	char	*buffer;
	int		len;

	fd = 0;
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	len = 0;
	while (buffer)
	{
		len++;
		ft_true_free(&buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (len);
}
