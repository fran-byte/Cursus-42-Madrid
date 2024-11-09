### ¿Qué es un Makefile?

Un **Makefile** es un archivo que define cómo deben ser compilados y enlazados los archivos de un proyecto de programación. En este caso, trabajarás en un proyecto en C, y un Makefile te permitirá automatizar la compilación y enlazado de tu programa y gestionar fácilmente sus dependencias.

### Componentes básicos de un Makefile

Para cumplir con las instrucciones de tu proyecto, tu Makefile debe contener al menos las siguientes reglas:

- `$(NAME)` para definir el nombre del ejecutable.
- `all` para compilar tu proyecto.
- `clean` para eliminar los archivos temporales o de objetos (.o).
- `fclean` para eliminar todo, incluyendo el ejecutable.
- `re` para recompilar todo desde cero.
- `bonus` para compilar los archivos de bonus (si aplica).
  
Además, tendrás que compilar tu proyecto con las banderas de compilación **-Wall -Wextra -Werror**, que activan advertencias estrictas y errores de compilación.

### Pasos para crear tu Makefile

#### 1. Definir variables

En la parte superior del Makefile, define algunas variables comunes. Estas variables te permiten reutilizar nombres y simplificar el mantenimiento.

```makefile
# Nombre del ejecutable
NAME = mi_programa

# Compilador
CC = cc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRC = main.c archivo1.c archivo2.c

# Archivos objeto, se generan a partir de los archivos fuente
OBJ = $(SRC:.c=.o)

# Librerías (si utilizas libft)
LIBFT = libft/libft.a
```

#### 2. Regla `all`

La regla `all` es la que compila el proyecto. Esta regla será la que se ejecute si simplemente invocas `make` en la terminal.

```makefile
all: $(NAME)

# Compila el ejecutable
$(NAME): $(OBJ)
$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Si tienes una librería libft
$(NAME): $(LIBFT) $(OBJ)
$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

# Compilar la librería libft si es necesario
$(LIBFT):
make -C libft
```

- **Explicación**: 
  - La regla `$(NAME)` indica que el ejecutable depende de los archivos `.o` (objetos).
  - `$(CC) $(CFLAGS) -o $(NAME) $(OBJ)` es el comando que usa `gcc` para generar el ejecutable.
  - Si usas una librería como libft, debes añadir la línea para compilar primero la librería.

#### 3. Regla `clean`

Esta regla elimina los archivos objeto (.o) generados durante la compilación, pero no el ejecutable. Esto es útil si solo quieres limpiar parcialmente el proyecto.

```makefile
clean:
rm -f $(OBJ)

# También limpia los objetos de la libft si la estás utilizando
clean:
rm -f $(OBJ)
make clean -C libft
```

#### 4. Regla `fclean`

La regla `fclean` elimina tanto los archivos objeto como el ejecutable. Es una limpieza completa.

```makefile
fclean: clean
rm -f $(NAME)

# Limpia también la librería si aplica
fclean: clean
rm -f $(NAME)
make fclean -C libft
```

#### 5. Regla `re`

La regla `re` es simplemente una combinación de `fclean` seguido de `all`. Sirve para limpiar todo y recompilar desde cero.

```makefile
re: fclean all
```

#### 6. Regla `bonus`

Si tu proyecto incluye archivos adicionales para los bonus, debes especificar cómo compilarlos por separado. Por lo general, estos archivos estarán en formatos como `_bonus.c` y `_bonus.h`.

```makefile
# Archivos de bonus
BONUS_SRC = archivo_bonus1.c archivo_bonus2.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Regla para compilar bonus
bonus: $(BONUS_OBJ)
$(CC) $(CFLAGS) -o $(NAME)_bonus $(BONUS_OBJ)
```

#### 7. Añadir la regla `.PHONY`

Para evitar conflictos con archivos del mismo nombre que tus reglas (`clean`, `fclean`, etc.), es buena práctica usar la regla especial `.PHONY`. Esto le dice a `make` que esas reglas no corresponden a un archivo real.

```makefile
.PHONY: all clean fclean re bonus
```

### Makefile completo


```makefile

# variables
FLAG = -Wall -Wextra -Werror
NAME = libft.a
CC = cc
RM = rm -f
AR = ar rcs

# mandatory files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# bonus files
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# objects
OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

# rules ---------------------------------------------
all: ${NAME}

# create the library from object files
${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	@echo "\n****** Library ${NAME} created ******"

# compile the bonus part
bonus: ${BONUS_OBJ}
	@${AR} ${NAME} ${BONUS_OBJ}

# compile source files into object files
%.o: %.c
	${CC} ${FLAG} -c $< -o $@

# remove object files
clean:
	${RM} ${OBJ} ${BONUS_OBJ}

# remove object files and the library
fclean: clean
	${RM} ${NAME}

# rebuild everything (clean and then compile everything)
re: fclean all

# prevent conflicts with files named like them
.PHONY: all clean fclean re bonus
```

### Consejos finales

1. **Evita el "relinking"**: Al usar archivos objeto (`.o`), evitas recompilar todos los archivos si solo has cambiado uno de ellos.
2. **Banderas de compilación**: Las banderas `-Wall`, `-Wextra`, y `-Werror` te ayudarán a detectar advertencias importantes durante la compilación. Esto es clave para asegurar que tu proyecto esté libre de errores.
3. **Limpieza de memoria**: Asegúrate de liberar toda la memoria que asignas con `malloc` o cualquier otra función que asigne memoria dinámica.
4. **Estructura de archivos**: Es recomendable separar los archivos de código principal y los archivos de bonus para que tu Makefile pueda distinguirlos correctamente.
