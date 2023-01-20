#include "cub3D.h"

float	ft_get_begin_angle(char orientation)
{
	float	ret;

	if (orientation == 'N')
		ret = PI / 2;
	if (orientation == 'E')
		ret = 0;
	if (orientation == 'W')
		ret = PI;
	if (orientation == 'S')
		ret = 3 * PI / 2;
	return (ret);
}

void	ft_pars_pos_player(t_vars *vars, char orientation)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (ft_if_player(vars, y, x))
			{
				vars->pa = ft_get_begin_angle(orientation);
				vars->map[y][x] = '0';
				vars->pdx = cos(vars->pa) * 5;
				vars->pdy = sin(vars->pa) * 5;
				vars->px = x * IMG + (IMG / 2);
				vars->py = y * IMG + (IMG / 2);
			}
		}
	}
}
