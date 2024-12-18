# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 21:12:48 by frromero          #+#    #+#              #
#    Updated: 2024/12/18 21:11:34 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = pipex

# Define source files
SRCS = ./src/pipex.c ./src/utils.c ./src/get_path.c

# Define object files
OBJS = $(SRCS:.c=.o)

# Define the include directory for header files
INCLUDE = ./inc/pipex.h

# Define the compiler
CC = cc

# Enable common and extra compiler warnings and treat them as errors
CFLAGS = -Wall -Wextra -Werror

# Default rule to build the program
all:	${NAME}

# Compile .c files into .o files
%.o: %.c
	@echo "◎ Compiling 👽 → $<"
	@${CC} -c $< -o $@

# Links the object files and creates the executable
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -g -Llibft -lft -o ${NAME}
	@echo "\n✨ Created $(NAME) ✨\n"

# Clean up object files
clean:
	@${RM} ${OBJS}
	@echo "\n✨ All objects cleaned successfully 🚀 ✨\n"

# Clean up object files, dependencies, and the executable
fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

# Rebuild the program from scratch
re: fclean all

# Mark rules as not corresponding to real files
.PHONY: all clean fclean re
