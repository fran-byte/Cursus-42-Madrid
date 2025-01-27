/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_and_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:22:37 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:30:18 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Opens the file specified in the command line argument.
 *
 * @param argv  The command line arguments, where argv[1] is the file name.
 * @return      The file descriptor of the opened file.
 *
 * If the file cannot be opened, the function triggers an error.
 */
int	open_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		x_error("Error\nFile Open Error\n");
	return (fd);
}

/**
 * Frees all allocated memory in the map structure.
 *
 * - Iterates through the map grid and frees each row.
 * - Frees the main grid array as well as the collectible coordinates arrays.
 * - Ensures no memory leaks by checking for valid pointers before freeing.
 *
 * @param map   The map structure containing the grid and other resources
 * to free.
 */
void	free_map(t_map *map)
{
	int	i;

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

/**
 * Frees all allocated resources in the map structure and exits with an error.
 *
 * - Similar to `free_map`, but also releases the map structure itself.
 * - Displays a custom error message provided as an argument.
 * - Exits the program immediately after cleaning up resources.
 *
 * @param map       The map structure to free.
 * @param msg_error The error message to display before exiting.
 */
void	free_map_error(t_map *map, char *msg_error)
{
	int	i;

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

/**
 * Writes an error message to the standard error stream and exits the program.
 *
 * - Displays the error message to stderr (file descriptor 2).
 * - Exits the program with `EXIT_FAILURE` to indicate an error.
 *
 * @param x  The error message to display.
 */
void	x_error(char *x)
{
	write(2, x, ft_strlen(x));
	exit(EXIT_FAILURE);
}

/**
 * Frees the map grid, a specific line, and other resources when an error occurs.
 *
 * - Frees the given line and any rows of the grid.
 * - Frees the map and triggers an error message before exiting.
 *
 * @param map   The map structure to free.
 * @param line  The line to free.
 * @param i     The current row index of the grid.
 * @param fd    The file descriptor to close after freeing resources.
 */
void	free_map_grid(t_map *map, char *line, int i, int fd)
{
	free(line);
	while (i > 0)
		free(map->grid[--i]);
	free(map->grid);
	free_map_error(map, "Error\nMalloc Error\n");
	close(fd);
	return ;
}
