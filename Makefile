NAME = cub3D

LIBFT = libft/libft.a

LIBFT_PRINTF = ft_printf/libft_printf.a

LIBMLX = mlx/libmlx.a

SRCSDIR = ./srcs/

SRCSDIR_BONUS = ./srcs_bonus/

SRCS = \
${SRCSDIR}ft_angle_adjustement.c \
${SRCSDIR}ft_distance.c \
${SRCSDIR}ft_mlx_pixel_put.c \
${SRCSDIR}ft_right_color_from_xpm.c \
${SRCSDIR}ft_left_color_from_xpm.c \
${SRCSDIR}ft_get_color_from_xpm.c \
${SRCSDIR}ft_get_wall_color.c \
${SRCSDIR}ft_print_type.c \
${SRCSDIR}ft_print_column.c \
${SRCSDIR}ft_3d_display.c \
${SRCSDIR}ft_ray_impact_wall.c \
${SRCSDIR}ft_deep_of_view_explorer.c \
${SRCSDIR}ft_parallel_axis.c \
${SRCSDIR}ft_h_not_parallel_axis.c \
${SRCSDIR}ft_v_not_parallel_axis.c \
${SRCSDIR}ft_horizontal_axis_intersection.c \
${SRCSDIR}ft_vertical_axis_intersection.c \
${SRCSDIR}ft_wall_identification.c \
${SRCSDIR}ft_draw_environment.c \
${SRCSDIR}ft_rotation.c \
${SRCSDIR}ft_map_wall.c \
${SRCSDIR}ft_foreward_backward.c \
${SRCSDIR}ft_left_right.c \
${SRCSDIR}ft_keyboard_interactions.c \
${SRCSDIR}ft_draw_ceilling.c \
${SRCSDIR}ft_draw_floor.c \
${SRCSDIR}ft_cub3d.c \
${SRCSDIR}ft_click_cross.c \
${SRCSDIR}ft_hold_key.c \
${SRCSDIR}ft_release_key.c \
${SRCSDIR}ft_hooks_activation.c \
${SRCSDIR}ft_if_player_here.c \
${SRCSDIR}ft_get_first_angle.c \
${SRCSDIR}ft_get_player_position.c \
${SRCSDIR}ft_init_keys.c \
${SRCSDIR}ft_init_vars.c \
${SRCSDIR}ft_set_texture.c \
${SRCSDIR}ft_get_textures_paths.c \
${SRCSDIR}ft_get_full_textures.c \
${SRCSDIR}ft_get_vars.c \
${SRCSDIR}ft_file_lines_counter.c \
${SRCSDIR}ft_potential_map_line.c \
${SRCSDIR}ft_strs_are_digits.c \
${SRCSDIR}ft_atoi_rgb_safe.c \
${SRCSDIR}ft_check_valid_fc.c \
${SRCSDIR}ft_check_valid_nswe.c \
${SRCSDIR}ft_check_valid_animation.c \
${SRCSDIR}ft_check_valid_door.c \
${SRCSDIR}ft_type_specifier.c \
${SRCSDIR}ft_define_line_type.c \
${SRCSDIR}ft_fill_content.c \
${SRCSDIR}ft_init_content.c \
${SRCSDIR}ft_init_t_textures.c \
${SRCSDIR}ft_init_t_context.c \
${SRCSDIR}ft_unset_content.c \
${SRCSDIR}ft_just_enough_surfaces.c \
${SRCSDIR}ft_enough_paths_err_no.c \
${SRCSDIR}ft_just_enough_paths.c \
${SRCSDIR}ft_one_last_map.c \
${SRCSDIR}ft_only_one_position.c \
${SRCSDIR}ft_check_one_texture.c \
${SRCSDIR}ft_check_duplicates.c \
${SRCSDIR}ft_check_format_punctuation.c \
${SRCSDIR}ft_check_format_textures.c \
${SRCSDIR}ft_check_type_in_content.c \
${SRCSDIR}ft_check_garbage.c \
${SRCSDIR}ft_check_content.c \
${SRCSDIR}ft_get_greatest_len.c \
${SRCSDIR}ft_line_to_standard.c \
${SRCSDIR}ft_spotted_spaces.c \
${SRCSDIR}ft_add_empty_line_to_map.c \
${SRCSDIR}ft_square_shaped_dotted_map.c \
${SRCSDIR}ft_get_map_size.c \
${SRCSDIR}ft_get_map.c \
${SRCSDIR}ft_check_if_flawless.c \
${SRCSDIR}ft_get_rgb.c \
${SRCSDIR}ft_get_player_orientation.c \
${SRCSDIR}ft_destroy_ani_context.c \
${SRCSDIR}ft_unset_context.c \
${SRCSDIR}ft_cub3d_bonus_parsing.c \
${SRCSDIR}ft_print_cub3d_error_2.c \
${SRCSDIR}ft_print_cub3d_error_1.c \
${SRCSDIR}ft_destroy_img_safely.c \
${SRCSDIR}ft_unset_vars.c \
${SRCSDIR}ft_init_cub3d.c \
${SRCSDIR}main.c

