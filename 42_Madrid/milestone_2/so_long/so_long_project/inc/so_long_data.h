/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:24 by frromero          #+#    #+#             */
/*   Updated: 2024/12/27 07:33:24 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include "so_long.h"
# include "../minilibx-linux/mlx.h"

/*	Represents the game map: contains the grid, dimensions, player position,
	collectibles, and the exit. */
typedef struct s_map {
	char **grid;
	int width;
	int height;
	int player_x;
	int player_y;
	int collectibles;
    int *collectibles_x;
    int *collectibles_y;
	int	exit_x;
	int	exit_y;

} t_map;

/*	Represents the global game state, including the map, the MiniLibX
	connection, the window, and the game status. */
typedef struct s_game {
    t_map map;
    void *mlx;
    void *window;
    int moves;
    int game_over;
} t_game;

/* 	Handles textures and sprites for rendering game elements such as the player,
	 walls, and collectibles. */
typedef struct s_sprites {
    void *player;
    void *wall;
    void *collectible;
    void *exit;
    void *floor;
} t_sprites;





#endif
