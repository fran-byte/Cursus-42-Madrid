```
**Nombre de la asignación:** rostring
**Archivos esperados:** rostring.c
**Funciones permitidas:** write, malloc, free

---

Escribe un programa que tome una cadena y la muestre después de rotarla un "palabra" hacia la izquierda.

Por lo tanto, la primera palabra se convierte en la última, y las demás permanecen en el mismo orden.

Una "palabra" se define como una parte de la cadena delimitada por espacios/tabulaciones, o por el inicio/fin de la cadena.

En la salida, las palabras estarán separadas por un solo espacio.

Si hay menos de un argumento, el programa muestra `\n`.

**Ejemplo:**


$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
```
