/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:28:55 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:26:42 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Handles key presses during gameplay.
 *
 * Key actions:
 * - `ESC_KEY`: Exits the game.
 * - `W_KEY`: Moves the player up.
 * - `A_KEY`: Moves the player left.
 * - `S_KEY`: Moves the player down.
 * - `D_KEY`: Moves the player right.
 *
 * After handling input, the function re-renders the map to reflect the
 * player's movement.
 *
 * @param keycode The key pressed by the user.
 * @param game Pointer to the game structure.
 * @return Always returns 0.
 */
int	handle_keypress(int keycode, t_game *game)
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
