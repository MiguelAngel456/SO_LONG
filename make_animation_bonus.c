/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:12:03 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 18:12:37 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static void	help_normi_animation(t_list_map *info_map, int i, int j)
{
	if (info_map->animation_time % 2 == 0)
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt),
			j * 64, i * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgSlimeM),
			j * 64, i * 64);
	}
	else
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgDirt),
			j * 64, i * 64);
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgSlime),
			j * 64, i * 64);
	}
}

void	change_animation(t_list_map *info_map)
{
	int		i;
	int		j;
	char	**copied;

	i = 0;
	copied = info_map->copied;
	while (i < info_map->hight)
	{
		j = 0;
		while (j < info_map->width)
		{
			change(info_map, copied[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	change(t_list_map *info_map, char letra, int i, int j)
{
	if (info_map->animation_time % 2 == 0)
	{
		if (letra == 'M')
		{
			help_normi_animation(info_map, i, j);
		}
	}
	else
	{
		if (letra == 'M')
		{
			help_normi_animation(info_map, i, j);
		}
	}
}
