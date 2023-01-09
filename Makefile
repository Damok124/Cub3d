# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:40:41 by zharzi            #+#    #+#              #
#    Updated: 2022/09/26 00:57:24 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a

BINARY = fdf

SRCSDIR = ./srcs/

SRCS = ${SRCSDIR}ft_fdf_free_matrix.c \
${SRCSDIR}ft_fdf_spacing.c \
${SRCSDIR}ft_fdf_btou.c \
${SRCSDIR}ft_fdf_rotation_x.c \
${SRCSDIR}ft_fdf_rotation_z.c \
${SRCSDIR}ft_fdf_get_col.c \
${SRCSDIR}ft_fdf_first_position.c \
${SRCSDIR}ft_fdf_last_position.c \
${SRCSDIR}ft_hypotenuse.c \
${SRCSDIR}ft_fdf_initvars.c \
${SRCSDIR}ft_map_to_matrix.c \
${SRCSDIR}ft_print_dot.c \
${SRCSDIR}ft_print_grid.c \
${SRCSDIR}ft_fdf_init_rows.c \
${SRCSDIR}ft_fdf_setup_dot.c \
${SRCSDIR}ft_standard_buffer.c \
${SRCSDIR}ft_fdf_initcol.c \
${SRCSDIR}ft_frame.c \
${SRCSDIR}ft_fdf_rowcount.c \
${SRCSDIR}ft_fdf_getlen.c \
${SRCSDIR}ft_fdf_lencheck.c \
${SRCSDIR}ft_get_octant.c \
${SRCSDIR}ft_pix_is_visible.c \
${SRCSDIR}ft_trace_oct.c \
${SRCSDIR}ft_link.c \
${SRCSDIR}ft_base_key.c \
${SRCSDIR}ft_manual_color.c \
${SRCSDIR}ft_renew_image.c \
${SRCSDIR}ft_keypress.c \
${SRCSDIR}ft_click_cross.c \
${SRCSDIR}ft_end_mlx.c \
${SRCSDIR}ft_pixel_put.c

HEADERDIR = includes/

HEADER = fdf.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : libmlx.a libfdf.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lfdf -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) -lm

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libfdf.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libft_printf.a :
	${MAKE} -C ft_printf/

libft.a :
	${MAKE} -C libft/

libmlx.a :
	${MAKE} -C mlx/

clean :
	rm -f $(OBJ)
	${MAKE} clean -C ft_printf/
	${MAKE} clean -C libft/
	${MAKE} clean -C mlx/

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)
	${MAKE} fclean -C ft_printf/
	${MAKE} fclean -C libft/
	${MAKE} clean -C mlx/

re : fclean all

.PHONY : all clean fclean re
