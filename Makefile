NAME = libcub3D.a

BINARY = cub3D

LIBFT = libft/libft.a

LIBFT_PRINTF = ft_printf/libft_printf.a

LIBMLX = mlx/libmlx.a

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}ft_full_cub3D.c

HEADERDIR = includes/

HEADER = cub3D.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : $(BINARY)

$(BINARY) : $(LIBMLX) $(NAME) $(LIBFT_PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lcub3D -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) -lm

%.o : %.c
	@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

$(NAME) : $(OBJ) $(HEADERDIR)$(HEADER)
	@ar -rcs $(NAME) $^

$(LIBFT_PRINTF) :
	@${MAKE} -sC ft_printf/

$(LIBFT) :
	@${MAKE} -sC libft/

$(LIBMLX) :
	@${MAKE} -sC mlx/

clean :
	@rm -f $(OBJ)
	@${MAKE} clean -sC ft_printf/
	@${MAKE} clean -sC libft/
	@${MAKE} clean -sC mlx/

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BINARY)
	@${MAKE} fclean -sC ft_printf/
	@${MAKE} fclean -sC libft/
	@${MAKE} clean -sC mlx/

re : fclean all

dev :
	@rm -f $(BINARY)
	@${MAKE} -sC ./

.PHONY : all clean fclean re
