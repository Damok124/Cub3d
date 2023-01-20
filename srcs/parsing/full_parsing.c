#include "cub3D.h"

#define BAD_FD 1

void	ft_show_strs(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	ft_click_cross(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

void	ft_cub3d(t_context *context)
{
	printf("\nAFTER PARSING\n");
	printf("NO path : %s\n", context->path_t_NO);
	printf("SO path : %s\n", context->path_t_SO);
	printf("WE path : %s\n", context->path_t_WE);
	printf("EA path : %s\n", context->path_t_EA);
	printf("Player Orientation : %c\n", context->player_orient);
	printf("floor R%d G%d B%d\n", context->floor.r, context->floor.g, context->floor.b);
	printf("ceiling R%d G%d B%d\n", context->ceiling.r, context->ceiling.g, context->ceiling.b);
	printf("map :\n");
	ft_show_strs(context->map);
	ft_init(context);
	context->vars.mlx = mlx_init();
	context->vars.win = mlx_new_window(context->vars.mlx, WINDOW_WIDTH , WINDOW_HEIGHT, "Hello world!");
	context->vars.img = mlx_new_image(context->vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	context->vars.addr = mlx_get_data_addr(context->vars.img, &context->vars.bits_per_pixel, &context->vars.line_length,
						&context->vars.endian);
	mlx_hook(context->vars.win, ON_DESTROY, DestroyAll, ft_click_cross, &(context->vars));
	mlx_hook(context->vars.win, 2, 1L << 0, button_down, &(context->vars));
	mlx_hook(context->vars.win, 3, 1L << 1, button_up, &(context->vars));
	mlx_loop_hook(context->vars.mlx, ft_display, context);
	mlx_loop(context->vars.mlx);
}

void	ft_check_lst_lines(t_lines *lst)
{
	int	i;

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

t_lines	*ft_setup_lst(int size, int fd, int index)
{
	t_lines	*elem;
	char	*buffer;

	elem = NULL;
	buffer = NULL;
	if (size)
	{
		buffer = get_next_line(fd);
		elem = (t_lines *)malloc(sizeof(t_lines));
		if (!elem)
			return (NULL);
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

t_lines	*ft_get_all_lines(char *filename, int *err_no)
{
	t_lines	*lst;
	int		size;
	int		fd;

	lst = NULL;
	size = ft_file_lines_counter(filename);
	fd = open(filename, O_RDONLY);
	if (fd > 0)
		lst = ft_setup_lst(size, fd, 0);
	else
		*err_no = BAD_FD;
	return (lst);
}

t_context	*ft_init_t_context(void)
{
	t_context	*context;

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
	t_lines	*tmp;
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

int	ft_get_map_size(t_lines *lst)
{
	int	size;

	size = 0;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char	**ft_get_map(t_lines *lst)
{
	char	**map;
	int		size;
	int		i;

	i = 0;
	size = ft_get_map_size(lst);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	map[size] = NULL;
	while (lst && lst->type != 'M')
		lst = lst->next;
	while (lst && lst->type == 'M')
	{
		map[i] = ft_strdup(lst->line);
		i++;
		lst = lst->next;
	}
	return (map);
}

char	**ft_strsdup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	dest = ft_alloc_strs(i);
	while (--i >= 0)
		dest[i] = ft_strdup(src[i]);
	return (dest);
}

int	ft_check_if_flawless(char **map)
{
	int	i;
	int	j;
	int	size;
	int	len;

	i = 1;
	j = 1;
	size = ft_strslen(map);
	len = ft_strlen(map[0]);
	while (i < (size - 1))
	{
		while (j < (len - 1))
		{
			if (ft_strchr("NSWE0", map[i][j]))
			{
				if (map[i - 1][j] == '.' || map[i + 1][j] == '.' \
					|| map[i][j - 1] == '.' || map[i][j + 1] == '.')
					return (0);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

void	ft_get_textures_paths(t_context **context, t_lines *content)
{
	t_context	*tmp;

	tmp = *context;
	while (content)
	{
		if (content->type == 'N')
			tmp->path_t_NO = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'S')
			tmp->path_t_SO = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'W')
			tmp->path_t_WE = ft_strtrim(content->line + 2, " ");
		else if (content->type == 'E')
			tmp->path_t_EA = ft_strtrim(content->line + 2, " ");
		content = content->next;
	}
}

t_rgb	ft_get_rgb(t_lines *content, char type)
{
	char	*tmp;
	char	**groups;
	t_rgb	colors;

	colors.r = 0;
	colors.g = 0;
	colors.b = 0;
	tmp = NULL;
	groups = NULL;
	while (content && content->type != type)
		content = content->next;
	if (content && content->type == type)
	{
		tmp = ft_strtrim(content->line + 1, " ");
		groups = ft_split(tmp, ',');
		ft_true_free((void **)&tmp);
		colors.r = ft_atoi(groups[0]);
		colors.g = ft_atoi(groups[1]);
		colors.b = ft_atoi(groups[2]);
		ft_full_free((void **)groups);
	}
	return (colors);
}

char	ft_get_player_orientation(t_lines *content)
{
	int	i;

	i = -1;
	while (content && content->type != 'M')
		content = content->next;
	while (content && content->type == 'M')
	{
		while (content->line[++i])
			if (ft_strchr("NSWE", content->line[i]))
				return (content->line[i]);
		i = -1;
		content = content->next;
	}
	return ('N');
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

void	ft_show_content(t_lines *content)
{
	printf("\nBEFORE PARSING\n");
	while (content)
	{
		printf("%s\n", content->line);
		content = content->next;
	}
}

t_context	*ft_cub3d_parsing(char **argv, int *err_no)
{
	t_context	*context;
	t_lines		*content;

	context = NULL;
	content = ft_get_all_lines(argv[1], err_no);
	ft_show_content(content);
	if (content && ft_check_content(content))
	{
		context = ft_init_t_context();
		if (context)
		{
			ft_square_shaped_dotted_map(content);
			ft_get_textures_paths(&context, content);
			context->player_orient = ft_get_player_orientation(content);
			context->floor = ft_get_rgb(content, 'F');
			context->ceiling = ft_get_rgb(content, 'C');
			context->map = ft_get_map(content);
			if (!ft_check_if_flawless(context->map))
				ft_unset_context(context);
		}
	}
	ft_unset_content(content);
	return (context);
}

//PROCHAINES ETAPES : GERER LES ERR_MSG - GERER LES TEXTURES
