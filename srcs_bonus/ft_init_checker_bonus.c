/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/14 20:28:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_init_checker(t_lines *content, t_checker *checker)
{
	checker->ani = ft_check_type_in_content(content, 'A');
	checker->door = ft_check_type_in_content(content, 'D');
}
