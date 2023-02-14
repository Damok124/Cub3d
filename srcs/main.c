/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:21 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **argv)
{
	int			err_no;
	t_context	*context;
	t_vars		*vars;

	err_no = 0;
	vars = NULL;
	if (ac == 2 && ft_check_extension(argv[1], ".cub"))
	{
		context = ft_cub3d_bonus_parsing(argv, &err_no);
		if (!err_no)
			ft_init_cub3d(vars, context, err_no);
		else
			ft_print_cub3d_error_1(err_no);
	}
	else
		write(2, "Error.\nCheck your arguments.\n", 29);
	ft_close_stdfds();
	return (0);
}
