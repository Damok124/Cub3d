/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:03:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:52:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleeping(t_philo *philo, int *forks)
{
	if (*forks > 2)
	{
		pthread_mutex_unlock(philo->left);
		*forks -= 2;
	}
	if (*forks > 0)
	{
		pthread_mutex_unlock(&philo->right);
		*forks -= 1;
	}
	if (!ft_is_dead(philo))
	{
		ft_print_msg(philo, "is sleeping");
		ft_usleep(philo, philo->context.rest_time);
	}
}
