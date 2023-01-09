/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:53:24 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	ls;
	size_t	i;
	char	*dup;

	i = 0;
	ls = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * ls);
	if (dup == NULL)
		return (NULL);
	while (i < ls)
	{
		dup[i] = (char)s[i];
		i++;
	}
	return (dup);
}
