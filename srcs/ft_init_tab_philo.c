/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:38 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:49:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_init_tab_philo(t_context context)
{
	t_philo	*tab;
	int		i;

	i = -1;
	tab = (t_philo *)malloc(sizeof(t_philo) * context.members);
	if (!tab)
		return (NULL);
	while (++i < context.members)
	{
		tab[i].id = i + 1;
		tab[i].alive = 1;
		tab[i].full = 0;
		tab[i].context = context;
		tab[i].deadline = (long int)context.life_time;
		tab[i].meals = 0;
		tab[i].left = NULL;
	}
	ft_init_mutexes(tab);
	if (context.members > 1)
	{
		tab[--i].left = &tab[0].right;
		while (--i >= 0)
			tab[i].left = &tab[i + 1].right;
	}
	return (tab);
}
