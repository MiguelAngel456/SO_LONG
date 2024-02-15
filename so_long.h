/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:22:39 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 16:46:42 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

//LIBRERIAS NECESARIAS
# include <stdarg.h>
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

//LISTAS ENLANZADAS (DATOS DEL MAPA)
typedef struct s_list_map
{
	int				hight; //ALTO
	int				width; //ANCHO
	int				pos_exit_x; //POSICION X DE LA SALIDA
	int				pos_exit_y; //POSICION Y DE LA SALIDA
	char			*arch_map; //CONTENIDO DEL MAPA
	int				pos_herox; //POSICION X DEL HEROE
	int				pos_heroy; //POSICION Y DEL HEROE
	mlx_t			*mlx; //VENTANA
	char			**copied; //COPIA
	int				taked_items; //CANTIDAD DE ITEMS RECOGIDOS
	int				total_items; //CANTIDAD DE ITEMS TOTALES
	int				animation_time; //TURNO DE LA ANIMACION
	int				number_moves; //NUMERO DE MOVIMIENTOS
	mlx_texture_t	*imgDirt; //TIERRA FONDO
	mlx_texture_t	*imgTree; //ARBOLES PARED
	mlx_texture_t	*imgOrc; //PERSONAJE
	mlx_texture_t	*imgOrcM; //PERSONAJE MOVIENDOSE
	mlx_texture_t	*imgSlime; //SLIME
	mlx_texture_t	*imgSlimeM; //SLIME MOVIENDOSE
	mlx_texture_t	*imgMera; //ITEM
	mlx_texture_t	*imgPrinc; //PRINCESA
	mlx_texture_t	*imgPrincM; //PRINCESA DE FRENTE
	}	t_list_map; //APODO


//FUNCIONES
int		check_walls(t_list_map *info_map);
int     check_cant(t_list_map *info_map, int cont_c, int cont_p, int cont_e);
int     check_rectangle(t_list_map *info_map);
void    flood_fill(char **copied, int x, int y);
int     check_path(char **copied, t_list_map *info_map);
void    print_background(t_list_map *info_map, mlx_t *mlx);
void	put_items_map(t_list_map *info_map, mlx_t *mlx);
void	controls_move_normi(t_list_map *info_map);
void	controls(mlx_key_data_t keydata, void* param);
void    item_collected(t_list_map *info_map, int i, int x);
void    item_count(t_list_map *info_map);
void    unlock_exit(t_list_map *info_map);
void	go_exit(t_list_map *info_map);
void	re_print_princes(t_list_map *info_map);
void	controls_move_w(t_list_map *info_map, int posy, int posx);
void	controls_move_a(t_list_map *info_map, int posy, int posx);
void	controls_move_s(t_list_map *info_map, int posy, int posx);
void	controls_move_d(t_list_map *info_map, int posy, int posx);
void    change(t_list_map *info_map, char letra, int i, int j);
void    change_normi(t_list_map *info_map, char letra, int i, int j);
void    free_close(char *line, int fd);
int     check_walls_normi(int row, t_list_map *info_map, char letra, int cont);
void	put_texture(t_list_map *info_map);
void	free_textures(t_list_map *info_map);
void	initialize_list(t_list_map *info_map);
char	**make_copied(t_list_map info_map, int fd);
void	liberar_memoria(char **matr ,t_list_map *info_map);
void	check_errors(t_list_map *info_map, char **copied);
void	help_normi3(t_list_map info_map, mlx_t *mlx, char **copied);
void	free_close(char *line, int fd);
int		check_digit(char **copied, t_list_map *info_map);
void	help_normi1(t_list_map info_map, mlx_t *mlx, char **copied);
void	help_normi2(t_list_map *info_map, char **copied);
#endif