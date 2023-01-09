/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:43 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:48:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->life);
	if (!philo->alive)
	{
		pthread_mutex_unlock(&philo->life);
		return (1);
	}
	if (philo->deadline < ft_get_chrono(philo->start_time))
	{
		pthread_mutex_unlock(&philo->life);
		return (1);
	}
	pthread_mutex_unlock(&philo->life);
	return (0);
}
