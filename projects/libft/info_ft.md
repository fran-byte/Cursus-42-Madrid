## FUNCIONES ORIGINALES

## Biblioteca <ctype.h> (Funciones de caracteres)

**isalpha:** Verifica si un carácter es una letra del alfabeto. Retorna un valor **distinto de cero** si el carácter es una letra, y cero en caso contrario.

**tolower:** Convierte un carácter a minúscula. Si el carácter ya está en mayúscula o no es una letra, se devuelve sin modificaciones.

**toupper:** Convierte un carácter a mayúscula. Si el carácter ya está en mayúscula o no es una letra, se devuelve sin modificaciones.

**isdigit:** Verifica si un carácter es un dígito. Retorna un valor **distinto de cero** si es un dígito, y cero en caso contrario.

**isalnum:** Verifica si un carácter es una letra o un dígito. Retorna un valor **distinto de cero** si el carácter es alfanumérico, y cero en caso contrario.

**isascii:** Verifica si un carácter pertenece al conjunto ASCII(0 y 127) Retorna un valor **distinto de cero** si es ASCII, y cero en caso contrario.

**isprint:** Verifica si un carácter es imprimible. Retorna un valor **distinto de cero** si es imprimible, y cero en caso contrario.

## Biblioteca <string.h> (Funciones de manejo de cadenas y memoria)

strchr: Busca la primera aparición de un carácter en una cadena. **Retorna un puntero** a la primera ocurrencia del carácter. Si el carácter no se encuentra, retorna NULL.

strrchr: Busca la última aparición de un carácter en una cadena. **Retorna un puntero** a la última ocurrencia del carácter. Si el carácter no se encuentra, retorna NULL.

**strlen:** Calcula la longitud de una cadena. Excluyendo el carácter nulo de terminación. **Retorna el número de caracteres** en la cadena. 

strncmp: Compara las primeras 'n' posiciones de dos cadenas. Retorna un valor **negativo, cero o positivo** dependiendo de si la primera cadena es **menor, igual o mayor** que la segunda, respectivamente.

strnstr: Busca una subcadena dentro de otra, hasta un número limitado de caracteres. Limitando la búsqueda a un número especificado de caracteres. **Retorna un puntero** a la primera aparición de la subcadena o NULL si no se encuentra.

**strlcpy:** Copia hasta un máximo de 'size-1' caracteres de una cadena fuente a un destino, asegurando que el destino esté terminado con un carácter nulo. **Retorna la longitud total de la cadena fuente.**

**strlcat:** Concatena hasta 'size-1' caracteres de una cadena fuente a un destino, asegurando que el destino esté terminado con un carácter nulo. **Retorna la longitud total de la cadena resultante.**

## Biblioteca <stdlib.h> (Funciones de conversión y utilidades)

atoi: Convierte una **cadena de caracteres** que representa un **número entero** en un valor entero. Los espacios iniciales se omiten y la conversión se detiene en el primer carácter no numérico.

## Biblioteca <string.h> (Funciones de manejo de memoria)

memset: **Rellena** una región de **memoria** con un **valor específico**, repitiendo el valor dado para cada byte en el rango de memoria especificado. Utilizado para inicializar o establecer valores en bloques de memoria.

bzero: Establece en **cero** una **región de memoria**, reemplazando el uso de memset para esta tarea. Se considera obsoleto, ya que memset es más versátil.

memchr: **Busca un valor** específico en una región de memoria y **retorna un puntero** a la primera aparición de dicho valor. Si el valor no se encuentra, retorna NULL.

memcpy: **Copia** un **bloque** de memoria de **una ubicación a otra**. **No verifica superposición** de áreas de memoria, por lo que se deben manejar cuidadosamente las áreas de origen y destino.

memcmp: **Compara** dos **bloques** de memoria de tamaño específico byte a byte. **Retorna** un valor **negativo, cero o positivo** dependiendo de si el primer bloque es **menor, igual o mayor** que el segundo.

memmove: **Copia** un **bloque** de memoria **a otro**, **manejando** adecuadamente las **superposiciones** entre las áreas de origen y destino. Asegura que el contenido original de la memoria no se sobrescriba antes de ser copiado.
