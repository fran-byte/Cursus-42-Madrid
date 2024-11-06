/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:59:24 by frromero          #+#    #+#             */
/*   Updated: 2024/11/06 08:27:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *my_line(char *stored)
{
	int i;
	char *line;
	int ln;

	i = 0;
	ln = 0;
	while (stored[ln] != '\n' && stored[ln] != '\0') // calculamos longitud de line
		ln++;
	if (*stored)
	{
		line = (char *)malloc((ln + 1) * sizeof(char) + 1); // reservamos tamaño de line
		if (line == NULL)
			return (free(stored), NULL);
		i = 0;
		while (i <= ln)
		{
			line[i] = stored[i]; // rellenamos line con longitud stored hasta ln
			i++;
		}
		line[i] = '\0'; // aplicamos el final de string
		return (line);
	}
	return (free(stored), NULL);
}

char *re_adj_storage(char *stored)
{
	int i;
	int j;
	char *swap_temp;

	i = 0;
	j = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i++])
	{
		free(stored);
		return (NULL);
	}
	swap_temp = (char *)malloc((ft_strlen(stored) - i + 1) * sizeof(char));
	if (!swap_temp)
		return (NULL);
	while (stored[i])
		swap_temp[j++] = stored[i++];
	swap_temp[j] = '\0';
	return (free(stored), swap_temp);
}
char *initialize_stored(char *stored, char *read_bff)
{
	if (!stored)
	{
		stored = malloc(1);
		if (!stored)
		{
			free(read_bff);
			return (NULL);
		}
		*stored = '\0';
	}
	return (stored);
}

char *read_join(char *stored, int fd) // Leer y concatenar en stored
{
	ssize_t bytes_read;
	char *read_bff;

	read_bff = malloc(BUFFER_SIZE + 1);
	if (!read_bff)
		return (NULL);
	stored = initialize_stored(stored, read_bff);
	if (!stored)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, read_bff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(read_bff);
			if (bytes_read == 0 && stored[0] != '\0')
				return stored;
			return (free(stored), NULL);
		}
		read_bff[bytes_read] = '\0';
		stored = special_strjoin_(stored, read_bff);
		if (ft_strchr(read_bff, '\n'))
			break;
	}
	return (free(read_bff), stored);
}

char *get_next_line(int fd)
{
	char *line;
	static char *stored;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) // truco para saber si el archivo esta disponible para leer
		return (NULL);
	stored = read_join(stored, fd);
	if (!stored)
		return (free(stored), NULL);
	line = my_line(stored);
	stored = re_adj_storage(stored);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("files/42_with_nl", O_RDONLY);
	char *next_line;

	if (fd == -1) {
		printf("Error: no se pudo abrir el archivo.\n");
		free(next_line);
		return (1);
	}
	while ((next_line = get_next_line(fd)) != NULL) {
		printf("%s", next_line);
		free(next_line);
	}
	free(next_line);
	close(fd);
	return (0);
}

// Compilar: cc -g -fsanitize=address -o a.out get_next_line.c get_next_line_utils.c && ./a.out
*/
