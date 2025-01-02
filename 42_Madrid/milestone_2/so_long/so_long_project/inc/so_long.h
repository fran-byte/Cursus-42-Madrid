/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:42:54 by frromero          #+#    #+#             */
/*   Updated: 2025/01/02 17:45:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/get_next_line_bonus.h"
# include "so_long_data.h"

void	x_error(char *x);
void 	free_map_error(t_map *map, char *msg_error);
int		parse_arguments(int argc, char **argv);
void	validate_map_dimensions(int fd, char **argv, t_map *map);
void	validate_map_items(t_map *map);
void	validate_wall_map(t_map *map);
int		open_file(char **argv);
void	parse_map_validation(t_map *map);
void	free_map(t_map *map);
int		height_calculator(int fd, t_map *map);
void	print_map(t_map *map);
char	**duplicate_grid(char **grid, int height);
void	free_grid(char **grid, int height);
int		is_exit_reachable(char **grid, int x, int y, t_map *map);
void	validate_map_playable(t_map *map);

#endif


