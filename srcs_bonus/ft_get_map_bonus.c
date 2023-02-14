/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	**ft_get_map(t_lines *lst)
{
	char	**map;
	int		size;
	int		i;

	i = 0;
	size = ft_get_map_size(lst);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	map[size] = NULL;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		map[i] = ft_strdup(lst->line);
		i++;
		lst = lst->next;
	}
	return (map);
}
