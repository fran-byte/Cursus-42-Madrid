
# BIBLIOTECA de FUNCIONES BÁSICAS ( libft.a ) 📚

<br>

# Parte 1 - Funciones de libc


## [ft_isalpha](libft/ft_isalpha.c)

``` c
int ft_isalpha (int c)
```

Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si el carácter dado es **alfabético** (letra mayúscula o minúscula).   | El carácter a probar | Devuelve Non-Zero si el carácter pertenece al alfabeto (A-Z o a-z) y 0 en caso contrario.

## [ft_isdigit](libft/ft_isdigit.c)

``` c
int ft_isdigit (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si el carácter dado es un **dígito** (0 a 9) | El carácter a probar | Devuelve Non-Zero si el carácter es un dígito numérico (entre '0' y '9') y 0 en caso contrario.

## [ft_isalnum](libft/ft_isalnum.c)

``` c
int ft_isalnum (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter **alfanumérico** | El carácter a probar | 0 si el carácter es falso y Non-Zero si el si el carácter es verdadero

## [ft_isascii](libft/ft_isascii.c)

``` c
int ft_isascii (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter **ASCII**, que es cualquier carácter entre 0 y octal 0177 inclusive | El carácter a probar | 0 si el carácter es falso y Non-Zero si el si el carácter es verdadero

## [ft_isprint](libft/ft_isprint.c)

``` c
int ft_isprint (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Verifica si es un carácter **imprimible**, incluido el espacio | El carácter a probar | 0 si el carácter es falso y Non-Zero si el carácter es verdadero

## [ft_strlen](libft/ft_strlen.c)
``` c
size_t ft_strlen (const char *s)
```
Descripción | Param. #1 | Valores de Retorno
:-----------: | :-----------: | :-----------:
Calcula la **longitud** de la cadena proporcionada, excluyendo el byte nulo (`'\0'`) al final. Devuelve el número de caracteres presentes en la cadena. Es útil para determinar el tamaño de las cadenas antes de manipularlas. | La cadena a calcular | Número de caracteres en la cadena apuntada por `s`

## [ft_memset](libft/ft_memset.c)

``` c
void *ft_memset (void *s, int c, size_t len)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Llena** un bloque de memoria con el valor especificado (convertido a un `unsigned char`). La función escribe `len` bytes del valor `c` en la memoria apuntada por `s`. Es útil para inicializar o resetear bloques de memoria. | La cadena sobre la que operar | Valor c (convertido a unsigned char) | El número de bytes | Un puntero al área de memoria `s`

## [ft_bzero](libft/ft_bzero.c)

``` c
void *ft_bzero (void *s,  size_t n)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Borra** los datos de un bloque de memoria, escribiendo ceros en los primeros `n` bytes de la memoria apuntada por `s`. Es útil para inicializar la memoria a cero antes de su uso. | La cadena sobre la que operar | El número de bytes | Ninguno

## [ft_memcpy](libft/ft_memcpy.c)

``` c
void *ft_memcpy (void *dst, const void *src, size_t n)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Copia** `n` bytes del área de memoria `src` a `dst`. Esta función es rápida, pero **podrían solaparse areas de memoria**; si lo hacen, es mejor utilizar `ft_memmove` también **puede sobrescribir memoria adyacente** .   | Área de memoria `dst` | Área de memoria `src` | El número de bytes | Un puntero al área de memoria `dst`

## [ft_memmove](libft/ft_memmove.c)

``` c
void *ft_memmove (void *dst, const void *src, size_t len)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Copia** `len` bytes de la memoria `src` a `dst`, pero a diferencia de `ft_memcpy`, maneja correctamente las áreas de memoria superpuestas. Primero copia a un buffer temporal y luego a `dst`. Se usa para evitar sobrescribir los datos cuando `src` y `dst` se solapan, **puede sobrescribir memoria adyacente** | Área de memoria `dst` | Área de memoria `src` | El número de bytes | Un puntero al área de memoria `dst`

## [ft_strlcpy](libft/ft_strlcpy.c)

``` c
size_t ft_strlcpy (char *dst, const char *src, size_t dstsize)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Copia** hasta `dstsize - 1` caracteres de la cadena `src` a `dst`, garantizando la terminación con `'\0'` si `dstsize` es mayor que 0. Se utiliza para evitar desbordamientos en la copia de cadenas.  | Cadena de destino donde se copiarán los caracteres de `src` | Cadena de origen que se desea copiar. | Tamaño del buffer de destino `dst`.| Devuelve la longitud total de la cadena de origen `src`. Si dstsize es 0, no se realiza ninguna copia y se devuelve la longitud de `src`

## [ft_strlcat](libft/ft_strlcat.c)

``` c
size_t ft_strlcat (char *dst, const char *src, size_t size)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Concatena** la cadena `src` al final de `dst`, hasta un máximo de `size - strlen(dst) - 1` bytes, asegurando la terminación con `'\0'`. Esta función es útil para evitar desbordamientos al concatenar cadenas.  | Arreglo de destino | Cadena a agregar a `dst` | Número máximo de caracteres a agregar | La longitud inicial de `dst` más la longitud de `src`

## [ft_toupper](libft/ft_toupper.c)

``` c
int ft_toupper (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Convierte un carácter en minúscula a su equivalente en mayúscula. Si el carácter no es una letra minúscula, se devuelve sin cambios. | El carácter a convertir | Si `c` es una letra minúscula, devuelve su equivalente en mayúscula. De lo contrario, devuelve `c`

## [ft_tolower](libft/ft_tolower.c)

``` c
int ft_tolower (int c)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
Convierte un carácter mayúscula a su equivalente en minúscula, si es aplicable. Si el carácter no es una letra mayúscula, se devuelve sin cambios. | El carácter a convertir | Si `c` es una letra mayúscula, devuelve su equivalente en minúscula. De lo contrario, devuelve `c`

## [ft_strchr](libft/ft_strchr.c)

``` c
char *ft_strchr (const char *s, int c)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Esta función localiza la **primera** ocurrencia del carácter `c` en la cadena apuntada por `s`. El carácter nulo de terminación (`'\0'`) es considerado parte de la cadena, por lo tanto, si `c` es `'\0'`, la función localizará el `'\0'` final. Es útil para buscar caracteres específicos en una cadena. | Puntero a la cadena | Carácter a localizar | Un puntero a la primera ocurrencia del carácter `c` en la cadena o `NULL` si no se encuentra el carácter

## [ft_strrchr](libft/ft_strrchr.c)

``` c
char *ft_strrchr (const char *s, int c)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
Localiza la **última** ocurrencia del carácter `c` en la cadena apuntada por `s`. El carácter nulo de terminación (`'\0'`) es considerado parte de la cadena, por lo tanto, si `c` es `'\0'`, la función localizará el `'\0'` final. Esta función es útil cuando se desea encontrar la última aparición de un carácter específico. | Puntero a la cadena | Carácter a localizar | Un puntero a la última ocurrencia del carácter `c` en la cadena o `NULL` si no se encuentra el carácter

## [ft_strncmp](libft/ft_strncmp.c)

``` c
int ft_strncmp (const char *s1, const char *s2, size_t n)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Compara** dos cadenas (s1 y s2) carácter por carácter, hasta un máximo de n caracteres. S| Primera cadena a comparar | Segunda cadena a comparar | Número máximo de caracteres a comparar | Si las cadenas son idénticas en esos primeros `n` caracteres, devuelve **0**. si el caracter encontrado difiere devolverá un valor : Negativo `s1` < `s2` y positivo si `s1` > `s2`. Es útil para comparar prefijos de cadenas. .

## [ft_memchr](libft/ft_memchr.c)

``` c
void *ft_memchr (const void *s, int c, size_t n)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Escanea** los primeros `n` bytes del área de memoria `s` en busca de la primera instancia del valor `c`. Es útil para buscar un valor específico dentro de una región de memoria. | `s` Un puntero al bloque de memoria donde se realiza la búsqueda | `c` El carácter que se busca (se convierte a unsigned char). | `n` El número de bytes en los que se va a buscar. | Un puntero al byte coincidente o `NULL` si el carácter no aparece en el área de memoria dada

## [ft_memcmp](libft/ft_memcmp.c)

``` c
void *ft_memcmp (void *dst, const void *src, size_t n)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Compara** los primeros `n` bytes de las áreas de memoria `s1` y `s2`. Devuelve un valor negativo, cero o positivo según si `s1` es menor, igual o mayor que `s2`. Es útil para comparar bloques de memoria de tamaño fijo. | Área de memoria `s1` | Área de memoria `s2` | El número de bytes | < 0 si `s1` es menor que `s2`, > 0 si `s1` es mayor que `s2`, = 0 si `s1` es igual a `s2`

## [ft_strnstr](libft/ft_strnstr.c)

``` c
char *ft_strnstr (const char *haystack, const char *needle, size_t len)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Busca** la primera aparición de la subcadena `big` en la cadena `tiny`, buscando solo en los primeros `len` caracteres de `big`. Esta función asegura que la búsqueda no exceda el límite de `len`. Es útil cuando se necesita encontrar una subcadena en un rango restringido de una cadena. | Cadena donde buscar | La subcadena a buscar en `big` | El número máximo de caracteres a buscar | Un puntero al primer carácter de la primera ocurrencia de `tiny`. `NULL` si la subcadena no se encuentra. Si "needle" es una cadena vacía, se devuelve `big`

## [ft_atoi](libft/ft_atoi.c)

``` c
int ft_atoi (const char *str)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
**Convierte** la cadena de caracteres `str` en un número entero (`int`). La función ignora cualquier espacio en blanco inicial y maneja un signo opcional. Es útil para convertir cadenas numéricas en enteros, por ejemplo, en la entrada de datos | La cadena a convertir en entero | El valor convertido


## [ft_calloc](libft/ft_calloc.c)

``` c
void *ft_calloc (size_t count, size_t size)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Asigna** memoria para una matriz de `count` elementos de `size` bytes cada uno, y llena la memoria asignada con ceros. Es útil para asignar memoria inicializada para matrices o estructuras. | Número de elementos a asignar | Tamaño de los elementos | Un puntero a la memoria asignada, o NULL si la solicitud falla


## [ft_strdup](libft/ft_strdup.c)

``` c
char *ft_strdup (const char *s)
```
Descripción | Param. #1 | Valores de Retorno
:-----------: | :-----------: | :-----------:
**Duplica** la cadena `s`, asignando nueva memoria con `malloc`. La memoria para la nueva cadena debe liberarse con `free` cuando ya no sea necesaria. Esta función es útil para crear una copia de una cadena que debe preservarse de cambios en la original.| La cadena a duplicar | Un puntero a la cadena duplicada. NULL si no había suficiente memoria disponible

<br><br><br><br><br>

# Parte 2 - Funciones adicionales

## [ft_substr](libft/ft_substr.c)

``` c
char *ft_substr (char const *s, unsigned int start, size_t len)
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Asigna** (con `malloc`) y devuelve una subcadena de `s`. La subcadena comienza en el índice `start` y tiene un tamaño máximo de `len` caracteres. Es útil para extraer partes de una cadena más grande | La cadena de la cual crear la subcadena | El índice de inicio de la subcadena en la cadena | La longitud máxima de la subcadena | La subcadena. Si la cadena `s` es NULL, la función retorna NULL para indicar un error. Si el índice ´start´ es mayor o igual a la longitud de la cadena ´s´, la función retorna una cadena vacía (strdup("")), indicando que no hay nada que extraer. El Usuario es el encargado de liberar la memoria asignada para evitar fugas de memoria en el programa.

## [ft_strjoin](libft/ft_strjoin.c)

``` c
char *ft_strjoin (char const *s1, char const *s2)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Asigna** memoria (con `malloc`) y devuelve una nueva cadena, resultado de la concatenación de `s1` y `s2`. La nueva cadena incluye el contenido de ambas, comenzando por `s1` seguido de `s2`. Es útil para combinar dos cadenas en una sola | La cadena prefijo | La cadena sufijo | La nueva cadena. NULL si la asignación falla

## [ft_strtrim](libft/ft_strtrim.c)

``` c
char *ft_strtrim (char const *s1, char const *set)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Asigna memoria (con `malloc`) y devuelve una copia de `s1` sin los caracteres especificados en `set` al principio y al final de la cadena. Es útil para eliminar caracteres indeseados (como espacios en blanco) de los extremos de una cadena. | La cadena prefijo | La cadena sufijo | La nueva cadena. NULL si la asignación falla | La cadena a recortar | El conjunto de caracteres de referencia para recortar | La cadena recortada. NULL si la asignación falla

## [ft_split](libft/ft_split.c)

``` c
char **ft_split (char const *s, char c)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Asigna** memoria (con `malloc`) y devuelve un array de cadenas, obtenido dividiendo la cadena `s` utilizando el carácter `c` como delimitador. Las subcadenas no incluyen el delimitador, y el array resultante termina con un puntero `NULL`. Es útil para dividir una cadena en partes según un delimitador específico. | La cadena a dividir | El carácter delimitador usado para separar las subcadenas | Un array de cadenas resultante de la división. NULL si la asignación falla

## [ft_itoa](libft/ft_itoa.c)

``` c
char   *ft_itoa (int n)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
**Asigna** memoria (con `malloc`) y devuelve una cadena que representa el número entero `n`. La cadena incluye el signo si el número es negativo. Es útil para convertir un número entero en su representación en cadena de caracteres. | El entero a convertir | La cadena que representa el entero. NULL si la asignación falla

## [ft_strmapi](libft/ft_strmapi.c)

``` c
char *ft_strmapi (char const *s, char (*f)(unsigned int, char))
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Aplica** la función `f` a cada carácter de la cadena `s`, pasando su índice como primer argumento. El resultado es una nueva cadena (asignada con `malloc`) que se forma a partir de las sucesivas aplicaciones de `f`. Es útil para transformar cada carácter de una cadena según su posición. | La cadena sobre la que iterar | La función a aplicar a cada carácter | La cadena creada a partir de las aplicaciones sucesivas de "f". Devuelve NULL si la asignación falla

## [ft_striteri](libft/ft_striteri.c)

``` c
void ft_striteri (char *s, void (*f)(unsigned int, char*))
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Aplica** la función `f` a cada carácter de la cadena `s`, proporcionando el índice del carácter como primer argumento. La función puede modificar directamente los caracteres de la cadena. Es útil para transformar o procesar los caracteres de una cadena de manera indexada, sin necesidad de devolver una nueva cadena. | La cadena sobre la que se aplicará la función, pasada como modificable. | La función que se aplicará a cada carácter, recibe el índice del carácter como primer parámetro y un puntero al carácter en la cadena como segundo parámetro. | No devuelve ningún valor (función `void`).


## [ft_putchar_fd](libft/ft_putchar_fd.c)

``` c
void ft_putchar_fd (char c, int fd)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Envía** el carácter `c` al file descriptor especificado mediante la función `write`. Es útil para escribir caracteres en diferentes salidas, como archivos, sockets, o terminales (usando `stdout`, `stderr` o descriptores de archivo). | El carácter que se va a enviar | El file descriptor sobre el cual escribir: `0` (stdin), `1` (stdout), `2` (stderr) o cualquier descriptor de archivo válido | No devuelve ningún valor (`void`).


## [ft_putstr_fd](libft/ft_putstr_fd.c)

``` c
void ft_putstr_fd (char *s, int fd)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Envía** la cadena de caracteres `s` al file descriptor especificado utilizando la función `write`. Es útil para escribir cadenas en diferentes salidas, como archivos, sockets o terminales. | `s` Un puntero a la cadena de caracteres que se desea imprimir. |El file descriptor sobre el cual escribir: `0` (stdin), `1` (stdout), `2` (stderr) o cualquier descriptor de archivo válido | No devuelve ningún valor (`void`).


## [ft_putendl_fd](libft/ft_putendl_fd.c)

``` c
void ft_putendl_fd(char *s, int fd)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Envía** la cadena `s` al file descriptor especificado, seguida de un salto de línea (`'\n'`), utilizando la función `write`. Es útil para escribir una cadena seguida de un salto de línea en cualquier salida. | La cadena de caracteres que se va a enviar | El file descriptor sobre el cual escribir: `0` (stdin), `1` (stdout), `2` (stderr) o cualquier descriptor de archivo válido | No devuelve ningún valor (`void`).


## [ft_putnbr_fd](libft/ft_putnbr_fd.c)

``` c
void ft_putnbr_fd(int n, int fd)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Envía** el número entero `n` al file descriptor especificado utilizando la función `write`. La función convierte el número en su representación en caracteres antes de enviarlo. Es útil para escribir números en salidas como archivos o terminales.| `n` El número entero que se desea imprimir. | El file descriptor sobre el cual escribir: `0` (stdin), `1` (stdout), `2` (stderr) o cualquier descriptor de archivo válido | No devuelve ningún valor (`void`).

<br><br><br><br><br>

# Parte bonus

## Añade la declaración a tu archivo libft.h :


``` c
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```
Los miembros de la estructura t_list son:

• **content:** la información contenida por el nodo.

 __void  *__: permite guardar cualquier tipo de información.

• **next:** la dirección del siguiente nodo, o NULL si el siguiente nodo es el último.

En tu Makefile, añade una regla make bonus que incorpore las funciones bonus a tu
libft.a


## [ft_lstnew](libft/ft_lstnew.c)

``` c
t_list *ft_lstnew(void *content)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
**Crea** un nuevo nodo de tipo `t_list`, utilizando `malloc` para asignar memoria. La variable `content` se inicializa con el valor proporcionado, y la variable `next` se inicializa en `NULL`. Es útil para crear nodos en listas enlazadas. | El contenido que se asignará al nuevo nodo | Un puntero al nuevo nodo creado. NULL si la asignación falla.


## [ft_lstadd_front](libft/ft_lstadd_front.c)

``` c
void ft_lstadd_front(t_list **lst, t_list *new)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Añade** el nodo `new` al principio de la lista `lst`. Actualiza el puntero de la lista para que apunte al nuevo nodo, convirtiéndolo en el primer nodo de la lista. Es útil para agregar nodos al inicio de una lista enlazada. | La dirección de un puntero al primer nodo de la lista | Un puntero al nodo que se añadirá al principio de la lista | No devuelve ningún valor (`void`).


## [ft_lstsize](libft/ft_lstsize.c)

``` c
int ft_lstsize(t_list *lst)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
**Cuenta** el número de nodos en la lista enlazada comenzando desde el nodo `lst`. Es útil para determinar la longitud de la lista. | El puntero al primer nodo de la lista | La longitud de la lista (número de nodos).


## [ft_lstlast](libft/ft_lstlast.c)

``` c
t_list *ft_lstlast(t_list *lst)
```
Descripción | Param. #1 | Valor de Retorno
:-----------: | :-----------: | :-----------:
**Devuelve** el último nodo de la lista enlazada comenzando desde el nodo `lst`. Es útil para obtener el nodo final de una lista. | El puntero al primer nodo de la lista | Un puntero al último nodo de la lista. Si la lista está vacía, devuelve `NULL`.


## [ft_lstadd_back](libft/ft_lstadd_back.c)

``` c
void ft_lstadd_back(t_list **lst, t_list *new)
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Añade** el nodo `new` al final de la lista `lst`. Si la lista está vacía, `new` se convierte en el primer nodo. Es útil para agregar nodos al final de una lista enlazada. | Un puntero al puntero que apunta al primer nodo de la lista | Un puntero al nodo que se añadirá al final de la lista | No devuelve ningún valor (`void`).


## [ft_lstdelone](libft/ft_lstdelone.c)

``` c
void ft_lstdelone(t_list *lst, void (*del)(void *))
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Toma** como parámetro un nodo `lst` y libera su contenido utilizando la función `del` proporcionada. Luego libera el nodo en sí, pero no afecta a los nodos siguientes. Es útil para eliminar un único nodo de una lista enlazada. | El nodo que se va a liberar | Un puntero a la función utilizada para liberar el contenido del nodo | No devuelve ningún valor (`void`).


## [ft_lstclear](libft/ft_lstclear.c)

``` c
void ft_lstclear(t_list **lst, void (*del)(void *))
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Elimina y libera** el nodo `lst` y todos los nodos siguientes en la lista, utilizando la función `del` para liberar el contenido de cada nodo. La memoria de los nodos es liberada con `free`, y al final, el puntero a la lista se establece en `NULL`. Es útil para vaciar y liberar completamente una lista enlazada. | La dirección de un puntero al primer nodo de la lista | Un puntero a la función utilizada para eliminar el contenido de cada nodo | No devuelve ningún valor (`void`).


## [ft_lstiter](libft/ft_lstiter.c)

``` c
void ft_lstiter(t_list *lst, void (*f)(void *))
```
Descripción | Param. #1 | Param. #2 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------:
**Itera** sobre la lista `lst` y aplica la función `f` al contenido de cada nodo. Es útil para realizar una operación sobre cada nodo en una lista enlazada. | Un puntero al primer nodo de la lista | Un puntero a la función que se aplicará a cada nodo | No devuelve ningún valor (`void`).

## [ft_lstmap](libft/ft_lstmap.c)

``` c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```
Descripción | Param. #1 | Param. #2 | Param. #3 | Valor de Retorno
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
**Itera** sobre la lista `lst` y aplica la función `f` al contenido de cada nodo, creando una nueva lista con los resultados de las aplicaciones de `f`. Si una asignación falla, utiliza la función `del` para liberar el contenido de los nodos ya creados. Es útil para transformar una lista existente en una nueva lista basada en una operación aplicada a cada nodo. | Un puntero al primer nodo de la lista | La dirección de un puntero a la función que transforma el contenido de cada nodo | Un puntero a la función que se utiliza para liberar el contenido de un nodo, si es necesario | Un puntero a la nueva lista creada. `NULL` si falla la reserva de memoria.

