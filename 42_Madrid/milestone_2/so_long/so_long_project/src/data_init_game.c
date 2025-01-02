/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:56:46 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 14:36:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

#include <stdio.h>

/*	This function loads a texture from the specified file path into the provided
	sprite pointer. If loading fails, it frees previously loaded textures,
	destroys the window, and exits the program */

static void	load_texture(t_game *game, void **sprite, char *path,
	int *img_width, int *img_height)
{
	*sprite = mlx_xpm_file_to_image(game->mlx, path, img_width, img_height);
	if (!*sprite)
	{
		free_textures(game);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		x_error("Error\nError loading the texture\n");
	}
}
/*	Initializes the game by setting up the MiniLibX connection, creating the
	window, and loading textures for the game objects. Also sets the player's
	initial position and prints debug information. */

void	initialize_game(t_game *game)
{
	int img_width;
	int img_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		x_error("Error\nError initializing MiniLibX\n");
	game->window = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
		game->map.height * TILE_SIZE, "So Long");
	if (!game->window)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		x_error("Error\nError creating the window\n");
	}
	load_texture(game, &game->sprites.player, "textures/player.xpm", &img_width, &img_height);
	load_texture(game, &game->sprites.wall, "textures/wall.xpm", &img_width, &img_height);
	load_texture(game, &game->sprites.collectible, "textures/collect.xpm", &img_width, &img_height);
	load_texture(game, &game->sprites.exit, "textures/exit.xpm", &img_width, &img_height);
	load_texture(game, &game->sprites.floor, "textures/floor.xpm", &img_width, &img_height);
	game->map.player_x = 1;
	game->map.player_y = 1;
}
