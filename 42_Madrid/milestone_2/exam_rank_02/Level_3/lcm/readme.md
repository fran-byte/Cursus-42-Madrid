```
Nombre de la asignación  : lcm
Archivos esperados   : lcm.c
Funciones permitidas: None
--------------------------------------------------------------------------------

Escribe una función que toma dos enteros sin signo como parámetros y devuelve el LCM (Mínimo Común Múltiplo) de esos parámetros.

El LCM (Mínimo Común Múltiplo) de dos enteros no nulos es el entero positivo más pequeño divisible por ambos enteros.

El LCM se puede calcular de dos maneras:

- Puedes calcular los múltiplos de cada número hasta encontrar un múltiplo común diferente de 0.

- Puedes usar el HCF (Máximo Común Divisor) de estos dos enteros y calcularlo de la siguiente manera:

  LCM(x, y) = | x * y | / HCF(x, y)

  Donde | x * y | significa "Valor absoluto del producto de x por y".

Si al menos uno de los enteros es nulo, el LCM es igual a 0.

Tu función debe estar prototipada de la siguiente manera:

  unsigned int    lcm(unsigned int a, unsigned int b);
```
