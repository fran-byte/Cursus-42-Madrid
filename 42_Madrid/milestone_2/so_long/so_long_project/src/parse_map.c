/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:48:28 by frromero          #+#    #+#             */
/*   Updated: 2024/12/23 20:39:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

int	search_items(char *line, int *e, int *p, int *c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
			return (-1);
		else if (line[i] == 'E')
			(*e)++;
		else if (line[i] == 'P')
			(*p)++;
		else if (line[i] == 'C')
			(*c)++;
		i++;
	}
	return (0);
}

void	validate_map_items(t_map *map)
{
	int		e;
	int		p;
	int		c;
	size_t	i;

	e = 0;
	p = 0;
	c = 0;
	i = 0;
	while (i < map->height)
	{
		if (search_items(map->grid[i], &e, &p, &c) == -1)
			free_map_error(map, "Invalid character in map\n");
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		free_map_error(map, "Invalid number of items in map\n");
}


void	validate_map_dimensions(int fd, char **argv, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	map->grid = malloc(sizeof(char *) * (map->height = height_calculator(fd)));
	if (!map->grid)
		free_map_error(map, "MALLOC ERROR\n");
	close (fd);
	fd = open_file(argv);
	while ((line = get_next_line(fd)) != NULL)
	{
		map->grid[i] = malloc(ft_strlen(line) + 1);
			if (!map->grid[i])
			{
				free(line);
				free_map_error(map, "MALLOC ERROR\n");
			}
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
	}
	close (fd);
}
