/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_enough_surfaces_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:57 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_just_enough_surfaces(t_lines *content, int *tab, int *err_no)
{
	while (content)
	{
		if (content->type == 'F')
			tab[0] += 1;
		else if (content->type == 'C')
			tab[1] += 1;
		content = content->next;
	}
	if (tab[0] != 1 || tab[1] != 1)
	{
		if (tab[0] == 0 || tab[1] == 0)
			*err_no = ERR_MISSING_SURFACES;
		else
			*err_no = ERR_TOO_MUCH_SURFACES;
		return (0);
	}
	return (1);
}
