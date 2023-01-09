/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_expired.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:05:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_expired(t_philo *philo)
{
	pthread_mutex_lock(&philo->life);
	if (philo->deadline < ft_get_chrono(philo->start_time))
	{
		pthread_mutex_unlock(&philo->life);
		return (1);
	}
	pthread_mutex_unlock(&philo->life);
	return (0);
}
