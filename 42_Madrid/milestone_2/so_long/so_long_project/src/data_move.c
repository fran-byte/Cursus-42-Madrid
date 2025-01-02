/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 14:39:30 by frromero         ###   ########.fr       */
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
	if (game->map.grid[new_y][new_x] != '1') /*si no es una pared (1)*/
	{
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.collectibles--;
		if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles == 0)
		{
			/*Renderiza la salida nuevamente (en caso de que haya sido sobrescrita)*/
			mlx_put_image_to_window(game->mlx, game->window, game->sprites.exit, new_x * TILE_SIZE, new_y * TILE_SIZE);

			game->game_over = 1; /* GAME OVER */
			printf("Estás en EXIT\n");   // BORRAR ****************************
			exit_game(game);
			return;
		}

		/*Moviendo al jugadorrrr*/
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
		game->map.grid[new_y][new_x] = 'P';
		game->map.player_x = new_x;
		game->map.player_y = new_y;
		game->moves++;

		/* Renderiza la nueva posición del jugador*/
		mlx_put_image_to_window(game->mlx, game->window, game->sprites.player, new_x * TILE_SIZE, new_y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->sprites.exit, new_x * TILE_SIZE, new_y * TILE_SIZE);

		/* Si el jugador pasa por la salida antes de recoger todos los coleccionables, no hace nada adicional*/
		{
			game->map.grid[new_y][new_x] = 'E';
			/* Si no ha recogido todos los coleccionables, no cambia el estado */
			printf("Aún te faltan coleccionables para salir.\n");   // BORRAR ****************************
		}
	}

	/*Debugging  BORRARRRRR*/
	printf("Jugador en (%d, %d), Coleccionables restantes: %d\n", game->map.player_x, game->map.player_y, game->map.collectibles);
}
