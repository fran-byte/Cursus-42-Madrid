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

char	*find_and_return_line(char *stored_bff)
{
	int	i;
	char	*line;
	int	ln;

	i = 0;
	ln = 0;
	while (stored_bff[ln] != '\n' && stored_bff[ln] != '\0') //calculamos longitud de line
		ln++;
	if (*stored_bff)
	{
		line = (char *)malloc(ln * sizeof(char) + 1); // reservamos tamaño de line
		if (line == NULL)
			return (free(stored_bff), NULL);
		i = -1;
		while (++i <= ln)
			line[i] = stored_bff[i]; // rellenamos line con longitud stored_bff hasta ln
		line[i] = '\0'; // aplicamos el final de string
		return (line);
	}
	return (free(stored_bff), NULL);
}

char	*swap_delete(char *stored_bff)
{
	int	i;
	int	j;
	char	*swap_temp;

	i = 0;
	j = 0;
	while (stored_bff[i] && stored_bff[i] != '\n')
		i++;
	if (!stored_bff[i++])
	{
		free(stored_bff);
		return (NULL);
	}
	swap_temp = (char *)malloc((ft_strlen(stored_bff) - i + 1) * sizeof(char));
	if (!swap_temp)
		return (free(stored_bff), NULL);
	while (stored_bff[i])
		swap_temp[j++] = stored_bff[i++];
	swap_temp[j] = '\0';
	return (free(stored_bff), swap_temp);
}

char	*read_and_join(char *stored_bff, int fd) //Leer y concatenar en stored_bff
{
	ssize_t		bytes_read;
	char	*read_bff;

	read_bff = (char *)malloc(BUFFER_SIZE + 1);// Reservar espacio para leer BUFFER_SIZE
	if (!read_bff)
		return ( NULL);
	if (!stored_bff)// Inicializar stored_bff como cadena vacía si es NULL
	{
		stored_bff = (char *)malloc(1);
		if (!stored_bff)
			return (free(read_bff), NULL);
		*stored_bff = '\0';
	}
	bytes_read = read(fd, read_bff, BUFFER_SIZE);// Leer hasta BUFFER_SIZE bytes en read_bff
	if (bytes_read <= 0)
	{
		free(read_bff);
		if (bytes_read == 0 && stored_bff[0] != '\0')
			return (stored_bff);// Retornar el contenido acumulado si lo hay
		return (free(stored_bff), NULL);// liberamos y Error o sin contenido en stored_bff
	}
	read_bff[bytes_read] = '\0';// colocamos el fin de string
	stored_bff = special_strjoin_(stored_bff, read_bff);
	return (stored_bff);
}


char	*get_next_line(int fd)
{
	char			*line;
	static char		*stored_bff;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (free(stored_bff), NULL);
	stored_bff = read_and_join(stored_bff, fd);
	if (!stored_bff)
		return (free(stored_bff), NULL);
	line = find_and_return_line(stored_bff);
	stored_bff = swap_delete(stored_bff);
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

