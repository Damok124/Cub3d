/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:03:10 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:09:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unset_philos(t_philo *tab)
{
	int	i;

	i = tab->context.members;
	while (--i >= 0)
	{
		pthread_mutex_destroy(&tab[i].right);
		pthread_mutex_destroy(&tab[i].life);
		tab[i].left = NULL;
	}
	ft_true_free((void **)&tab);
}
