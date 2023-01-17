/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:48:51 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 01:53:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_true_splitset(const char *s, char **strs, char *set, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] && a < len)
	{
		while (s[i + j] && ft_strchr(set, s[i + j]))
			i++;
		while ((s[i + j] && !ft_strchr(set, s[i + j])))
			j++;
		if (ft_strchr(set, s[i + j]) || s[i + j] == 0)
			strs[a] = ft_substr(s, i, j);
		a++;
		i = i + j;
		j = 0;
	}
}

char	**ft_split_set(const char *s, char *set)
{
	char	**strs;
	ssize_t	len;

	strs = NULL;
	if (s)
	{
		len = ft_count_strs_set(s, set);
		strs = (char **)malloc(sizeof(char *) * (len + 1));
		if (!strs)
			return (NULL);
		strs[len] = NULL;
		ft_true_splitset(s, strs, set, len);
	}
	return (strs);
}
