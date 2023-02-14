/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:27:48 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:27:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int ac, char **argv)
{
	int			err_no;
	t_context	*context;
	t_vars		*vars;
	t_checker	checker;

	err_no = 0;
	checker.ani = 0;
	checker.door = 0;
	vars = NULL;
	if (ac == 2 && ft_check_extension(argv[1], ".cub"))
	{
		context = ft_cub3d_bonus_parsing(argv, &err_no, &checker);
		if (!err_no)
			ft_init_cub3d(vars, context, err_no, &checker);
		else
			ft_print_cub3d_error_1(err_no);
	}
	else
		write(2, "Error.\nCheck your arguments.\n", 29);
	ft_close_stdfds();
	return (0);
}
