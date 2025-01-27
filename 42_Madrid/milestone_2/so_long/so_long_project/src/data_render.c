/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:48:01 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:28:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Draws a specific texture at the given grid position and updates the
 * Heads-Up Display.
 *
 * This function places a texture on the game window based on the current grid
 * cell position and updates the Display with the current move count and
 * remaining collectibles.
 *
 * @param game Pointer to the game structure.
 * @param texture Pointer to the texture to be rendered.
 * @param x Pointer to the horizontal grid position (will be incremented).
 * @param y Pointer to the vertical grid position.
 */
static void	render_mlx(t_game *game, void *texture, int *x, int *y)
{
	char	*str_moves;
	char	*str_collects;

	mlx_put_image_to_window(game->mlx, game->window, texture,
		*x * TILE_SIZE, *y * TILE_SIZE);
	str_moves = ft_itoa(game->moves);
	str_collects = ft_itoa(game->map.collectibles);
	mlx_string_put(game->mlx, game->window, 5, 26, 0xFFFFFF, "MOVES");
	mlx_string_put(game->mlx, game->window, 85, 26, 0xff0000, str_moves);
	mlx_string_put(game->mlx, game->window, 143, 26, 0xFFFFFF, "FRUITS");
	mlx_string_put(game->mlx, game->window, 233, 26, 0xff0000, str_collects);
	free(str_moves);
	free(str_collects);
	*x = *x + 1;
}

/**
 * Renders the entire game map by iterating through each grid cell and
 * placing the appropriate sprite.
 *
 * This function determines the type of sprite to render based on the map's grid
 * values:
 * - '1': Wall sprite.
 * - '0': Floor sprite.
 * - 'C': Collectible sprite.
 * - 'E': Exit sprite.
 * - 'P': Player sprite.
 *
 * Each sprite is drawn at its corresponding position in the game window using
 * the MiniLibX `mlx_put_image_to_window` function.
 *
 * @param game Pointer to the game structure.
 * @param sprites Pointer to the sprites structure containing textures.
 */
void	render_map(t_game *game, t_sprites *sprites)
{
	int		y;
	int		x;
	void	*texture;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			texture = NULL;
			if (game->map.grid[y][x] == '1')
				texture = sprites->wall;
			else if (game->map.grid[y][x] == '0')
				texture = sprites->floor;
			else if (game->map.grid[y][x] == 'C')
				texture = sprites->collectible;
			else if (game->map.grid[y][x] == 'E')
				texture = sprites->exit;
			else if (game->map.grid[y][x] == 'P')
				texture = sprites->player;
			render_mlx(game, texture, &x, &y);
		}
		y++;
	}
}
