/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_triple_into_double.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:15:51 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 11:18:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strs_triple_into_double(char ***triple)
{
	char	**strs;
	int		size;
	int		i;
	int		j;
	int		x;

	i = -1;
	j = -1;
	x = -1;
	size = ft_triple_strslen(triple);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	strs[size] = NULL;
	while (triple[++i])
	{
		while (triple[i][++j])
			strs[++x] = ft_strdup(triple[i][j]);
		j = -1;
	}
	ft_triple_free(triple);
	return (strs);
}
