
---

## [ft_memset](libft/ft_memset.c)

`void       *ft_memset(void *s, int c, size_t len)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Rellena con "len" bytes de "c" la memoria de "s" | La cadena sobre la que operar | Valor c (convertido a unsigned char) | El número de bytes | Un puntero al área de memoria s

## [ft_bzero](libft/ft_bzero.c)

`void       *ft_bzero(void *s,  size_t n)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Borra los datos en los "n" bytes de la memoria comenzando en la ubicación señalada por "s", escribiendo ceros | La cadena sobre la que operar | El número de bytes | Ninguno

## [ft_memcpy](libft/ft_memcpy.c)

`void       *ft_memcpy(void *dst, const void *src, size_t n)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Copia "n" bytes del área de memoria "src" a la memoria de "dst". Las áreas de memoria no deben solaparse. Usa [ft_memmove](#ft_memmove) si las áreas de memoria se solapan. | Área de memoria dst | Área de memoria src | El número de bytes | Un puntero al área de memoria dst

## [ft_memccpy](libft/ft_memccpy.c)

`void       *ft_memccpy(void *dst, const void *src, int c, size_t n)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Param. #4 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Copia "n" bytes del área de memoria "src" al área de memoria "dst", deteniéndose cuando se encuentra el carácter "c", o después de copiar "n" caracteres, lo que ocurra primero. Si la copia se realiza entre objetos que se solapan, el comportamiento es indefinido. | Área de memoria dst | Área de memoria src | Un carácter a buscar | Número de bytes que memccpy() copió | Un puntero al siguiente carácter en "dst" después de "c", o NULL si "c" no se encontró en los primeros "n" bytes

## [ft_memmove](libft/ft_memmove.c)

`void       *ft_memmove(void *dst, const void *src, size_t len)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Copia "len" bytes de la memoria de "src" a "dst". Las memorias pueden solaparse. Primero, los bytes en "src" se copian en un arreglo temporal y luego a "dst". | Área de memoria dst | Área de memoria src | El número de bytes | Un puntero al área de memoria dst

## [ft_memchr](libft/ft_memchr.c)

`void       *ft_memchr(const void *s, int c, size_t n)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Escanea los primeros "n" bytes de "s" en busca de la primera instancia de "c" | Área de memoria s | Un carácter a buscar | El número de bytes | Un puntero al byte coincidente o NULL si el carácter no aparece en el área de memoria dada

## [ft_memcmp](libft/ft_memcmp.c)

`void       *ft_memcmp(void *dst, const void *src, size_t n)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Compara la cadena de bytes "s1" con la cadena de bytes "s2" | Área de memoria s1 | Área de memoria s2 | El número de bytes | < 0 si s1 es menor que s2, > 0 si s1 es mayor que s2, = 0 si s1 es igual a s2

## [ft_strlen](libft/ft_strlen.c)
`size_t     ft_strlen(const char *s)`

Descripción | Param. #1 | Valores de Retorno
:-----------: | :-----------: | :-----------:
Calcula la longitud de la cadena apuntada por "s", excluyendo el byte nulo de terminación ('\0') | La cadena a calcular | Número de caracteres en la cadena apuntada por "s"

## [ft_strdup](libft/ft_strdup.c)
`char       *ft_strdup(const char *s)`

Descripción | Param. #1 | Valores de Retorno
:-----------: | :-----------: | :-----------:
Duplica la cadena "s". La memoria para la nueva cadena se obtiene con malloc y puede ser liberada con free | La cadena a duplicar | Un puntero a la cadena duplicada. NULL si no había suficiente memoria disponible

## [ft_strndup](libft/ft_strndup.c)

`char       *ft_strndup(const char *s, size_t n)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna una cantidad específica de memoria para copiar una cadena | La cadena a copiar | La cantidad máxima de caracteres a copiar de la cadena | Un puntero a la nueva cadena

## [ft_strcdup](libft/ft_strcdup.c)

