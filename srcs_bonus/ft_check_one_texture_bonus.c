/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_one_texture_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:46 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_check_one_texture(char *path, int *err_no)
{
	if (path)
	{
		if (!ft_check_extension(path, ".xpm"))
			if (access(path, R_OK))
				*err_no = ERR_UNREADABLE_PATH;
	}
}
