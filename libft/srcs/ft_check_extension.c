/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:10:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/13 18:30:41 by alprival         ###   ########.fr       */
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
	i = ft_strlen((char *)str1) - 1;
	j = n - 1;
	while (i >= 0 && j >= 0)
	{
		if ((!str1 && !str2) || (str1[0] == '\0' && str2[0] == '\0'))
			return (0);
		else if (!str1 && str2 && str2[j])
			return (-str2[j]);
		else if (str1 && !str2 && str1[i])
			return (str1[i]);
		else if (str1[i] - str2[j] != 0)
			return (str1[i] - str2[j]);
		i--;
		j--;
	}
	return (0);
}

int	ft_check_extension(char *filename, char *extension)
{
	size_t	filename_len;
	size_t	extension_len;
	int		i;

	if (filename && extension)
	{
		filename_len = ft_strlen(filename);
		extension_len = ft_strlen(extension);
		i = filename_len;
		if (filename_len && filename_len > extension_len)
		{
			while (i && filename[i - 1] && filename[i - 1] != '/')
				i--;
			filename = filename + i;
			filename_len = ft_strlen(filename);
			i = 0;
			if (filename_len > extension_len)
				if (!ft_end_strncmp(filename, extension, ft_strlen(extension)))
					return (1);
		}
	}
	return (0);
}
