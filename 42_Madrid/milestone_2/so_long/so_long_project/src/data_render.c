/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:48:01 by frromero          #+#    #+#             */
/*   Updated: 2025/01/22 16:23:54 by frromero         ###   ########.fr       */
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
   - Uses `mlx_put_image_to_window` to draw each sprite scaled by `TILE_SIZE`.*/

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
