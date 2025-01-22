/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:48:28 by frromero          #+#    #+#             */
/*   Updated: 2025/01/22 17:15:52 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Initializes map item positions (player, exit, and collectibles) and allocates
	memory for collectible coordinates. */

static void	initialize_map_items(t_map *map)
{
	map->player_x = -1;
	map->player_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->collectibles = 0;
	map->collectibles_x = malloc(sizeof(int) * map->height * map->width);
	map->collectibles_y = malloc(sizeof(int) * map->height * map->width);
	if (!map->collectibles_x || !map->collectibles_y)
		free_map_error(map, "Error\nMalloc Error\n");
}

/* Iterates over the map grid to count and store positions of items
	(exit, player, collectibles). */

static void	count_and_store_items(t_map *map, int *e, int *p, int *c)
{
	int	x;
	int	y;
	int	line_len;

	y = 0;
	while (y < map->height)
	{
		line_len = ft_strlen(map->grid[y]);
		x = 0;
		while (x < line_len)
		{
			if (map->grid[y][x] == 'E')
				put_item_e(map, x, y, e);
			else if (map->grid[y][x] == 'P')
				put_item_p(map, x, y, p);
			else if (map->grid[y][x] == 'C')
				put_item_c(map, x, y, c);
			x++;
		}
		y++;
	}
}

/* Validates the number of items (exit, player, collectibles) and ensures
	correct map setup. */

void	validate_map_items(t_map *map)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	initialize_map_items(map);
	count_and_store_items(map, &e, &p, &c);
	if (e != 1 || p != 1 || c < 1)
		free_map_error(map, "Error\nInvalid number of items in map\n");
}
