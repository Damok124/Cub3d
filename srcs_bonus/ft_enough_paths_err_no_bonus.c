/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enough_paths_err_no_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:19 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_enough_paths_err_no(int *tab, int *err_no)
{
	if (tab[0] == 0 || tab[1] == 0 || tab[2] == 0 || tab[3] == 0)
		*err_no = ERR_MISSING_TEXTURE_PATHS;
	else
		*err_no = ERR_TOO_MUCH_TEXTURE_PATHS;
}
