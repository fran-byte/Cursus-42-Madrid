/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:38:43 by frromero          #+#    #+#             */
/*   Updated: 2025/01/26 00:15:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Main entry point for the game.
 *
 * @param argc  Number of arguments passed to the program.
 * @param argv  Array of argument strings.
 * @return      0 if the program executes successfully.
 *
 * 1. Parse and validate the input arguments.
 *
 * 2. Dynamically allocate memory for the map.
 *
 * 3. Validate the map dimensions, items, walls, and accessibility.
 *
 * 4. Initialize the game data and game window.
 *
 * 5. Render the map and set up input handling via event hooks.
 *
 * 6. Enter the main game loop.
 */
int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_game	game;

	fd = parse_arguments(argc, argv);
	map = malloc(sizeof(t_map));
	if (!map)
		x_error("Error\nMalloc Error");
	validate_map_dimensions(fd, argv, map);
	validate_map_items(map);
	validate_wall_map(map);
	validate_map_playable(map);
	game.map = *map;
	free(map);
	initialize_game(&game);
	render_map(&game, &game.sprites);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
/* valgrind --leak-check=full --track-origins=yes
--show-leak-kinds=all ./so_long maps/2.ber*/
