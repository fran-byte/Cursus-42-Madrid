/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:25:56 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 19:48:29 by frromero         ###   ########.fr       */
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

	// Si el movimiento no es hacia una pared
	if (game->map.grid[new_y][new_x] != '1')
	{
		// Si el jugador pasa por un coleccionable, decrementa
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.collectibles--;

		// Borra la antigua posición del jugador solo si no es la salida
		//if (game->map.grid[game->map.player_y][game->map.player_x] != game->map.grid[game->map.exit_y][game->map.exit_x])
		//{
			game->map.grid[game->map.player_y][game->map.player_x] = '0'; // Borra la antigua posición
		//}

		// Asigna la nueva posición al jugador
		game->map.grid[new_y][new_x] = 'P'; // Coloca al jugador en la nueva celda
		game->map.player_x = new_x;
		game->map.player_y = new_y;
		game->moves++;

		// Renderiza la nueva posición del jugador
		mlx_put_image_to_window(game->mlx, game->window, game->sprites.player,
								new_x * TILE_SIZE, new_y * TILE_SIZE);

		// Siempre renderiza la salida en su lugar
		if (game->map.grid[new_y][new_x] != 'E') // Solo si el jugador no está en la salida
		{
			mlx_put_image_to_window(game->mlx, game->window, game->sprites.exit,
									game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
		}

		// Si el jugador ha llegado a la salida
		if (game->map.grid[new_y][new_x] == 'E')
		{
			if (game->map.collectibles == 0)
			{
				// Si ha recogido todos los coleccionables, termina el juego
				game->game_over = 1; // GAME OVER
				printf("Estás en EXIT y has recogido todos los coleccionables. ¡Juego terminado!\n");
				exit_game(game);
				return;
			}
			else
			{
				// Si no ha recogido todos los coleccionables, imprime mensaje
				printf("Aún faltan coleccionables para salir.\n");
			}
		}
	}

	// Debugging: muestra la posición del jugador y los coleccionables restantes
	printf("Jugador en (%d, %d), Coleccionables restantes: %d\n", game->map.player_x, game->map.player_y, game->map.collectibles);
}
