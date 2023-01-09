/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_overflow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:10 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:04:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arg_overflow(char *arg)
{
	int	check;

	check = 1;
	ft_atoi_safe(arg, &check);
	if (!check)
		return (0);
	return (1);
}
