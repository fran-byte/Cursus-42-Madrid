# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 21:12:48 by frromero          #+#    #+#              #
#    Updated: 2025/01/18 15:36:49 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Source files
SRCS = 	./src/so_long.c ./src/parse_arguments.c \
		./src/parse_map_items.c ./src/parse_map_wall.c \
		./src/parse_map_playable.c ./src/utils_free_and_open.c \
		./src/parse_map_dimensions.c ./src/parse_map_items_put.c \
		./src/data_exit_game.c ./src/data_init_game.c \
		./src/data_key_press.c ./src/data_move.c ./src/data_render.c

# Paths
LIB = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
DIR_MINILIBX = minilibx-linux

# Compiler
CC = cc

# Flags
# CFLAGS =	-Wall -Wextra -Werror -g3 -I inc -I libft
CFLAGS =	-Wall -Wextra -Werror \
			-fsanitize=address -fsanitize=undefined \
			-g3 -I inc -I libft

# Object files
OBJS = $(SRCS:./src/%.c=./src/%.o)

# Include directory for header files
INCLUDE = ./inc/so_long.h ./inc/so_long_data.h ./minilibx-linux/mlx.h

# External library flags
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

# Default rule to build the program
all: ${NAME}

# Links the object files and creates the executablemake
${NAME}: ${OBJS}
	@$(MAKE) -C libft -s
	@$(MAKE) -C $(DIR_MINILIBX) -s
	@${CC} ${CFLAGS} ${OBJS} $(LIB) $(MINILIBX ) $(MLX_FLAGS) -o ${NAME}
	@echo "\n✨ Created $(NAME) ✨\n"

# Compile .c files into .o files
./src/%.o: ./src/%.c
	@echo "◎ Compiling  → $<"
	@${CC} ${CFLAGS} -c $< -o $@

# Clean up object files
clean:
	@${RM} ${OBJS}
	@${RM} minilibx-linux/obj/*.*
	@echo "\n✨ All objects cleaned successfully  ✨\n"

# Clean up object files, dependencies, and the executable
fclean: clean
	@$(MAKE) -C libft fclean -s
	@$(MAKE) -C $(DIR_MINILIBX) clean -s
	@${RM} ${NAME}
	@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

# Rebuild the program from scratch
re: fclean all

# Mark rules as not corresponding to real files
.PHONY: all clean fclean re
