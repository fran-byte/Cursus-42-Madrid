
```
Nombre de la asignación  : do_op
Archivos esperados   : *.c, *.h
Funciones permitidas: atoi, printf, write
--------------------------------------------------------------------------------

Escribe un programa que tome tres cadenas:
- La primera y la tercera representan enteros con signo en base 10 que caben en un int.
- La segunda es un operador aritmético elegido entre: + - * / %

El programa debe mostrar el resultado de la operación aritmética solicitada, seguido de un salto de línea. Si el número de parámetros no es 3, el programa solo muestra un salto de línea.

Puedes asumir que las cadenas no contienen errores ni caracteres adicionales. Los números negativos, ya sea en la entrada o salida, tendrán solo un signo '-' al inicio. El resultado de la operación cabe en un int.

Ejemplos:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
```
