## [ft_strlcat](libft/ft_strlcat.c)

size_t     ft_strlcat(char *dst, const char *src, size_t dstsize)

Descripción: Añade la cadena terminada en NUL "src" al final de "dst". Está diseñado para evitar desbordamientos de búfer al copiar un número limitado de caracteres. El resultado es siempre una cadena terminada en NUL, a menos que el tamaño "dstsize" sea cero
Param. #1: Cadena de destino
Param. #2: Cadena a agregar
Param. #3: El tamaño máximo del búfer de destino
Valor de Retorno: La longitud total de la cadena que se intentó crear (longitud de "src" + longitud inicial de "dst")

## [ft_strnstr](libft/ft_strnstr.c)

char       *ft_strnstr(const char *haystack, const char *needle, size_t len)

Descripción: Localiza la primera aparición de la subcadena "needle" dentro de "haystack", buscando como máximo "len" caracteres. Los caracteres que aparecen después de un \0 no se buscan
Param. #1: Cadena donde buscar
Param. #2: Subcadena a localizar
Param. #3: El número de caracteres a buscar
Valor de Retorno: Un puntero a la primera ocurrencia de "needle" o NULL si no se encuentra la subcadena en los primeros "len" caracteres

## [ft_strcmp](libft/ft_strcmp.c)

int        ft_strcmp(const char *s1, const char *s2)

Descripción: Compara las cadenas "s1" y "s2". Devuelve un número negativo si "s1" es menor que "s2", positivo si "s1" es mayor que "s2" y 0 si son iguales
Param. #1: Primera cadena
Param. #2: Segunda cadena
Valor de Retorno: Un entero negativo, positivo o cero según la relación entre "s1" y "s2"

## [ft_strncmp](libft/ft_strncmp.c)

int        ft_strncmp(const char *s1, const char *s2, size_t n)

Descripción: Compara como máximo "n" caracteres de las cadenas "s1" y "s2". Devuelve un número negativo si "s1" es menor que "s2", positivo si "s1" es mayor que "s2" y 0 si son iguales
Param. #1: Primera cadena
Param. #2: Segunda cadena
Param. #3: Número de caracteres a comparar
Valor de Retorno: Un entero negativo, positivo o cero según la relación entre "s1" y "s2"

## [ft_strnew](libft/ft_strnew.c)

char       *ft_strnew(size_t size)

Descripción: Crea una nueva cadena vacía de "size" bytes, inicializada a '\0'. Usa malloc para asignar memoria
Param. #1: Tamaño de la cadena a crear
Valor de Retorno: Un puntero a la nueva cadena, o NULL si la asignación de memoria falla

## [ft_strdel](libft/ft_strdel.c)

void       ft_strdel(char **as)

Descripción: Libera la memoria de la cadena apuntada por "as" y luego pone el puntero a NULL
Param. #1: La dirección de un puntero a la cadena a eliminar
Valor de Retorno: Ninguno

## [ft_strclr](libft/ft_strclr.c)

void       ft_strclr(char *s)

Descripción: Establece cada carácter de la cadena "s" en '\0'
Param. #1: Cadena a borrar
Valor de Retorno: Ninguno

## [ft_striter](libft/ft_striter.c)

void       ft_striter(char *s, void (*f)(char *))

Descripción: Aplica la función "f" a cada carácter de la cadena "s". Cada carácter se pasa como un puntero a "f"
Param. #1: Cadena a iterar
Param. #2: Función a aplicar
Valor de Retorno: Ninguno

## [ft_striteri](libft/ft_striteri.c)

void       ft_striteri(char *s, void (*f)(unsigned int, char *))

Descripción: Aplica la función "f" a cada carácter de la cadena "s", proporcionando el índice del carácter en el primer argumento de "f"
Param. #1: Cadena a iterar
Param. #2: Función a aplicar
Valor de Retorno: Ninguno

## [ft_strmap](libft/ft_strmap.c)

char       *ft_strmap(const char *s, char (*f)(char))

Descripción: Aplica la función "f" a cada carácter de la cadena "s" para crear una nueva cadena con los resultados de la función
Param. #1: Cadena a transformar
Param. #2: Función a aplicar
Valor de Retorno: Una nueva cadena con los resultados de "f", o NULL si falla la asignación de memoria

## [ft_strmapi](libft/ft_strmapi.c)

char       *ft_strmapi(const char *s, char (*f)(unsigned int, char))

## [ft_strmapi](libft/ft_strmapi.c)

char       *ft_strmapi(const char *s, char (*f)(unsigned int, char))

Descripción: Aplica la función "f" a cada carácter de la cadena "s", proporcionando el índice del carácter en el primer argumento de "f" para crear una nueva cadena con los resultados de la función
Param. #1: Cadena a transformar
Param. #2: Función a aplicar
Valor de Retorno: Una nueva cadena con los resultados de "f", o NULL si falla la asignación de memoria

## [ft_strequ](libft/ft_strequ.c)

int        ft_strequ(const char *s1, const char *s2)

