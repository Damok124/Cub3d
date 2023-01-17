/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_strslen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:07:18 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 11:14:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_triple_strslen(char ***strs)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	j = 0;
	total = 0;
	while (strs && strs[i])
	{
		while (strs[i][j])
		{
			total++;
			j++;
		}
		j = 0;
		i++;
	}
	return (total);
}
