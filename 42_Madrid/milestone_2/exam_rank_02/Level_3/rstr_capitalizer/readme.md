
```
Nombre de la asignación: rstr_capitalizer
Archivos esperados: rstr_capitalizer.c
Funciones permitidas: write
--------------------------------------------------------------------------------

Escribe un programa que tome una o más cadenas y, para cada argumento, ponga
la última letra de cada palabra en mayúscula y el resto en minúsculas, luego
muestra el resultado seguido de un salto de línea.

Una palabra es una sección de la cadena delimitada por espacios/tabulaciones
o el inicio/final de la cadena. Si una palabra tiene una sola letra, debe
estar en mayúsculas.

Una letra es un carácter en el conjunto [a-zA-Z].

Si no hay parámetros, muestra un salto de línea.

Ejemplos:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
```
