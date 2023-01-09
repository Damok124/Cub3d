/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_chrono.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:47:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_chrono(struct timeval start)
{
	struct timeval	result;
	struct timeval	actual;
	int				time;

	time = 0;
	gettimeofday(&actual, NULL);
	result.tv_sec = actual.tv_sec - start.tv_sec;
	result.tv_usec = actual.tv_usec - start.tv_usec;
	time = (result.tv_sec * 1000) + (result.tv_usec / 1000);
	return (time);
}
