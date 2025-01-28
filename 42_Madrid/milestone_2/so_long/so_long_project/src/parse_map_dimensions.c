/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:34:39 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:26:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Fills the map grid with lines read from the file.
 *
 * This function reads the map file line by line, allocates memory for each row,
 * and copies each line into the map grid. It also sets the map's width based
 * on the first line. If memory allocation fails, it frees any previously
 * allocated
 * memory and exits the program.
 *
 * @param fd The file descriptor of the map file.
 * @param map A pointer to the map structure where the grid will be stored.
 */
static void	fill_map_grid(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[i] = malloc(ft_strlen(line) + 1);
		if (!map->grid[i])
		{
			free_map_grid(map, line, i, fd);
			return ;
		}
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

/**
 * Allocates memory for the map grid based on the map's height.
 *
 * If memory allocation is successful, it returns 1. Otherwise, it prints
 * an error message and returns 0.
 *
 * @param map A pointer to the map structure that will hold the grid.
 * @param fd The file descriptor of the map file.
 *
 * @return 1 if allocation is successful, 0 if it fails.
 */
static int	allocate_map_grid(t_map *map, int fd)
{
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
	{
		free_map_error(map, "Error\nMalloc Error\n");
		close(fd);
		return (0);
	}
	return (1);
}

/**
 * Frees the map structure and exits the program with an error message.
 *
 * This function is called when the map dimensions are invalid. It frees the
 * map structure and terminates the program with an error message.
 *
 * @param map A pointer to the map structure to be freed.
 */
static void	free_calculator(t_map *map)
{
	free(map);
	x_error("Error\nInvalid size Map\n");
}

/**
 * Calculates the height of the map and validates the width of each line.
 *
 * This function reads the map file line by line to calculate the map's height.
 * It ensures all lines have the same width and that the dimensions meet the
 * minimum requirements. If the map is invalid, it calls `free_calculator` to
 * free the map and terminate the program.
 *
 * @param fd The file descriptor of the map file.
 * @param map A pointer to the map structure to store the calculated dimensions.
 *
 * @return The height of the map if valid, or -1 if the map is invalid.
 */
int	height_calculator(int fd, t_map *map)
{
	int		height;
	int		width;
	char	*line;
	int		len;
	int		invalid;

	height = 0;
	width = 0;
	invalid = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line) - 1;
		if (width == 0)
			width = len;
		else if (len != width || width < 3)
			invalid = 1;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (invalid || height < 3)
		free_calculator(map);
	close(fd);
	return (height);
}

/**
 * Validates the map dimensions and fills the map grid.
 *
 * This function calculates the map's height using `height_calculator`, reopens
 * the file, allocates memory for the map grid, and fills it with the content
 * of the map file. It also checks for invalid map dimensions and exits the
 * program if the dimensions are incorrect.
 *
 * @param fd The file descriptor of the map file.
 * @param argv The command-line arguments (used to reopen the map file).
 * @param map A pointer to the map structure to hold the grid and dimensions.
 */
void	validate_map_dimensions(int fd, char **argv, t_map *map)
{
	map->height = height_calculator(fd, map);
	fd = open_file(argv);
	if (map->height == -1)
	{
		close(fd);
		return ;
	}
	if (!allocate_map_grid(map, fd))
		return ;
	fill_map_grid(fd, map);
}
