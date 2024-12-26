/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:38:43 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 21:47:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"
# include "../inc/so_long_data.h"


int	main(int argc, char **argv)
{
	int fd;
	t_map	*map;

	fd = parse_arguments(argc, argv);
	map = malloc(sizeof(t_map));
	if (!map)
		x_error("Malloc Error");
	validate_map_dimensions(fd, argv, map);
	parse_map_validation(map);
	//init_game(map);

	print_map(map);
	free_map(map);

	return (0);
}

/* valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./p */
