/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/11 20:45:42 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_fdf_setup_matrix(t_vars *vars, t_spot **matrix)
{
	ft_fdf_first_position(vars, matrix);
	ft_fdf_rotation_z(vars, matrix, 3.14159265 * 45 / 180);
	ft_fdf_rotation_x(vars, matrix, 3.14159265 * 60 / 180);
	ft_fdf_last_position(vars, matrix);
	ft_print_grid(vars, matrix);
}

void	ft_fdf(char *filename)
{
	t_vars	*vars;
	t_spot	**matrix;

	vars = ft_fdf_initvars(filename);
	if (!vars)
	{
		ft_printf("Map error.\n");
		return ;
	}
	matrix = ft_map_to_matrix(vars, filename);
	mlx_key_hook(vars->win, ft_keypress, vars);
	mlx_hook(vars->win, ON_DESTROY, DestroyAll, ft_click_cross, vars);
	mlx_loop_hook(vars->mlx, ft_frame, vars);
	ft_fdf_setup_matrix(vars, matrix);
	mlx_loop(vars->mlx);
	ft_fdf_free_matrix(matrix, vars);
	ft_end_mlx(&vars);
}

int	ft_fdf_error_management(int ac, char **argv)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv[1]);
	if (ac != 2 || len < 5)
		return (1);
	if (!ft_check_extension(argv[1], ".fdf"))
		return (2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (3);
	close(fd);
	return (0);
}


void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_if_player(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'E' || vars->map[y][x] == 'N' || vars->map[y][x] == 'S' || vars->map[y][x] == 'W')
		return (1);
	return (0);
}

void	ft_draw_squarre(t_vars *vars, int y, int x, int color)
{
	int i;
	int j;

	j = 1;
	while(j < IMG)
	{
		i = 1;
		while(i < IMG)
		{
			my_mlx_pixel_put(vars, i + (x * IMG) ,j + (y * IMG), color);
			i++;
		}
		j++;
	}
}



void	ft_draw_map(t_vars *vars)
{
	int x;
	int	y;
	
	y = 0;
	while(vars->map[y])
	{
		x = 0;
		while(vars->map[y][x])
		{
			if(vars->map[y][x] == '1')
				ft_draw_squarre(vars, y, x, 0xFFFFFFFF);
			else if(vars->map[y][x] == '.')
				ft_draw_squarre(vars, y, x, 0x00BBEECC);
			else if(vars->map[y][x] == '0')
				ft_draw_squarre(vars, y, x, 0xFF000000);
			x++;
		}
		y++;
	}
}

void	ft_draw_ray_hit(t_vars *vars, t_rays *rays, unsigned int color)
{
	my_mlx_pixel_put(vars, rays->sx + 1, rays->sy, color);
	my_mlx_pixel_put(vars, rays->sx - 1, rays->sy, color);
	my_mlx_pixel_put(vars, rays->sx, rays->sy + 1, color);
	my_mlx_pixel_put(vars, rays->sx, rays->sy - 1, color);
}

float	ft_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}	

void	ft_horizontal_line(t_vars *vars, t_rays *rays)
{
	rays->dof = 0;
	rays->aTan = - 1 / tan(rays->ra);
	if(rays->ra > PI)
	{
		rays->ry = (((int)vars->py >> 6) << 6) - 0.0001;
		rays->rx = (vars->py - rays->ry) * rays->aTan + vars->px;
		rays->yo = -64;
		rays->xo = -rays->yo * rays->aTan;
	}
	if(rays->ra < PI)
	{
		rays->ry = (((int)vars->py >> 6) << 6) + 64;
		rays->rx = (vars->py - rays->ry) * rays->aTan + vars->px;
		rays->yo = 64;
		rays->xo = -rays->yo * rays->aTan;
	} 
	if(rays->ra == 0 || rays->ra == PI)
	{
		rays->rx = vars->px;
		rays->ry = vars->py;
		rays->dof= 16;
	}
	while(rays->dof < 16)
	{
		rays->mx = (int)(rays->rx) >> 6;
		rays->my = (int)(rays->ry) >> 6;
		if(rays->mx >= 0 && rays->my >= 0 
			&& rays->mx < vars->map_lenght 
			&& rays->my < vars->map_height 
			&& vars->map[rays->my][rays->mx] == '1')
			rays->dof = 16;
		else
		{
			rays->rx+=rays->xo;
			rays->ry+=rays->yo;
			rays->dof+=1;
		}
	}
	rays->sx = rays->rx;
	rays->sy = rays->ry;
}

