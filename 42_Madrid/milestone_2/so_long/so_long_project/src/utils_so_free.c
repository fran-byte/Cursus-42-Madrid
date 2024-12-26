/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:22:37 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 17:56:04 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

#include <stdlib.h>

void safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
void free_calculator(t_map *map)
{
			free(map);
			x_error("Invalid size Map\n");
}

void free_map(t_map *map)
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
}

