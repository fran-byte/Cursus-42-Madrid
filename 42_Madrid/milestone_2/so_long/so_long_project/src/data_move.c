/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/22 20:05:37 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

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
	}
}