`char       *ft_strcdup(const char *s, int c)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna una cantidad específica de memoria para copiar una cadena hasta la aparición de "c". Ejemplo: ft_strcdup("Blue", 'u') -> "Bl" | La cadena a copiar antes de "c" | El carácter "c" | Un puntero a la nueva cadena

## [ft_strchr](libft/ft_strchr.c)

`char		*ft_strchr(const char *s, int c)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza la primera ocurrencia de "c" en la cadena apuntada por "s". El carácter nulo de terminación se considera parte de la cadena, por lo tanto, si "c" es '\0', localiza el '\0' final | Puntero a la cadena | Carácter a localizar | Un puntero a la primera ocurrencia del carácter "c" en la cadena o NULL si no se encuentra el carácter


---

## [ft_strrchr](libft/ft_strrchr.c)

`char		*ft_strrchr(const char *s, int c)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza la última ocurrencia de "c" en la cadena apuntada por "s". El carácter nulo de terminación se considera parte de la cadena, por lo tanto, si "c" es '\0', localiza el '\0' final | Puntero a la cadena | Carácter a localizar | Un puntero a la última ocurrencia del carácter "c" en la cadena o NULL si no se encuentra el carácter

## [ft_strcpy](libft/ft_strcpy.c)

`char       *ft_strcpy(char *dst, const char *src)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Copia una cadena, incluyendo el byte nulo de terminación ('\0') | Arreglo de destino | Cadena a copiar | Un puntero a la cadena de destino "dst"

## [ft_strlcpy](libft/ft_strlcpy.c)

`size_t     ft_strlcpy(char *dst, const char *src, size_t dstsize)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Copia hasta "dstsize - 1" caracteres de la cadena terminada en NUL "src" a "dst", terminando en NUL el resultado | Arreglo de destino | Cadena a copiar | Número de caracteres a copiar de "src" | Longitud total de la cadena creada (longitud de "src")

## [ft_strcat](libft/ft_strcat.c)

`char       *ft_strcat(char *dst, const char *src)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Concatena dos cadenas (agrega "s2" a "s1"), incluyendo el byte nulo de terminación ('\0') | Arreglo de destino | Cadena a agregar a "dst" | Un puntero a la cadena resultante "dst"

## [ft_strlcat](libft/ft_strlcat.c)

`size_t     ft_strlcat(char *dst, const char *src, size_t size)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Concatena la cadena "src" al final de "dst". Concatenará como máximo "size - strlen(dst) - 1" bytes, terminando en NUL el resultado | Arreglo de destino | Cadena a agregar a "dst" | Número máximo de caracteres a agregar | La longitud inicial de "dst" más la longitud de "src"

## [ft_strstr](libft/ft_strstr.c)

`char       *ft_strstr(const char *haystack, const char *needle)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza una subcadena. Encuentra la primera ocurrencia de la subcadena "needle" en la cadena "haystack". Los bytes nulos de terminación ('\0') no se comparan | Cadena donde buscar | La subcadena a buscar en la cadena "haystack" | Un puntero al comienzo de la subcadena encontrada. NULL si la subcadena no se encuentra. Si "needle" es una cadena vacía, se devuelve "haystack"

## [ft_strnstr](libft/ft_strnstr.c)

`char       *ft_strnstr(const char *haystack, const char *needle, size_t len)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Localiza una subcadena, donde no se buscan más de "len" caracteres. Encuentra la primera ocurrencia de la subcadena "needle" en la cadena "haystack". Los bytes nulos de terminación ('\0') no se comparan | Cadena donde buscar | La subcadena a buscar en "haystack" | El número máximo de caracteres a buscar | Un puntero al primer carácter de la primera ocurrencia de "needle". NULL si la subcadena no se encuentra. Si "needle" es una cadena vacía, se devuelve "haystack"

## [ft_atoi](libft/ft_atoi.c)

`int        ft_atoi(const char *str)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Convierte una cadena en un entero | La cadena a convertir en entero | El valor convertido

## [ft_isalpha](libft/ft_isalpha.c)

`int        ft_isalpha(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter alfabético. Es equivalente a ([ft_isupper](#ft_isupper)(c) o [ft_islower](#ft_islower)(c)) | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero


---

## [ft_isdigit](libft/ft_isdigit.c)

`int         ft_isdigit(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un dígito (0 a 9) | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_isalnum](libft/ft_isalnum.c)

