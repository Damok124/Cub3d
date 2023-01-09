/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:14:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/26 00:49:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_stash(char *stash)
{
	int	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_make_buff(int fd, char **ret, int *count)
{
	char	*tbuff;
	char	*tret;

	tret = *ret;
	tbuff = (char *)malloc(BUFFER_SIZE + 1);
	if (!tbuff)
		return (NULL);
	*count = read(fd, tbuff, BUFFER_SIZE);
	if (*count == -1)
	{
		ft_true_free(&tbuff);
		return (tret);
	}
	tbuff[*count] = '\0';
	return (tbuff);
}

char	*ft_next_line(char **stash)
{
	t_tools1	x;

	x.n = 0;
	x.tmp = *stash;
	while (x.tmp[x.n] && x.tmp[x.n] != '\n')
		x.n++;
	if (x.tmp[x.n] == '\n')
		x.n++;
	x.line = (char *)ft_calloc(sizeof(char) * x.n + 1, 1);
	if (!x.line)
		return (NULL);
	x.i = -1;
	while (++x.i < x.n)
		x.line[x.i] = x.tmp[x.i];
	x.line[x.n] = '\0';
	stash[0] = ft_strdup((x.tmp) + x.i);
	ft_true_free(&x.tmp);
	return (x.line);
}

char	*get_next_line(int fd)
{
	t_tools2	x;
	static char	*stash[1023];

	x.ret = NULL;
	x.count = 1;
	if (fd != -1 && BUFFER_SIZE > 0)
	{
		while (x.count && (!stash[fd] || !ft_check_stash(stash[fd])))
		{
			x.buff = ft_make_buff(fd, &x.ret, &x.count);
			if (!x.buff)
				return (x.ret);
			x.ret = ft_strjoin(stash[fd], x.buff);
			ft_true_free(&x.buff);
			if (stash[fd])
				ft_true_free(&stash[fd]);
			stash[fd] = x.ret;
			x.ret = NULL;
		}
		if (stash[fd][0])
			x.ret = ft_next_line(&stash[fd]);
		else if (stash[fd][0] == '\0')
			ft_true_free(&stash[fd]);
	}
	return (x.ret);
}
