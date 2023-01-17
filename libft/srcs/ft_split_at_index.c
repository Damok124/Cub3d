/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_at_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:59:49 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 02:00:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_at_index(char *str, int i)
{
	char	**final;
	char	*first;
	char	*last;

	final = NULL;
	if (str)
	{
		last = ft_strdup(str + i);
		str[i] = '\0';
		first = ft_strdup(str);
		final = (char **)malloc(sizeof(char *) * 3);
		if (!final)
			return (NULL);
		final[0] = first;
		final[1] = last;
		final[2] = NULL;
	}
	return (final);
}
