<p align="center" width="100%"><a href="milestone_2/"><img src="../../img/milestone_2/push_swap.png" width="72" />

# push_swap

### Explorando el proyecto
El proyecto está compuesto por muchos archivos, organizados en un **directorio**. Por ejemplo:  
- **`push_swap.c`**: contiene la función principal, el "corazón" del programa.  
- **Archivos `.h`** (headers): contienen prototipos de funciones necesarias y declaraciones compartidas entre los archivos del proyecto.  

El **header file** es clave para proyectos más grandes porque permite la organización modular del código. Por ejemplo, declara funciones para crear pilas, manejar errores, y administrar nodos.  

### Estructura del programa
Todo programa en C comienza con la función `main`, que sirve como punto de entrada al proceso. En un buen diseño, la función `main` actúa como un resumen del proyecto. Observando esta estructura:  

1. **Control de entrada:** El programa recibe una lista de números enteros como argumentos de la línea de comandos y verifica si los datos de entrada son válidos .  
2. **Inicialización:** Se crean las dos pilas (A y B) y se inicializan con los números de entrada en la pila A.
3. **Ejecución del algoritmo:** Ordena los números según las reglas definidas.  
4. **Limpieza:** Libera la memoria utilizada para evitar fugas.  

Por ejemplo: en el código, vemos que `stack_init` probablemente inicializa la pila, y luego hay una verificación para determinar si la pila ya está ordenada o no.  

### Probar el algoritmo
Para probar si el algoritmo funciona, utilizamos un **tester online**. Por ejemplo:  
- Probamos con **100 números** y realizamos **50 pruebas**.  
- Los resultados muestran cuántos movimientos (instrucciones) fueron necesarios para ordenar correctamente los números.  

Los valores de salida, como un **máximo de 665 instrucciones** y un promedio de 606, indican que el algoritmo está funcionando correctamente.  

Lo más importante son los **resultados** 

Para **500 números**, se pude obtener un promedio **5,510 instrucciones**. Básicamente, funciona. Ese es el punto principal. Puedo ejecutar `push_swap` con valores aleatorios. Por ejemplo: **2, 1, 34**, y como salida obtengo **sa**, que significa "intercambiar".  

Es importante notar que puedo pasar como entrada una **serie de números entre comillas**. Aunque parecen iguales, para la línea de comandos no son lo mismo: un caso son **verdaderos argumentos separados**, y el otro es una sola cadena de texto.  

El algoritmo no funcionará si hay errores en la entrada, como escribir un valor no numérico. Esto forma parte de la **fase de control**.  

### ¿Qué es una pila (stack)?  
Una pila es una estructura de datos muy básica, parecida a una pila de platos. Imagina que tienes varios elementos apilados uno sobre otro. El **tope de la pila** es como el plato superior. Puedes:  
- **Push**: Añadir un elemento al tope de la pila.  
- **Pop**: Retirar el elemento superior.  


### Implementación de la pila  
He decidido usar una **lista enlazada** porque es una estructura flexible y bien adaptada a este tipo de problemas. Alternativamente, podrías usar un arreglo (array), donde cada elemento representa un "plato" en la pila, pero implementar las operaciones necesarias con un arreglo puede ser más complicado.  

Cada estructura de datos tiene ventajas y desventajas:  
- **Listas enlazadas**: Muy flexibles y fáciles de manipular, pero más complejas en términos de manejo de punteros.  
- **Arreglos**: Más sencillos de manejar en memoria, pero menos flexibles para operaciones dinámicas.  

En mi implementación, cada nodo de la lista enlazada tiene:  
1. Un valor (el número).  
2. Un puntero al nodo anterior.  
3. Un puntero al nodo siguiente.  

Esto permite crear una **lista doblemente enlazada**, donde los nodos están conectados entre sí.  

### ¿Qué es un nodo?  
Un nodo es una **estructura (struct)** en C que actúa como un contenedor de datos. A diferencia de un arreglo, donde todos los elementos deben ser del mismo tipo, una estructura permite almacenar datos de diferentes tipos en un solo contenedor.  

En este proyecto, un nodo contiene:  
- El valor (número) a almacenar.  
- Punteros al nodo siguiente y al anterior.  
- Metadatos adicionales, como posición actual o coste de movimiento, que son útiles para el algoritmo.  

