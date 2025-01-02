/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:38:43 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 20:01:11 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Main function of the program:
	- Validates arguments and map structure.
	- Initializes game data and window using MiniLibX.
	- Renders the map and configures event hooks for input handling.
	- Enters the main event loop to keep the game running. */

# include "../inc/so_long.h"
# include "../inc/so_long_data.h"

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
	parse_map_validation(map);
	game.map = *map;
	free(map);
	initialize_game(&game);
	render_map(&game, &game.sprites);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
/* valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long maps/2.ber*/
/* valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --verbose --suppressions=valgrind.supp ./so_long maps/2.ber */
/* valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --verbose --suppressions=valgrind.supp ./so_long maps/2.ber */
