```
Nombre de la asignación  : last_word
Archivos esperados   : last_word.c
Funciones permitidas: write
--------------------------------------------------------------------------------

Escribe un programa que tome una cadena y muestre su última palabra, seguida de un salto de línea (\n).

Una palabra es una sección de la cadena delimitada por espacios/tabulaciones o por el inicio/final de la cadena.

Si el número de parámetros no es 1, o no hay palabras, muestra solo un salto de línea.

Ejemplo:

$> ./last_word "FOR PONY" | cat -e
PONY$

$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$

$> ./last_word "   " | cat -e
$

$> ./last_word "a" "b" | cat -e
$

$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
```
