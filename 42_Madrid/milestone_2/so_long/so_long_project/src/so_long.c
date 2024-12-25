/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:38:43 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 00:21:49 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"
# include "../inc/so_long_data.h"


int	main(int argc, char **argv)
{
	int fd;
	t_map	*map;

	fd = parse(argc, argv);
	map = malloc(sizeof(t_map));
	if (!map)
		x_error("Malloc Error");
	validate_map_dimensions(fd, argv, map);
	validate_map_items(map);
	validate_wall_map(map);
	validate_map_playable(map);

	print_map(map);
	free_map(map);

	return (0);
}
