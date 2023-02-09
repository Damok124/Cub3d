/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:10:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/09 21:45:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_end_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;
	int				j;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	// printf("\n9\n");
	i = ft_strlen((char *)str1) - 1;
	// printf("\n10\n");
	j = n - 1;
	// printf("\n11\n");
	while (i >= 0 && j >= 0)
	{
		// printf("\n12 ET i=%d ET j=%d\n", i, j);
		if ((!str1 && !str2) || (str1[0] == '\0' && str2[0] == '\0'))
			return (0);
		else if (!str1 && str2 && str2[n])
			return (-str2[n]);
		else if (str1 && !str2 && str1[i])
			return (str1[i]);
		else if (str1[i] - str2[j] != 0)
			return (str1[i] - str2[j]);
		i--;
		j--;
	}
	return (0);
}

#include <stdio.h>

int	ft_check_extension(char *filename, char *extension)
{
	size_t	filename_len;
	size_t	extension_len;
	int		i;

	if (filename && extension)
	{
		// printf("f:%s-e:%s\n", filename, extension);
		filename_len = ft_strlen(filename);
		// printf("\n1\n");
		extension_len = ft_strlen(extension);
		// printf("\n2\n");
		i = filename_len;
		// printf("\n3\n");
		if (filename_len && filename_len > extension_len)
		{
			// printf("\n4\n");
			while (i && filename[i - 1] && filename[i - 1] != '/')
			{
				// printf("\n5 ET i=%d\n", i);
				i--;
			}
			filename = filename + i;
			// printf("\n6\n");
			filename_len = ft_strlen(filename);
			// printf("\n7\n");
			i = 0;
			// printf("\n8\n");
			if (filename_len > extension_len)
				if (!ft_end_strncmp(filename, extension, ft_strlen(extension)))
					return (1);
		}
	}
	return (0);
}
