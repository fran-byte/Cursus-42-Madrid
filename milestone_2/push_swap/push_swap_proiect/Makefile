# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 23:08:43 by frromero          #+#    #+#              #
#    Updated: 2024/12/11 23:22:28 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = push_swap

# define source files
SRCS = ./src/check.c ./src/check_multiple_args.c ./src/check_one_arg.c \
		./src/check_one_arg_split.c ./src/errors_free_exit.c \
		./src/ft_lstadd_back.c ./src/ft_lstclear.c ./src/ft_lstdelone.c \
		./src/ft_lstiter.c ./src/ft_lstlast.c ./src/ft_lstnew.c \
		./src/ft_lstsize.c ./src/ft_utils_libft.c ./src/ft_utils_atois.c \
		./src/init_stack_mult_args.c ./src/init_stack_one_arg.c \
		./src/mov_ra_rb_rr.c ./src/mov_rra_rrb_rrr.c ./src/mov_sa_sb_pa_pb.c \
		./src/push_swap.c ./src/sort_measure.c ./src/sort_up_to_five.c \
		./src/sorted.c ./src/t_algorithm.c ./src/turkish_adjust_a.c \
		./src/turkish_adjust_b.c ./src/turkish_adjust_top.c \
		./src/turkish_adjust_top_end.c ./src/turkish_algorithm.c


# define header file
INCLUDE = ./inc/push_swap.h

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
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n✨ All objects cleaned successfully 🚀 ✨\n"

# Cleans up object files, dependencies, and the executable
fclean:
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@${RM} ${NAME}
			@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

# Rebuilds the program from scratch
re: fclean all

# Marks rules as not corresponding to real files
.PHONY: all clean fclean re


