/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:49:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **argv)
{
	t_context	context;
	t_philo		*philos;

	philos = NULL;
	if (ft_check_args(ac - 1, argv + 1))
	{
		context = ft_init_context(argv + 1, ac -1);
		philos = ft_init_tab_philo(context);
		if (philos)
			ft_philo(philos);
		else
			printf("FAILURE\n");
	}
	else
		printf("Wrong arguments.\n");
	return (EXIT_SUCCESS);
}
