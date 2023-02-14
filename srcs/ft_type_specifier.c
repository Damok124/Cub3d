/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	ft_type_specifier(char *str, int target_type)
{
	char	type;

	type = '0';
	if (target_type == 1)
		type = ft_check_valid_fc(str);
	else if (target_type == 2)
		type = ft_check_valid_nswe(str);
	else if (target_type == 3)
		type = ft_check_valid_door(str);
	else if (target_type == 4)
		type = ft_check_valid_animation(str);
	return (type);
}
