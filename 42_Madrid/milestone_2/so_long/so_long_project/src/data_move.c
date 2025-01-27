/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:22:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Logs the player's total move count to the terminal.
 *
 * Converts the move count to a string, writes it to the terminal,
 * and appends a newline character.
 *
 * @param game Pointer to the game structure containing the move count.
 */
static void	terminal_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free (str);
}

/**
 * Handles player movement, interactions, and game state updates.
 *
 * This function checks for collisions, updates the player's position,
 * handles collectible items, and checks for the game's win condition.
 * If the player reaches the exit tile after collecting all items,
 * the game ends.
 *
 * @param game Pointer to the game structure.
 * @param dx Horizontal movement delta (-1 for left, 1 for right,
 * 0 for no movement).
 * @param dy Vertical movement delta (-1 for up, 1 for down, 0 for no movement).
 */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (game->map.grid[new_y][new_x] != '1')
	{
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.collectibles--;
		if (game->map.grid[game->map.player_y][game->map.player_x] != 'E')
			game->map.grid[game->map.player_y][game->map.player_x] = '0';
		if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles == 0)
		{
			game->game_over = 1;
			game->moves++;
			exit_game(game);
		}
		if (game->map.grid[new_y][new_x] != 'E')
			game->map.grid[new_y][new_x] = 'P';
		game->map.player_x = new_x;
		game->map.player_y = new_y;
		game->moves++;
		terminal_moves(game);
	}
}
