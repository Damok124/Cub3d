#include "../includes/fdf.h"

void	ft_init(t_vars *vars)
{
	vars->key.a = 0;
	vars->key.w = 0;
	vars->key.s = 0;
	vars->key.d = 0;
	ft_pars_pos_player(vars);
}
