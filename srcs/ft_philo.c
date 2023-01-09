/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:51 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:48:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(t_philo *philos)
{
	pthread_mutex_t	mut_printf;

	pthread_mutex_init(&mut_printf, NULL);
	ft_share_printf_mutex(philos, &mut_printf);
	if (philos->context.meals_max)
	{
		ft_put_thread_on_routine(philos);
		ft_soul_taking(philos);
		ft_join_them_all(philos);
	}
	pthread_mutex_destroy(&mut_printf);
	ft_unset_philos(philos);
}
