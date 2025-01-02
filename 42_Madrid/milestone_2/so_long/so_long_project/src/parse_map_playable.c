/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_playable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:54:49 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 17:35:52 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void flood_fill(char **grid, int x, int y, t_map *map, int *collectible_count)
{
	// Si está fuera de los límites, o es un muro, regresa
	if (x < 0 || y < 0 || x >= map->width || y >= map->height || grid[y][x] == '1')
		return;
	// Si ya visitamos esta celda, regresa
	if (grid[y][x] == 'V')
		return;
	// Marcar celda como visitada
	if (grid[y][x] == 'C')
		(*collectible_count)--;
	grid[y][x] = 'V';
	// Recursión en las 4 direcciones cardinales
	flood_fill(grid, x + 1, y, map, collectible_count);
	flood_fill(grid, x - 1, y, map, collectible_count);
	flood_fill(grid, x, y + 1, map, collectible_count);
	flood_fill(grid, x, y - 1, map, collectible_count);
}

int is_exit_reachable(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height || grid[y][x] == '1')
		return (0);
	if (grid[y][x] == 'E')
		return (1);
	if (grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	return (is_exit_reachable(grid, x + 1, y, map) ||
			is_exit_reachable(grid, x - 1, y, map) ||
			is_exit_reachable(grid, x, y + 1, map) ||
			is_exit_reachable(grid, x, y - 1, map));
}

char **duplicate_grid(char **grid, int height)
{
	char **new_grid;
	int i;

	i = 0;
	new_grid = malloc(sizeof(char *) * height);
	if (!new_grid)
		return (NULL);
	while (i < height)
	{
		new_grid[i] = ft_strdup(grid[i]);
		if (!new_grid[i])
		{
			while (i > 0)
			{
				free(new_grid[i - 1]);
				i--;
			}
			free(new_grid);
			return (NULL);
		}
		i++;
	}
	return (new_grid);
}

void free_grid(char **grid, int height)
{
	int i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void validate_map_playable(t_map *map)
{
	int collectible_count;
	int exit_accessible;
	char **temp_grid;

	collectible_count = (map->collectibles);
	exit_accessible = 0;
	temp_grid = duplicate_grid(map->grid, map->height);
	if (!temp_grid)
		free_map_error(map, "Error\nMemory allocation error\n");
	flood_fill(temp_grid, map->player_x, map->player_y, map, &collectible_count);
	free_grid(temp_grid, map->height);
	if (collectible_count > 0)
		free_map_error(map, "Error\nNot all collectibles are reachable\n");
	temp_grid = duplicate_grid(map->grid, map->height);
	if (!temp_grid)
		free_map_error(map, "Error\nMemory allocation error\n");
	exit_accessible = is_exit_reachable(temp_grid, map->player_x, map->player_y, map);
	free_grid(temp_grid, map->height);
	if (!exit_accessible)
		free_map_error(map, "Error\nExit is not reachable\n");
}
