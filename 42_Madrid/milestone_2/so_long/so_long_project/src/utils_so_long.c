/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:15 by frromero          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:00 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void print_map(t_map *map)  /* eliminar cuando esté completo el proyecto */
{
	int i;

	i = 0;
	if (map == NULL || map->grid == NULL)
		x_error("Error\nInvalid map to print\n");
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
