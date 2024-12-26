/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:24:41 by frromero          #+#    #+#             */
/*   Updated: 2024/12/25 18:16:44 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

int	scan_lines(char *line)
{
	int	i;
	int len;

	i = 0;
	len = (int)ft_strlen(line) - 1;
	while (line[i])
	{
		if (line[0] != '1' || line[len - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	scan_lines_up_down(char *line)
{
	int	i;
	int len;

	i = 0;
	len = (int)ft_strlen(line) - 1;
	while (i < len)
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}


void	validate_wall_map(t_map *map)
{
	int	i;

	i = 1;
	if (scan_lines_up_down(map->grid[map->height - 1]) == -1
		|| scan_lines_up_down(map->grid[0]) == -1)
		free_map_error(map, "Invalid map: The wall is open\n");
	while (i < map->height - 1)
	{
		if (scan_lines(map->grid[i]) == -1)
			free_map_error(map, "Invalid map: The wall is open\n");
		i++;
	}


}
