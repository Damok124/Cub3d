#include "cub3D.h"

void	my_mlx_pixel_put(t_data *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_color(t_data *vars, int x, int y)
{
	char	*dst;
	int		color;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	ft_draw_line(t_vars *vars, t_rays *rays,int line_start, int line_end)
{
	while(line_start < line_end)
	{
		my_mlx_pixel_put(&vars->view, rays->r, line_start, rays->color);
		line_start++;
	}
}

void	ft_3d_display(t_vars *vars, t_rays *rays)
{
	float	lineH;
	float	line_start;
	float	line_end;
	float	ca;
	float 	ratio;
	ratio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
	
	ca = vars->pa - rays->ra;
	if (ca < 0)
		ca += 2 *PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	rays->distT = rays->distT *cos(ca);
	lineH = ((IMG * (WINDOW_HEIGHT)) / rays->distT) * ratio ;
	if(lineH > (WINDOW_HEIGHT))
		lineH = (WINDOW_HEIGHT);
	line_start = ((WINDOW_HEIGHT) / 2) - (lineH / 2);
	line_end = line_start + lineH;
	ft_draw_line(vars, rays, line_start, line_end);
}
