/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_items_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:25:58 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:27:27 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Sets the exit position and increments the exit counter.
 *
 * @param map The map structure.
 * @param x The x-coordinate of the exit.
 * @param y The y-coordinate of the exit.
 * @param e The exit counter.
 */
void	put_item_e(t_map *map, int x, int y, int *e)
{
	(*e)++;
	map->exit_x = x;
	map->exit_y = y;
}

/**
 * Sets the player's position and increments the player counter.
 *
 * @param map The map structure.
 * @param x The x-coordinate of the player.
 * @param y The y-coordinate of the player.
 * @param p The player counter.
 */
void	put_item_p(t_map *map, int x, int y, int *p)
{
	(*p)++;
	map->player_x = x;
	map->player_y = y;
}

/**
 * Sets the collectible position and increments the collectible counter.
 *
 * @param map The map structure.
 * @param x The x-coordinate of the collectible.
 * @param y The y-coordinate of the collectible.
 * @param c The collectible counter.
 */
void	put_item_c(t_map *map, int x, int y, int *c)
{
	(*c)++;
	map->collectibles_x[map->collectibles] = x;
	map->collectibles_y[map->collectibles] = y;
	map->collectibles++;
}
