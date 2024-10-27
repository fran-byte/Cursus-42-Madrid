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


size_t	ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*buf;

	i = 0;
	buf = (unsigned char *)s;
	while (i < n)
	{
		buf[i] = c;
		i++;
	}
	return (buf);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dst,  char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
size_t	ft_strlcat(char *dst,  char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (len_src + size);
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_src + len_dst);
}

char	*ft_strjoin(char  *read_bff, char  *stored_bff)
{
	int		total_sz;
	char	*str;

	total_sz = ft_strlen(read_bff) + ft_strlen(stored_bff);
	str = (char *)malloc(sizeof(*str) * (total_sz));
	if (!str)
		return (NULL);
	ft_strlcpy(str, read_bff, total_sz + 1);
	ft_strlcat(str, stored_bff, total_sz + 1);
	//free (read_bff);
	return (str);
}

char	*find_and_return_line( char *stored_bff, int c, int *ptr_n)
{
	size_t	i;
	char *line;

	i = 0;

	while(*stored_bff)
	{
		if (stored_bff[i] == (char)c) //  i será el tamaño de line
		{
			line = ft_calloc(i, sizeof(char)+1); // reservamos solo el tamaño de line
					 // lo llenamos de ceros y colocamos el fin de linea \n
			i = 0;
			while (stored_bff[i] != '\n')
			{
				line[i] = stored_bff[i]; // rellenamos line con s(la str concatenada) solo hasta
								// completar line, el final de line es donde estará el \n
				i++;
			}
			//stored_bff = stored_bff + i+1; //dejamos stored_bff apuntando a la siguiente línea
			line[i] = '\n'; // Acoplamos el final de linea.
			*ptr_n = *ptr_n + i + 1;
			return (line);
		}
		i++;

	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char *read_bff;
	int bytes_read;
	char *line;
	static char *stored_bff;
	int 	i;
	static	int ptr_n = 0;

	i = 0;

	if (stored_bff == NULL)
		stored_bff = NULL; // Solo se pone a NULL en la primera pasada
	if (fd == -1)
		return (NULL);


	if (!stored_bff) // Si el baffer acumulado está vacio entramos y llamamos a read_bff
	{

		read_bff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // Tamaño asinado para read_bff
		if (!read_bff)
			return (NULL);
		if (!stored_bff)
				stored_bff = ft_calloc(1, sizeof(char));
						// Inicializar stored_bff como cadena vacía

		bytes_read = read(fd, read_bff, BUFFER_SIZE); // LEEMOS a buffer !!!
		if (bytes_read <= 0)
		{
			free(read_bff);
			if (stored_bff[0] == '\0')
			{ // Si no hay nada acumulado
                free(stored_bff);
                return NULL; // Termina la función
			}
		}
        read_bff[bytes_read] = '\0'; // Asegúrate de que el buffer esté terminado en nulo
		stored_bff = ft_strjoin(stored_bff, read_bff); // Contatenamos temp+buffer
		while(stored_bff[i]) //Buscamos si hay \n y si la hay vamos a extraer la linea
		{
			if(stored_bff[i] == '\n') // Si hay final de línea, vamos a extraerlo
			{
				line = find_and_return_line(stored_bff, '\n', &ptr_n);
				stored_bff = stored_bff + ptr_n;
				return (line);
			}
			i++;
		}
	}
	else // Pero si el buffer acumulado tiene algo no llamamos a read_bff
		while(stored_bff[i]) //Buscamos si hay \n y si la hay vamos a extraer la linea
		{
			if(stored_bff[i] == '\n') // Si hay final de línea, vamos a extraerlo
			{
				line = find_and_return_line(stored_bff, '\n', &ptr_n);
				stored_bff = stored_bff + ptr_n;
				return (line);
			}
			i++;
		}


	return (line);

}

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
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	next_line = get_next_line(fd);
	printf("%s", next_line); // línea leída
	//next_line = get_next_line(fd);
	//printf("%s", next_line);  // línea leída
	//while ((next_line = get_next_line(fd)) != NULL) {
	//	count++;
	//	printf("[%d]: %s", count, next_line);  // línea leída

	//}
	free(next_line); // Liberar la línea
	close(fd);
	return 0;
}