#### Código del nodo  
El nodo se define en el archivo `push_swap.h`, para que pueda ser usado en cualquier parte del proyecto. La definición incluye:  
- **Punteros** al nodo anterior y siguiente.  
- **Datos del algoritmo** (como posición y otros).  

Usamos **typedef** para simplificar el nombre de la estructura, de manera que podamos referirnos al nodo como `t_list` en lugar de escribir `struct t_list` cada vez. Esto mejora la legibilidad y la organización del código.  

En resumen, un nodo es una pequeña unidad de datos que se conecta a otros nodos, formando la base de una lista enlazada. Este enfoque permite implementar las operaciones de pila (push, pop, swap) de manera más sencilla y eficiente en el contexto del proyecto `push_swap`.


### Explicación de la función principal
En la función `main`, declaramos inmediatamente un puntero a un nodo llamado `stack_a`. Esto significa que `stack_a` es un puntero a un nodo que, inicialmente, está fuera del stack. Como mencioné antes, comenzamos con un puntero nulo. Este puntero no apunta a ningún lugar, por lo que no puede causar daños ni errores de segmentación.

#### Verificación inicial
Primero realizamos algunas verificaciones:
1. Si el contador de argumentos (`argc`) es igual a 1, significa que no hay argumentos de entrada. Este caso ocurre cuando solo se proporciona el programa en sí (por ejemplo, solo `push_swap` u otro similar).
2. Si el contador de argumentos es igual a 2, pero el primer carácter del argumento de entrada es un carácter nulo (`'\0'`), significa que la cadena está vacía. En cualquiera de estos casos, simplemente salimos de la función devolviendo 1. 

Estas condiciones manejan los casos donde no hay entrada o donde la cadena proporcionada está vacía. Por lo tanto, el programa no realiza ninguna acción adicional.

#### Manejo de entradas válidas
Si los argumentos son dos y la cadena no está vacía, asignamos un nuevo valor al vector de argumentos. Utilizamos la función `ft_split`, que toma como entrada el argumento en la posición 1 (`argv[1]`) y un separador, en este caso un espacio (`' '`). 

### Función `ft_split`
La función `ft_split` se encuentra en un archivo separado debido a su complejidad. Esta función realiza una separación de la cadena basándose en el separador y devuelve un nuevo arreglo. En el programa principal, se usa con una sola línea de código, pero en realidad contiene múltiples funciones internas (en este caso, tres) y suma más de 100 líneas de código.


### `init_stack_one_arg` / `init_stack`
- Depende si entra como un solo argumento `init_stack_one_arg` o multiples argumentos `init_stack`

Inicializa la pila, creando la pila (es decir, una lista enlazada en el heap). Básicamente, este es el creador de la pila. 
La función se asegura de evitar repeticiones, manejar desbordamientos de enteros y gestionar las conexiones entre nodos. Al final, se libera cualquier memoria innecesaria para evitar pérdidas.

Ahora tenemos una lista enlazada correctamente configurada en el heap, lista para ser utilizada en el algoritmo. ¿Qué opinas? Con la animación es bastante directo.

Esto resume cómo funciona `init_stack_one_arg` / `init_stack` y las herramientas relacionadas. Ahora estamos listos para implementar comandos como `swap`, `rotate`, y `push` para trabajar con nuestra pila bajo las restricciones definidas.


Estamos en una fase en la que debemos agregar funcionalidades a nuestra pila: permitir que los nodos se muevan, específicamente para realizar las operaciones de intercambio, rotación, rotación inversa y empuje.

## Instrucciones Básicas:
## sa (swap a):
- Intercambia los dos elementos en la cima de la pila A.
## sb (swap b):
- Intercambia los dos elementos en la cima de la pila B.
## ss:
- Aplica sa y sb simultáneamente.
## pa (push a):
- Toma el elemento superior de la pila B y lo coloca en la cima de la pila A.
## pb (push b):
- Toma el elemento superior de la pila A y lo coloca en la cima de la pila B.
## ra (rotate a):
- Rota todos los elementos de la pila A una posición hacia arriba.
## rb (rotate b):
- Rota todos los elementos de la pila B una posición hacia arriba.
## rr:
- Aplica ra y rb simultáneamente.
## rra (reverse rotate a):
- Rota todos los elementos de la pila A una posición hacia abajo.
## rrb (reverse rotate b):
- Rota todos los elementos de la pila B una posición hacia abajo.
## rrr:
- Aplica rra y rrb simultáneamente.


