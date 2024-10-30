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

#include "get_next_line.h"


char	*find_and_return_line( char *stored_bff, int c, int *ptr_n)
{
	int	i;
	char *line;

	i = 0;
	while(*stored_bff)
	{
		if (stored_bff[i] == (char)c) //  i será el tamaño de line
		{
			line = (char *)malloc(i * sizeof(char)+1); // reservamos solo el tamaño de line
					 // lo llenamos de ceros y colocamos el fin de linea \n
			i = 0;
			while (stored_bff[i] != '\n')
			{
				line[i] = stored_bff[i]; // rellenamos line con stored_bff(la str concatenada) hasta
								// completar line, el final de line es donde estará el \n
				i++;
			}
			line[i] = '\n'; // Acoplamos el final de linea.
			*ptr_n = *ptr_n + i + 1;
			return (line);
		}
		i++;
	}
	return (NULL);
}
char	*swap_delete(char *stored_bff, int ptr_n)
{
	int 	j;
	char	*swap_temp;

	j = 0;
	swap_temp = (char *)malloc((ft_strlen(stored_bff) - ptr_n + 1) * sizeof(char)); // mismo tamaño que stored_bff
	if (!swap_temp)
		return NULL;
	while (stored_bff[ptr_n] != '\0') // hacemos la copia
	{
		swap_temp[j] = stored_bff [ptr_n];
		j++;
		ptr_n++;
	}
	swap_temp[j] = '\0';
	free (stored_bff);
	return (swap_temp);
}
char	*read_buffer(char *stored_bff, int fd)
{
	int bytes_read;
	char *read_bff;

		read_bff = (char *)malloc((BUFFER_SIZE) * sizeof(char) + 1); // Tamaño asinado para read_bff
		if (!read_bff)
			return (NULL);
		if (!stored_bff)
				stored_bff =(char *)malloc(1 * sizeof(char)); // Inicializar stored_bff como cadena vacía
		bytes_read = read(fd, read_bff, BUFFER_SIZE); // LEEMOS a buffer !!!
		if (bytes_read <= 0)
		{
			free(read_bff);
			if (stored_bff && stored_bff[0] == '\0') // Si no hay nada acumulado
			{
                //free(stored_bff);
                return NULL; // Termina la función
			}
		}
        read_bff[bytes_read] = '\0'; // buffer terminado en nulo
		stored_bff = ft_strjoin(stored_bff, read_bff); // Contatenamos temp+buffer
		free(read_bff);
		return (stored_bff);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *stored_bff;
	int ptr_n;

	ptr_n = 0;
	if (stored_bff == NULL)
		stored_bff = NULL; // Solo se pone a NULL en la primera pasada
	if (fd == -1)
		return (NULL);
	if (!stored_bff) // Si el buffer acumulado está vacio entramos y llamamos a read_buffer
	{
		stored_bff = read_buffer(stored_bff, fd);
		while(ft_strchr(stored_bff, '\n') == NULL) // vamos a leer del buffer y concatenar hasta obtener un \n
			stored_bff = read_buffer(stored_bff, fd);
	}
	while(ft_strchr(stored_bff, '\n') == NULL) // vamos a leer del buffer y concatenar hasta obtener un \n
		stored_bff = read_buffer(stored_bff, fd);
	line = find_and_return_line(stored_bff, '\n', &ptr_n);
	stored_bff = stored_bff + ptr_n;
	return (line);
}
#include <fcntl.h>

int main(void) {
	int fd;
	char *next_line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error: no se pudo abrir el archivo.\n");
		return 1;
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
	return 0;
}
