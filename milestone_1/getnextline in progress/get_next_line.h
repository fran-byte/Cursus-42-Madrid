/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:35:27 by frromero          #+#    #+#             */
/*   Updated: 2024/10/31 23:40:13 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  // BORRAR****************************************

#define BUFFER_SIZE 15

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*ft_strjoin(char *read_bff, char *stored_bff);
char	*special_strjoin_(char *read_bff, char *stored);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

int main(void); // ELIMINAR ********************

#endif