`int        ft_isalnum(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter alfanumérico; es equivalente a ([ft_isalpha](#ft_isalpha) o [ft_isdigit](#ft_isdigit)) | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_isascii](libft/ft_isascii.c)

`int        ft_isascii(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter ASCII, que es cualquier carácter entre 0 y octal 0177 inclusive | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_isprint](libft/ft_isprint.c)

`int        ft_isprint(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter imprimible, incluido el espacio | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_toupper](libft/ft_toupper.c)

`int        ft_toupper(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Si el carácter pasado como argumento es una letra minúscula, se convierte a mayúscula | El carácter a convertir | Si "c" es una letra minúscula, devuelve su equivalente en mayúscula. De lo contrario, devuelve "c"

## [ft_tolower](libft/ft_tolower.c)

`int        ft_tolower(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Si el carácter pasado como argumento es una letra mayúscula, se convierte a minúscula | El carácter a convertir | Si "c" es una letra mayúscula, devuelve su equivalente en minúscula. De lo contrario, devuelve "c"

## [ft_calloc](libft/ft_calloc.c)

`void       *ft_calloc(size_t count, size_t size)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna suficiente espacio para "count" objetos, cada uno de "size" bytes de memoria, y devuelve un puntero a la memoria asignada. La memoria asignada se llena con bytes de valor cero | Número de elementos a asignar | Tamaño de los elementos | Un puntero a la memoria asignada, o NULL si la solicitud falla

## [ft_substr](libft/ft_substr.c)

`char   *ft_substr(char const *s, unsigned int start, size_t len)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Asigna (con malloc) y devuelve una subcadena de la cadena dada como argumento. La subcadena comienza en el índice "start" y tiene un tamaño máximo de "len" | La cadena de la cual crear la subcadena | El índice de inicio de la subcadena en la cadena | La longitud máxima de la subcadena | La subcadena. NULL si la asignación falla

## [ft_strjoin](libft/ft_strjoin.c)

`char *ft_strjoin(char const *s1, char const *s2)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna (con malloc) y devuelve una nueva cadena, resultado de la concatenación de "s1" y "s2" | La cadena prefijo | La cadena sufijo | La nueva cadena. NULL si la asignación falla

## [ft_strtrim](libft/ft_strtrim.c)

`char *ft_strjoin(char const *s1, char const *s2)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna (con malloc) y devuelve una copia de la cadena dada como argumento sin los caracteres especificados en el argumento "set" al principio y al final de la cadena | La cadena a recortar | El conjunto de caracteres de referencia para recortar | La cadena recortada. NULL si la asignación falla

## [ft_strsplit](libft/ft_strsplit.c)

`char **ft_split(char const *s, char c)`
---

## [ft_strrchr](libft/ft_strrchr.c)

`char		*ft_strrchr(const char *s, int c)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza la última ocurrencia de "c" en la cadena apuntada por "s". El carácter nulo de terminación se considera parte de la cadena, por lo tanto, si "c" es '\0', localiza el '\0' final | Puntero a la cadena | Carácter a localizar | Un puntero a la última ocurrencia del carácter "c" en la cadena o NULL si no se encuentra el carácter

## [ft_strcpy](libft/ft_strcpy.c)

`char       *ft_strcpy(char *dst, const char *src)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Copia una cadena, incluyendo el byte nulo de terminación ('\0') | Arreglo de destino | Cadena a copiar | Un puntero a la cadena de destino "dst"

## [ft_strlcpy](libft/ft_strlcpy.c)

`size_t     ft_strlcpy(char *dst, const char *src, size_t dstsize)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Copia hasta "dstsize - 1" caracteres de la cadena terminada en NUL "src" a "dst", terminando en NUL el resultado | Arreglo de destino | Cadena a copiar | Número de caracteres a copiar de "src" | Longitud total de la cadena creada (longitud de "src")

## [ft_strcat](libft/ft_strcat.c)

`char       *ft_strcat(char *dst, const char *src)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Concatena dos cadenas (agrega "s2" a "s1"), incluyendo el byte nulo de terminación ('\0') | Arreglo de destino | Cadena a agregar a "dst" | Un puntero a la cadena resultante "dst"

## [ft_strlcat](libft/ft_strlcat.c)

`size_t     ft_strlcat(char *dst, const char *src, size_t size)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Concatena la cadena "src" al final de "dst". Concatenará como máximo "size - strlen(dst) - 1" bytes, terminando en NUL el resultado | Arreglo de destino | Cadena a agregar a "dst" | Número máximo de caracteres a agregar | La longitud inicial de "dst" más la longitud de "src"

## [ft_strstr](libft/ft_strstr.c)

`char       *ft_strstr(const char *haystack, const char *needle)`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza una subcadena. Encuentra la primera ocurrencia de la subcadena "needle" en la cadena "haystack". Los bytes nulos de terminación ('\0') no se comparan | Cadena donde buscar | La subcadena a buscar en la cadena "haystack" | Un puntero al comienzo de la subcadena encontrada. NULL si la subcadena no se encuentra. Si "needle" es una cadena vacía, se devuelve "haystack"

## [ft_strnstr](libft/ft_strnstr.c)

`char       *ft_strnstr(const char *haystack, const char *needle, size_t len)`

Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Localiza una subcadena, donde no se buscan más de "len" caracteres. Encuentra la primera ocurrencia de la subcadena "needle" en la cadena "haystack". Los bytes nulos de terminación ('\0') no se comparan | Cadena donde buscar | La subcadena a buscar en "haystack" | El número máximo de caracteres a buscar | Un puntero al primer carácter de la primera ocurrencia de "needle". NULL si la subcadena no se encuentra. Si "needle" es una cadena vacía, se devuelve "haystack"

## [ft_atoi](libft/ft_atoi.c)

`int        ft_atoi(const char *str)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Convierte una cadena en un entero | La cadena a convertir en entero | El valor convertido

## [ft_isalpha](libft/ft_isalpha.c)

`int        ft_isalpha(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter alfabético. Es equivalente a ([ft_isupper](#ft_isupper)(c) o [ft_islower](#ft_islower)(c)) | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

---

¿Deseas que siga con más funciones?

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Asigna (con malloc) y devuelve un arreglo de cadenas obtenido al dividir "s" usando el carácter "c" como delimitador. El arreglo debe terminar con un puntero NULL | La cadena a dividir | El carácter delimitador | El arreglo de nuevas cadenas resultado de la división. NULL si la asignación falla

## [ft_strmapi](libft/ft_strmapi.c)

`char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`

Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Aplica la función "f" a cada carácter de la cadena pasada como argumento para crear una nueva cadena (con malloc) resultante de las aplicaciones sucesivas de "f" | La cadena sobre la que iterar | La función a aplicar a cada carácter | La cadena creada a partir de las aplicaciones sucesivas de "f". Devuelve NULL si la asignación falla

## [ft_itoa](libft/ft_itoa.c)

`char   *ft_itoa(int n)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Asigna (con malloc) y devuelve una cadena que representa el entero recibido como argumento. Los números negativos deben ser manejados | El entero a convertir | La cadena que representa el entero. NULL si la asignación falla


---

## [ft_islower](libft/ft_islower.c)

`int  ft_islower(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter en minúscula | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_isupper](libft/ft_isupper.c)

`int ft_isupper(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter en mayúscula | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_isspace](libft/ft_isspace.c)

`int ft_isspace(int c)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter de espacio en blanco. Estos son: espacio, avance de página ('\f'), nueva línea ('\n'), retorno de carro ('\r'), tabulador horizontal ('\t') y tabulador vertical ('\v') | El carácter a probar | 0 si el carácter es falso y 1 si el carácter es verdadero

## [ft_capitalize](libft/ft_capitalize.c)

`char  *ft_capitalize(char *s)`

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Capitaliza la primera letra de cada palabra en una cadena | La cadena a capitalizar | La nueva cadena con las palabras capitalizadas

---
