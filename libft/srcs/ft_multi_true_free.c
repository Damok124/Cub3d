/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_true_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:10:48 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/31 18:14:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_multi_true_free(void **one, void **two, void **three, void **four)
{
	ft_true_free(one);
	ft_true_free(two);
	ft_true_free(three);
	ft_true_free(four);
}
