/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_enough_paths_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_just_enough_paths(t_lines *content, int *tab, int *err_no)
{
	while (content)
	{
		if (content->type == 'N')
			tab[0] += 1;
		else if (content->type == 'S')
			tab[1] += 1;
		else if (content->type == 'W')
			tab[2] += 1;
		else if (content->type == 'E')
			tab[3] += 1;
		else if (content->type == 'D')
			tab[4] += 1;
		else if (content->type == 'A')
			tab[5] += 1;
		content = content->next;
	}
	if (tab[0] != 1 || tab[1] != 1 || tab[2] != 1 || tab[3] != 1 \
		|| tab[4] > 1 || tab[5] > 1)
	{
		ft_enough_paths_err_no(tab, err_no);
		return (0);
	}
	return (1);
}
