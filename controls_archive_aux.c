/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_archive_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:16:45 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:38:54 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	controls_move_normi(t_list_map *info_map)
{
	mlx_image_to_window(info_map->mlx, mlx_texture_to_image(info_map->mlx,
			info_map->imgOrc),
		info_map->pos_herox * 64, info_map->pos_heroy * 64);
}