void	ft_vertical_line(t_vars *vars, t_rays *rays)
{
	rays->dof = 0;
	rays->nTan = -tan(rays->ra);
	if(rays->ra > P2 && rays->ra < P3)
	{
		rays->rx = (((int)vars->px >> 6) << 6) - 0.0001;
		rays->ry = (vars->px - rays->rx) * rays->nTan + vars->py;
		rays->xo = -64;
		rays->yo = -rays->xo * rays->nTan;
	}
	if(rays->ra < P2 || rays->ra > P3)
	{
		rays->rx = (((int)vars->px >> 6) << 6) + 64;
		rays->ry = (vars->px - rays->rx) * rays->nTan + vars->py;
		rays->xo = 64;
		rays->yo = -rays->xo * rays->nTan;
	} 
	if(rays->ra == 0 || rays->ra == PI)
	{
		rays->rx = vars->px;
		rays->ry = vars->py;
		rays->dof= 16;
	}
	while(rays->dof < 16)
	{
		rays->mx = (int)(rays->rx) >> 6;
		rays->my = (int)(rays->ry) >> 6;
		if(rays->mx >= 0 && rays->my >= 0
			&& rays->mx < vars->map_lenght 
			&& rays->my < vars->map_height 
			&& vars->map[rays->my][rays->mx] == '1')
			rays->dof = 16;
		else
		{
			rays->rx+=rays->xo;
			rays->ry+=rays->yo;
			rays->dof+=1;
		}
	}
	if(ft_dist(vars->px,vars->py,rays->rx,rays->ry) < ft_dist(vars->px,vars->py,rays->sx,rays->sy))
	{
		rays->sx = rays->rx;
		rays->sy = rays->ry;
		rays->color = 0x00FF0000;
	}
	else
		rays->color = 0x00AA0000;
	rays->distT = ft_dist(vars->px,vars->py,rays->sx,rays->sy);
}

void	ft_draw_line(t_vars *vars, t_rays *rays,int line_start, int line_end)
{
	int i;
	int gl_line_width;

	gl_line_width = ((vars->map_lenght + 1) * IMG) / 90;
	i = 0;
	while(line_start < line_end)
	{
		i = 0;
		while(i < gl_line_width)
		{
			my_mlx_pixel_put(vars, ((vars->map_lenght - 1) * IMG) + (rays->r * gl_line_width + i), line_start, rays->color);
			i++;
		}
		line_start++;
	}
}

void	ft_3d_display(t_vars *vars, t_rays *rays)
{
	float	lineH;
	float	line_start;
	float	line_end;
	float	ca;
	
	ca = vars->pa - rays->ra;
	if (ca < 0)
		ca += 2 *PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	rays->distT = rays->distT *cos(ca);
	lineH = (IMG * (IMG * vars->map_height)) / rays->distT;
	if(lineH > (IMG * vars->map_height))
		lineH = (IMG * vars->map_height);
	line_start = ((vars->map_height * IMG) / 2) - (lineH / 2);
	line_end = line_start + lineH;
	ft_draw_line(vars, rays, line_start, line_end);
}

void	ft_ang_rays(t_rays *rays)
{
	if(rays->ra < 0)
		rays->ra += 2 * PI;
	if(rays->ra > 2 * PI)
		rays->ra -= 2 * PI;
}

