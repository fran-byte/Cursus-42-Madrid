/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:59:24 by frromero          #+#    #+#             */
/*   Updated: 2024/11/07 20:44:59 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function reads from a file descriptor line by line. */
/* It stores leftover text in a static buffer between calls, */
/* handling partial lines across multiple reads. */
/* The `my_line` function extracts a full line */

#include "get_next_line.h"

/* Extracts a line from the stored buffer up to a newline or end. */

char	*my_line(char *stored)
{
	int			i;
	char		*line;
	int			ln;

	i = 0;
	ln = 0;
	while (stored[ln] != '\n' && stored[ln] != '\0')
		ln++;
	if (*stored)
	{
		line = (char *)malloc((ln + 1) * sizeof(char) + 1);
		if (line == NULL)
			return (free(stored), NULL);
		while (i <= ln)
		{
			line[i] = stored[i];
			i++;
		}
		line[i] = '\0';
		return (line);
	}
	return (free(stored), NULL);
}
/* Re-adjusts the stored buffer by removing the first line. */

char	*re_adj_storage(char *stored)
{
	int		i;
	int		j;
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
		return (NULL);
	while (stored[i])
		swap_temp[j++] = stored[i++];
	swap_temp[j] = '\0';
	return (free(stored), swap_temp);
}
/* Initializes the stored buffer to an empty string if NULL. */

char	*initialize_stored(char *stored, char *read_bff)
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
/* Reads from the file descriptor and joins data to the stored buffer. */

char	*read_join(char *stored, int fd)
{
	ssize_t	bytes_read;
	char	*read_bff;

	read_bff = malloc(BUFFER_SIZE + 1);
	if (!read_bff)
		return (NULL);
	if (!stored)
		stored = initialize_stored(stored, read_bff);
	while (1)
	{
		bytes_read = read(fd, read_bff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(read_bff);
			if (bytes_read == 0 && stored[0] != '\0')
				return (stored);
			return (free(stored), NULL);
		}
		read_bff[bytes_read] = '\0';
		stored = special_strjoin_(stored, read_bff);
		if (ft_strchr(read_bff, '\n'))
			break ;
	}
	return (free(read_bff), stored);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stored = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = read_join(stored, fd);
	if (!stored)
		return (NULL);
	line = my_line(stored);
	stored = re_adj_storage(stored);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

// Compilar: cc -g -fsanitize=address -o a.out get_next_line.c
get_next_line_utils.c && ./a.out
// Compilar si vamos a pasar valgrind: sin fsanitize
//cc -g3 -o a.out get_next_line.c get_next_line_utils.c && ./a.out

int main(void)
{
	char *next_line;
	int fd = open("files/42_with_nl", O_RDONLY);

	if (fd == -1)
	{
		printf("Error: no se pudo abrir el archivo.\n");
		return (1);
	}
	while ((next_line = get_next_line(fd)) != NULL)
	{
		printf("%s", next_line);
		free(next_line);
	}
	free(next_line);
	close(fd);
	return (0);
}*/
