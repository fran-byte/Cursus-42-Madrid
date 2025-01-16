/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exit_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:42:01 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 16:42:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

void free_textures(t_game *game)
{
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.collectible)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
}


int exit_game(t_game *game)
{
	int i;

	free_textures(game);
	if (game->map.grid != NULL)
	{
		i = 0;
		while (i < game->map.height)
		{
			if (game->map.grid[i] != NULL)
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->map.collectibles_x != NULL)
		free(game->map.collectibles_x);
	if (game->map.collectibles_y != NULL)
		free(game->map.collectibles_y);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
