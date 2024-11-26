# Algoritmo de ordenación Radix Sort

El Radix Sort clasifica números de menor a mayor analizando sus bits binarios (o dígitos en base 10, pero aquí trabajamos en **binario**). En este caso, adaptamos el algoritmo para trabajar con dos pilas (stack_a y stack_b).


---

Proceso Paso a Paso

# 1. Preparación:

Todos los números están inicialmente en stack_a.

El algoritmo analiza cada bit (posición binaria) de los números, comenzando por el bit menos significativo (derecha).



# 2. Iteración por Bits:

Para cada bit, el algoritmo mira uno por uno los números en stack_a.

Si el bit actual (digamos el de la posición i) es 0, el número se mueve a stack_b.

Si el bit actual es 1, el número se deja en stack_a y se rota al final.



# 3. Reagrupación:

Una vez que todos los números han sido revisados para un bit específico, los números que se movieron a stack_b se devuelven a stack_a.

Este proceso garantiza que los números en stack_a estén ordenados parcialmente según el bit actual.



# 4. Repetición:

El algoritmo repite el proceso para el siguiente bit (posición i+1) y así sucesivamente, hasta haber procesado todos los bits necesarios para los números más grandes.

Por ejemplo, si el número más grande tiene 8 bits (en binario), el algoritmo hará 8 iteraciones.



# 5. Resultado Final:

Al completar las iteraciones para todos los bits, los números estarán completamente ordenados en stack_a.





---

# Ejemplo Conceptual

Supongamos que los números son 3, 6, 9 (en binario: 011, 110, 100):

# 1. Procesar el bit menos significativo (posición 0):

```3 (011): bit 0 es 1 → se queda en stack_a.

6 (110): bit 0 es 0 → se mueve a stack_b.

9 (100): bit 0 es 0 → se mueve a stack_b.

Después: stack_a = [3], stack_b = [6, 9].```



# 2. Reagrupar desde stack_b a stack_a:

`stack_a = [3, 6, 9].`



# 3. Procesar el siguiente bit (posición 1):

```3 (011): bit 1 es 1 → se queda en stack_a.

6 (110): bit 1 es 1 → se queda en stack_a.

9 (100): bit 1 es 0 → se mueve a stack_b.

Después: stack_a = [3, 6], stack_b = [9].```



# 4. Reagrupar desde stack_b a stack_a:

`stack_a = [9, 3, 6].`



# 5. Procesar el bit más significativo (posición 2):

```9 (100): bit 2 es 1 → se queda en stack_a.

3 (011): bit 2 es 0 → se mueve a stack_b.

6 (110): bit 2 es 1 → se queda en stack_a.

Después: stack_a = [9, 6], stack_b = [3].```



# 6. Reagrupar desde stack_b a stack_a:

```stack_a = [3, 6, 9] (ordenados).```





---

# Ventajas del Radix Sort en Stacks

Simple de Implementar: Solo necesitas mover números entre pilas según su bit actual.

Eficiente en Movimientos: Por cada bit, cada número se mueve como máximo dos veces (pa y pb).

Garantiza el Orden: No requiere comparaciones directas entre los números, solo analiza bits.


Con esta estrategia, los números se ordenan eficientemente cumpliendo los requisitos del proyecto.
