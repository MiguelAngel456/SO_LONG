/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:20:01 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:18:02 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	put_texture(t_list_map *info_map)
{
	info_map->imgDirt = mlx_load_png("./assets/environment/Dirt.png");
	info_map->imgTree = mlx_load_png("./assets/environment/Tree.png");
	info_map->imgOrc = mlx_load_png("./assets/orc-png/orc-idle.png");
	info_map->imgSlime = mlx_load_png("./assets/slime-png/slime-idle.png");
	info_map->imgPrinc = mlx_load_png("./assets/female/princes1.png");
	info_map->imgMera = mlx_load_png("./assets/item/mera.png");
}

void	free_textures(t_list_map *info_map)
{
	mlx_delete_texture(info_map->imgDirt);
	mlx_delete_texture(info_map->imgTree);
	mlx_delete_texture(info_map->imgOrc);
	mlx_delete_texture(info_map->imgSlime);
	mlx_delete_texture(info_map->imgPrinc);
	mlx_delete_texture(info_map->imgMera);
}
