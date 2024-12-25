/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:24 by frromero          #+#    #+#             */
/*   Updated: 2024/12/23 14:32:32 by frromero         ###   ########.fr       */
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

typedef struct s_map {
	char **grid;
	size_t width;
	size_t height;
	int player_x;
	int player_y;
} t_map;

void	free_map(t_map *map);
int		height_calculator(int fd);
void	print_map(t_map *map);




#endif
