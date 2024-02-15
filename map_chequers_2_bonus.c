/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chequers_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:13:42 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 13:18:13 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ARCHIVO ENCARGADO DE COMPROBAR QUE EEL MAPA SEA CORRECTO
#include "./so_long_bonus.h"

int	check_walls(t_list_map *info_map)
{
	int		fd;
	char	*line;
	int		cont;
	int		row;
	int		result;

	fd = open(info_map->arch_map, O_RDONLY);
	line = get_next_line(fd);
	row = 1;
	result = 1;
	while (line)
	{
		cont = 0;
		while (cont < info_map->width)
		{
			if (check_walls_normi(row, info_map, line[cont], cont) == 0)
				return (0);
			cont++;
		}
		row++;
		free(line);
		line = get_next_line(fd);
	}
	free_close(line, fd);
	return (1);
}

int	check_walls_normi(int row, t_list_map *info_map, char letra, int cont)
{
	if ((row == 1 || row == info_map->hight) && (letra != '1'))
		return (0);
	if ((row != 1 && row != info_map->hight)
		&& (cont == 0 || cont == (info_map->width - 1))
		&& (letra != '1'))
		return (0);
	return (1);
}

int	check_cant(t_list_map *info_map, int cont_c, int cont_p, int cont_e)
{
	int		fd;
	char	*line;
	int		cont;

	fd = open(info_map->arch_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		cont = 0;
		while ((cont++) < info_map->width)
		{
			if (line[cont] == 'E')
				cont_e++;
			if (line[cont] == 'P')
				cont_p++;
			if (line[cont] == 'C')
				cont_c++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free_close(line, fd);
	if (cont_p != 1 || cont_e != 1 || cont_c <= 0)
		return (4);
	return (1);
}
