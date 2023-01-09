/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_lencheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:03:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_lencheck(t_vars *vars, char *filename)
{
	int		fd;
	char	*buff1;
	int		*check;
	int		ret;

	ret = 1;
	check = (int *)malloc(sizeof(int) * 2);
	if (!check)
		return (0);
	fd = open(filename, O_RDONLY);
	buff1 = get_next_line(fd);
	check[0] = ft_fdf_getlen(buff1);
	vars->len = check[0];
	while (buff1)
	{
		ft_true_free(&buff1);
		buff1 = get_next_line(fd);
		if (buff1)
			check[1] = ft_fdf_getlen(buff1);
		if (check[0] != check[1])
			ret = 0;
	}
	close(fd);
	ft_true_free(&check);
	return (ret);
}