En conclusión, estas operaciones son simplemente tareas de "conectar y desconectar" punteros en una lista enlazada. Al principio puede parecer complicado, pero una vez que te familiarizas, no es difícil. Además, este enfoque es elegante y fácil de implementar. Usar una lista enlazada facilita estas manipulaciones de datos, aunque también podrías usar un arreglo, dependiendo de tus preferencias.

Finalmente, después de implementar estas operaciones, podemos usar el algoritmo para ordenar una serie de números generados aleatoriamente utilizando solo estas instrucciones, logrando resolver el problema de manera eficiente dentro de las restricciones dadas.

Ahora vamos a entender muy bien los algoritmos que voy a usar. Primero que nada, tengo un archivo llamado *sort_up_to_five.c * en el que tengo todo lo necesario para realizar este tipo de ordenamiento. ¿Cuál es la idea del *sort_up_to_five.c *? Bueno, si tengo 5, 4 o solo 3 nodos, este ultimo va a ser súper trivial ordenar estos elementos.

Ahora, el problema real, claro, es ordenar una serie de números más grande que tres nodos.

Por supuesto, vamos a necesitar el stack B. En este caso, no podemos hacer magia solo con el stack A como cuando teníamos solo tres nodos. ¿Qué hago entonces? Sé que para ordenar tres elementos es como mi caso base. Cuando tengo tres elementos en mi stack, realizo *tiny sort*. Esto es mi caso base, lo puedo hacer muy fácilmente. Así que empujo todos los elementos a B hasta que solo queden tres elementos en A.

Una vez que tenga esta situación, la repito, realizando *sort_three* en A. 

Ahora bien, el problema real, el verdadero núcleo del algoritmo, es ordenar una serie de números que sea mayor que 3 nodos, 4 o 5. 
Pero como vieron, puedo tener múltiples nodos, puedo tener cien, quinientos nodos. ¿Qué hago en este caso? Dado que solo tengo esas operaciones: "swap", "rotate", "reverse rotate" y "push", ¿qué hago? Pues tengo que diseñar un algoritmo.  Por supuesto, vamos a necesitar la pila B en este caso, ya que no podemos hacer magia solo con la pila A como cuando teníamos solo tres nodos.

Sé que para ordenar 3 elementos es mi caso base. Realizo "sort_three".

Entonces empujo todos los elementos en B hasta que solo queden tres elementos en A. Una vez que tengo esta situación, hago mi caso base "sort_three" en la pila A. 

¿Qué hacemos después? Tenemos que realizar una inserción precisa de los nodos desde B a A, y esta es, por supuesto, la parte difícil, tenemos que idear una estrategia. Decido que cada nodo de B tendrá un nodo "Target" (objetivo), ¿y qué es este nodo objetivo? es un nodo que es más grande que el nodo en B. En este caso, estoy usando 42 como ejemplo. Pero no solo debe ser más grande, debe ser el más pequeño de los más grandes. Esto es un poco difícil de entender, pero denme tiempo. Por el contrario, 1,337 obtiene -21. Esta vez no es más grande porque 1,337 es el más grande, así que no puedo encontrar nada más grande en la pila A. Así que busco el más pequeño, esa es la clave.

Probablemente es mejor explicar este punto con un caso real cuando tengo muchos nodos. Ahora miren cuidadosamente aquí. Cada nodo de B tiene que estar vinculado a un nodo de A. Es decir, cada nodo debe tener un nodo "Target" que sea más grande, como les acabo de decir, pero al mismo tiempo tiene que ser la mejor opción para la etapa actual. Por ejemplo, -48 querría tomar como objetivo algo que sea más grande, pero debe ser el más pequeño de los más grandes. Así que, ¿cuál es en este caso? Tengo -21, -16 y 96. El más pequeño de los más grandes es -21. Entonces, -48 obtiene como objetivo -21. ¿Por qué? Porque quiero empujar este nodo justo encima de -21, respetando el orden ascendente. Así que si pongo -48 justo encima de -21, tengo la propiedad ascendente. Sencillo. 

