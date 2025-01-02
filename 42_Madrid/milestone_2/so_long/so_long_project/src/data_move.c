/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 21:31:45 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

#include <stdio.h>
void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->map.player_x + dx;
    new_y = game->map.player_y + dy;
    if (game->map.grid[new_y][new_x] != '1')
    {
        if (game->map.grid[new_y][new_x] == 'C')
            game->map.collectibles--;
        if (game->map.grid[game->map.player_y][game->map.player_x] != 'E')
            game->map.grid[game->map.player_y][game->map.player_x] = '0';
        if (game->map.grid[new_y][new_x] == 'E')
        {
            if (game->map.collectibles == 0)
            {
                game->game_over = 1; // GAME OVER
                printf("Juego terminado! Has recogido todos los coleccionables.\n");
                game->moves++;
                exit_game(game);
                return;
            }
            else
            {
                printf("* * * Aún faltan coleccionables para salir.\n");
                game->map.grid[new_y][new_x] = 'E';
                game->map.player_x = new_x;
                game->map.player_y = new_y;
                game->moves++;
                return;
            }
        }
        game->map.grid[new_y][new_x] = 'P';
        game->map.player_x = new_x;
        game->map.player_y = new_y;
        game->moves++;
    }
    printf("Jugador en (%d, %d), Coleccionables: %d\n", game->map.player_x, game->map.player_y, game->map.collectibles);
}

