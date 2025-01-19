/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:35:27 by frromero          #+#    #+#             */
/*   Updated: 2025/01/18 16:38:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

char	*special_strjoin_(char *read_bff, char *stored);
char	*my_line(char *stored);
char	*initialize_stored(char *stored, char *read_bff);
char	*read_join(char *stored, int fd);
char	*re_adj_storage(char *stored);
char	*get_next_line(int fd);
#endif