Ahora, -3 obtiene algo que es más grande. Bueno, -3 obtiene 96, ya que es el único que es más grande. 100 no es más grande que nada en la pila A. Entonces, ¿qué hago en este caso? Quiero el más pequeño, quiero el más pequeño que sea -21. ¿Por qué el más pequeño? Porque tienes que pensar que esto es como un objeto redondo. Esta lista enlazada es como un anillo. Básicamente, puedo rotar. Puedo rotar. Así que tengo el más grande que fácilmente puede ir justo encima del más pequeño. Al final del algoritmo, solo tengo que rotar hasta tener mi lista enlazada en orden. Así que tengo 100 apuntando a 21, y luego, básicamente, todos los nodos se van a vincular a un nodo específico.

Ahora, tengo todos los nodos que tienen un nodo "Target" específico, que tiene que ser el más pequeño de los más grandes. Si no encuentro nada que cumpla con esta condición, el nodo "Target" va a ser el más pequeño porque estos son objetos redondos. Sencillo, ¿de acuerdo?

Este es el código. Este es el código para establecer el nodo objetivo. Como pueden ver, si solo miran el código no es muy sencillo, pero si entienden el principio, no es tan difícil. Tengo un "while" que dice: "Hasta que no haya elementos en mi lista enlazada B, ¿qué hago?" Simplemente busco iterativamente todos los nodos que están en la pila A. Y miren bien la condición que destacamos. Si el valor de A es mayor que el valor de B, es decir, si el nodo tiene un valor mayor y al mismo tiempo es la mejor opción, es decir, el valor más cercano pero mayor, entonces lo establezco como nodo "Target". Si no encuentro algo que sea mayor, busco el más pequeño. Esa es la idea.

Creo que si ven el código con la explicación y la visualización, no es tan difícil de entender, ¿verdad? Ahora que tengo todos mis nodos objetivo, tengo que decidir qué movimiento hacer. ¿A quién muevo ahora? Sé que tres, por ejemplo, debería ir justo encima de 96, pero ahora tengo otro truco. Tengo que asignar a cada nodo su posición actual. Ahora, amigos, entienden muy bien lo que significa este valor de "posición actual", ¿verdad? Cada vez que un nodo tiene una posición específica, dependiendo de la configuración específica de las pilas, así que dada esta posición actual, cada vez que hago un "push", todo va a cambiar. Puedo explotar estas posiciones para obtener el valor de "push", el "push price" (precio del push). ¿Qué es este "push price"? Bueno, es la suma de la posición actual del nodo y el nodo objetivo. Por ejemplo, tomemos -3. -3 tiene una posición actual de 0 y 96 tiene una posición actual de 2. Pero esto no es totalmente correcto, ¿por qué? ¿Qué significa añadir las posiciones? Bueno, puedo realizar el "push" con los elementos superiores. Así que el costo es cuán costoso es llevar el nodo y el nodo objetivo a la parte superior de las pilas. ¿Cuánto cuesta llevar -3 y 96 a la parte superior? Como pueden ver, no es correcto. El costo aquí es uno, porque -3 ya está en la posición superior, mientras que 96 está en la posición inferior. Solo necesito realizar una "reverse rotate". Simplemente tengo que llevar 96 a la parte superior, lo que puedo hacer con un movimiento. Así que la pregunta no es cierta. ¿Qué podemos hacer? Podemos simplemente realizar una subdivisión en dos partes: una superior, media y una inferior a la media. Con esta vista, solo tengo los elementos que están en el medio de las pilas, que son los más costosos. Como pueden ver

, la posición se encuentra como en la "misma pile". Pero el valor final es cuánto me cuesta cada uno. El objetivo es realizar la operación.

## 4. Algoritmo de Ordenación:
## Implementaré el algoritmo llamado "Turco":

- Tiene dos fases principales: 

1. **Mover números del stack A al stack B** hasta que en A queden solo tres números, que ordenaremos facilmente en A.
2. **Mover números de regreso desde el stack B al stack A**, asegurando que queden correctamente ordenados en A.

### **Fase 1: Pasar números de A a B**
1. **Preparación inicial:**
   - Empuja los primeros dos números de A a B sin ningún cálculo ni orden.
   - Esto da a B un número grande y un número pequeño inicial para comenzar a ordenar.

