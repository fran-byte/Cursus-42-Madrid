
```
Nombre de la asignación: str_capitalizer
Archivos esperados: str_capitalizer.c
Funciones permitidas: write
--------------------------------------------------------------------------------

Escribe un programa que tome una o varias cadenas y, para cada argumento,
pone en mayúsculas el primer carácter de cada palabra (si es una letra,
obviamente), pone el resto en minúsculas y muestra el resultado en la salida
estándar, seguido de un salto de línea.

Una "palabra" se define como una parte de una cadena delimitada ya sea por
espacios/tabulaciones, o por el inicio/final de la cadena. Si una palabra
tiene solo una letra, debe estar en mayúsculas.

Si no hay argumentos, el programa debe mostrar un salto de línea.

Ejemplo:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
```
