# Makefile de libft
### 1. **VARIABLES**
```make
# variables
FLAG = -Wall -Wextra -Werror
NAME = libft.a
CC = gcc
RM = rm -f
AR = ar rcs
```

- **FLAG**: Esta variable contiene los flags que se pasan al compilador.
  - `-Wall`: Habilita todos los avisos sobre características de código que pueden no ser problemas, pero que pueden ser mejoras.
  - `-Wextra`: Habilita avisos adicionales que no están incluidos en `-Wall`.
  - `-Werror`: Convierte los avisos en errores, haciendo que el compilador no genere el archivo objeto si hay algún aviso.

- **NAME**: Esta variable define el nombre de la biblioteca que se va a generar, en este caso `libft.a`.

- **CC**: Define el compilador a utilizar, que es `gcc`.

- **RM**: Es el comando para eliminar archivos; `rm -f` forzará la eliminación sin pedir confirmación.

- **AR**: Define el comando para crear bibliotecas estáticas, en este caso, `ar rcs`:
  - `r`: Añade archivos a una biblioteca.
  - `c`: Crea la biblioteca si no existe.
  - `s`: Crea un índice para la biblioteca.

### 2. **Archivos fuente obligatorios**

```make
# mandatory files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
```

- **SRC**: Aquí se listan todos los archivos `.c` que se van a compilar para formar la biblioteca. Cada línea está separada por una barra invertida (`\`), que permite dividir la lista en varias líneas para mayor legibilidad.

### 3. **Archivos fuente adicionales (bonus)**

```make
# bonus files
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
```

- **BONUS_SRC**: Similar a `SRC`, pero contiene los archivos de código fuente que se consideran parte de una sección adicional (bonus) del proyecto. Esto sugiere que estas funciones son opcionales o que se mejoran las funcionalidades existentes.

### 4. **Objetos generados a partir de los archivos fuente**

```make
# objects
OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}
```

- **OBJ**: Se define una variable que contiene todos los archivos objeto (`.o`) correspondientes a los archivos fuente (`.c`). Esta sintaxis `${SRC:.c=.o}` reemplaza la extensión `.c` por `.o` para todos los archivos listados en `SRC`.

- **BONUS_OBJ**: Lo mismo que `OBJ`, pero para los archivos de bonificación en `BONUS_SRC`.

### 5. **Reglas de compilación**

```make
# rules ---------------------------------------------
all: ${NAME}
```

- **all**: Esta es la regla principal y se ejecuta cuando simplemente se escribe `make` en la línea de comandos. Depende de la regla `${NAME}`, que se definió anteriormente como `libft.a`.

```make
# create the library from object files
${NAME}: ${OBJ}
${AR} ${NAME} ${OBJ}
@echo "\n****** Library ${NAME} created ******"
```

- **${NAME}: ${OBJ}**: Esta regla se ejecuta cuando se necesita crear la biblioteca (`libft.a`). Depende de los archivos objeto que se generaron anteriormente.
 
- **${AR} ${NAME} ${OBJ}**: Usa la variable `AR` para crear la biblioteca a partir de los archivos objeto.

- **@echo ...**: Imprime un mensaje en la consola. El `@` evita que el comando `echo` se imprima antes de su ejecución.

```make
# compile the bonus part
bonus: ${BONUS_OBJ}
${AR} ${NAME} ${BONUS_OBJ}
@echo "\n****** Bonus part compiled and added to ${NAME} ******"
```

- **bonus**: Esta regla permite compilar y agregar la parte de bonificación a la biblioteca. Se ejecuta con `make bonus`.

- **${AR} ${NAME} ${BONUS_OBJ}**: Similar a la regla anterior, pero utiliza los archivos objeto de bonificación.

```make
# compile source files into object files
%.o: %.c
${CC} ${FLAG} -c $< -o $@
```

- **%.o: %.c**: Esta es una regla de patrón que indica cómo compilar los archivos fuente en archivos objeto. `$<` representa el primer prerequisito (el archivo `.c` que se está compilando) y `$@` es el objetivo (el archivo `.o` que se está creando).

- **${CC} ${FLAG} -c $< -o $@**: Ejecuta el compilador `gcc` con los flags definidos para compilar un archivo `.c` en un archivo `.o`.

### 6. **Limpieza de archivos**

```make
# remove object files
clean:
${RM} ${OBJ} ${BONUS_OBJ}
@echo "\n****** Object files cleaned ******"
```

- **clean**: Esta regla se ejecuta con `make clean` y se usa para eliminar los archivos objeto generados.

- **${RM} ${OBJ} ${BONUS_OBJ}**: Usa la variable `RM` para eliminar los archivos objeto.

```make
# remove object files and the library
fclean: clean
${RM} ${NAME}
@echo "\n****** Library and object files cleaned ******"
```

- **fclean**: Se ejecuta con `make fclean` y primero llama a `clean` para eliminar los archivos objeto, y luego también elimina la biblioteca `libft.a`.

```make
# rebuild everything (clean and then compile everything)
re: fclean all
```

- **re**: Se ejecuta con `make re` y se utiliza para limpiar todo y luego compilar nuevamente todo desde cero, llamando a `fclean` y luego a `all`.

### 7. **Evitar conflictos**

```make
# prevent conflicts with files named like them
.PHONY: all clean fclean re bonus
```

- **.PHONY**: Esta línea indica que las reglas listadas (`all`, `clean`, `fclean`, `re`, `bonus`) son "phony" (no representan archivos reales). Esto significa que siempre se ejecutarán, incluso si hay archivos en el directorio con el mismo nombre.

---
# POR LINEA DE COMADOS
### 1. **Compilar los archivos fuente y crear la librería**

```bash
# Compilar cada archivo .c en su correspondiente .o
gcc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o
gcc -Wall -Wextra -Werror -c ft_isdigit.c -o ft_isdigit.o
...resto de archivos .c ........

# Crear la librería estática a partir de los archivos objeto
ar rcs libft.a ft_isalpha.o ft_isdigit.o
...resto de archivos .o
```

### 2. **Compilar los archivos de bonificación (opcional)**

```bash
# Compilar los archivos bonus
gcc -Wall -Wextra -Werror -c ft_lstnew_bonus.c -o ft_lstnew_bonus.o
gcc -Wall -Wextra -Werror -c ft_lstadd_front_bonus.c -o ft_lstadd_front_bonus.o
...resto de archivos .o

# Añadir los archivos objeto de bonificación a la librería
ar rcs libft.a ft_lstnew_bonus.o ft_lstadd_front_bonus.o 
resto de archivos .o del bonus ...
```

### 3. **Limpiar archivos objeto**

```bash
# Eliminar los archivos objeto generados
rm -f ft_isalpha.o ft_isdigit.o
resto de archivos .o  ...
```

### 4. **Eliminar la librería y los archivos objeto**

```bash
# Eliminar la librería y los archivos objeto
rm -f libft.a ft_isalpha.o ft_isdigit.o
resto de archivos .o  ...
```

### 5. **Limpiar todo y recompilar**

```bash
# Limpiar
rm -f libft.a ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
resto de archivos .o  ...

# Volver a compilar y crear la librería estática desde cero
gcc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o
gcc -Wall -Wextra -Werror -c ft_isdigit
resto de archivos ...


# Crear la librería estática a partir de los archivos objeto recompilados
ar rcs libft.a ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o \
resto de archivos .o  ...
```
