# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    s                                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alprival <alprival@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:40:41 by zharzi            #+#    #+#              #
#    Updated: 2023/01/17 17:20:02 by alprival         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub3d.a

BINARY = cub3d

SRCSDIR = ./srcs/

UTILSDIR = ./utils/

SRCS = 	${SRCSDIR}ft_display.c \
		${SRCSDIR}ft_keycode_input.c \
		${SRCSDIR}parsing/ft_parsing.c \
		${SRCSDIR}ft_3d_display.c \
		${SRCSDIR}init/ft_init.c \
		${SRCSDIR}parsing/full_parsing.c \

HEADERDIR = includes/

HEADER = cub3d.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : libmlx.a libcub3D.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lcub3d -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) -lm

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libcub3D.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libft_printf.a :
	${MAKE} -C ft_printf/

libft.a :
	${MAKE} -C libft/

libmlx.a :
	${MAKE} -C mlx/

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
