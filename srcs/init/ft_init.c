#include "cub3D.h"

void	ft_init(t_context *context)
{
	t_data *tmp_view;
	t_data *tmp_knife;

	tmp_view = &context->vars.view;
	tmp_knife = &context->vars.knife;
	
	context->vars.mlx = mlx_init();
	context->vars.win = mlx_new_window(context->vars.mlx, WINDOW_WIDTH , WINDOW_HEIGHT, "Hello world!");

	context->vars.key.a = 0;
	context->vars.key.w = 0;
	context->vars.key.s = 0;
	context->vars.key.d = 0;

	context->vars.view.img = NULL;
	context->vars.view.img_xmp = NULL;
	context->vars.view.bits_per_pixel = 0;
	context->vars.view.endian = 0;
	context->vars.view.addr = NULL;
	context->vars.view.line_length = 0;
	context->vars.knife.img = NULL;
	context->vars.knife.img_xmp = NULL;
	context->vars.knife.bits_per_pixel = 0;
	context->vars.knife.endian = 0;
	context->vars.knife.addr = NULL;
	context->vars.knife.line_length = 0;

	context->vars.key.weapon = 0;
	context->vars.map_height = 14;
	context->vars.map_lenght = ft_strlen(context->map[0]);
	context->vars.map = context->map;
	ft_pars_pos_player(&context->vars, context->player_orient);


	tmp_view->img = mlx_new_image(context->vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	tmp_view->addr = mlx_get_data_addr(tmp_view->img, &tmp_view->bits_per_pixel, &tmp_view->line_length,
						&tmp_view->endian);
	tmp_knife->img_xmp = mlx_xpm_file_to_image(context->vars.mlx, "img/knife_one", &tmp_knife->width, &tmp_knife->height);
	tmp_knife->img = mlx_new_image(context->vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	tmp_knife->addr = mlx_get_data_addr(tmp_knife->img, &tmp_knife->bits_per_pixel, &tmp_knife->line_length,
						&tmp_knife->endian);
}
