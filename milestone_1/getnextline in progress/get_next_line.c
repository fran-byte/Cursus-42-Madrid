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

char *check_free_stored_buffer(char *stored_bff, char *read_bff)
{
	free(read_bff);
	if (stored_bff[0] == '\0')
    	{
        	free(stored_bff);
        	return NULL;
    	}
    	return stored_bff;
}

char *process_buffer_line(char *stored_bff, int *ptr_n)
{
	int i;
	char *line;

	i = 0
	while (stored_bff[i])
	{
		if (stored_bff[i] == '\n')
        	{
            		line = find_and_return_line(stored_bff, '\n', ptr_n);
            		stored_bff = swap_delete(stored_bff, *ptr_n);
            		*ptr_n = 0;
            		return line;
        	}
        	i++;
    	}
    	return NULL;
}

char *no_read_extract_line(char *stored_bff, int *ptr_n)
{
	int i;
	char *line;

	i = 0
	while (stored_bff[i])
    	{
        	if (stored_bff[i] == '\n')
        	{
            		line = find_and_return_line(stored_bff, '\n', ptr_n);
            		stored_bff += *ptr_n;
            		return line;
        	}
        	i++;
    	}
    	return NULL;
}

char *get_next_line(int fd)
{
	static char *stored_bff = NULL;
	char *read_bff;
	char *line;
	int bytes_read;
	int ptr_n;

	ptr_n = 0;
	if (!stored_bff)
		stored_bff = ft_strdup(""); // Inicializar stored_bff si es la primera llamada	
	line = no_read_extract_line(stored_bff, &ptr_n);// Verificar si stored_bff ya contiene una línea completa sin hacer una nueva lectura
	while (1)
	{
        	read_bff = malloc(BUFFER_SIZE + 1);
        	if (!read_bff)
            		return NULL;
        	bytes_read = read(fd, read_bff, BUFFER_SIZE);
        	if (bytes_read == -1)
            		return (check_free_stored_buffer(stored_bff, read_bff));
        	if (bytes_read == 0) // Fin de archivo
            		return (check_free_stored_buffer(stored_bff, read_bff));
        	read_bff[bytes_read] = '\0';
        	stored_bff = ft_strjoin(stored_bff, read_bff); // concatenar stored_bff con read_bff
        	line = process_buffer_line(stored_bff, &ptr_n);
        	if (line)
            		return (line); // Retornar línea si la encuentra
    	}
}
