/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_and_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:22:37 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:10 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Open file descriptor */

int open_file(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		x_error("Error\nFile Open Error\n");
	return (fd);
}
/* Frees all allocated memory in the map structure:
   - Iterates through the map grid and frees each row.
   - Frees the main grid array, as well as the collectible coordinates arrays.
   - Ensures no memory leaks occur by checking for valid pointers. */

void free_map(t_map *map)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		if (map->grid)
			free(map->grid);
		if (map->collectibles_x)
			free(map->collectibles_x);
		if (map->collectibles_y)
			free(map->collectibles_y);
	}
}
/* Frees all allocated resources in the map structure and exits with an error:
   - Similar to `free_map`, but also releases the map structure itself.
   - Displays a custom error message provided as an argument.
   - Exits the program immediately after cleaning up resources. */

void free_map_error(t_map *map, char *msg_error)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		if (map->collectibles_x)
			free(map->collectibles_x);
		if (map->collectibles_y)
			free(map->collectibles_y);
		free(map);
	}
	x_error(msg_error);
}

/* Writes an error message to the standard error stream and exits:
   - Display the error message on file descriptor 2 (stderr).
   - Exits the program:`EXIT_FAILURE` to indicate an error occurred. */

void	x_error(char *x)
{
	write(2, x, ft_strlen(x));
	exit(EXIT_FAILURE);
}
