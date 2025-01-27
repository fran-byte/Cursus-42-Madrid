/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_playable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:54:49 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:23:37 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Flood-fill algorithm to check if all collectibles are reachable.
 * Marks visited cells as 'V' to avoid revisiting.
 * Decrements collectible count when a collectible is found.
 *
 * @param grid  Map grid.
 * @param x     Current x-coordinate.
 * @param y     Current y-coordinate.
 * @param map   Map structure.
 */
static void	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| grid[y][x] == '1')
		return ;
	if (grid[y][x] == 'V')
		return ;
	if (grid[y][x] == 'C')
		map->collectible_count--;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
}

/**
 * Checks if the exit is reachable from the player's position using a
 * flood-fill approach.
 * Marks visited cells as 'V' to avoid revisiting.
 *
 * @param grid  Map grid.
 * @param x     Current x-coordinate.
 * @param y     Current y-coordinate.
 * @param map   Map structure.
 *
 * @return 1 if exit is reachable, 0 otherwise.
 */
int	is_exit_reachable(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| grid[y][x] == '1')
		return (0);
	if (grid[y][x] == 'E')
		return (1);
	if (grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	return (is_exit_reachable(grid, x + 1, y, map)
		|| is_exit_reachable(grid, x - 1, y, map)
		|| is_exit_reachable(grid, x, y + 1, map)
		|| is_exit_reachable(grid, x, y - 1, map));
}

/**
 * Creates a duplicate of the map grid.
 * Allocates memory for a new grid and copies the content from the
 * original grid.
 * If memory allocation fails, returns NULL.
 *
 * @param grid   Original map grid.
 * @param height Map height (number of rows).
 *
 * @return A new grid, or NULL if allocation fails.
 */
char	**duplicate_grid(char **grid, int height)
{
	char	**new_grid;
	int		i;

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

/**
 * Frees the memory allocated for a grid.
 *
 * @param grid   Map grid.
 * @param height Map height (number of rows).
 */
void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * Validates if the map is playable.
 * Ensures all collectibles and the exit are reachable.
 * Uses duplicated grids to avoid modifying the original grid.
 *
 * @param map   Map structure.
 */
void	validate_map_playable(t_map *map)
{
	int		exit_accessible;
	char	**temp_grid;

	map->collectible_count = (map->collectibles);
	exit_accessible = 0;
	temp_grid = duplicate_grid(map->grid, map->height);
	if (!temp_grid)
		free_map_error(map, "Error\nMemory allocation error\n");
	flood_fill(temp_grid, map->player_x, map->player_y,
		map);
	free_grid(temp_grid, map->height);
	if (map->collectible_count > 0)
		free_map_error(map, "Error\nNot all collectibles are reachable\n");
	temp_grid = duplicate_grid(map->grid, map->height);
	if (!temp_grid)
		free_map_error(map, "Error\nMemory allocation error\n");
	exit_accessible = is_exit_reachable(temp_grid, map->player_x,
			map->player_y, map);
	free_grid(temp_grid, map->height);
	if (!exit_accessible)
		free_map_error(map, "Error\nExit is not reachable\n");
}
