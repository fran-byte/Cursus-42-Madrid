/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-22 14:35:46 by frromero          #+#    #+#             */
/*   Updated: 2024-10-22 14:35:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 70

char	*get_next_line(int fd)
{
	char *buffer;
	int bytes_read;
	char *line;
	char * temp;
	int 	i;

	i=0;

	if (fd == -1)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);  // Devuelve NULL si no se leen más datos (EOF o error)
	}
	while (buffer[i] != '\n' && i <= strlen(buffer))
	{
		printf(". %c\n",buffer[i]);
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp = (char *)malloc((i) * sizeof(char));
		while (i >=0)
		{
			temp[i] = buffer[i];
			i--;
		}
		free (buffer);
	}

	//buffer[bytes_read] = '\0';  // terminar el buffer con un nulo

	line = temp;
	return (line);

}

int main(void) {
    int fd;
    char *next_line;
    int count = 0;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error: no se pudo abrir el archivo.\n");
        return 1;
    }

    // Bucle para leer todas las líneas del archivo
    while ((next_line = get_next_line(fd)) != NULL) {
        count++;
        printf("[%d]: %s", count, next_line);  // Mostrar la línea leída

    }
    free(next_line);  // Liberar la línea después de usarla
    close(fd);  // Cerrar el archivo
    return 0;   // Finalizar el programa
}
