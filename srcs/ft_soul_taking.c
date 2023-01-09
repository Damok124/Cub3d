/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soul_taking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:03:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:57:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_soul_taking(void *arg)
{
	t_philo	*philo;
	int		all_full;
	int		i;

	i = 0;
	all_full = 0;
	philo = (t_philo *)arg;
	while (!ft_is_dead(&philo[i]))
	{
		ft_is_full(&philo[i], &all_full);
		if (all_full >= philo->context.members)
			break ;
		i = (i + 1) % philo->context.members;
		usleep(10);
	}
	if (ft_is_expired(&philo[i]))
		ft_print_last_msg(&philo[i], "died");
	i = -1;
	while (++i < philo->context.members)
	{
		pthread_mutex_lock(&philo[i].life);
		philo[i].alive = 0;
		pthread_mutex_unlock(&philo[i].life);
	}
	return (NULL);
}
