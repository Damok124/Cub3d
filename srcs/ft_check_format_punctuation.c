/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_punctuation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:23:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_format_punctuation(t_lines *content, int *err_no)
{
	char	*path;

	path = NULL;
	while (content)
	{
		if (ft_strchr("FC", content->type))
		{
			path = ft_strtrim(content->line + 1, " ");
			ft_check_duplicates(path, err_no, ',');
			if (!ft_isdigit(path[ft_strlen(path) - 1]))
				*err_no = ERR_WRONG_FORMAT_SURFACES;
		}
		ft_true_free((void **)&path);
		content = content->next;
	}
	if (*err_no)
		return (0);
	return (1);
}
