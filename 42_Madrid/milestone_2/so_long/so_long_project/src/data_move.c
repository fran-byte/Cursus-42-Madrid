/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 19:57:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Updates the player's position and map state:
   - Collects items ('C') and decreases the collectible count.
   - Handles exit ('E') logic based on remaining collectibles.
   - Updates the player's position on the grid.
   - Increments the move counter. */


void handle_player_movement(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectibles--;
	if (game->map.grid[game->map.player_y][game->map.player_x] != 'E')
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->map.collectibles == 0)
		{
			game->game_over = 1;
			game->moves++;
			exit_game(game);
			return;
		}
		else
			game->map.grid[new_y][new_x] = 'E';
	}
	else
		game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
}

/* Calculates the player's new position based on movement direction.
   - Checks for collisions with walls ('1').
   - Calls `handle_player_movement` if movement is valid. */

void move_player(t_game *game, int dx, int dy)
{
	int new_x;
	int new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;

	if (game->map.grid[new_y][new_x] != '1')
		handle_player_movement(game, new_x, new_y);
}

