/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_context.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:49:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_context	ft_init_context(char **argv, int ac)
{
	t_context	context;
	int			check;

	check = 1;
	context.members = ft_atoi_safe(argv[0], &check);
	context.life_time = ft_atoi_safe(argv[1], &check);
	context.meal_time = ft_atoi_safe(argv[2], &check);
	context.rest_time = ft_atoi_safe(argv[3], &check);
	if (ac == 5)
		context.meals_max = ft_atoi_safe(argv[4], &check);
	else
		context.meals_max = -1;
	return (context);
}
