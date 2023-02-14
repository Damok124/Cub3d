/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minitools_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:52 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_init_minitools(t_minitools *tools, t_player *pos)
{
	tools->start_x = ((pos->player_x) - ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->start_y = ((pos->player_y) - ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->target_x = ((pos->player_x) + ((MINIZONE * SQ_SIZE / 2))) / SCALING;
	tools->target_y = ((pos->player_y) + ((MINIZONE * SQ_SIZE / 2))) / SCALING;
}
