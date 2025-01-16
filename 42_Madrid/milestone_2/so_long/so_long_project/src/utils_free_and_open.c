/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_and_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:22:37 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 16:59:40 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

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

int open_file(char **argv)
{
	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		x_error("Error\nFile Open Error\n");
	return (fd);
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

void	x_error(char *x)
{
	write(2, x, ft_strlen(x));
	exit(EXIT_FAILURE);
}
