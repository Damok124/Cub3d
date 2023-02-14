/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_bonus_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_context	*ft_cub3d_bonus_parsing(char **av, int *err_no)
{
	t_context	*context;
	t_lines		*content;

	context = NULL;
	content = ft_init_content(av[1], err_no);
	if (content && ft_check_content(content, err_no))
	{
		context = ft_init_t_context(err_no);
		if (context && !(*err_no))
		{
			ft_square_shaped_dotted_map(content);
			ft_get_textures_paths(context, content);
			context->orientation = ft_get_player_orientation(content);
			context->floor = ft_get_rgb(content, 'F');
			context->ceiling = ft_get_rgb(content, 'C');
			context->map = ft_get_map(content);
			context->map_height = ft_get_map_size(content);
			context->map_length = ft_get_greatest_len(content);
			if (!ft_check_if_flawless(context->map, err_no))
				ft_unset_context(context);
		}
	}
	ft_unset_content(content);
	return (context);
}
