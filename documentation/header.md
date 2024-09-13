### ¿Qué son los archivos `.h` y `.c`?

- **Archivos `.h` (headers o cabeceras)**: Estos archivos contienen **declaraciones** de funciones, macros, constantes y estructuras de datos que se utilizarán en diferentes archivos `.c`. Los `.h` no contienen el código fuente completo, sino que sirven como un "contrato" para los archivos `.c`.
  
- **Archivos `.c` (código fuente)**: Estos archivos contienen la **implementación** de las funciones y el código que hace funcionar tu programa.

### ¿Cómo enlazan los archivos `.h` y `.c`?

1. **Declaración de funciones en el archivo `.h`**: Declaras las funciones que implementarás en los archivos `.c` dentro del archivo `.h`. Esto le dice a otros archivos `.c` cómo pueden llamar a esas funciones sin tener que conocer su implementación exacta.
   
2. **Incluir el archivo `.h` en el archivo `.c`**: Para que los archivos `.c` conozcan las funciones, estructuras, o variables globales definidas en el `.h`, deben **incluir** ese archivo usando la directiva `#include`.

3. **Compilación y enlazado**: Cuando el compilador genera los archivos objeto (.o), estos archivos son combinados para crear el ejecutable final, donde se enlazan todas las referencias entre funciones y variables de los diferentes archivos.

### Pasos para enlazar archivos `.h` y `.c`

#### 1. Crear el archivo de cabecera `.h`

El archivo de cabecera es donde se declaran las funciones, las estructuras y cualquier otra cosa que quieras compartir entre múltiples archivos `.c`.

##### Ejemplo: `funciones.h`

```c
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Declaración de funciones
void funcion1(void);
void funcion2(int a);

// Declaración de estructuras, constantes, etc. (si es necesario)
typedef struct {
    int valor;
} EstructuraEjemplo;

#endif
```

- **Explicación**:
  - `#ifndef, #define y #endif`: Estas líneas previenen la inclusión múltiple de este archivo (guardas de inclusión), es decir, aseguran que el contenido de este archivo solo sea incluido una vez en cada archivo `.c`.
  - Declaras funciones (`funcion1`, `funcion2`) que luego implementarás en archivos `.c`.
  - También puedes declarar estructuras o macros que serán compartidas entre los archivos `.c`.

#### 2. Crear los archivos `.c` con las implementaciones

Cada archivo `.c` implementará las funciones que declaraste en el `.h`. Cada archivo `.c` incluirá el `.h` correspondiente para que las demás funciones y estructuras sean accesibles.

##### Ejemplo: `funcion1.c`

```c
#include "funciones.h"
#include <stdio.h>  // Incluye otras librerías estándar si es necesario

// Implementación de funcion1
void funcion1(void) {
    printf("Funcion 1 ejecutada.\n");
}
```

##### Ejemplo: `funcion2.c`

```c
#include "funciones.h"
#include <stdio.h>

// Implementación de funcion2
void funcion2(int a) {
    printf("Funcion 2 ejecutada con valor: %d\n", a);
}
```

#### 3. Crear el `main.c` que utilice estas funciones

El archivo `main.c` es donde llamas a las funciones definidas en otros archivos `.c`, pero utilizando el archivo `.h` para hacer la "conexión".

##### Ejemplo: `main.c`

```c
#include "funciones.h"

int main(void) {
    funcion1();    // Llama a funcion1 definida en funcion1.c
    funcion2(5);   // Llama a funcion2 definida en funcion2.c
    return 0;
}
```

- En este archivo, no necesitas conocer los detalles de la implementación de `funcion1` y `funcion2`, solo tienes que incluir `funciones.h` para poder usarlas.

### 4. Compilación con `Makefile`

Para compilar todos estos archivos `.c` y enlazarlos en un ejecutable, puedes usar un **Makefile** como el que te mostré anteriormente. A continuación te muestro cómo integrarlo con los nuevos archivos.

#### Ejemplo de Makefile para compilar varios archivos `.c`:

```makefile
# Nombre del ejecutable
NAME = mi_programa

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRC = main.c funcion1.c funcion2.c
OBJ = $(SRC:.c=.o)

# Regla principal: compila todo
all: $(NAME)

$(NAME): $(OBJ)
$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Limpia los archivos objeto
clean:
rm -f $(OBJ)

# Limpia todo, incluyendo el ejecutable
fclean: clean
rm -f $(NAME)

# Vuelve a compilar desde cero
re: fclean all

.PHONY: all clean fclean re
```

### Explicación de cómo ocurre el enlace:

1. **Inclusión del archivo `.h`**: 
   - En `main.c`, `funcion1.c` y `funcion2.c` incluyes el archivo `funciones.h`. Esto le dice a cada archivo que las funciones `funcion1` y `funcion2` están declaradas, incluso si su implementación está en otro archivo `.c`.

2. **Compilación separada de cada archivo `.c`**: 
   - El Makefile genera archivos objeto `.o` para cada archivo `.c` por separado. Estos archivos contienen el código máquina pero todavía no están enlazados.

3. **Enlazado final**: 
   - En la línea `$(CC) $(CFLAGS) -o $(NAME) $(OBJ)`, el compilador toma todos los archivos objeto generados y los enlaza juntos para formar el ejecutable final `mi_programa`.

### Resumen

- Los archivos `.h` permiten compartir declaraciones entre varios archivos `.c` y definir interfaces comunes para que las funciones y estructuras sean accesibles.
- Los archivos `.c` implementan el código de las funciones y utilizan las declaraciones del archivo `.h`.
- Al compilar y enlazar, el compilador usa los archivos objeto generados por cada `.c` y los combina para formar el programa completo.

Este método te permite separar claramente la lógica de tu programa en varios archivos, lo que facilita la mantenibilidad y escalabilidad de tu código.
