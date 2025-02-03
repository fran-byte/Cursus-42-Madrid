<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20so_long%20%20-1e90ff" style="width:140px;height:40px;"></a>

</div>

# so_long

Este proyecto es una introducción a la creación de videojuegos 2D utilizando la biblioteca **MiniLibX**. El objetivo es desarrollar un juego simple donde un personaje se mueve por un mapa, recolecta objetos y alcanza una salida para ganar. A continuación, se detalla la estructura y los componentes clave del proyecto.

---

## Resumen del Proyecto

| **Aspecto**          | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **Objetivo**          | Crear un juego 2D donde el jugador recolecta objetos y alcanza una salida.      |
| **Mapa**              | Representado por un archivo `.ber` con elementos como paredes (`1`), espacio vacío (`0`), personaje (`P`), coleccionables (`C`) y salida (`E`). |
| **Interacciones**     | El jugador mueve al personaje con el teclado para recolectar objetos y llegar a la salida. |
| **Requisitos**        | Validación del mapa, uso de MiniLibX para gráficos, y manejo de eventos.        |
| **Aprendizajes**      | Gráficos 2D, gestión de eventos, validación de datos, y organización de proyectos en C. |

---

## Organización del Proyecto

### **Estructura de Archivos**

| **Archivo**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`so_long.c`**       | Función principal del programa.                                                 |
| **`map_validation.c`**| Contiene funciones para validar el mapa (rectangular, rodeado de paredes, etc.).|
| **`graphics.c`**      | Maneja la renderización de gráficos usando MiniLibX.                            |
| **`events.c`**        | Gestiona eventos como teclas presionadas y cierre de la ventana.                |
| **`player.c`**        | Controla el movimiento y las interacciones del personaje.                       |
| **`utils.c`**         | Funciones auxiliares para manejo de memoria, errores, etc.                      |



<p align="center" width="100%"><a href="#"><img src="../../img/milestone_3/so_long_flujo.png" width="900" /></a></p>
---

## MiniLibX: Biblioteca Gráfica

MiniLibX es una biblioteca ligera para crear gráficos 2D y manejar eventos en C. A continuación, se describen sus componentes principales:

### **1. Inicialización**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_init()`**      | Inicializa MiniLibX y devuelve un puntero a la conexión gráfica.                |
| **`mlx_new_window()`**| Crea una nueva ventana gráfica con un tamaño y título específicos.              |

**Ejemplo**:
```c
void *mlx_ptr = mlx_init();
void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
```

---

### **2. Colores**

| **Formato**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`0xRRGGBB`**        | Formato hexadecimal para definir colores (8 bits por canal).                    |
| **Ejemplos**          | `0xFFFFFF` (Blanco), `0xFF0000` (Rojo), `0x00FF00` (Verde), `0x0000FF` (Azul).  |

**Función**:
```c
mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0x00FF00); // Dibuja un píxel verde en (100, 100)
```

---

### **3. Dibujo de Gráficos**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_new_image()`** | Crea una imagen en memoria para dibujar píxeles eficientemente.                 |
| **`mlx_get_data_addr()`** | Obtiene un puntero a los datos de la imagen para manipular píxeles.           |
| **`mlx_put_image_to_window()`** | Muestra la imagen en la ventana.                                     |

**Ejemplo**:
```c
void *img = mlx_new_image(mlx_ptr, 800, 600);
char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

// Dibujar un píxel rojo en (100, 50)
int x = 100, y = 50;
int color = 0xFF0000;
*(int *)(data + (y * size_line + x * (bpp / 8))) = color;

mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
```

---

### **4. Carga de Imágenes**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_xpm_file_to_image()`** | Carga una imagen `.xpm` desde un archivo.                                   |
| **`mlx_put_image_to_window()`** | Muestra la imagen en la ventana.                                     |

**Ejemplo**:
```c
void *img = mlx_xpm_file_to_image(mlx_ptr, "sprite.xpm", &width, &height);
mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100, 100);
```

---

### **5. Gestión de Eventos**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_key_hook()`**  | Maneja eventos de teclado.                                                      |
| **`mlx_mouse_hook()`**| Maneja eventos del ratón.                                                       |
| **`mlx_hook()`**      | Maneja eventos generales (cierre de ventana, etc.).                             |
| **`mlx_loop()`**      | Inicia el bucle principal para mantener la ventana abierta y procesar eventos.  |

**Ejemplo**:
```c
int handle_keypress(int keycode, void *param)
{
    if (keycode == 53) // Tecla Esc en macOS
        exit(0);
    return (0);
}

mlx_key_hook(win_ptr, handle_keypress, NULL);
mlx_loop(mlx_ptr);
```

---

### **6. Cierre Limpio**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_destroy_window()`** | Cierra y libera la memoria de una ventana.                                   |
| **`mlx_destroy_image()`** | Libera la memoria asociada a una imagen.                                     |

**Ejemplo**:
```c
mlx_destroy_window(mlx_ptr, win_ptr);
mlx_destroy_image(mlx_ptr, img_ptr);
```

---

### **7. Textos**

| **Función**           | **Descripción**                                                                 |
|-----------------------|---------------------------------------------------------------------------------|
| **`mlx_string_put()`**| Dibuja texto en la ventana.                                                     |

**Ejemplo**:
```c
mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0xFFFFFF, "Hola, so_long!");
```

---

## Validación del Mapa

El mapa debe cumplir las siguientes reglas:
1. **Formato rectangular**: Todas las filas deben tener la misma longitud.
2. **Rodeado de paredes**: Los bordes del mapa deben estar formados por paredes (`1`).
3. **Elementos obligatorios**:
   - Un personaje (`P`).
   - Una salida (`E`).
   - Al menos un coleccionable (`C`).
4. **Camino válido**: Debe existir un camino desde el personaje hasta la salida, pasando por todos los coleccionables.

---

## Ejemplo de Mapa

```plaintext
1111111111
1001000001
101100C001
10P0010001
1111111111
```

---

## Flujo de Ejecución

1. **Cargar el mapa**: Leer el archivo `.ber` y validar su estructura.
2. **Inicializar gráficos**: Crear la ventana y cargar las imágenes (sprites, fondos, etc.).
3. **Manejar eventos**: Capturar teclas presionadas y mover al personaje.
4. **Actualizar el juego**: Verificar si el jugador ha recolectado todos los objetos y alcanzado la salida.
5. **Cerrar el juego**: Liberar recursos y salir correctamente.

---

## Referencias

- [Documentación de MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Ejemplos de uso de MiniLibX](https://github.com/42Paris/minilibx-linux)

