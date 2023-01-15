NAME = libcub3D.a

BINARY = cub3D

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}test.c

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
