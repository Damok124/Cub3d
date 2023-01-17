/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:58:41 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 01:58:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	dest = ft_alloc_strs(i);
	while (--i >= 0)
		dest[i] = ft_strdup(src[i]);
	return (dest);
}
