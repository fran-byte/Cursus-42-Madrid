/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:48:01 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 19:58:31 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Renders the game map to the window:
   - Iterates through the grid of the map.
   - Determines the correct sprite for each cell:
     - '1': Wall sprite.
     - '0': Floor sprite.
     - 'C': Collectible sprite.
     - 'E': Exit sprite.
     - 'P': Player sprite.
   - Places the sprite on the window at the corresponding position.
   - Uses `mlx_put_image_to_window` to draw each sprite scaled by `TILE_SIZE`. */

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
			sprite = NULL;
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
