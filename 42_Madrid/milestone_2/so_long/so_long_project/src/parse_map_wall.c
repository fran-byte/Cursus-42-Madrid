/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:24:41 by frromero          #+#    #+#             */
/*   Updated: 2025/01/18 18:17:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/* Checks if the first and last characters of a line are '1':
   - Returns -1 if the line does not start or end with '1'.
   - Returns 0 if the line is valid. */

static int	scan_lines(char *line)
{
	int	i;
	int	len;

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
/* Verifies if all characters in the top or bottom line are '1':
   - Returns -1 if any character is not '1'.
   - Returns 0 if the line is valid. */

static int	scan_lines_up_down(char *line)
{
	int	i;
	int	len;

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

/* Validates the map's wall boundaries:
   - Ensures the top and bottom rows are entirely '1' using `scan_lines_up_down`
   - Checks if the sides of each middle row are '1' using `scan_lines`.
   - If any validation fails, triggers an error and exits. */

void	validate_wall_map(t_map *map)
{
	int	i;

	i = 1;
	if (scan_lines_up_down(map->grid[map->height - 1]) == -1
		|| scan_lines_up_down(map->grid[0]) == -1)
		free_map_error(map, "Error\nInvalid map: The wall is open\n");
	while (i < map->height - 1)
	{
		if (scan_lines(map->grid[i]) == -1)
			free_map_error(map, "Error\nInvalid map: The wall is open\n");
		i++;
	}
}
