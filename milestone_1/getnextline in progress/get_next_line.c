/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:35:46 by frromero          #+#    #+#             */
/*   Updated: 2024/11/01 19:21:03 by frromero         ###   ########.fr       */
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
	while (*stored_bff)
	{
		line = (char *)malloc(ln * sizeof(char) + 1); // reservamos tamaño de line
		if (line == NULL)
			return (NULL);
		i = -1;
		while (++i <= ln)
			line[i] = stored_bff[i]; // rellenamos line con longitud stored_bff hasta ln
		line[i] = '\0'; // aplicamos el final de string
		return (line);
	}
	return (NULL);
}


char	*swap_delete(char *stored_bff)
{
	int 	i;
	char	*swap_temp;
	int	ln;
	int	ln_total;

	ln = 0;
	ln_total = 0;
	while (stored_bff[ln] != '\n') //calculamos longitud de line
		ln++;
	ln_total = ft_strlen(stored_bff); //calculamos longitud de stored_bff
	i = 0;
	swap_temp = (char *)malloc(ln_total * sizeof(char) + 1); // mismo tamaño que el restante stored_bff
	if (swap_temp == NULL)
		return (NULL);
	while (stored_bff[ln] != '\0') // hacemos la copia de la parte restante
	{
		swap_temp[i] = stored_bff [ln + 1];
		i++;
		ln++;
	}
	swap_temp[i] = '\0';
	free (stored_bff);
	return (swap_temp);
}

char	*read_and_join(char *stored_bff, int fd)
{
	int	bytes_read;
	char	*read_bff;

	read_bff = (char *)malloc((BUFFER_SIZE) * sizeof(char) + 1); // Tamaño asinado para read_bff
	//printf("Read_bff = %p\n", read_bff);
	if (read_bff == NULL)
		return (NULL);
	if (stored_bff == NULL)
	{
		stored_bff = (char *)malloc(1 * sizeof(char)); // Inicializar stored_bff como cadena vacía
		if (stored_bff == NULL)
			return (NULL);
	}
	bytes_read = read(fd, read_bff, BUFFER_SIZE); // LEEMOS a read_bff !!!
	if (bytes_read <= 0)
	{
		free(read_bff);
		if (stored_bff[0] == '\0') // Si no hay nada acumulado
		{
			free(stored_bff);
			return (NULL); // Termina la función
		}
		free(stored_bff);
		return (NULL); // REVISAR
	}
	read_bff[bytes_read] = '\0'; // la str de read_buff terminado en nulo
	stored_bff = special_strjoin_(stored_bff, read_bff); // Contatenamos stored_bff+read_bff
	free(read_bff); //liberamos el read_bff que ya no utilizamos
	return (stored_bff);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*stored_bff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stored_bff == NULL) // Si el buffer acumulado no apunta a nada entramos y llamamos a read_and_join
	{
		stored_bff = read_and_join(stored_bff, fd); // aquí ya tenemos la cadena concatenada
		if (stored_bff == NULL) // pero Si el buffer acumulado no apunta:
		{
			free (stored_bff);
			return (NULL);
		}
	}
	while (ft_strchr(stored_bff, '\n') == NULL) // si el stored_buff no está vacio, pero no tiene \n
	{
		stored_bff = read_and_join(stored_bff, fd); //vamos a leer del stored_bff y concatenar hasta obtener un \n
		if (stored_bff == NULL)
		{
			free (stored_bff);
			return (NULL);
		}
	}
	line = find_and_return_line(stored_bff);// vamos a filtar la stored_bff y obtener la línea
	stored_bff = swap_delete(stored_bff);
	if (stored_bff == NULL)
		{
		free (stored_bff);
		return (NULL);
		}
	return (line);
}

/*
#include <fcntl.h>

int main(void) {
	int fd;
	char *next_line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error: no se pudo abrir el archivo.\n");
		return (1);
	}
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line); // Liberar la línea
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	free(next_line); // Liberar la línea
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	free(next_line); // Liberar la línea
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	free(next_line); // Liberar la línea
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	free(next_line); // Liberar la línea
	next_line = get_next_line(fd); // *******************  ESTA LINEA YA NO EXISTE
	printf("%s", next_line); // línea leída
	free(next_line); // Liberar la línea
	close(fd);
	return (0);
}
//cc -fsanitize=leak -static-libsan get_next_line.c  get_next_line_utils.c && ./a.out
*/
