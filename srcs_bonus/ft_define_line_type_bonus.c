/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_line_type_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:01 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	ft_define_line_type(char *str, int len)
{
	char	type;

	type = '0';
	if (len)
	{
		if (ft_potential_map_line(str, len))
			type = 'M';
		else if (ft_strchr("FC", str[0]) && len > 2)
			type = ft_type_specifier(str, 1);
		else if (ft_strchr("D", str[0]) && len > 3)
			type = ft_type_specifier(str, 3);
		else if (ft_strchr("A", str[0]) && len > 4)
			type = ft_type_specifier(str, 4);
		else if (ft_strchr("NSWE", str[0]) && len > 3)
			type = ft_type_specifier(str, 2);
	}
	return (type);
}
