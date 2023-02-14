/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:24:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_keys	*ft_init_keys(void)
{
	t_keys	*keys;

	keys = (t_keys *)malloc(sizeof(t_keys));
	if (!keys)
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left_arr = 0;
	keys->right_arr = 0;
	return (keys);
}
