/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:34:39 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 14:42:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"
# include "../inc/so_long_data.h"

int allocate_map_grid(t_map *map, int fd)
{
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
	{
		free_map_error(map, "Error\nMalloc Error\n");
		close(fd);
		return (0);
	}
	return 1;
}

void fill_map_grid(int fd, t_map *map)
{
	char *line;
	int i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (i == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[i] = malloc(ft_strlen(line) + 1);
		if (!map->grid[i])
		{
			free(line);
			while (i > 0)
				free(map->grid[--i]);
			free(map->grid);
			free_map_error(map, "Error\nMalloc Error\n");
			close(fd);
			return;
		}
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
	}
	close(fd);
}
static void free_calculator(t_map *map)
{
			free(map);
			x_error("Error\nInvalid size Map\n");
}

int height_calculator(int fd, t_map *map)
{
	int height;
	int width;
	char *line;
	int len;
	int invalid;

	height = 0;
	width = 0;
	invalid = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line) - 1;
		if (width == 0)
			width = len;
		else if (len != width || width < 3)
			invalid = 1;
		height++;
		free(line);
	}
	if (invalid || height < 3 || height == width)
		free_calculator(map);
	close(fd);
	return (height);
}

void validate_map_dimensions(int fd, char **argv, t_map *map)
{
	map->height = height_calculator(fd, map);
	fd = open_file(argv);
	if (map->height == -1)
	{
		close(fd);
		return;
	}
	if (!allocate_map_grid(map, fd))
		return;
	fill_map_grid(fd, map);
}
