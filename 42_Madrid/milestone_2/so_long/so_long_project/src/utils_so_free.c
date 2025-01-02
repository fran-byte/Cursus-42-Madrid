/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:22:37 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 14:42:19 by frromero         ###   ########.fr       */
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

void free_map(t_map *map)
{
	int i = 0;

	if (map)
	{
		// Liberamos cada fila de la matriz
		while (i < map->height)
		{
			if (map->grid[i]) // Asegurarse de que la fila no sea NULL
				free(map->grid[i]);
			i++;
		}

		// Liberamos la matriz principal de las filas
		if (map->grid)
			free(map->grid);

		// Liberamos los arrays de coleccionables si existen
		if (map->collectibles_x)
			free(map->collectibles_x);
		if (map->collectibles_y)
			free(map->collectibles_y);
	}
}
