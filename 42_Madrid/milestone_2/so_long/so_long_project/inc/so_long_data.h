/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:24 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 21:43:26 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **grid is a 2D array to store the map
    width is a Map width
    height is a Map height
    player_x is a Player's X coordinate
    player_y is a Player's Y coordinate */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include "so_long.h"
# include "../minilibx-linux/mlx.h"

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

void	draw_map(t_data *data);




#endif