2. **Criterios para mover nodos de A a B:**
   - **Nodo objetivo en B:** Cada número en A necesita un "nodo objetivo" en B, que es:
     - El número más pequeño en B que sea **mayor** que el número que estás empujando.
     - Si no hay ningún número mayor en B, el nodo objetivo será el número más grande en B.

3. **Cálculo del costo de inserción:**
   - Para cada número en A, calcula:
     - **Operaciones para llevar el número a la cima de A.**
     - **Operaciones para llevar su nodo objetivo a la cima de B.**
   - El costo de empuje es la suma de estas operaciones.

4. **Seleccionar el nodo más barato:**
   - Encuentra el número en A con el costo de empuje más bajo.
   - Mueve este número a B, ordenando B en **orden descendente** a medida que avanza.

5. **Repite el proceso:**
   - Continúa empujando números de A a B hasta que solo queden **tres números en A**.

---

### **Fase 2: Ordenar los tres números restantes en A**
1. **Algoritmo de tres números:**
   - Si los números en A no están en orden ascendente:
     - Encuentra el número más grande y colócalo en la **parte inferior** usando rotaciones.
     - Intercambia los dos números superiores si es necesario para que queden en orden ascendente.

---

### **Fase 3: Pasar números de B a A**
1. **Preparación del nodo objetivo en A:**
   - Cada número en B necesita un "nodo objetivo" en A, que es:
     - El número más grande en A que sea **menor** que el número que estás empujando.
     - Si no hay ningún número menor en A, el nodo objetivo será el número más pequeño en A.

2. **Cálculo del costo de inserción:**
   - Para cada número en B:
     - **Operaciones para llevar el número a la cima de B.**
     - **Operaciones para llevar su nodo objetivo a la cima de A.**
   - Calcula el costo total.

3. **Seleccionar el nodo más barato:**
   - Encuentra el número en B con el costo de empuje más bajo.
   - Mueve este número a A, asegurando que A permanezca en **orden ascendente**.

4. **Repite el proceso:**
   - Continúa moviendo números de B a A hasta que B esté vacío.

---

### **Fase final: Ajustar el número más pequeño en A**
- Una vez que todos los números estén en A, encuentra el número más pequeño.
- Si no está en la cima de A:
  - Usa rotaciones (rotate o reverse rotate) para llevarlo a la cima.

---

## EJEMPLO:

### **Pila A Inicial:**
```
./push_swap 1 6 3 4 5 7 2
```

```
A   B   (TOP)
2   
7
5
4
3
6
1
```

---
# **Fase 1: Mover los números de A a B hasta que en A queden solo tres números**

1. **Mover el primer número (2) de A a B:**
   - El número **2** es el primero en la pila A y se mueve directamente a B.


```
A   B
7  [2]  
5
4
3
6
1
```

2. **Mover el siguiente número (7) de A a B:**
   - El número **7** es el segundo número en moverse directamente a B.

```
A   B
5  [7]
4   2
3
6
1
```
 
Ahora, procederemos con el análisis adecuado para mover los **restantes números de A** a B, siguiendo los pasos del algoritmo:

#### Paso 1: Análisis para el número **5** de A a B
1. **Preparar el nodo objetivo de 5 en B**:
   - El nodo objetivo de **5** en **B** es **2** porque **2** es el número más cercano en **B** que es menor que **5**.

```
 A   B
[5]  7
 4  [2]
 3
 6
 1
```
   
2. **Calcular el costo de inserción**:
   - **A** está en la posición correcta para mover **5**, no se requieren movimientos adicionales en A.
   - En **B**, se necesita hacer un cambio porque **5** debe colocarse encima de **2** se hará `rb`. 
   
   **Costo de inserción** = 1 (`rb`)

#### Paso 2: Análisis para el número **4** de A a B
1. **Preparar el nodo objetivo de 4 en B**:
   - El nodo objetivo de **4** en **B** es **2** porque **2** es el número más cercano en **B** que es menor que **4**.

```
 A   B
 5   7
[4] [2]
 3
 6
 1
```
   
