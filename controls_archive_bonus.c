/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_archive_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:18:49 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:38:21 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	controls(mlx_key_data_t keydata, void *param)
{
	t_list_map	*info_map;
	char		**copied;

	info_map = param;
	copied = info_map->copied;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(info_map->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		controls_move_w(info_map, info_map->pos_heroy, info_map->pos_herox);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		controls_move_s(info_map, info_map->pos_heroy, info_map->pos_herox);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		controls_move_a(info_map, info_map->pos_heroy, info_map->pos_herox);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		controls_move_d(info_map, info_map->pos_heroy, info_map->pos_herox);
	unlock_exit(info_map);
}

void	controls_move_w(t_list_map *info_map, int posy, int posx)
{
	char	*nume;

	if (info_map->copied[info_map->pos_heroy - 1][info_map->pos_herox] != '1')
	{
		info_map->number_moves++;
		nume = ft_itoa(info_map->number_moves);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), posx * 64, posy * 64);
		item_collected(info_map, info_map->pos_heroy - 1, info_map->pos_herox);
		if (info_map->pos_herox == info_map->pos_exit_y)
			re_print_princes(info_map);
		info_map->pos_heroy = info_map->pos_heroy - 1;
		info_map->animation_time++;
		controls_move_normi(info_map);
		if (info_map->copied[info_map->pos_heroy][info_map->pos_herox] == 'M')
			mlx_close_window(info_map->mlx);
		go_exit(info_map);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), 1 * 64, 0 * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgTree), 1 * 64, 0 * 64);
		mlx_put_string(info_map->mlx, nume, 80, 10);
		free(nume);
		ft_printf("MOVES: %i\n", info_map->number_moves);
	}
}

void	controls_move_s(t_list_map *info_map, int posy, int posx)
{
	char	*nume;

	if (info_map->copied[info_map->pos_heroy + 1][info_map->pos_herox] != '1')
	{
		info_map->number_moves++;
		nume = ft_itoa(info_map->number_moves);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), posx * 64, posy * 64);
		item_collected(info_map, info_map->pos_heroy + 1, info_map->pos_herox);
		if (info_map->pos_herox == info_map->pos_exit_y)
			re_print_princes(info_map);
		info_map->pos_heroy = info_map->pos_heroy + 1;
		info_map->animation_time++;
		controls_move_normi(info_map);
		if (info_map->copied[info_map->pos_heroy][info_map->pos_herox] == 'M')
			mlx_close_window(info_map->mlx);
		go_exit(info_map);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), 1 * 64, 0 * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgTree), 1 * 64, 0 * 64);
		mlx_put_string(info_map->mlx, nume, 80, 10);
		free(nume);
		ft_printf("MOVES: %i\n", info_map->number_moves);
	}
}

void	controls_move_a(t_list_map *info_map, int posy, int posx)
{
	char	*nume;

	if (info_map->copied[info_map->pos_heroy][info_map->pos_herox - 1] != '1')
	{
		info_map->number_moves++;
		nume = ft_itoa(info_map->number_moves);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), posx * 64, posy * 64);
		item_collected(info_map, info_map->pos_heroy, info_map->pos_herox - 1);
		if (info_map->pos_herox == info_map->pos_exit_y)
			re_print_princes(info_map);
		info_map->pos_herox = info_map->pos_herox - 1;
		info_map->animation_time++;
		controls_move_normi(info_map);
		if (info_map->copied[info_map->pos_heroy][info_map->pos_herox] == 'M')
			mlx_close_window(info_map->mlx);
		go_exit(info_map);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), 1 * 64, 0 * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgTree), 1 * 64, 0 * 64);
		mlx_put_string(info_map->mlx, nume, 80, 10);
		free(nume);
		ft_printf("MOVES: %i\n", info_map->number_moves);
	}
}

void	controls_move_d(t_list_map *info_map, int posy, int posx)
{
	char	*nume;

	if (info_map->copied[info_map->pos_heroy][info_map->pos_herox + 1] != '1')
	{
		info_map->number_moves++;
		nume = ft_itoa(info_map->number_moves);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), posx * 64, posy * 64);
		item_collected(info_map, info_map->pos_heroy, info_map->pos_herox + 1);
		if (info_map->pos_herox == info_map->pos_exit_y)
			re_print_princes(info_map);
		info_map->pos_herox = info_map->pos_herox + 1;
		info_map->animation_time++;
		controls_move_normi(info_map);
		if (info_map->copied[info_map->pos_heroy][info_map->pos_herox] == 'M')
			mlx_close_window(info_map->mlx);
		go_exit(info_map);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt), 1 * 64, 0 * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgTree), 1 * 64, 0 * 64);
		mlx_put_string(info_map->mlx, nume, 80, 10);
		free(nume);
		ft_printf("MOVES: %i\n", info_map->number_moves);
	}
}
