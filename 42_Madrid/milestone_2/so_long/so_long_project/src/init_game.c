/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:55:31 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 21:47:45 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

#define TILE_SIZE 32 // Tamaño de cada celda del mapa

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    t_map *map;
} t_data;

void draw_map(t_data *data)
{
    int x, y;
    y = 0;
    while (y < data->map->height) {
        x = 0;
        while (x < data->map->width) {
            if (data->map->grid[y][x] == '1') {
                // Dibuja una pared (puedes usar una imagen en lugar de píxeles)
                int i = 0;
                while (i < TILE_SIZE) {
                    int j = 0;
                    while (j < TILE_SIZE) {
                        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * TILE_SIZE + i, y * TILE_SIZE + j, 0x00FF00);
                        j++;
                    }
                    i++;
                }
            }
            // Puedes agregar más condiciones aquí para otros tipos de celdas
            x++;
        }
        y++;
    }
}

void	init_game(map)
{
    t_data data;
    data.map = &map;

    // Inicialización de MiniLibX
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);

    // Crear una nueva ventana con el tamaño adecuado
    data.win_ptr = mlx_new_window(data.mlx_ptr, map.width * TILE_SIZE, map.height * TILE_SIZE, "Mapa");
    if (data.win_ptr == NULL)
    {
        free(data.mlx_ptr);
        return (1);
    }

    // Dibujar el mapa
    draw_map(&data);

    // Iniciar el ciclo principal de eventos
    mlx_loop(data.mlx_ptr);

    return (0);
}

