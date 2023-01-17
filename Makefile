# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alprival <alprival@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:40:41 by zharzi            #+#    #+#              #
#    Updated: 2023/01/17 16:15:39 by alprival         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a

BINARY = cub3d

SRCSDIR = ./srcs/

UTILSDIR = ./utils/

SRCS = 	${SRCSDIR}ft_display.c\
		${SRCSDIR}ft_keycode_input.c\
		${SRCSDIR}parsing/ft_parsing.c\
		${SRCSDIR}ft_3d_display.c\
		${SRCSDIR}init/ft_init.c\
		
UTILS = \
${UTILSDIR}ft_fdf_free_matrix.c \
${UTILSDIR}ft_fdf_spacing.c \
${UTILSDIR}ft_fdf_btou.c \
${UTILSDIR}ft_fdf_rotation_x.c \
${UTILSDIR}ft_fdf_rotation_z.c \
${UTILSDIR}ft_fdf_get_col.c \
${UTILSDIR}ft_fdf_first_position.c \
${UTILSDIR}ft_fdf_last_position.c \
${UTILSDIR}ft_hypotenuse.c \
${UTILSDIR}ft_fdf_initvars.c \
${UTILSDIR}ft_map_to_matrix.c \
${UTILSDIR}ft_print_dot.c \
${UTILSDIR}ft_print_grid.c \
${UTILSDIR}ft_fdf_init_rows.c \
${UTILSDIR}ft_fdf_setup_dot.c \
${UTILSDIR}ft_standard_buffer.c \
${UTILSDIR}ft_fdf_initcol.c \
${UTILSDIR}ft_frame.c \
${UTILSDIR}ft_fdf_rowcount.c \
${UTILSDIR}ft_fdf_getlen.c \
${UTILSDIR}ft_fdf_lencheck.c \
${UTILSDIR}ft_get_octant.c \
${UTILSDIR}ft_pix_is_visible.c \
${UTILSDIR}ft_trace_oct.c \
${UTILSDIR}ft_link.c \
${UTILSDIR}ft_base_key.c \
${UTILSDIR}ft_manual_color.c \
${UTILSDIR}ft_renew_image.c \
${UTILSDIR}ft_keypress.c \
${UTILSDIR}ft_click_cross.c \
${UTILSDIR}ft_end_mlx.c \
${UTILSDIR}ft_pixel_put.c

HEADERDIR = includes/

HEADER = cub3D.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : $(BINARY)

$(BINARY) : libmlx.a libcub3D.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lcub3D -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) -lm

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libcub3D.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libft_printf.a :
	${MAKE} -sC ft_printf/

libft.a :
	${MAKE} -sC libft/

libmlx.a :
	${MAKE} -sC mlx/

clean :
	rm -f $(OBJ)
	${MAKE} clean -sC ft_printf/
	${MAKE} clean -sC libft/
	${MAKE} clean -sC mlx/

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)
	${MAKE} fclean -sC ft_printf/
	${MAKE} fclean -sC libft/
	${MAKE} clean -sC mlx/

re : fclean all

.PHONY : all clean fclean re
