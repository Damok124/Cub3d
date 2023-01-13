#include "../../includes/fdf.h"

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
				vars->map[y][x] = '0';
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