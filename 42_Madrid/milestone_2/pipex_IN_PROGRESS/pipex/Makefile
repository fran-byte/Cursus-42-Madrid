# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 21:12:48 by frromero          #+#    #+#              #
#    Updated: 2024/12/18 16:39:39 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = pipex

# define source files
SRCS = ./src/pipex.c ./src/utils.c

# define header file
INCLUDE = ./inc/pipex.h


# define compiler
CC = cc

# enable common and extra compiler warnings and treat them as errors
CFLAGS = -Wall -Wextra -Werror

# .c files are compiled into .o
%.o: %.c
			@echo "◎ Compiling 👽 → $<"
			@${CC} -c $< -o $@
OBJS = ${SRCS:.c=.o}


# Default rule to build the program
all:	${NAME}

# Links the object files and header files to create the executable
${NAME}: ${OBJS} $(INCLUDE)

#use debugger(-g) flag: @${CC} -g ${CFLAGS} ${SRCS} ${CFLAGS} -o ${NAME}
	@${CC} ${CFLAGS} ${SRCS} ${CFLAGS} -o ${NAME}
	@echo "\n✨ Created $(NAME) ✨\n"

# Cleans up object files and dependencies
clean:
			@${RM} ${OBJS}
			@echo "\n✨ All objects cleaned successfully 🚀 ✨\n"

# Cleans up object files, dependencies, and the executable
fclean:
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

# Rebuilds the program from scratch
re: fclean all

# Marks rules as not corresponding to real files
.PHONY: all clean fclean re
