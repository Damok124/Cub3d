/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_content(t_lines *content, int *err_no)
{
	if (!ft_just_enough_surfaces(content, (int [2]){0, 0}, err_no))
		return (0);
	if (!ft_just_enough_paths(content, (int [6]){0, 0, 0, 0, 0, 0}, err_no))
		return (0);
	if (!ft_check_format_textures(NULL, content, err_no, -1))
		return (0);
	if (!ft_check_format_punctuation(content, err_no))
		return (0);
	if (!ft_one_last_map(content, err_no))
		return (0);
	if (!ft_only_one_position(content, err_no))
		return (0);
	if (!ft_check_garbage(content, err_no))
		return (0);
	return (1);
}
