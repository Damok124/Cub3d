NAME = libcub3D.a
NAME_BONUS = libcub3D_bonus.a

BINARY = cub3D

BINARY_BONUS = cub3D

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

HEADER_BONUS = cub3D.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : $(BINARY)

bonus : $(BINARY_BONUS)

$(BINARY) : $(LIBMLX) $(NAME) $(LIBFT_PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lcub3D -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY) -lm

$(BINARY_BONUS) : $(LIBMLX) $(NAME_BONUS) $(LIBFT_PRINTF) $(LIBFT)
	@$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lcub3D -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY_BONUS) -lm

%.o : %.c
	@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

$(NAME) : $(OBJ) $(HEADERDIR)$(HEADER)
	@ar -rcs $(NAME) $^

$(NAME_BONUS) : $(OBJ_BONUS) $(HEADERDIR)$(HEADER_BONUS)
	@ar -rcs $(NAME_BONUS) $^

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
