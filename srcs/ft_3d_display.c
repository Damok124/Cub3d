#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_line(t_vars *vars, t_rays *rays,int line_start, int line_end)
{
	while(line_start < line_end)
	{
			// if(rays->distT < 200)
				my_mlx_pixel_put(vars, ((vars->map_lenght - 1) * IMG) + rays->r, line_start, rays->color);
			// else
				// my_mlx_pixel_put(vars, ((vars->map_lenght - 1) * IMG) + rays->r, line_start, 0x00000000);
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
