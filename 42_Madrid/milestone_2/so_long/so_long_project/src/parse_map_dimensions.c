/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:34:39 by frromero          #+#    #+#             */
/*   Updated: 2025/01/18 18:21:34 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Fills the map grid with lines read from the file:
   - Reads: `get_next_line`.
   - Sets the map's width based on the first line.
   - Allocates memory for each row of the grid and copies the line into it.
   - Frees and exits if allocation fails.*/

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

/* Allocates memory for the map grid based on the map's height.
   - Returns 1 if allocation is successful, or 0 if it fails.*/

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

/* Frees the map structure */

static void	free_calculator(t_map *map)
{
	free(map);
	x_error("Error\nInvalid size Map\n");
}
/* Calculates the map's height and validates the width of each line:
   - Reads the file line by line to count the total number of lines (height).
   - Ensures all lines have the same width and that the dimensions meet
   		minimum requirements.
   - Frees resources */

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
	if (invalid || height < 3 || height == width)
		free_calculator(map);
	close(fd);
	return (height);
}
/* Validates the map dimensions (height and width) and fills the map grid:
   - Computes the map's height using `height_calculator`.
   - Reopens the file to start reading from the beginning.
   - Allocates memory for the map grid using `allocate_map_grid`.
   - Fills the grid with the file's content using `fill_map_grid`. */

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
