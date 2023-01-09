/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_last_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:06:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_last_msg(t_philo *philo, char *msg)
{
	int	time;

	time = ft_get_chrono(philo->start_time);
	pthread_mutex_lock(philo->mut_printf);
	printf("%i %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->mut_printf);
}