void	ft_draw_rays(t_vars *vars)
{
	t_rays 	rays;
	
	rays.r = 0;
	rays.ra = vars->pa - DR * 30;
	ft_ang_rays(&rays);
	while(rays.r < 90)
	{
		ft_horizontal_line(vars, &rays);
		ft_vertical_line(vars, &rays);
		ft_draw_ray_hit(vars, &rays, rays.color);
		ft_3d_display(vars, &rays);
		ft_ang_rays(&rays);
		rays.ra += DR;
		rays.r++;
	}
}


void	ft_draw_player(t_vars *vars)
{
	my_mlx_pixel_put(vars, vars->px  - 1, vars->py, 0x00BBCCBB);
	my_mlx_pixel_put(vars, vars->px + 1, vars->py, 0x00BBCCBB);
	my_mlx_pixel_put(vars, vars->px,vars->py -1, 0x00BBCCBB);
	my_mlx_pixel_put(vars, vars->px, vars->py +1, 0x00BBCCBB);
}



void	ft_display(t_vars *vars)
{

	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
								&vars->endian);
	ft_draw_map(vars);
	ft_draw_player(vars);
	ft_draw_rays(vars);
}

int	ft_close_key(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	ft_move_keycode(int keycode, t_vars *vars)
{
	if (keycode ==  65363 || keycode == 'd') // right
	{
		vars->pa += RSPEED;
		if (vars->pa > (2 * PI))
			vars->pa -= (2 * PI);
		vars->pdx=cos(vars->pa) * 5;
		vars->pdy=sin(vars->pa) * 5;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_display(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,0 , 0);
	}
	if (keycode == 65361 || keycode == 'a') // left
	{
		vars->pa -= RSPEED;
		if (vars->pa < 0)
			vars->pa += (2 * PI);
		vars->pdx=cos(vars->pa) * 5;
		vars->pdy=sin(vars->pa) * 5;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_display(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,0 , 0);
	}
	if (keycode == 65364 || keycode == 's') // bottom
	{
		vars->px -= vars->pdx;
		vars->py -= vars->pdy;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_display(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,0 , 0);
	}
	if (keycode == 65362 || keycode == 'w' ) // up
	{
		vars->px += vars->pdx;
		vars->py += vars->pdy;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_display(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,0 , 0);
	}
	if (keycode == 65307)
		ft_close_key(vars);
	return(keycode);
}

void	ft_pars_pos_player(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while(vars->map[y])
	{
		x = 0;
		while(vars->map[y][x])
		{
			if(ft_if_player(vars, y, x))
			{
				if(vars->map[y][x] == 'N')
					vars->pa = PI / 2;
				if(vars->map[y][x] == 'E')
					vars->pa = 0;
				if(vars->map[y][x] == 'W')
					vars->pa = PI;
				if(vars->map[y][x] == 'S')
					vars->pa = 3 * PI / 2;
				vars->pdx=cos(vars->pa) * 5;
				vars->pdy=sin(vars->pa) * 5;
				vars->px = x * IMG + (IMG/2);
				vars->py = y * IMG + (IMG/2);
			}
			x++;
		}
		y++;
	}

}

void	ft_init(t_vars *vars)
{
	ft_pars_pos_player(vars);
}

int	main(int ac, char **argv)
{
	t_vars	vars;

	int fd;
	int i;
	fd = open("map.cub",O_RDWR);
	vars.map = malloc(sizeof(char *) * 11);
	vars.map_height = 11;
	i = 0;
	vars.map[i] = get_next_line(fd);
	vars.map_lenght = ft_strlen(vars.map[i]);
	while(vars.map[i])
	{
		vars.map[i + 1] = get_next_line(fd);
		i++;
	}
	vars.map_height = i - 1;
	ft_init(&vars);
	(void)ac;
	(void)argv;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map_lenght -1) * 2 * IMG, vars.map_height * IMG, "Hello world!");
	ft_display(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_move_keycode, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
}
