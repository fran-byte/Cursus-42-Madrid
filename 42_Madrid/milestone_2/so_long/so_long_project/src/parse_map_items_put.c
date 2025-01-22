/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_items_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:25:58 by frromero          #+#    #+#             */
/*   Updated: 2025/01/21 20:26:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Places an item (exit, player, or collectible) on the map, updating
	positions and counts. */

void	put_item_e(t_map *map, int x, int y, int *e)
{
	(*e)++;
	map->exit_x = x;
	map->exit_y = y;
}

void	put_item_p(t_map *map, int x, int y, int *p)
{
	(*p)++;
	map->player_x = x;
	map->player_y = y;
}

void	put_item_c(t_map *map, int x, int y, int *c)
{
	(*c)++;
	map->collectibles_x[map->collectibles] = x;
	map->collectibles_y[map->collectibles] = y;
	map->collectibles++;
}
