/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:31 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_get_map_size(t_lines *lst)
{
	int	size;

	size = 0;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
