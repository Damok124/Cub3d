/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cub3d_error_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:25:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:29:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_cub3d_error_2(int err_no)
{
	if (err_no == ERR_EMPTY_FILE)
		printf("The file is empty.\n");
	else if (err_no == ERR_TEXTURE_INIT_FAILED)
		printf("Failed to malloc textures structures.\n");
	else if (err_no == ERR_MALLOC_CONTEXT)
		printf("Failed to malloc parsed datas structure.\n");
	else if (err_no == ERR_BAD_TEXTURE_FILE)
		printf("Wrong texture file.\n");
	else if (err_no == ERR_FLOOR_CEILLING_FORMAT)
		printf("Wrong definition of colors for floor or ceilling.\n");
	else if (err_no == ERR_WRONG_FORMAT_SURFACES)
		printf("Wrong surfaces format.\n");
	else if (err_no == ERR_UNEXPECTED_MENTIONS)
		printf("There are unexpected mentions in your file.\n");
}
