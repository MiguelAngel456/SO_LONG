/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:49:57 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 17:22:30 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	initialize_list_normi(char letra, int i, int x, t_list_map *info_map)
{
	if (letra == 'E')
	{
		info_map->pos_exit_x = x;
		info_map->pos_exit_y = i;
	}
	if (letra == 'P')
	{
		info_map->pos_heroy = x;
		info_map->pos_herox = i;
	}
}

void	initialize_list(t_list_map *info_map)
{
	int		i;
	int		x;
	char	*line;
	int		fd;

	fd = open(info_map->arch_map, O_RDONLY);
	x = 0;
	line = get_next_line(fd);
	while ((line))
	{
		i = 0;
		while (line[i++] != '\0')
		{
			initialize_list_normi(line[i], i, x, info_map);
		}
		free(line);
		line = get_next_line(fd);
		x++;
	}
	free_close(line, fd);
}

char	**make_copied(t_list_map info_map, int fd)
{
	char	**copied;
	int		i;
	char	*line;
	int		j;

	copied = malloc(sizeof(char *) * info_map.hight);
	i = 0;
	line = get_next_line(fd);
	while (i < info_map.hight)
	{
		j = 0;
		copied[i] = malloc(sizeof(char) * info_map.width + 1);
		while (j < info_map.width)
		{
			copied[i][j] = line[j];
			j++;
		}
		copied[i][j] = '\0';
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free_close(line, fd);
	return (copied);
}
