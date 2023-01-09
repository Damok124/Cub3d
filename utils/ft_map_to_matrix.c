/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:52:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_spot	**ft_map_to_matrix(t_vars *vars, char *filename)
{
	int		fd;
	char	*buffer;
	char	*savebuff;
	int		y;
	t_spot	**matrix;

	matrix = (t_spot **)malloc(sizeof(t_spot *) * vars->rows);
	y = 0;
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	savebuff = buffer;
	while (buffer)
	{
		buffer = ft_standard_buffer(buffer);
		matrix[y] = ft_fdf_init_rows(&buffer, vars, y);
		y++;
		ft_true_free(&savebuff);
		buffer = get_next_line(fd);
		savebuff = buffer;
	}
	close(fd);
	return (matrix);
}
