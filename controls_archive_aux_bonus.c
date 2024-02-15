/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_archive_aux_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:16:45 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:39:06 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	controls_move_normi(t_list_map *info_map)
{
	if (info_map->animation_time % 2 != 0)
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgOrc),
			info_map->pos_herox * 64, info_map->pos_heroy * 64);
		change_animation(info_map);
	}
	else
	{
		mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
				info_map->imgOrcM),
			info_map->pos_herox * 64, info_map->pos_heroy * 64);
		change_animation(info_map);
	}
}
