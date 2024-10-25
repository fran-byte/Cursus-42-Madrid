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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_sz;
	char	*str;

	total_sz = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (total_sz + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_sz + 1);
	ft_strlcat(str, s2, total_sz + 1);
	return (str);
}

char	*find_end_line(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	int bytes_read;
	char *line;
	char *temp_buffer;
	int 	i;

	i = 0;

	if (fd == -1)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buffer)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	temp_buffer = ft_strjoin(buffer, temp_buffer);
	while(temp_buffer[i] != '\0')
	{
		if(temp_buffer[i] == '\n')
		{
			line = find_end_line(temp_buffer, '\n');
		}
		i++;
	}


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

	while ((next_line = get_next_line(fd)) != NULL) {
		count++;
		printf("[%d]: %s", count, next_line);  // línea leída

	}
	free(next_line); // Liberar la línea
	close(fd);
	return 0;
}
