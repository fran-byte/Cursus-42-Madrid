/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:24 by frromero          #+#    #+#             */
/*   Updated: 2025/01/24 19:22:39 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include "so_long.h"
# include "../minilibx-linux/mlx.h"
# define TILE_SIZE 32

/*	Represents the game map: contains the grid, dimensions, player position,
	collectibles, and the exit. */

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collectible_count;
	int		*collectibles_x;
	int		*collectibles_y;
	int		exit_x;
	int		exit_y;
}	t_map;

/* 	Handles textures and sprites for rendering game elements such as the player,
	walls, and collectibles. */

typedef struct s_sprites
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*floor;
}	t_sprites;

/*	Represents the global game state, including the map, the MiniLibX
	connection, the window, and the game status. */

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*window;
	int			moves;
	int			game_over;
	t_sprites	sprites;
}	t_game;

/*	keycodes */

# define ESC_KEY 65307
# define W_KEY  119
# define A_KEY  97
# define S_KEY  115
# define D_KEY  100

int		exit_game(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	initialize_game(t_game *game);
void	render_map(t_game *game, t_sprites *sprites);
void	move_player(t_game *game, int dx, int dy);
void	free_textures(t_game *game);
#endif