Descripción: Compara las cadenas "s1" y "s2" para verificar si son iguales. Devuelve 1 si son iguales, 0 si no lo son
Param. #1: Primera cadena
Param. #2: Segunda cadena
Valor de Retorno: 1 si las cadenas son iguales, 0 si no lo son

## [ft_strnequ](libft/ft_strnequ.c)

int        ft_strnequ(const char *s1, const char *s2, size_t n)

Descripción: Compara como máximo "n" caracteres de las cadenas "s1" y "s2". Devuelve 1 si son iguales, 0 si no lo son
Param. #1: Primera cadena
Param. #2: Segunda cadena
Param. #3: Número de caracteres a comparar
Valor de Retorno: 1 si las cadenas son iguales, 0 si no lo son

## [ft_strsub](libft/ft_strsub.c)

char       *ft_strsub(const char *s, unsigned int start, size_t len)

Descripción: Crea una nueva cadena que es una subcadena de "s", comenzando en el índice "start" y de longitud "len"
Param. #1: Cadena original
Param. #2: Índice de inicio de la subcadena
Param. #3: Longitud de la subcadena
Valor de Retorno: Un puntero a la nueva subcadena, o NULL si la asignación de memoria falla

## [ft_strjoin](libft/ft_strjoin.c)

## [ft_putstr](libft/ft_putstr.c)

void       ft_putstr(const char *s)

Descripción: Escribe la cadena "s" en la salida estándar
Param. #1: La cadena a escribir
Valor de Retorno: Ninguno

## [ft_putendl](libft/ft_putendl.c)

void       ft_putendl(const char *s)

Descripción: Escribe la cadena "s" seguida de un salto de línea en la salida estándar
Param. #1: La cadena a escribir
Valor de Retorno: Ninguno

## [ft_putnbr](libft/ft_putnbr.c)

void       ft_putnbr(int n)

Descripción: Escribe el número entero "n" en la salida estándar
Param. #1: El número entero a escribir
Valor de Retorno: Ninguno

## [ft_putchar_fd](libft/ft_putchar_fd.c)

void       ft_putchar_fd(char c, int fd)

Descripción: Escribe el carácter "c" en el archivo o descriptor de archivo dado
Param. #1: El carácter a escribir
Param. #2: El descriptor de archivo
Valor de Retorno: Ninguno

## [ft_putstr_fd](libft/ft_putstr_fd.c)

void       ft_putstr_fd(const char *s, int fd)

Descripción: Escribe la cadena "s" en el archivo o descriptor de archivo dado
Param. #1: La cadena a escribir
Param. #2: El descriptor de archivo
Valor de Retorno: Ninguno

## [ft_putendl_fd](libft/ft_putendl_fd.c)

void       ft_putendl_fd(const char *s, int fd)

Descripción: Escribe la cadena "s" seguida de un salto de línea en el archivo o descriptor de archivo dado
Param. #1: La cadena a escribir
Param. #2: El descriptor de archivo
Valor de Retorno: Ninguno

## [ft_putnbr_fd](libft/ft_putnbr_fd.c)

void       ft_putnbr_fd(int n, int fd)

Descripción: Escribe el número entero "n" en el archivo o descriptor de archivo dado
Param. #1: El número entero a escribir
Param. #2: El descriptor de archivo
Valor de Retorno: Ninguno

char       *ft_strjoin(const char *s1, const char *s2)

Descripción: Crea una nueva cadena que es la concatenación de las cadenas "s1" y "s2"
Param. #1: Primera cadena
Param. #2: Segunda cadena
Valor de Retorno: Un puntero a la nueva cadena, o NULL si la asignación de memoria falla

## [ft_strtrim](libft/ft_strtrim.c)

char       *ft_strtrim(const char *s)

Descripción: Crea una nueva cadena eliminando los espacios en blanco al principio y al final de la cadena "s"
Param. #1: Cadena a recortar
Valor de Retorno: Un puntero a la nueva cadena recortada, o NULL si la asignación de memoria falla

## [ft_strsplit](libft/ft_strsplit.c)

char       **ft_strsplit(const char *s, char c)

Descripción: Divide la cadena "s" en subcadenas utilizando el carácter "c" como delimitador. La cadena resultante es una matriz de cadenas
Param. #1: Cadena a dividir
Param. #2: Carácter delimitador
Valor de Retorno: Un puntero a una matriz de nuevas cadenas, o NULL si la asignación de memoria falla

## [ft_itoa](libft/ft_itoa.c)

char       *ft_itoa(int n)

Descripción: Convierte el entero "n" a una cadena de caracteres. Utiliza malloc para la asignación de memoria
Param. #1: El número entero a convertir
Valor de Retorno: Un puntero a la nueva cadena, o NULL si la asignación de memoria falla

## [ft_putchar](libft/ft_putchar.c)

void       ft_putchar(char c)

Descripción: Escribe el carácter "c" en la salida estándar
Param. #1: El carácter a escribir
Valor de Retorno: Ninguno

