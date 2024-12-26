/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:48:28 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 13:13:27 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

int search_items(char *line, int *e, int *p, int *c)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
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

void validate_map_items(t_map *map)
{
	int e = 0;
	int p = 0;
	int c = 0;
	int x = 0;
	int y = 0;
	int line_len;

	map->player_x = -1;
	map->player_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->collectibles_x = malloc(sizeof(int) * map->height * map->width);
	map->collectibles_y = malloc(sizeof(int) * map->height * map->width);
	if (!map->collectibles_x || !map->collectibles_y)
		free_map_error(map, "MALLOC ERROR\n");
	map->collectibles = 0;
	while (x < map->height)
	{
		line_len = ft_strlen(map->grid[x]);
		y = 0;
		while (y < line_len)
		{
			if (map->grid[x][y] == 'E')
			{
				e++;
				map->exit_x = x;
				map->exit_y = y;
			}
			else if (map->grid[x][y] == 'P')
			{
				p++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[x][y] == 'C')
			{
				c++;
				map->collectibles_x[map->collectibles] = x;
				map->collectibles_y[map->collectibles] = y;
				map->collectibles++;
			}
			y++;
		}
		x++;
	}
	if (e != 1 || p != 1 || c < 1)
		free_map_error(map, "Invalid number of items in map\n");
}

void	validate_map_dimensions(int fd, char **argv, t_map *map)
{
	int i;
	char *line;

	i = 0;
	map->height = height_calculator(fd, map); // REVISAR POR POSIBLE LEACKS **********************
	fd = open_file(argv);

	// Reserva memoria para el puntero `grid` (matriz de caracteres)
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
	{
		free_map_error(map, "MALLOC ERROR\n");
		close(fd);
		return;
	}

	// Leer las líneas del archivo y reservar memoria para cada fila
	while ((line = get_next_line(fd)) != NULL)
	{
		if (i == 0)
			map->width = ft_strlen(line) - 1;

		// Reservar memoria para cada fila de la cuadrícula
		map->grid[i] = malloc(ft_strlen(line) + 1);
		if (!map->grid[i])
		{
			// Si ocurre un error, liberar la memoria reservada hasta ahora
			free(line);
			while (i > 0)
			{
				free(map->grid[--i]); // Liberar las filas anteriores
			}
			free(map->grid); // Liberar la matriz
			free_map_error(map, "MALLOC ERROR\n");
			close(fd);
			return;
		}

		// Copiar la línea en la fila correspondiente de `grid`
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		free(line); // Liberar la línea leída
		i++;
	}

	close(fd);
}
