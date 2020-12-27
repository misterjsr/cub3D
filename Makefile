UNAME_S := $(shell uname)

NAME =      cub3D
LIBFT_A =   libft.a
CC = 		@gcc
FLAGS =     -I./includes -Wall -Werror -Wextra -g

ifeq ($(UNAME_S), Darwin)
	MLX = ./mlx/minilibx/libmlx.a
    FLAGSX = -I./⁨usr⁩/⁨local⁩/⁨include -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME_S), Linux)
	MLX = ./mlx/minilibx_linux/libmlx.a
  	FLAGSX = -Lmlx -lmlx -no-pie -lXext -lX11 -lbsd -lm
endif

LIBFT_H =   -I libft/
OBJ_DIR =   objects/
SRC_DIR =   srcs/
LIB_DIR =   libft/

SRC =     main.c \
			get_next_line.c \
			array.c \
			read_file.c \
			parsemap.c \
			init.c \
			draw.c \
			raycasting.c \
			keys.c \
			save.c \
			raysprite.c \
			sprite.c \
			ft_swaps.c \
			img.c \
			textures.c \
			error.c
			
OBJ =       $(addprefix ${OBJ_DIR}, ${SRC:.c=.o})

all:		$(NAME)

$(NAME): 	$(OBJ)
			@echo LIBFT START
			@make -C $(LIB_DIR)
			@echo Copying $(LIBFT_A) to root.
			@cp $(LIB_DIR)$(LIBFT_A) .
			@mv $(LIBFT_A) $(NAME) 
			${CC} ${FLAGS} ${OBJ} -o ${NAME} ./libft/libft.a $(MLX) ${FLAGSX}
			@echo Merged: $(NAME) with $(LIBFT_A)
			@echo CUB3D COMPLETE

$(OBJ_DIR)%.o: ${SRC_DIR}%.c
			@mkdir -p $(OBJ_DIR)
			${CC} ${FLAGS} -o $@ -c $<
        	@echo Create: cub3d Object directory

clean:
			@/bin/rm -rf $(OBJ_DIR)
			@make -C $(LIB_DIR) clean
			@echo Cleaned cubed object files
fclean: clean
			@/bin/rm -rf $(NAME)
			@make -C $(LIB_DIR) fclean
			@echo Cleaned $(NAME)
re: fclean all

.PHONY: all clean fclean re
