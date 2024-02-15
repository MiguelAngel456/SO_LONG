/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chequers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:13:42 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:19:32 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ARCHIVO ENCARGADO DE COMPROBAR QUE EEL MAPA SEA CORRECTO
#include "./so_long_bonus.h"

int	check_rectangle(t_list_map *info_map)
{
	int		fd;
	char	*line;
	size_t	row;
	size_t	length;

	fd = open(info_map->arch_map, O_RDONLY);
	line = get_next_line(fd);
	length = ft_strlen(line);
	row = 0;
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	free_close(line, fd);
	if ((length - 1) == row)
		return (0);
	return (1);
}

int	check_path(char **copied, t_list_map *info_map)
{
	int		cont;
	int		i;
	int		cont_v;

	i = 0;
	cont_v = 0;
	while (i != info_map->hight)
	{
		cont = 0;
		while (copied[i][cont] != '\0')
		{
			if (copied[i][cont] == 'P' || copied[i][cont] == 'E'
				|| copied[i][cont] == 'C')
				cont_v++;
			cont++;
		}
		i++;
	}
	if (cont_v != 0)
		return (1);
	return (0);
}

int	check_digit(char **copied, t_list_map *info_map)
{
	int		cont;
	int		i;
	int		cont_v;

	i = 0;
	cont_v = 0;
	while (i != info_map->hight)
	{
		cont = 0;
		while (copied[i][cont] != '\0')
		{
			if (copied[i][cont] != 'P' && copied[i][cont] != 'E'
				&& copied[i][cont] != 'C' && copied[i][cont] != '1'
				&& copied[i][cont] != '0' && copied[i][cont] != 'M')
				return (1);
			cont++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **copied, int x, int y)
{
	if (copied[y][x] == '1' || copied[y][x] == 'F' || copied[y][x] == 'M')
	{
		return ;
	}
	copied[y][x] = 'F';
	flood_fill(copied, x - 1, y);
	flood_fill(copied, x + 1, y);
	flood_fill(copied, x, y + 1);
	flood_fill(copied, x, y - 1);
}
