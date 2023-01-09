/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_safe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:59:32 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 02:17:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long int	ft_atoll_safe2(const char *nptr, int *check, \
	long long int i, long long int j)
{
	int	k;

	k = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		k = -1;
	else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
		k = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		j = i;
		i *= 10;
		i += *nptr - '0';
		if (j > i)
			*check = 0;
		nptr++;
	}
	return (i * k);
}

long long int	ft_atoll_safe1(const char *nptr, int *check)
{
	long long int	i;
	long long int	j;
	long long int	ret;

	i = 0;
	j = i;
	ret = 0;
	if (nptr)
		ret = ft_atoll_safe2(nptr, check, i, j);
	return (ret);
}
