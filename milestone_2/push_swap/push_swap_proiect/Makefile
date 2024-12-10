# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 23:08:43 by frromero          #+#    #+#              #
#    Updated: 2024/12/10 21:04:54 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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
	@echo "\n✨ Created $(NAME) ✨\n"

clean:
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n✨ All objects cleaned successfully 🚀 ✨\n"

fclean:
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@${RM} ${NAME}
			@echo "\n✨ 🚀 Objects and executables cleaned ✨\n"

re: fclean all

.PHONY: all clean fclean re
