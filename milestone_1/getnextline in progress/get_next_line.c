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


size_t	ft_strlen(const char *str)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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
size_t	ft_strlcat(char *dst, const char *src, size_t size)
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

char	*ft_strjoin(char const *buffer, char const *temp_buffer)
{
	int		total_sz;
	char	*str;

	total_sz = ft_strlen(buffer) + ft_strlen(temp_buffer);
	str = (char *)malloc(sizeof(*str) * (total_sz));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, total_sz + 1);
	ft_strlcat(str, temp_buffer, total_sz + 1);
	//free(buffer);
	//buffer = NULL;
	return (str);
}

char	*find_and_return_line(const char *s, int c)
{
	size_t	i;
	char *line;

	i = 0;
/*	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}*/
	while(*s)
	{
		if (s[i] == (char)c)
		{
			//return ((char *)&s[i]);
			line = ft_calloc(i, sizeof(char)+1); // reservamos solo el tamaño de line
			//line[i+1] = '\n';  // lo llenamos de ceros y colocamos el fin de linea \n
			i = 0;

			while (s[i] != '\n')
			{
				line[i] = s[i]; // rellenamos line con s(la str concatenada) solo hasta
								// completar line, el final de line es donde estará el \n
				i++;
			}
			line[i] = '\n';
			return (line);
		}
		i++;
		//else
		//	return ((char *)s);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char *buffer;
	int bytes_read;
	char *line;
	static char *temp_buffer;
	int 	i;

	i = 0;
	temp_buffer = NULL;
	if (fd == -1)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!temp_buffer)
			temp_buffer = ft_calloc(1, sizeof(char));  // Inicializar temp_buffer como cadena vacía

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	temp_buffer = ft_strjoin(buffer, temp_buffer);
	while(temp_buffer[i])
	{
		if(temp_buffer[i] == '\n')
		{
			line = find_and_return_line(temp_buffer, '\n');
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
	printf("%s", next_line);  // línea leída
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
