# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include <math.h>
# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <stdio.h>
# include "libft/includes/libft.h"
# include "ft_printf/includes/ft_printf.h"

/*
clang -Wall -Wextra -Werror -g3 full_parsing.c -Iincludes/ -Ift_printf/includes/ -Ilibft/includes/ -Imlx/ -L. -lcub3D -L./mlx -lmlx -lXext -lX11 -L./libft -lft -L./ft_printf -lft_printf -o parsing -lm
*/

typedef struct s_lines {
	char			*line;
	int				index;
	int				len;
	char			type;
	struct s_lines	*next;
}	t_lines;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_context {
	char	*path_t_NO;
	char	*path_t_SO;
	char	*path_t_WE;
	char	*path_t_EA;
	t_rgb	floor;
	t_rgb	ceiling;
	char	**map;
}	t_context;

void	ft_cub3d(t_context *context)
{
	(void)context;
}

void	ft_check_lst_lines(t_lines *lst)
{
	int i;

	i = 0;
	printf("check :\n");
	while (lst)
	{
		printf("%d\t%c; len %d\t;", i, lst->type, lst->len);
		printf("%s\n", lst->line);
		lst = lst->next;
		i++;
	}
	printf("end check.\n");
}

int	ft_file_lines_counter(char *filename)
{
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		buffer = get_next_line(fd);
		while (buffer)
		{
			i++;
			ft_true_free((void **)&buffer);
			buffer = get_next_line(fd);
		}
		close(fd);
	}
	return (i);
}

int	ft_potential_map_line(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(" 01NSWE", str[i]))
		i++;
	if (i == len)
		return (1);
	return (0);
}

int	ft_strs_are_digits(char **strs)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (strs && strs[++i])
	{
		while (strs[i][++j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (0);
		}
		j = -1;
	}
	return (1);
}

char	ft_find_valid_fc(char *str)
{
	int		i;
	char	type;
	char	**colors;
	t_rgb	set;

	type = str[0];
	i = 1;
	while (str[i] == ' ')
		i++;
	if (i == 1 || !str[i])
		return ('0');
	colors = ft_split(str + i, ',');
	if (ft_strslen(colors) == 3 && ft_strs_are_digits(colors))
	{
		set.r = ft_atoi(colors[0]);
		set.g = ft_atoi(colors[1]);
		set.b = ft_atoi(colors[2]);
		ft_full_free((void **)colors);
		if (set.r <= 255 || set.g <= 255 || set.b <= 255)
			return (type);
	}
	ft_full_free((void **)colors);
	return ('0');
}

char	ft_find_valid_nswe(char *str)
{
	int		i;
	char	type;

	type = '0';
	i = 2;
	if ((str[0] == 'N' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'S' && str[1] == 'O' && str[2] == ' ') || \
		(str[0] == 'W' && str[1] == 'E' && str[2] == ' ') || \
		(str[0] == 'E' && str[1] == 'A' && str[2] == ' '))
		type = str[0];
	while (str[i] == ' ')
		i++;
	if (i == 2 || !str[i])
		return ('0');
	return (type);
}

char	ft_type_specifier(char *str, int target_size)
{
	char	type;

	type = '0';
	if (target_size == 1)
		type = ft_find_valid_fc(str);
	else if (target_size == 2)
		type = ft_find_valid_nswe(str);
	return (type);
}

// int	ft_are_space_only(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		if (str[i] != ' ')
// 			return (0);
// 	return (1);
// }

char	ft_define_line_type(char *str, int	len)
{
	char	type;

	type = '0';
	if (len)
	{
		if (ft_strchr("NSWE", str[0]) && len > 3)
			type = ft_type_specifier(str, 2);
		if (ft_strchr("FC", str[0]) && len > 2)
			type = ft_type_specifier(str, 1);
		else if (ft_potential_map_line(str, len))
			type = 'M';
	}
	return (type);
}

// void	ft_transform_tab(char *src, char *dest)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = 0;
// 	while (src[++i])
// 	{
// 		if (src[i] == '\t')
// 		{
// 			dest[j] = ' ';
// 			dest[j + 1] = ' ';
// 			dest[j + 2] = ' ';
// 			dest[j + 3] = ' ';
// 			j += 4;
// 		}
// 		else
// 		{
// 			dest[j] = src[i];
// 			j++;
// 		}
// 	}
// 	dest[j] = '\0';
// }

// char	*ft_ajust_spec_char(char *str)
// {
// 	int		len;
// 	char	*dest;
// 	int		n;
// 	int		i;

// 	i = -1;
// 	n = 0;
// 	while (str[++i])
// 		if (str[i] == '\t')
// 			n++;
// 	str[i - 1] = '\0';
// 	len = (i - 1) + (n * 3);
// 	dest = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dest)
// 		return (str);
// 	ft_transform_tab(str, dest);
// 	ft_true_free((void **)&str);
// 	return (dest);
// }

t_lines	*ft_setup_lst(int size, int fd, int index)
{
	t_lines *elem;
	char	*buffer;

	elem = NULL;
	buffer = NULL;
	if (size)
	{
		buffer = get_next_line(fd);
		elem = (t_lines *)malloc(sizeof(t_lines));
		if (!elem)
			return (NULL);
		// buffer = ft_ajust_spec_char(buffer);
		buffer[ft_strlen(buffer) - 1] = '\0';
		elem->index = index;
		elem->line = buffer;
		elem->len = ft_strlen(buffer);
		elem->type = ft_define_line_type(buffer, ft_strlen(buffer));
		--size;
		++index;
		elem->next = ft_setup_lst(size, fd, index);
	}
	if (++size && --index == 0)
		buffer = get_next_line(fd);
	return (elem);
}

