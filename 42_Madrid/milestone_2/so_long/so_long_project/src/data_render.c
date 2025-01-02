/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:48:01 by frromero          #+#    #+#             */
/*   Updated: 2025/01/01 23:44:56 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void render_map(t_game *game, t_sprites *sprites)
{
	int y;
	int x;
	char cell;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell = game->map.grid[y][x];
			void *sprite;
			if (cell == '1')
				sprite = sprites->wall;
			else if (cell == '0')
				sprite = sprites->floor;
			else if (cell == 'C')
				sprite = sprites->collectible;
			else if (cell == 'E')
				sprite = sprites->exit;
			else if (cell == 'P')
				sprite = sprites->player;
			mlx_put_image_to_window(game->mlx, game->window, sprite,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
