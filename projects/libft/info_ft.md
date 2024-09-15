## FUNCIONES ORIGINALES

## Biblioteca <ctype.h> (Funciones de caracteres)

*isalpha: Verifica si un carácter es una letra del alfabeto.
*toupper: Convierte un carácter a mayúscula.
*tolower: Convierte un carácter a minúscula.
*isdigit: Verifica si un carácter es un dígito.
*isalnum: Verifica si un carácter es una letra o un dígito.
*isascii: Verifica si un carácter pertenece al conjunto ASCII.
\*isprint: Verifica si un carácter es imprimible.

## Biblioteca <string.h> (Funciones de manejo de cadenas y memoria)

strchr: Busca la primera aparición de un carácter en una cadena.
strrchr: Busca la última aparición de un carácter en una cadena.
*strlen: Calcula la longitud de una cadena.
strncmp: Compara las primeras 'n' posiciones de dos cadenas.
strnstr: Busca una subcadena dentro de otra, hasta un número limitado de caracteres.
*strlcpy: Copia una cadena a un destino, garantizando la terminación nula.
\*strlcat: Concatena dos cadenas, garantizando la terminación nula.

## Biblioteca <stdlib.h> (Funciones de conversión y utilidades)

atoi: Convierte una cadena en un entero.

## Biblioteca <string.h> (Funciones de manejo de memoria)

memset: Rellena una región de memoria con un valor dado.
bzero: Establece en cero una región de memoria.(obsoleto usar memset)
memchr: Busca un valor en una región de memoria.
memcpy: Copia un bloque de memoria a otro.
memcmp: Compara dos bloques de memoria.
memmove: Copia un bloque de memoria, manejando superposición de áreas.
