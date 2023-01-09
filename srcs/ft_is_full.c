/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:31:52 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 14:03:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_full(t_philo *philo, int *all_full)
{
	pthread_mutex_lock(&philo->life);
	if (philo->full)
	{
		*all_full += 1;
		pthread_mutex_unlock(&philo->life);
	}
	else
	{
		*all_full = 0;
		pthread_mutex_unlock(&philo->life);
	}
}
