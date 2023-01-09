/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:51:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_msg(t_philo *philo, char *msg)
{
	int	time;

	if (!ft_is_dead(philo))
	{
		pthread_mutex_lock(philo->mut_printf);
		time = ft_get_chrono(philo->start_time);
		printf("%i %i %s\n", time, philo->id, msg);
		pthread_mutex_unlock(philo->mut_printf);
	}
}
