```
Nombre de la asignación  : hidenp
Archivos esperados   : hidenp.c
Funciones permitidas: write
--------------------------------------------------------------------------------

Escribe un programa llamado hidenp que toma dos cadenas y muestra 1 seguido de un salto de línea
si la primera cadena está oculta en la segunda, de lo contrario, muestra 0 seguido de un salto de línea.

Sean s1 y s2 cadenas. Decimos que s1 está oculta en s2 si es posible encontrar cada carácter
de s1 en s2, en el mismo orden en que aparecen en s1. Además, la cadena vacía está oculta en cualquier cadena.

Si el número de parámetros no es 2, el programa muestra un salto de línea.

Ejemplos:

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
```
