/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cub3d_error_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_cub3d_error_1(int err_no)
{
	printf("Error\n");
	if (err_no == ERR_BAD_FD)
		printf("Check if existing file or your right to read it.\n");
	else if (err_no == ERR_MISSING_START_POSITION)
		printf("No starting position.\n");
	else if (err_no == ERR_TOO_MUCH_START_POSITION)
		printf("Put only one starting position.\n");
	else if (err_no == ERR_MISSING_MAP)
		printf("No map defined.\n");
	else if (err_no == ERR_SOMETHING_BELOW_MAP)
		printf("Unexpected map content or position.\n");
	else if (err_no == ERR_MISSING_TEXTURE_PATHS)
		printf("Missing texture paths.\n");
	else if (err_no == ERR_TOO_MUCH_TEXTURE_PATHS)
		printf("Too much texture paths defined.\n");
	else if (err_no == ERR_MISSING_SURFACES)
		printf("Missing proper floor or ceilling definition.\n");
	else if (err_no == ERR_TOO_MUCH_SURFACES)
		printf("Too much floor or ceilling definition.\n");
	else if (err_no == ERR_MAP_NOT_CLOSED)
		printf("This map is not closed.\n");
	else if (err_no == ERR_UNREADABLE_PATH)
		printf("Unreadable texture path.\n");
	ft_print_cub3d_error_2(err_no);
}
