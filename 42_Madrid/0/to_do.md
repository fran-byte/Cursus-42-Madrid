**Desarrollo del Proyecto Libft**

---

### **1. Configuración del Entorno**
- **Compilador y Editor**: Asegúrate de tener `gcc` instalado y un editor (VS Code, Vim, etc.).
- **Estructura de Directorios**:
  ```
  libft/
  ├── includes/     # Archivos de cabecera
  │   └── libft.h
  ├── srcs/         # Código fuente (.c)
  ├── objs/         # Objetos compilados (.o)
  └── Makefile
  ```

---

### **2. Archivo de Cabecera (`libft.h`)**
```c
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// Prototipos de funciones estándar
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
// ... otros prototipos

#endif
```

---

### **3. Implementación de Funciones Básicas**
**Ejemplo: `ft_strlen`** (archivo `ft_strlen.c`):
```c
#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}
```

**Ejemplo: `ft_strdup`** (usa `malloc`):
```c
#include "libft.h"

char *ft_strdup(const char *s)
{
    char *dup;
    size_t len;

    len = ft_strlen(s) + 1;
    dup = (char *)malloc(len);
    if (!dup)
        return (NULL);
    ft_strlcpy(dup, s, len); // Usar ft_strlcpy para copiar
    return (dup);
}
```

---

### **4. Funciones Adicionales**
**Ejemplo: `ft_split`** (divide una cadena):
```c
#include "libft.h"

static int  count_words(const char *s, char c)
{
    int count;

    count = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
            count++;
        while (*s && *s != c)
            s++;
    }
    return (count);
}

char **ft_split(const char *s, char c)
{
    // Implementación completa aquí
    // (Ver manejo de memoria y casos de borde)
}
```

---

### **5. Makefile**
```makefile
NAME = libft.a
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
mkdir -p $@

clean:
rm -rf $(OBJ_DIR)

fclean: clean
rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

### **6. Pruebas**
**Ejemplo de prueba unitaria** (`test_ft_strlen.c`):
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *str = "Hola Mundo";
    printf("ft_strlen: %zu\n", ft_strlen(str)); // Debe imprimir 10
    return (0);
}
```
Compilar y ejecutar:
```bash
gcc -Iincludes test_ft_strlen.c libft.a -o test && ./test
```

---

### **7. Documentación**
- **Comentarios en código**: Explica la lógica de funciones complejas.
- **README.md**:
  ```
  # Libft

  Biblioteca personalizada de funciones en C.

  ## Instalación
  Ejecutar `make` para compilar la biblioteca estática `libft.a`.

  ## Uso
  Incluir `libft.h` y enlazar con `-lft`.

  ## Funciones implementadas
  - `ft_strlen`: Calcula la longitud de una cadena.
  - `ft_strdup`: Duplica una cadena.
  - ... (lista completa)
  ```

---

### **8. Consideraciones Clave**
- **Manejo de Memoria**: Verifica siempre el retorno de `malloc`.
- **Casos Extremos**: Cadenas vacías, NULLs, valores numéricos límite.
- **Optimización**: Usa `valgrind` para detectar fugas de memoria.
- **Normas**: Asegúrate de seguir todas las normas de estilo (norminette) (ej: 25 líneas por función, 4 argumentos máx. por función, 5 variables máx. por función, etc).