t_lines	*ft_get_all_lines(char *filename)
{
	t_lines	*lst;
	int		size;
	int		fd;

	size = ft_file_lines_counter(filename);
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		lst = ft_setup_lst(size, fd, 0);
	return (lst);
}

t_context	*ft_init_t_context(void)
{
	t_context *context;

	context = (t_context *)malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->path_t_NO = NULL;
	context->path_t_SO = NULL;
	context->path_t_WE = NULL;
	context->path_t_EA = NULL;
	context->map = NULL;
	return (context);
}

void	ft_unset_content(t_lines *content)
{
	t_lines	*tmp;
	if (content)
	{
		while (content)
		{
			tmp = content;
			content = content->next;
			ft_true_free((void **)&tmp->line);
			ft_true_free((void **)&tmp);
		}
	}
}

int	ft_just_enough_args(t_lines *content, int *tab)
{
	while (content && content->type != 'M')
	{
		if (content->type == 'N')
			tab[0] += 1;
		else if (content->type == 'S')
			tab[1] += 1;
		else if (content->type == 'W')
			tab[2] += 1;
		else if (content->type == 'E')
			tab[3] += 1;
		else if (content->type == 'F')
			tab[4] += 1;
		else if (content->type == 'C')
			tab[5] += 1;
		content = content->next;
	}
	if (tab[0] + tab[1] + tab[2] + tab[3] + tab[4] + tab[5] != 6)
		return (0);
	return (1);
}

int	ft_one_last_map(t_lines *content)
{
	while (content && content->type != 'M')
		content = content->next;
	if (!content)
		return (0);
	while (content && content->type == 'M')
		content = content->next;
	if (content)
		return (0);
	return (1);
}

int	ft_only_one_position(t_lines *content)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				check++;
		i = -1;
		content = content->next;
	}
	if (check != 1)
		return (0);
	return (1);
}

int	ft_check_content(t_lines *content)
{
	if (!ft_just_enough_args(content, (int [6]){0, 0, 0, 0, 0, 0}))
		return (0);
	if (!ft_one_last_map(content))
		return (0);
	if (!ft_only_one_position(content))
		return (0);
	return (1);
}

int	ft_get_greatest_len(t_lines *content)
{
	int	max;

	max = 0;
	while (content && content->type != 'M')
		content = content->next;
	while (content)
	{
		if (content->len > max)
			max = content->len;
		content = content->next;
	}
	return (max);
}

char	*ft_line_to_standard(char *str, int	max)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char *)malloc(sizeof(char) * (max + 1));
	if (!dest)
		return (NULL);
	dest[max] = '\0';
	dest[0] = ' ';
	while (str[++i])
		dest[i + 1] = str[i];
	while (i < max - 1)
	{
		dest[i + 1] = ' ';
		i++;
	}
	ft_true_free((void **)&str);
	return (dest);
}

void	ft_spotted_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			str[i] = '.';
}

t_lines	*ft_add_empty_map_line(int max, t_lines *next)
{
	char	*empty_line;
	t_lines	*new;
	int		i;

	i = -1;
	new = (t_lines *)malloc(sizeof(t_lines));
	if (!new)
		return (NULL);
	empty_line = (char *)malloc(sizeof(char) * (max + 1));
	if (!empty_line)
	{
		ft_true_free((void **)&new);
		return (NULL);
	}
	empty_line[max] = '\0';
	while (++i < max)
		empty_line[i] = '.';
	new->len = max;
	new->index = 0;
	new->type = 'M';
	new->next = next;
	new->line = empty_line;
	return (new);
}

void	ft_square_shaped_dotted_map(t_lines *content)
{
	t_lines *tmp;
	int		max;

	tmp = NULL;
	max = ft_get_greatest_len(content) + 2;
	while (content && content->type != 'M')
	{
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_map_line(max, content);
	while (content)
	{
		content->line = ft_line_to_standard(content->line, max);
		ft_spotted_spaces(content->line);
		tmp = content;
		content = content->next;
	}
	tmp->next = ft_add_empty_map_line(max, NULL);
}

t_context	*ft_cub3d_parsing(char **argv)
{
	t_context	*context;
	t_lines		*content;

	context = ft_init_t_context();
	content = NULL;
	if (context)
	{
		if (ft_check_extension(argv[1], ".cub"))///////////////////to pimp
			content = ft_get_all_lines(argv[1]);
		else
			perror("Wrong extension.\n");
		if (!ft_check_content(content))
			printf("Error.\n");//////////////et exit le programme
		ft_square_shaped_dotted_map(content);
		ft_check_lst_lines(content);/////////////////////////////////
		// ft_content_into_context(content, context);
	}
	ft_unset_content(content);
	return (context);
}

void	ft_unset_context(t_context *context)
{
	ft_true_free((void **)&context->path_t_NO);
	ft_true_free((void **)&context->path_t_SO);
	ft_true_free((void **)&context->path_t_WE);
	ft_true_free((void **)&context->path_t_EA);
	ft_full_free((void **)context->map);
	ft_true_free((void **)&context);
}

int	main(int ac, char **argv)
{
	t_context	*context;

	if (ac == 2)
	{
		context = ft_cub3d_parsing(argv);
		if (context)
		{
			ft_cub3d(context);
			ft_unset_context(context);
		}
		else
			perror("FAILURE.\n");
	}
	else
		write(2, "Wrong arguments.\n", 17);
	return (0);
}
