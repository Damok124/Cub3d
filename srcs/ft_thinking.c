/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:03:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:52:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	if (!ft_is_dead(philo))
	{
		ft_print_msg(philo, "is thinking");
	}
}
