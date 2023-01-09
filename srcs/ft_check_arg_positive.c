/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_positive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/20 21:04:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arg_positive(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i])
		return (0);
	return (1);
}
