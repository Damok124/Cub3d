/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:03:12 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:48:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, int timer)
{
	long int	rest;

	rest = (long int)timer;
	if ((long int)philo->deadline \
		< (long int)ft_get_chrono(philo->start_time) + rest)
		rest = (long int)philo->deadline \
			- (long int)ft_get_chrono(philo->start_time);
	if (rest < 0)
		rest = 0;
	if (rest)
		usleep((rest) * 1000);
	else
		usleep(1000);
}
