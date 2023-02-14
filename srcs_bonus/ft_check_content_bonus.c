/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_content_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_content(t_lines *content, int *err_no)
{
	if (!ft_just_enough_surfaces(content, (int [2]){0, 0}, err_no))
		return (0);
	if (!ft_just_enough_paths(content, (int [6]){0, 0, 0, 0, 0, 0}, err_no))
		return (0);
	if (!ft_check_format_textures(NULL, content, err_no, -1) \
		|| !ft_check_format_ani_textures(NULL, content, err_no, -1))
		return (0);
	if (!ft_check_format_punctuation(content, err_no))
		return (0);
	if (!ft_one_last_map(content, err_no))
		return (0);
	if (!ft_only_one_position(content, err_no))
		return (0);
	if (!ft_check_ani_consistency(content, err_no))
		return (0);
	if (!ft_check_door_consistency(content, err_no))
		return (0);
	if (!ft_check_ani_textures(content, err_no, NULL))
		return (0);
	if (!ft_check_door_textures(content, err_no))
		return (0);
	if (!ft_check_garbage(content, err_no))
		return (0);
	return (1);
}
