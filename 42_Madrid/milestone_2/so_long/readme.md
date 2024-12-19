# so_long

Es un proyecto introductorio en la creación de videojuegos 2D simples utilizando gráficos básicos con la biblioteca **MiniLibX**. El objetivo principal es la familiarización con la manipulación de gráficos, eventos del teclado y la creación de mapas, mientras se aplican principios de programación estructurada.

### Resumen del proyecto:
1. **Objetivo**: Crear un pequeño juego en 2D donde un personaje se mueve por un mapa recolectando objetos, alcanzando un punto de salida para ganar.
2. **Elementos principales**:
   - **Mapa**: El juego utiliza un mapa representado por un archivo `.ber` (un archivo de texto con una representación en formato rectangular). Este mapa debe contener:
     - Un personaje jugable (`P`).
     - Una salida (`E`).
     - Al menos un coleccionable (`C`).
     - Paredes (`1`) y espacio vacío (`0`).
   - **Interacciones**: El jugador debe mover al personaje con el teclado para recolectar todos los coleccionables antes de llegar a la salida.
3. **Requisitos técnicos**:
   - El mapa debe ser validado para cumplir ciertas reglas (ser rectangular, rodeado de paredes, y con al menos un camino válido hacia la salida).
   - Se debe usar **MiniLibX** para renderizar gráficos básicos.
   - La gestión de eventos como presionar teclas o cerrar la ventana debe implementarse correctamente.
4. **Aprendizajes clave**:
   - Manipulación de gráficos 2D.
   - Gestión de entradas del usuario y eventos.
   - Validación y parsing de datos.
   - Organización de un proyecto en C.


# MiniLibX:

**MiniLibX** (Mini Library X) es una biblioteca gráfica diseñada por y para la comunidad de la escuela 42. Es un entorno liviano y simplificado que permite trabajar con gráficos 2D y eventos en el lenguaje de programación C.

---

### **Características Principales**
1. **Interfaz Simple**: MiniLibX proporciona una API minimalista para crear ventanas, manejar gráficos y capturar eventos.
2. **Compatibilidad Limitada**: Está diseñada para funcionar exclusivamente en entornos Unix-like (macOS y Linux) y utiliza dependencias como X11 en Linux y OpenGL para macOS.
3. **Gráficos Básicos**: Soporta operaciones elementales como dibujar píxeles, líneas, formas simples y manejar imágenes.
4. **Gestión de Eventos**: Ofrece herramientas para capturar y manejar interacciones del usuario, como entradas de teclado y ratón.
5. **Uso Educativo**: No es una biblioteca estándar en la industria, pero es ideal para introducir a los estudiantes de 42 en conceptos gráficos.

---

### **Componentes y Funcionalidades**
#### 1. **Inicialización**
   Antes de cualquier operación gráfica, necesitas **inicializar** MiniLibX y abrir una ventana:
   ```c
   void *mlx_ptr = mlx_init(); // Inicializa MiniLibX
   void *win_ptr = mlx_new_window(mlx_ptr, ancho, alto, "Titulo"); // Crea una ventana
   ```

#### 2. **Colores**
   Los colores se definen en formato hexadecimal de 32 bits: `0xRRGGBB`.
   - Ejemplo: `0xFFFFFF` representa blanco, `0xFF0000` es rojo.

#### 3. **Dibujo de Píxeles**
   Puedes dibujar un píxel en la ventana usando:
   ```c
   mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
   ```

#### 4. **Manipulación de Imágenes**
   - Crear una imagen:
     ```c
     void *img_ptr = mlx_new_image(mlx_ptr, ancho, alto);
     ```
   - Dibujar en la imagen manipulando su memoria:
     ```c
     char *img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
     ```
   - Mostrar la imagen en la ventana:
     ```c
     mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
     ```

#### 5. **Carga de Texturas**
   MiniLibX permite cargar imágenes en formato `.xpm` para utilizarlas como texturas:
   ```c
   void *img = mlx_xpm_file_to_image(mlx_ptr, "file.xpm", &width, &height);
   ```

#### 6. **Gestión de Eventos**
   MiniLibX captura eventos como teclas presionadas, movimientos del ratón o clics. Se manejan mediante *hooks* (funciones callback):
   ```c
   mlx_key_hook(win_ptr, funcion_de_evento, parametro);
   mlx_mouse_hook(win_ptr, funcion_de_evento, parametro);
   mlx_hook(win_ptr, evento, mascara, funcion_de_evento, parametro);
   ```
   - Ejemplo de eventos:
     - `2`: Presión de una tecla.
     - `17`: Cerrar ventana.
   - La función `mlx_loop()` activa el ciclo principal, manteniendo la ventana abierta:
     ```c
     mlx_loop(mlx_ptr);
     ```

#### 7. **Cierre Limpio**
   Al finalizar, es fundamental liberar recursos:
   ```c
   mlx_destroy_window(mlx_ptr, win_ptr);
   mlx_destroy_image(mlx_ptr, img_ptr);
   ```

---

### **Dependencias y Configuración**
#### En **macOS**:
   - MiniLibX utiliza OpenGL y puede instalarse fácilmente desde los repositorios de 42 o mediante un `Makefile` configurado.
   - No requiere configuración adicional.

#### En **Linux**:
   - Requiere instalar las dependencias de **X11**:
     ```bash
     sudo apt-get install libx11-dev libxext-dev
     ```

---

### **Ventajas y Limitaciones**

#### **Ventajas**:
1. **Simplicidad**: Es ideal para aprender los fundamentos de gráficos 2D en C.
2. **Integración**: Diseñada específicamente para proyectos en 42, por lo que tiene una curva de aprendizaje adaptada al currículum.
3. **Ligera y Directa**: No introduce conceptos avanzados innecesarios para principiantes.

#### **Limitaciones**:
1. **Portabilidad**: Funciona únicamente en sistemas Unix-like, con una implementación específica para macOS y Linux.
2. **Capacidades Limitadas**: No soporta gráficos 3D ni operaciones avanzadas como sombreado o transformación.
3. **Falta de Documentación Oficial**: La documentación oficial es escasa, lo que obliga a los usuarios a aprender a través de ejemplos y proyectos previos.


---

### **Ejemplo Completo**
```c
#include "mlx.h"
#include <stdlib.h>

int cerrar_ventana(int keycode, void *param)
{
    (void)keycode;
    (void)param;
    exit(0);
}

int main()
{
    void *mlx;
    void *win;

    // Inicialización
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "MiniLibX Example");

    // Dibujar un píxel
    mlx_pixel_put(mlx, win, 400, 300, 0xFF0000); // Píxel rojo en el centro

    // Hook para cerrar la ventana
    mlx_hook(win, 17, 0, cerrar_ventana, NULL);

    // Loop principal
    mlx_loop(mlx);

    return (0);
}
```
