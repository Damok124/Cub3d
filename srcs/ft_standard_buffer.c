/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:10:11 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 15:46:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_standard_buffer(char *buffer)
{
	int		i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'f')
			buffer[i] -= 32;
		i++;
		if (buffer && buffer[i] == '\n')
			buffer[i] -= 10;
	}
	return (buffer);
}
