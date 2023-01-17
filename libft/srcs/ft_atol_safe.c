/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:59:19 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 02:16:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_atol_safe2(const char *ptr, int *check, long long i, long long j)
{
	int	k;

	k = 0;
	while ((*ptr >= '\t' && *ptr <= '\r') || *ptr == ' ')
		ptr++;
	if (*ptr == '-')
		k = -1;
	else if (*ptr == '+' || (*ptr >= '0' && *ptr <= '9'))
		k = 1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr && *ptr >= '0' && *ptr <= '9')
	{
		j = i;
		i *= 10;
		i += *ptr - '0';
		if (j > i)
			*check = 0;
		ptr++;
	}
	return (i * k);
}

long	ft_atol_safe1(const char *nptr, int *check)
{
	long long	i;
	long long	j;
	long		ret;

	i = 0;
	j = i;
	ret = 0;
	if (nptr)
		ret = ft_atol_safe2(nptr, check, i, j);
	return (ret);
}
