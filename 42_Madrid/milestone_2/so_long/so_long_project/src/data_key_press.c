/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:28:55 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 19:56:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Handles key presses:
   - ESC_KEY: Exits the game.
   - W, A, S, D: Moves the player in the corresponding direction.
   - Re-renders the map after handling input.*/

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == W_KEY)
		move_player(game, 0, -1);
	else if (keycode == A_KEY)
		move_player(game, -1, 0);
	else if (keycode == S_KEY)
		move_player(game, 0, 1);
	else if (keycode == D_KEY)
		move_player(game, 1, 0);
	render_map(game, &game->sprites);
	return (0);
}
