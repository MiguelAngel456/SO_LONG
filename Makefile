#VARIABLES
NAME = so_long
BONUS_NAME = so_long_bonus
CC = gcc -Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
LIBFT_PATH = ./libft
MLX42 = ./MLX42
MLX_LIBFT = ./MLX42/lib/MLX42/MLX42.h 
CCMLX = ./MLX42/libmlx42.a -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
#ARCHIVOS
FILES = so_long.c \
		put_textures.c \
		create_map.c \
		map_chequers.c \
		map_chequers_2.c \
		controls_archive_aux.c \
		controls_archive.c \
		items_control.c \
		help_normi.c \
		initialize_struct.c \

#ARCHIVO DEL BONUS
BONUS_FILES = so_long_bonus.c \
		put_textures_bonus.c \
		create_map_bonus.c \
		map_chequers_bonus.c \
		map_chequers_2_bonus.c \
		controls_archive_aux_bonus.c \
		controls_archive_bonus.c \
		items_control_bonus.c \
		make_animation_bonus.c \
		help_normi_bonus.c \
		initialize_struct_bonus.c \

#CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)
#CREO LOS ARCHIVOS OBJETO DEL BONUS
OBJS_BONUS = $(BONUS_FILES:.c=.o)

#COMPILA LOS ARCHIVOS
#SE ENCARGA DE QUE AGREGAR A LA LIBRERIA .A LOS OBJETOS
all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/mfuente-/.brew/opt/glfw/lib/" -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/mfuente-/.brew/opt/glfw/lib/" -o $(BONUS_NAME)

%.o: %.c
	make -C $(LIBFT_PATH)
	make -C ./MLX42
	$(CC) -I ./so_long_bonus.h -I so_long.h -c $< -o $@

#ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN FT_PRINTF

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean
	make -C ./MLX42 fclean

re: fclean all

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re bonus