2. **Calcular el costo de inserción**:
   - **A** no está en la posición correcta para mover **4** necesitamos un cambio `ra`.
   - En **B**, se necesita hacer un cambio porque **4** debe colocarse encima de **2** se hará `rb`.

   **Costo de inserción** = 2 (`ra` `rb`)


#### Paso 3: Análisis para el número **3** de A a B
1. **Preparar el nodo objetivo de 3 en B**:
   - El nodo objetivo de **3** es **2** porque **2** es el número más cercano en **B** que es menor que **3**.

```
 A   B
 5   7
 4  [2]
[3]
 6
 1
```
   
2. **Calcular el costo de inserción**:
   - **A** no está en la posición correcta para mover **3** necesitamos dos cambios `ra` `ra`.
   - En **B**, se necesita hacer un cambio porque **3** debe colocarse encima de **2** se hará `rb`.

   **Costo de inserción** = 3 (`ra` `ra` `rb`).

#### Paso 4: Análisis para el número **6** de A a B
1. **Preparar el nodo objetivo de 6 en B**:
   - El nodo objetivo de **6** es **2** porque **2** es el número más cercano en **B** que es menor que **6**.

```
 A   B
 5   7
 4  [2]
 3
[6]
 1
```
   
2. **Calcular el costo de inserción**:
   - **A** no está en la posición correcta para mover **6** necesitamos dos cambios `rra` `rra`.
   - En **B**, se necesita hacer un cambio porque **6** debe colocarse encima de **2** se hará `rb`.
   
   **Costo de inserción** = 3 (`rra` `rra` `rb`).


#### Paso 5: Análisis para el número **1** de A a B
1. **Preparar el nodo objetivo de 1 en B**:
   - El nodo objetivo de **1** es el número **7** en **B** ya que **1** no es mayor que 2 es menor que todos los números en **B**.
```
 A   B
 5  [7]
 4   2
 3
 6
[1]
```
   
2. **Calcular el costo de inserción**:
   - **A** no está en la posición correcta para mover **1** necesitamos un cambio `rra`.
    - En **B**, se no se necesita hacer cambios porque **1** puede colocarse encima de **7**.
      
   **Costo de inserción** = 1 (`rra`).


### Los costes de inserción mas baratos son:

 - **Costo de inserción** = 1 (`rb`) para el número **5**
 - **Costo de inserción** = 1 (`rra`) para el número **1**
 - Al ser iguales, tomamos por orden y el primero en analizar fue el número **5**

```
 A   B              A   B              A   B
[5]  7             [5] [2]             4  [5]
 4  [2]             4   7              3  [2]
 3        (rb) ->   3        (pb) ->   6   7
 6                  6                  1
 1                  1
```
## Volvemos a repetir el proceso de nodo objetivo / Coste:

```
 A   B
 4   5
 3   2
 6   7
 1
```
- En este caso el mas barato es el número **4**

```
 A   B              A   B              A   B
[4]  5             [4] [2]             3  [4]
 3  [2]   (rb) ->   3   7    (pb) ->   6  [2]
 6   7              6   5              1   7
 1                  1                      5
```
- Ya que **4** es mayor que **2** y menor que el resto de **B**
```
 A   B
 3   4
 6   2
 1   7
     5
```
# **Fase 2: Ordenar los tres números restantes en A**
1. **Algoritmo de tres números:**
   - Si los números en A no están en orden ascendente:
     - Encuentra el número más grande y colócalo en la **parte inferior** usando rotaciones.
     - Intercambia los dos números superiores si es necesario para que queden en orden ascendente.

```
 A   B
 1   4
 3   2
 6   7
     5
```
# **Fase 3: Pasar números de B a A**
- Recordamos:
- Cada número en **B** necesita un "nodo objetivo" en **A**, que es:
     - El número más grande en **A** que sea **menor** que el número que estás empujando.
     - Si no hay ningún número menor en **A**, el nodo objetivo será el número más pequeño en **A**.
     - 
## Volvemos a repetir el proceso de nodo objetivo / Coste en sentido contrario:

---

### **Resultado Final:**
La pila **A** está ahora ordenada en orden ascendente:

```
[1, 2, 3, 4, 5, 6, 7]
```

---



---
## Verificación:
- Se puede implementar un módulo de verificación para asegurarse de que la secuencia de instrucciones ordena correctamente los números.





