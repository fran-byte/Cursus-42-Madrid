# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 22:41:24 by frromero          #+#    #+#              #
#    Updated: 2025/02/01 15:40:39 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = philo

# Source files
SRCS = 	./src/philo.c ./src/philo_utils.c ./src/philo_start.c \
		./src/philo_monitor_deaths.c ./src/philo_create.c

# Compiler
CC = cc

# Flags
CFLAGS =	-Wall -Wextra -Werror -I inc
#CFLAGS =	-Wall -Wextra -Werror -g3 -I inc
#CFLAGS =	-Wall -Wextra -Werror \
			-fsanitize=address -fsanitize=undefined -g3 -I inc

# Object files
OBJS = $(SRCS:./src/%.c=./src/%.o)

# Include directory for header files
INCLUDE = ./inc/philo.h

# Default rule to build the program
all: ${NAME}

# Links the object files and creates the executablemake
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "\n✨ Created $(NAME) ✨\n"

# Compile .c files into .o files
./src/%.o: ./src/%.c
	@echo "◎ Compiling  → $<"
	@${CC} ${CFLAGS} -c $< -o $@

# Clean up object files
clean:
	@${RM} ${OBJS}
	@echo "\n✨ All objects cleaned successfully  ✨\n"

# Clean up object files, dependencies, and the executable
fclean: clean
	@${RM} ${NAME}
	@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

# Rebuild the program from scratch
re: fclean all

# Mark rules as not corresponding to real files
.PHONY: all clean fclean re
