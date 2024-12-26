/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:42:54 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 00:21:12 by frromero         ###   ########.fr       */
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
int		parse(int argc, char **argv);
void	validate_map_dimensions(int fd, char **argv, t_map *map);
void	validate_map_items(t_map *map);
void	validate_wall_map(t_map *map);
int		open_file(char **argv);

#endif


