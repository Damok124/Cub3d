#include "cub3D.h"

void	ft_draw_player(t_vars *vars)
{
	my_mlx_pixel_put(vars, (vars->px  / SCALING) - 1, vars->py / SCALING, 0x00BBCCBB);
	my_mlx_pixel_put(vars, (vars->px / SCALING) + 1, vars->py/ SCALING, 0x00BBCCBB);
	my_mlx_pixel_put(vars, vars->px / SCALING, (vars->py / SCALING) - 1, 0x00BBCCBB);
	my_mlx_pixel_put(vars, vars->px / SCALING, (vars->py / SCALING) + 1, 0x00BBCCBB);
}

void	ft_draw_ray_hit(t_vars *vars, t_rays *rays, unsigned int color)
{
	my_mlx_pixel_put(vars, rays->sx + 1, rays->sy, color);
	my_mlx_pixel_put(vars, rays->sx - 1, rays->sy, color);
	my_mlx_pixel_put(vars, rays->sx, rays->sy + 1, color);
	my_mlx_pixel_put(vars, rays->sx, rays->sy - 1, color);
}

void	ft_draw_square(t_vars *vars, int y, int x, int color)
{
	int i;
	int j;

	j = 0;
	while(j <= IMG / SCALING)
	{
		i = 0;
		while(i <= IMG / SCALING)
		{
			my_mlx_pixel_put(vars, i + (x * IMG) / SCALING ,j + (y * IMG) / SCALING, color);
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
				ft_draw_square(vars, y, x, 0xFFFFFFFF);
			// else if(vars->map[y][x] == '.')
				// ft_draw_squarre(vars, y, x, 0x00BBEECC);
			else if(vars->map[y][x] == '0')
				ft_draw_square(vars, y, x, 0xFF000000);
			x++;
		}
		y++;
	}
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
		rays->dof= DOF;
	}
	while(rays->dof < DOF)
	{
		rays->mx = (int)(rays->rx) >> 6;
		rays->my = (int)(rays->ry) >> 6;
		if(rays->mx >= 0 && rays->my >= 0 
			&& rays->mx < vars->map_lenght 
			&& rays->my < vars->map_height + 1
			&& rays->my < WINDOW_HEIGHT
			&& rays->mx < WINDOW_WIDTH
			&& vars->map[rays->my][rays->mx] == '1')
			rays->dof = DOF;
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
		rays->dof= DOF;
	}
	while(rays->dof < DOF)
	{
		rays->mx = (int)(rays->rx) >> 6;
		rays->my = (int)(rays->ry) >> 6;
		if(rays->mx >= 0 && rays->my >= 0
			&& rays->mx < vars->map_lenght 
			&& rays->my < vars->map_height + 1
			&& rays->my < WINDOW_HEIGHT
			&& rays->mx < WINDOW_WIDTH
			&& vars->map[rays->my][rays->mx] == '1')
			rays->dof = DOF;
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
		if((int)rays->sx > (int)vars->px) // OUEST
			rays->color = 0xf4c430;
		else
			rays->color = 0x0000FF00;	//EST
	}
	else
	{
		if((int)rays->sy > (int)vars->py) // NORTH
			rays->color = 0x000000FF;
		else
			rays->color = 0x00FF0000;	//SOUTH
	}
	rays->distT = ft_dist(vars->px,vars->py,rays->sx,rays->sy);
}

void	ft_ang_rays(t_rays *rays)
{
	if(rays->ra < 0)
		rays->ra += 2 * PI;
	if(rays->ra > 2 * PI)
		rays->ra -= 2 * PI;
}


void	ft_draw_ceilling(t_context *context)
{
	int x;
	int color;
	int y;
	
	color = (context->ceiling.r << 16) + (context->ceiling.g << 8) + (context->ceiling.b);
	y = 0;
	while(y <  WINDOW_HEIGHT / 2)
	{
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&context->vars, x ,y , color);
			x++;
		}
		y++;
	}
}

void	ft_draw_floor(t_context *context)
{
	int x;
	int color;
	int y;
	
	color = (context->floor.r << 16) + (context->floor.g << 8) + (context->floor.b);
	y = WINDOW_HEIGHT / 2;
	while(y < WINDOW_HEIGHT)
	{
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&context->vars, x ,y , color);
			x++;
		}
		y++;
	}
}
void	ft_draw_rays(t_context *context)
{
	context->vars.rays.r = 0;
	context->vars.rays.ra = context->vars.pa - (DR * 30);
	ft_draw_ceilling(context);	// dessin du plafond
	ft_draw_floor(context); // dessin du sol 
	ft_ang_rays(&context->vars.rays); 
	while(context->vars.rays.r < WINDOW_WIDTH)
	{
		ft_horizontal_line(&context->vars, &context->vars.rays);
		ft_vertical_line(&context->vars, &context->vars.rays);
		// ft_draw_ray_hit(context->vars,&context->vars.rays,0x00FF00);
		ft_3d_display(&context->vars, &context->vars.rays);
		ft_ang_rays(&context->vars.rays);
		context->vars.rays.ra += ((M_PI / 3 /WINDOW_WIDTH));
		context->vars.rays.r++;
	}
}

void	ft_key_input(t_vars *vars)
{
	int xo;
	int	yo;
	int	ipx;
	int	ipx_add_xo;
	int	ipx_sub_xo;
	int	ipy;
	int	ipy_add_yo;
	int	ipy_sub_yo;
	

	if(vars->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if(vars->pdy < 0)
		yo = -20;
	else
		yo = 20;
	ipx = vars->px / 64;
	ipx_add_xo = (vars->px + xo) / 64;
	ipx_sub_xo = (vars->px - xo) / 64;
	ipy = vars->py / 64;
	ipy_add_yo = (vars->py + yo) / 64;
	ipy_sub_yo = (vars->py - yo) / 64;
	if(vars->key.d == 1)
	{
		vars->pa += RSPEED;
		if (vars->pa > (2 * PI))
			vars->pa -= (2 * PI);
		vars->pdx=cos(vars->pa) * SPEED;
		vars->pdy=sin(vars->pa) * SPEED;
	}
	if(vars->key.a == 1)
	{
		vars->pa -= RSPEED;
		if (vars->pa < 0)
			vars->pa += (2 * PI);
		vars->pdx=cos(vars->pa) * SPEED;
		vars->pdy=sin(vars->pa) * SPEED;
	}
	if(vars->key.s == 1)
	{
		if(vars->map[ipy][ipx_sub_xo] == '0')
		vars->px -= vars->pdx;
		if(vars->map[ipy_sub_yo][ipx] == '0')
		vars->py -= vars->pdy;
	}
	if(vars->key.w == 1)
	{
		if(vars->map[ipy][ipx_add_xo] == '0')
			vars->px += vars->pdx;
		if(vars->map[ipy_add_yo][ipx] == '0')
			vars->py += vars->pdy;
	}
}

int	ft_display(t_context *context)
{
	if(context->vars.img)
		mlx_destroy_image(context->vars.mlx, context->vars.img);
	ft_key_input(&context->vars);
	context->vars.img = mlx_new_image(context->vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	context->vars.addr = mlx_get_data_addr(context->vars.img, &context->vars.bits_per_pixel, &context->vars.line_length,
								&context->vars.endian);
	ft_draw_rays(context);
	ft_draw_map(&context->vars);
	ft_draw_player(&context->vars);
	mlx_put_image_to_window(context->vars.mlx, context->vars.win, context->vars.img, 0, 0);
	return (1);
}

