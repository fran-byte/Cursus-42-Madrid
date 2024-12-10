# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 23:08:43 by frromero          #+#    #+#              #
#    Updated: 2024/11/22 22:50:20 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ./src/init_stack.c ./src/init_stackb.c ./src/errors.c ./src/check_in.c \
		./src/ft_atoi.c ./src/ft_lstnew.c ./src/ft_lstadd_front.c \
		./src/ft_lstsize.c ./src/ft_lstlast.c ./src/ft_lstadd_back.c \
		./src/ft_lstclear.c ./src/ft_lstiter.c ./src/ft_lstmap.c \
		./src/ft_lstdelone.c ./src/push_swap.c ./src/sa.c ./src/ra.c \
		./src/rra.c ./src/sb.c ./src/rb.c ./src/rrb.c ./src/rrr.c ./src/ss.c \
		./src/pb.c ./src/pa.c ./src/one_argument.c ./src/ft_calloc.c \
		./src/ft_strlen.c ./src/ft_memset.c

INCLUDE = ./inc/push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@echo "◎ Compiling 👽 → $<"
			@${CC} -c $< -o $@
OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS} $(INCLUDE)
#@${CC} -g  ${SRCS} -o ${NAME}
	@${CC} ${CFLAGS} ${SRCS} ${CFLAGS} -o ${NAME}
	@echo "\nCreated $(NAME) ✓\n"

clean:
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n◎ - ✨ All objects cleaned successfully 🚀 ✨ - ◎\n"

fclean:
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n◎ ✨ Objects and executables cleaned -  Aliens beamed them up and returned home!! ✨  ◎\n"

re: fclean all

.PHONY: all clean fclean re
