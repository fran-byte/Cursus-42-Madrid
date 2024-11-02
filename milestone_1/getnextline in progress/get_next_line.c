/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:59:24 by frromero          #+#    #+#             */
/*   Updated: 2024/11/02 17:54:12 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_line(char *stored)
{
	int	i;
	char	*line;
	int	ln;

	i = 0;
	ln = 0;
	while (stored[ln] != '\n' && stored[ln] != '\0') //calculamos longitud de line
		ln++;
	if (*stored_bff)
	{
		line = (char *)malloc(ln * sizeof(char) + 1); // reservamos tamaño de line
		if (line == NULL)
			return (free(stored), NULL);
		i = -1;
		while (++i <= ln)
			line[i] = stored[i]; // rellenamos line con longitud stored hasta ln
		line[i] = '\0'; // aplicamos el final de string
		return (line);
	}
	return (free(stored), NULL);
}

char	*adj_storage(char *stored)
{
	int	i;
	int	j;
	char	*swap_temp;

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
		return (free(stored), NULL);
	while (stored[i])
		swap_temp[j++] = stored[i++];
	swap_temp[j] = '\0';
	return (free(stored), swap_temp);
}

char	*trim_line(char *stored, int fd) //Leer y concatenar en stored
{
	ssize_t		bytes_read;
	char	*read_bff;

	read_bff = (char *)malloc(BUFFER_SIZE + 1);// Reservar espacio para leer BUFFER_SIZE
	if (!read_bff)
		return ( NULL);
	if (!stored)// Inicializar stored como cadena vacía si es NULL
	{
		stored = (char *)malloc(1);
		if (!stored)
			return (free(read_bff), NULL);
		*stored = '\0';
	}
	bytes_read = read(fd, read_bff, BUFFER_SIZE);// Leer hasta BUFFER_SIZE bytes en read_bff
	if (bytes_read <= 0)
	{
		free(read_bff);
		if (bytes_read == 0 && stored[0] != '\0')
			return (stored);// Retornar el contenido acumulado si lo hay
		return (free(stored), NULL);// liberamos y Error o sin contenido en stored
	}
	read_bff[bytes_read] = '\0';// colocamos el fin de string
	stored = special_strjoin_(stored, read_bff);
	return (stored);
}


char	*get_next_line(int fd)
{
	char			*line;
	static char		*stored;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (free(stored), NULL);
	stored = trim_line(stored, fd);
	if (!stored)
		return (free(stored), NULL);
	line = get_line(stored);
	stored = adj_storage(stored);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
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
	close(fd);
	return (0);
}
*/
// Compilar: cc -fsanitize=leak -static-libsan get_next_line.c get_next_line_utils.c && ./a.out

