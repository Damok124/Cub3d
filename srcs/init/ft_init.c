#include "cub3D.h"

void	ft_init(t_context *context)
{
	context->vars.key.a = 0;
	context->vars.key.w = 0;
	context->vars.key.s = 0;
	context->vars.key.d = 0;
	context->vars.map_height = 14;
	context->vars.map_lenght = ft_strlen(context->map[0]);
	context->vars.map = context->map;
	ft_pars_pos_player(&context->vars);
}
