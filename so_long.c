/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:20:14 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 16:53:09 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks so_long > leaks.txt");
}

void	free_close(char *line, int fd)
{
	free(line);
	close(fd);
}

void	liberar_memoria(char **matr, t_list_map *info_map)
{
	int	i;

	i = 0;
	if (matr == NULL)
		return ;
	while (i != info_map->hight)
	{
		free(matr[i]);
		i++;
	}
	free(matr);
}

void	size_map(t_list_map *info_map)
{
	int		fd;
	char	*line;

	fd = open(info_map->arch_map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("ERROR\nMAPA NO LEIBLE");
		free(line);
		exit (EXIT_FAILURE);
	}
	info_map->width = ft_strlen(line) - 1;
	info_map->hight = 0;
	while (line)
	{
		if ((int)(ft_strlen(line) - 1) != info_map->width)
		{
			ft_printf("ERROR\nMAPA NO VALIDO");
			exit (EXIT_FAILURE);
		}
		info_map->hight++;
		free(line);
		line = get_next_line(fd);
	}
	free_close(line, fd);
}

int	main(int argc, char **argv)
{
	char		**copied;
	mlx_t		*mlx;
	t_list_map	info_map;

	if ((argc - 1) == 1)
	{
		atexit(ft_leaks);
		info_map.arch_map = argv[1];
		size_map(&info_map);
		mlx = NULL;
		copied = make_copied(info_map, open(info_map.arch_map, O_RDONLY));
		if (check_walls(&info_map) == 1 && check_cant(&info_map, 0,
				0, 0) != 4 && check_rectangle(&info_map) != 0
			&& check_digit(copied, &info_map) == 0)
		{
			help_normi3(info_map, mlx, copied);
		}
		else
			check_errors(&info_map, copied);
		exit(0);
		free(copied);
	}
	return (0);
}
