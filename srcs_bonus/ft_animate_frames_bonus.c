/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_frames_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_animate_frames(int *frames)
{
	static int	j;
	static int	i;

	if (!j)
		j = 1;
	if (i++ / 7)
	{
		i = 0;
		if (*frames > 10 && j == 1)
			j = -1;
		else if (*frames < 1 && j == -1)
			j = 1;
		*frames += j;
	}
}
