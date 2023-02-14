NAME = cub3D

LIBFT = libft/libft.a

LIBFT_PRINTF = ft_printf/libft_printf.a

LIBMLX = mlx/libmlx.a

SRCSDIR = ./srcs/

SRCSDIR_BONUS = ./srcs_bonus/

SRCS = \
${SRCSDIR}ft_full_cub3D.c

SRCS_BONUS = \
${SRCSDIR_BONUS}ft_full_cub3D_bonus.c

HEADERDIR = includes/

HEADER = cub3D.h

HEADER_BONUS = cub3D_bonus.h

ifdef BONUS
	SRCS = $(SRCS_BONUS)
endif

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

.c.o:
	$(CC) $(IFLAG) $(FLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

bonus :
	make BONUS=1

$(NAME) : $(LIBFT) $(LIBFT_PRINTF)  $(LIBMLX) $(OBJ)
	$(CC)  $(OBJ) -o $(NAME) $(FLAGS) $(IFLAG) -L./mlx -lmlx -lXext -lX11 -L./libft -lft -L./ft_printf -lft_printf -lm

$(LIBFT_PRINTF) :
	${MAKE} -sC ft_printf/

$(LIBFT) :
	${MAKE} -sC libft/

$(LIBMLX) :
	${MAKE} -sC mlx/

clean :
	rm -f $(OBJ)
	${MAKE} clean -sC ft_printf/
	${MAKE} clean -sC libft/
	${MAKE} clean -sC mlx/

fclean : clean
	rm -f $(NAME)
	${MAKE} fclean -sC ft_printf/
	${MAKE} fclean -sC libft/
	${MAKE} clean -sC mlx/

re : fclean all

bre : fclean bonus

.PHONY : all clean fclean re bonus
