<p align="center" width="100%"><a href="milestone_2/"><img src="../../img/milestone_2/push_swap.png" width="72" />

# COMO INICIAR push_swap

## 1. Lectura y Validación de Datos:
## Entrada:
- El programa recibe una lista de números enteros como argumentos de la línea de comandos.
## Validación:
- Se verifica que los argumentos sean números válidos y que no haya duplicados.
## Inicialización:
- Se crean las dos pilas (A y B) y se inicializan con los números de entrada en la pila A.
## 2. Estructura de Datos:
## Pilas:
- Se utilizan dos pilas para almacenar los números.
## Nodo:
- Cada número se representa como un nodo en una lista enlazada.
## Funciones auxiliares:
- Se definen funciones para manejar las operaciones básicas en las pilas (push, pop, peek).
## 3. Instrucciones Básicas:
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
A   B
2   
7
5
4
3
6
1
```

- El número **1** está en el fondo de la pila.
- El número **2** está en la parte superior (top) de la pila.


---

### **Fase 1: Mover los números de A a B hasta que en A queden solo tres números**

1. **Mover el primer número (2) de A a B:**
   - El número **2** es el primero en la pila A y se mueve directamente a B.
   - **Pila A:** `[7, 5, 4, 3, 6, 1]`  
   - **Pila B:** `[2]`

```
A   B
7   2  
5
4
3
6
1
```

2. **Mover el siguiente número (7) de A a B:**
   - El nodo objetivo de **7** en B es **2**, porque **7** es mayor que **2**. Entonces, **7** se coloca encima de **2**.
   - **Pila A:** `[5, 4, 3, 6, 1]`  
   - **Pila B:** `[7, 2]` (Orden descendente en B)

```
A   B
5   7
4   2
3
6
1
```
 
Ahora, procederemos con el análisis adecuado para mover los **restantes números de A** a B, siguiendo los pasos del algoritmo:

#### Paso 1: Mover el número **5** de A a B
1. **Preparar el nodo objetivo de 5 en B**:
   - El nodo objetivo de **5** en **B** es **2** porque **2** es el número más cercano en **B** que es menor que **5**.
   
2. **Calcular el costo de inserción**:
   - **A** está en la posición correcta para mover **5**, no se requieren movimientos adicionales en A.
   - En **B**, se necesita hacer un cambio porque **5** debe colocarse encima de **2** se hará `sa`. 
   
   **Costo de inserción** = 1 

3. **Resultado**:
   - **Pila A:** `[4, 3, 6, 1]`
   - **Pila B:** `[5, 7, 2]` (Orden descendente en B)

#### Paso 2: Mover el número **4** de A a B
1. **Preparar el nodo objetivo de 4 en B**:
   - El nodo objetivo de **4** es **5** (ya que **4** es menor que **5** pero mayor que **2**).
   
2. **Calcular el costo de inserción**:
   - **A** está en la posición correcta para mover **4**.
   - En **B**, **4** debe ir encima de **5**, sin rotación.

   **Costo de inserción** = 0 (sin rotaciones).

3. **Resultado**:
   - **Pila A:** `[3, 6, 1]`
   - **Pila B:** `[4, 5, 7, 2]` (Orden descendente en B)

#### Paso 3: Mover el número **3** de A a B
1. **Preparar el nodo objetivo de 3 en B**:
   - El nodo objetivo de **3** es **4** (porque **3** es menor que **4** pero mayor que **2**).
   
2. **Calcular el costo de inserción**:
   - **A** está en la posición correcta para mover **3**.
   - En **B**, **3** debe ir encima de **4**, sin rotación.

   **Costo de inserción** = 0 (sin rotaciones).

3. **Resultado**:
   - **Pila A:** `[6, 1]`
   - **Pila B:** `[3, 4, 5, 7, 2]` (Orden descendente en B)

#### Paso 4: Mover el número **6** de A a B
1. **Preparar el nodo objetivo de 6 en B**:
   - El nodo objetivo de **6** es **7** (porque **6** es menor que **7** pero mayor que los demás).
   
2. **Calcular el costo de inserción**:
   - **A** está en la posición correcta para mover **6**.
   - En **B**, **6** debe ir encima de **7**, sin necesidad de rotación.
   
   **Costo de inserción** = 0 (sin rotaciones).

3. **Resultado**:
   - **Pila A:** `[1]`
   - **Pila B:** `[6, 3, 4, 5, 7, 2]` (Orden descendente en B)

#### Paso 5: Mover el número **1** de A a B
1. **Preparar el nodo objetivo de 1 en B**:
   - El nodo objetivo de **1** es el número **7** en **B** ya que **1** es menor que todos los números en **B**.
   
2. **Calcular el costo de inserción**:
   - No es necesario hacer ninguna rotación en **A** o **B**. **1** debe ir debajo de **7**, por lo que simplemente lo empujamos a **B**.
   
   **Costo de inserción** = 0 (sin rotaciones).

3. **Resultado**:
   - **Pila A:** `[]` (vacía)
   - **Pila B:** `[7, 6, 5, 4, 3, 2, 1]` (Orden descendente en B)

---

### **Fase 2: Ordenar los tres números restantes en A**

En este caso, **A está vacía**, por lo que esta fase no es necesaria.

---

### **Fase 3: Mover los números de B a A**

Ahora que hemos movido todos los números a **B**, necesitamos devolverlos a **A** en orden ascendente. Para ello, aplicamos el proceso de mover los números de **B** a **A**, asegurando que **A** se mantenga en orden ascendente.

1. **Mover 7 desde B a A**:
   - **7** es el nodo objetivo para **A** porque es el número más grande de **A**. 
   - **Pila A:** `[7]`
   - **Pila B:** `[6, 5, 4, 3, 2, 1]`

2. **Mover 6 desde B a A**:
   - El nodo objetivo de **6** en **A** es **7**, ya que **6** es menor que **7** pero mayor que los demás.
   - **Pila A:** `[6, 7]`
   - **Pila B:** `[5, 4, 3, 2, 1]`

3. **Mover 5 desde B a A**:
   - El nodo objetivo de **5** en **A** es **6**, ya que **5** es menor que **6** pero mayor que los demás.
   - **Pila A:** `[5, 6, 7]`
   - **Pila B:** `[4, 3, 2, 1]`

4. **Mover 4 desde B a A**:
   - El nodo objetivo de **4** en **A** es **5**, ya que **4** es menor que **5** pero mayor que los demás.
   - **Pila A:** `[4, 5, 6, 7]`
   - **Pila B:** `[3, 2, 1]`

5. **Mover 3 desde B a A**:
   - El nodo objetivo de **3** en **A** es **4**, ya que **3** es menor que **4** pero mayor que los demás.
   - **Pila A:** `[3, 4, 5, 6, 7]`
   - **Pila B:** `[2, 1]`

6. **Mover 2 desde B a A**:
   - El nodo objetivo de **2** en **A** es **3**, ya que **2** es menor que **3** pero mayor que **1**.
   - **Pila A:** `[2, 3, 4, 5, 6, 7]`
   - **Pila B:** `[1]`

7. **Mover 1 desde B a A**:
   - **1** es el número más pequeño y debe ir

 al fondo de la pila **A**.
   - **Pila A:** `[1, 2, 3, 4, 5, 6, 7]`
   - **Pila B:** `[]` (vacía)

---

### **Resultado Final:**
La pila **A** está ahora ordenada en orden ascendente:

```
[1, 2, 3, 4, 5, 6, 7]
```

---

Este es el proceso corregido y detallado, teniendo en cuenta la preparación del **nodo objetivo**, el **cálculo del costo de inserción**, y la **selección del nodo más barato** para los números restantes en **A**. ¡Gracias por tu paciencia! Si tienes más preguntas o dudas, no dudes en preguntar.

---
## Verificación:
- Se puede implementar un módulo de verificación para asegurarse de que la secuencia de instrucciones ordena correctamente los números.


# Posible estructura:

## push_swap()
                                 |___ get_numbers
     |_____read_input____________|___ check_duplicates
     |____ initialize_______     |___ validate_imput
     |____ algorithm___     |    
                       |    |           
                       |    |________ create_stacks                   |_ sa 
                       |                                              |_ sb
                       |_____________ choose_algorithm                |_ ss
                       |_____________ divide_piles                    |_ pa                         |__ swap
                       |_____________ compare_elements                |_ pb                         |__ rotate
                       |_____________ perform_Operations _____________|_ ra       -> aux_functions _|__ reverse_rotate
                       |_____________ check_condition                 |_ rb                         |__ calculate_cost
                                                                      |_ rr                         |__ find_cheapest_move
                                                                      |_ rra
                                                                      |_ rrb
                                                                      |_ rrr
                                 
