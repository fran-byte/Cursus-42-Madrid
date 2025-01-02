/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:48:28 by frromero          #+#    #+#             */
/*   Updated: 2025/01/01 23:32:47 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

int search_items(char *line, int *e, int *p, int *c)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != '\n')
				return (-1);
		else if (line[i] == 'E')
			(*e)++;
		else if (line[i] == 'P')
			(*p)++;
		else if (line[i] == 'C')
			(*c)++;
		i++;
	}
	return (0);
}
void initialize_map_items(t_map *map)
{
	map->player_x = -1;
	map->player_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->collectibles_x = malloc(sizeof(int) * map->height * map->width);
	map->collectibles_y = malloc(sizeof(int) * map->height * map->width);
	if (!map->collectibles_x || !map->collectibles_y)
		free_map_error(map, "Error\nMalloc Error\n");
	map->collectibles = 0;
}

void count_and_store_items(t_map *map, int *e, int *p, int *c)
{
	int x;
	int y;
	int line_len;

	x = 0;
	while (x < map->height)
	{
		line_len = ft_strlen(map->grid[x]);
		y = 0;
		while (y < line_len)
		{
			if (map->grid[x][y] == 'E')
				(*e)++, map->exit_x = x, map->exit_y = y;
			else if (map->grid[x][y] == 'P')
				(*p)++, map->player_x = x, map->player_y = y;
			else if (map->grid[x][y] == 'C')
				(*c)++, map->collectibles_x[map->collectibles] = x,
					map->collectibles_y[map->collectibles] = y,
						map->collectibles++;
			y++;
		}
		x++;
	}
}

void validate_map_items(t_map *map)
{
	int e;
	int p;
	int c;

	e = 0;
	p = 0;
	c = 0;
	initialize_map_items(map);
	count_and_store_items(map, &e, &p, &c);
	if (e != 1 || p != 1 || c < 1)
		free_map_error(map, "Error\nInvalid number of items in map\n");
}


