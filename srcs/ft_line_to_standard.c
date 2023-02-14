/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_standard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_line_to_standard(char *str, int max)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char *)malloc(sizeof(char) * (max + 1));
	if (!dest)
		return (NULL);
	dest[max] = '\0';
	dest[0] = ' ';
	while (str[++i])
		dest[i + 1] = str[i];
	while (i < max - 1)
	{
		dest[i + 1] = ' ';
		i++;
	}
	ft_true_free((void **)&str);
	return (dest);
}
