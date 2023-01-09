/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_thread_on_routine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:09:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_put_thread_on_routine(t_philo *tab)
{
	struct timeval	beginning;
	int				i;

	i = -1;
	gettimeofday(&beginning, NULL);
	while (++i < tab->context.members)
	{
		tab[i].start_time = beginning;
		pthread_create(&tab[i].philo, NULL, ft_routine, (void *)&tab[i]);
	}
}
