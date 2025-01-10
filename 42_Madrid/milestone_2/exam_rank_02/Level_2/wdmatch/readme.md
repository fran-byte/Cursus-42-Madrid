```
Nombre de la asignación  : wdmatch
Archivos esperados   : wdmatch.c
Funciones permitidas: write
--------------------------------------------------------------------------------

Escribe un programa que tome dos cadenas y verifique si es posible escribir la primera cadena utilizando caracteres de la segunda cadena, respetando el orden en el que estos caracteres aparecen en la segunda cadena.

Si es posible, el programa mostrará la cadena, seguida de un salto de línea; de lo contrario, simplemente mostrará un salto de línea.

Si el número de argumentos no es 2, el programa mostrará solo un salto de línea.

Ejemplos:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$

$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$

$>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
forty two$

$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$

$>./wdmatch | cat -e
$
```
