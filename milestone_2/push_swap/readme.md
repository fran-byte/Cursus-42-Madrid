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

- Inicializa la pila, creando la pila (es decir, una lista enlazada en el heap). Básicamente, este es el creador de la pila.
  
- La función se asegura de evitar repeticiones, manejar desbordamientos de enteros y gestionar las conexiones entre nodos. Al final, se libera cualquier memoria innecesaria para evitar pérdidas.

- Ahora tenemos una lista enlazada correctamente configurada en el heap, lista para ser utilizada en el algoritmo.

- Estamos en una fase en la que debemos agregar funcionalidades a nuestra pila: permitir que los nodos se muevan, específicamente para realizar las operaciones de intercambio, rotación, rotación inversa y empuje.

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


- Estas operaciones son simplemente tareas de "conectar y desconectar" punteros en una lista enlazada. Este enfoque es elegante y fácil de implementar. Usar una lista enlazada facilita estas manipulaciones de datos, aunque también podrías usar un arreglo, dependiendo de tus preferencias.

- Después de implementar estas operaciones, podemos usar el algoritmo para ordenar una serie de números generados aleatoriamente utilizando solo estas instrucciones, logrando resolver el problema de manera eficiente dentro de las restricciones dadas.

- Primero que nada, tengo un archivo llamado *sort_up_to_five.c* en el que tengo todo lo necesario para realizar este tipo de ordenamiento básico. 
¿Cuál es la idea del *sort_up_to_five.c *? Ordenar 5, 4 o solo 3 nodos, este último va a ser una ordenación trivial.

- Para ordenar una cantidad de numeros mayores a 3, vamos a necesitar el stack B.
  
- Entonces la idea es empujar aplicando el algoritmo que veremos después todos los elementosde A a B hasta que solo queden tres elementos en A.

- Una vez que tenga esta situación, realizando *sort_three* en A. 


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
     - El número más grande en **A** que sea **menor** que el número que estás empujando de B, es decir, este "nodo objetivo" es un nodo que es más grande que el nodo en B, pero debe ser el más pequeño de los más grandes.
     - Si no hay ningún número mayor en **A** que el que vamos a empujar, el nodo objetivo pasará a ser el número más pequeño en **A**.
     - Aplicando siempre la regla de costes de movimientos, se pasará el número mas barato.
       


