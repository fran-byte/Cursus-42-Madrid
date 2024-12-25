/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:15 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 00:36:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void print_map(t_map *map)
{
	int i;

	i = 0;
	if (map == NULL || map->grid == NULL)
		x_error("Invalid map to print\n");
	while (i < map->height)
	{
		write(1, map->grid[i], ft_strlen(map->grid[i]));
		i++;
	}
}

int open_file(char **argv)
{
	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		x_error("File Open Error\n");
	return (fd);
}

int height_calculator(int fd)
{
	int height;
	int width;
	char *line;
	int len;

	height = 0;
	width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line) - 1;
		if (width == 0)
			width = len;
		else if (len != width || width < 3)
		{
			free(line);
			x_error("Invalid size Map\n");
		}
		height++;
		free(line);
	}
	if (height < 3 || height == width)
		x_error("Invalid size Map\n");
	close(fd);
	return (height);
}

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
