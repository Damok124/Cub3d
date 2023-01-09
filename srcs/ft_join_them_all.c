/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_them_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:48 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:09:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_them_all(t_philo *tab)
{
	int	i;

	i = -1;
	while (++i < tab->context.members)
		pthread_join(tab[i].philo, NULL);
}
