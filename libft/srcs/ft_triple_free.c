/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:08:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 11:14:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_triple_free(char ***tobefreed)
{
	int	i;

	i = 0;
	while (tobefreed && tobefreed[i])
	{
		ft_full_free((void **)tobefreed[i]);
		i++;
	}
	if (tobefreed)
	{
		free(tobefreed);
		tobefreed = NULL;
	}
}
