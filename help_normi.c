/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_normi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:56:38 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/14 09:42:22 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_normi1(t_list_map info_map, mlx_t *mlx, char **copied)
{
	info_map.total_items = 0;
	info_map.taked_items = 0;
	info_map.mlx = mlx;
	put_texture(&info_map);
	info_map.copied = copied;
	print_background(&info_map, mlx);
	put_items_map(&info_map, mlx);
	item_count(&info_map);
	info_map.number_moves = 0;
	mlx_key_hook(mlx, controls, &info_map);
	mlx_loop(mlx);
	liberar_memoria(info_map.copied, &info_map);
	free_textures(&info_map);
	mlx_terminate(mlx);
}

void	help_normi2(t_list_map *info_map, char **copied)
{
	initialize_list(info_map);
	flood_fill(copied, info_map->pos_herox, info_map->pos_heroy);
	if (check_path(copied, info_map) == 1)
	{
		ft_printf("ERROR\n/*--------------MAPA NO PASABLE--------------*\\\n");
		exit (EXIT_FAILURE);
	}
	ft_printf("/*--------------MAPA PERFECTO--------------*\\\n");
	liberar_memoria(copied, info_map);
}

void	check_errors(t_list_map *info_map, char **copied)
{
	if (check_walls(info_map) != 1)
	{
		ft_printf("ERROR\n/*-------MURO DEL MAPA MAL COMPUESTOS-------*\\\n");
	}
	if (check_cant(info_map, 0, 0, 0) == 4)
	{
		ft_printf("ERROR\n/*-CANT DE PERSONAJE, SALIDA O ITEMS ERRONEA-*\\\n");
	}
	if (check_rectangle(info_map) == 0)
	{
		ft_printf("ERROR\n/*-------EL MAPA NO ES RECTANGULAR-------*\\\n");
	}
	if (check_path(copied, info_map) == 1)
	{
		ft_printf("ERROR\n/*--------------MAPA NO PASABLE-------------*\\\n");
	}
	if (check_digit(copied, info_map) == 1)
	{
		ft_printf("ERROR\n/*--------ELEMENTOS DEL MAPA ERRONEOS--------*\\\n");
	}
	if (check_digit(copied, info_map) == 1)
	{
		ft_printf("ERROR\n/*--------ELEMENTOS DEL MAPA ERRONEOS--------*\\\n");
	}
	exit (EXIT_FAILURE);
}

void	help_normi3(t_list_map info_map, mlx_t *mlx, char **copied)
{
	help_normi2(&info_map, copied);
	info_map.copied = make_copied(info_map,
			open(info_map.arch_map, O_RDONLY));
	mlx = mlx_init(info_map.width * 64,
			info_map.hight * 64, "so_long", true);
	if (mlx == 0)
		exit(EXIT_FAILURE);
	help_normi1(info_map, mlx, copied);
}