SRCS_BONUS = \
${SRCSDIR_BONUS}ft_angle_adjustement_bonus.c \
${SRCSDIR_BONUS}ft_distance_bonus.c \
${SRCSDIR_BONUS}ft_mlx_pixel_put_bonus.c \
${SRCSDIR_BONUS}ft_right_color_from_xpm_bonus.c \
${SRCSDIR_BONUS}ft_left_color_from_xpm_bonus.c \
${SRCSDIR_BONUS}ft_get_color_from_xpm_bonus.c \
${SRCSDIR_BONUS}ft_get_wall_color_bonus.c \
${SRCSDIR_BONUS}ft_print_type_bonus.c \
${SRCSDIR_BONUS}ft_print_column_bonus.c \
${SRCSDIR_BONUS}ft_3d_display_bonus.c \
${SRCSDIR_BONUS}ft_ray_impact_wall_bonus.c \
${SRCSDIR_BONUS}ft_deep_of_view_explorer_bonus.c \
${SRCSDIR_BONUS}ft_parallel_axis_bonus.c \
${SRCSDIR_BONUS}ft_h_not_parallel_axis_bonus.c \
${SRCSDIR_BONUS}ft_v_not_parallel_axis_bonus.c \
${SRCSDIR_BONUS}ft_horizontal_axis_intersection_bonus.c \
${SRCSDIR_BONUS}ft_vertical_axis_intersection_bonus.c \
${SRCSDIR_BONUS}ft_wall_identification_bonus.c \
${SRCSDIR_BONUS}ft_minimap_pixel_put_bonus.c \
${SRCSDIR_BONUS}ft_confirm_wall_type_bonus.c \
${SRCSDIR_BONUS}ft_animate_frames_bonus.c \
${SRCSDIR_BONUS}ft_draw_environment_bonus.c \
${SRCSDIR_BONUS}ft_pixel_around_impacts_bonus.c \
${SRCSDIR_BONUS}ft_draw_ray_hit_bonus.c \
${SRCSDIR_BONUS}ft_draw_rays_minimap_bonus.c \
${SRCSDIR_BONUS}ft_put_pixel_around_bonus.c \
${SRCSDIR_BONUS}ft_draw_player_bonus.c \
${SRCSDIR_BONUS}ft_draw_square_minimap_bonus.c \
${SRCSDIR_BONUS}ft_draw_minispaces_bonus.c \
${SRCSDIR_BONUS}ft_init_minitools_bonus.c \
${SRCSDIR_BONUS}ft_put_minimap_on_display_bonus.c \
${SRCSDIR_BONUS}ft_draw_miniwalls_bonus.c \
${SRCSDIR_BONUS}ft_draw_minimap_bonus.c \
${SRCSDIR_BONUS}ft_mouse_interactions_bonus.c \
${SRCSDIR_BONUS}ft_rotation_bonus.c \
${SRCSDIR_BONUS}ft_map_wall_bonus.c \
${SRCSDIR_BONUS}ft_foreward_backward_bonus.c \
${SRCSDIR_BONUS}ft_left_right_bonus.c \
${SRCSDIR_BONUS}ft_collision_bonus.c \
${SRCSDIR_BONUS}ft_putchar_on_map_bonus.c \
${SRCSDIR_BONUS}ft_open_door_bonus.c \
${SRCSDIR_BONUS}ft_close_door_bonus.c \
${SRCSDIR_BONUS}ft_map_door_bonus.c \
${SRCSDIR_BONUS}ft_keyboard_interactions_bonus.c \
${SRCSDIR_BONUS}ft_draw_ceilling_bonus.c \
${SRCSDIR_BONUS}ft_draw_floor_bonus.c \
${SRCSDIR_BONUS}ft_player_around_bonus.c \
${SRCSDIR_BONUS}ft_cub3d_bonus.c \
${SRCSDIR_BONUS}ft_click_cross_bonus.c \
${SRCSDIR_BONUS}ft_hold_key_bonus.c \
${SRCSDIR_BONUS}ft_release_key_bonus.c \
${SRCSDIR_BONUS}ft_hooks_activation_bonus.c \
${SRCSDIR_BONUS}ft_if_player_here_bonus.c \
${SRCSDIR_BONUS}ft_get_first_angle_bonus.c \
${SRCSDIR_BONUS}ft_get_player_position_bonus.c \
${SRCSDIR_BONUS}ft_init_keys_bonus.c \
${SRCSDIR_BONUS}ft_set_minimap_bonus.c \
${SRCSDIR_BONUS}ft_init_minimap_bonus.c \
${SRCSDIR_BONUS}ft_init_vars_bonus.c \
${SRCSDIR_BONUS}ft_set_texture_bonus.c \
${SRCSDIR_BONUS}ft_get_textures_paths_bonus.c \
${SRCSDIR_BONUS}ft_set_animated_texture_bonus.c \
${SRCSDIR_BONUS}ft_check_animated_texture_bonus.c \
${SRCSDIR_BONUS}ft_get_full_textures_bonus.c \
${SRCSDIR_BONUS}ft_total_frames_bonus.c \
${SRCSDIR_BONUS}ft_get_vars_bonus.c \
${SRCSDIR_BONUS}ft_file_lines_counter_bonus.c \
${SRCSDIR_BONUS}ft_potential_map_line_bonus.c \
${SRCSDIR_BONUS}ft_strs_are_digits_bonus.c \
${SRCSDIR_BONUS}ft_atoi_rgb_safe_bonus.c \
${SRCSDIR_BONUS}ft_check_valid_fc_bonus.c \
${SRCSDIR_BONUS}ft_check_valid_nswe_bonus.c \
${SRCSDIR_BONUS}ft_check_valid_animation_bonus.c \
${SRCSDIR_BONUS}ft_check_valid_door_bonus.c \
${SRCSDIR_BONUS}ft_type_specifier_bonus.c \
${SRCSDIR_BONUS}ft_define_line_type_bonus.c \
${SRCSDIR_BONUS}ft_fill_content_bonus.c \
${SRCSDIR_BONUS}ft_init_content_bonus.c \
${SRCSDIR_BONUS}ft_init_t_textures_bonus.c \
${SRCSDIR_BONUS}ft_get_animation_len_bonus.c \
${SRCSDIR_BONUS}ft_get_animated_textures_bonus.c \
${SRCSDIR_BONUS}ft_init_ani_textures_bonus.c \
${SRCSDIR_BONUS}ft_init_t_context_bonus.c \
${SRCSDIR_BONUS}ft_unset_content_bonus.c \
${SRCSDIR_BONUS}ft_just_enough_surfaces_bonus.c \
${SRCSDIR_BONUS}ft_enough_paths_err_no_bonus.c \
${SRCSDIR_BONUS}ft_just_enough_paths_bonus.c \
${SRCSDIR_BONUS}ft_one_last_map_bonus.c \
${SRCSDIR_BONUS}ft_only_one_position_bonus.c \
${SRCSDIR_BONUS}ft_check_one_texture_bonus.c \
${SRCSDIR_BONUS}ft_check_duplicates_bonus.c \
${SRCSDIR_BONUS}ft_check_format_punctuation_bonus.c \
${SRCSDIR_BONUS}ft_check_format_textures_bonus.c \
${SRCSDIR_BONUS}ft_check_format_ani_textures_bonus.c \
${SRCSDIR_BONUS}ft_check_type_in_content_bonus.c \
${SRCSDIR_BONUS}ft_check_ani_consistency_bonus.c \
${SRCSDIR_BONUS}ft_check_door_consistency_bonus.c \
${SRCSDIR_BONUS}ft_check_ani_textures_bonus.c \
${SRCSDIR_BONUS}ft_check_door_textures_bonus.c \
${SRCSDIR_BONUS}ft_check_garbage_bonus.c \
${SRCSDIR_BONUS}ft_check_content_bonus.c \
${SRCSDIR_BONUS}ft_get_greatest_len_bonus.c \
${SRCSDIR_BONUS}ft_line_to_standard_bonus.c \
${SRCSDIR_BONUS}ft_spotted_spaces_bonus.c \
${SRCSDIR_BONUS}ft_add_empty_line_to_map_bonus.c \
${SRCSDIR_BONUS}ft_square_shaped_dotted_map_bonus.c \
${SRCSDIR_BONUS}ft_get_map_size_bonus.c \
${SRCSDIR_BONUS}ft_get_map_bonus.c \
${SRCSDIR_BONUS}ft_check_if_flawless_bonus.c \
${SRCSDIR_BONUS}ft_get_rgb_bonus.c \
${SRCSDIR_BONUS}ft_get_player_orientation_bonus.c \
${SRCSDIR_BONUS}ft_destroy_ani_context_bonus.c \
${SRCSDIR_BONUS}ft_unset_context_animated_bonus.c \
${SRCSDIR_BONUS}ft_unset_context_bonus.c \
${SRCSDIR_BONUS}ft_init_checker_bonus.c \
${SRCSDIR_BONUS}ft_cub3d_bonus_parsing_bonus.c \
${SRCSDIR_BONUS}ft_print_cub3d_error_2_bonus.c \
${SRCSDIR_BONUS}ft_print_cub3d_error_1_bonus.c \
${SRCSDIR_BONUS}ft_destroy_img_safely_bonus.c \
${SRCSDIR_BONUS}ft_destroy_ani_bonus.c \
${SRCSDIR_BONUS}ft_unset_vars_bonus.c \
${SRCSDIR_BONUS}ft_init_cub3d_bonus.c \
${SRCSDIR_BONUS}main_bonus.c

HEADERDIR = includes/

HEADER = cub3D.h

HEADER_BONUS = cub3D_bonus.h

ifdef BONUS
	SRCS = $(SRCS_BONUS)
	HEADER = $(HEADER_BONUS)
endif

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

.c.o:
	@$(CC) $(IFLAG) $(FLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

bonus :
	@make BONUS=1

$(NAME) : $(LIBFT) $(LIBFT_PRINTF)  $(LIBMLX) $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(FLAGS) $(IFLAG) -L./mlx -lmlx -lXext -lX11 -L./libft -lft -L./ft_printf -lft_printf -lm

$(LIBFT_PRINTF) :
	@${MAKE} -sC ft_printf/

$(LIBFT) :
	@${MAKE} -sC libft/

$(LIBMLX) :
	@${MAKE} -sC mlx/

clean :
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@${MAKE} clean -sC ft_printf/
	@${MAKE} clean -sC libft/
	@${MAKE} clean -sC mlx/

fclean : clean
	@rm -f $(NAME)
	@${MAKE} fclean -sC ft_printf/
	@${MAKE} fclean -sC libft/
	@${MAKE} clean -sC mlx/

re : fclean all

bre : fclean bonus

.PHONY : all clean fclean re bonus
