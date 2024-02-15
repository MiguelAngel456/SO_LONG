/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:52:25 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 11:46:53 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_background(t_list_map *info_map, mlx_t *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < info_map->hight)
	{
		j = 0;
		while (j < info_map->width)
		{
			mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
					info_map->imgDirt), j * 64, i * 64);
			j++;
		}
		i++;
	}
}

static void	put_items_map_normi(mlx_t *mlx, t_list_map *info_map, int i, int j)
{
	if (info_map->copied[i][j] == '1')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
				info_map->imgTree), j * 64, i * 64);
	else if (info_map->copied[i][j] == 'P')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
				info_map->imgOrc), j * 64, i * 64);
	else if (info_map->copied[i][j] == 'C')
	{
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
				info_map->imgMera), j * 64, i * 64);
	}
	else if (info_map->copied[i][j] == 'E')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx,
				info_map->imgPrinc), j * 64, i * 64);
}

void	put_items_map(t_list_map *info_map, mlx_t *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < info_map->hight)
	{
		j = 0;
		while (j < info_map->width)
		{
			put_items_map_normi(mlx, info_map, i, j);
			j++;
		}
		i++;
	}
}
