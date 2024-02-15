/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_control_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:23:10 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 13:18:20 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	item_count(t_list_map *info_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < info_map->hight)
	{
		j = 0;
		while (j < info_map->width)
		{
			if (info_map->copied[i][j] == 'C')
				info_map->total_items++;
			j++;
		}
		i++;
	}
}

void	item_collected(t_list_map *info_map, int i, int x)
{
	if (info_map->copied[i][x] == 'C')
	{
		info_map->taked_items++;
		info_map->copied[i][x] = '0';
	}
}

void	unlock_exit(t_list_map *info_map)
{
	if (info_map->taked_items == info_map->total_items)
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt),
			info_map->pos_exit_y * 64, info_map->pos_exit_x * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgPrincM),
			info_map->pos_exit_y * 64, info_map->pos_exit_x * 64);
	}
}

void	go_exit(t_list_map *info_map)
{
	if ((info_map->taked_items == info_map->total_items)
		&& (info_map->pos_heroy == info_map->pos_exit_x
			&& info_map->pos_herox == info_map->pos_exit_y))
	{
		mlx_close_window(info_map->mlx);
	}
}

void	re_print_princes(t_list_map *info_map)
{
	if ((info_map->pos_heroy == info_map->pos_exit_x
			&& info_map->pos_herox == info_map->pos_exit_y))
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt),
			info_map->pos_exit_y * 64, info_map->pos_exit_x * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgPrinc),
			info_map->pos_exit_y * 64, info_map->pos_exit_x * 64);
	}
}
