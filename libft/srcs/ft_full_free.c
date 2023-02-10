/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:23:40 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/10 17:38:41 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free(void **tobefreed)
{
	int	i;

	i = -1;
	while (tobefreed && tobefreed[++i])
		ft_true_free(&tobefreed[i]);
	if (tobefreed)
	{
		free(tobefreed);
		tobefreed = NULL;
	}
}
