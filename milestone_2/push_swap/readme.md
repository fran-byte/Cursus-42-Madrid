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
[1, 6, 3, 4, 5, 7, 2]
```
- El número **1** está en el fondo de la pila.
- El número **2** está en la parte superior (top) de la pila.

---

### **Fase 1: Mover los números de A a B hasta que en A queden solo tres números**

1. **Mover el primer número (1) de A a B:**
   - No es necesario hacer ningún cálculo, simplemente empujamos el número **1** de A a B.
   - **Pila A:** `[6, 3, 4, 5, 7, 2]`  
   - **Pila B:** `[1]` (Orden descendente en B)

2. **Mover el siguiente número (6) de A a B:**
   - Como **6** es el siguiente número más grande, se empuja directamente a B.
   - **Pila A:** `[3, 4, 5, 7, 2]`  
   - **Pila B:** `[6, 1]` (Orden descendente en B)

3. **Mover el siguiente número (3) de A a B:**
   - El nodo objetivo de **3** en B es **6**, ya que **3** es menor que **6** pero mayor que **1**. Entonces **3** se coloca sobre **6**.
   - **Pila A:** `[4, 5, 7, 2]`  
   - **Pila B:** `[6, 3, 1]` (Orden descendente en B)

4. **Mover el siguiente número (4) de A a B:**
   - El nodo objetivo de **4** es **5**, ya que **4** es menor que **5** pero mayor que **3**. Esto requiere que se realice una rotación inversa en B para mover **5** a la parte superior.
   - **Pila A:** `[5, 7, 2]`  
   - **Pila B:** `[6, 5, 4, 3, 1]` (Orden descendente en B)

5. **Mover el siguiente número (5) de A a B:**
   - El nodo objetivo de **5** es **6**, ya que **5** es menor que **6** pero mayor que **3**. Se empuja **5** sobre **6**.
   - **Pila A:** `[7, 2]`  
   - **Pila B:** `[6, 5, 4, 3, 1]` (Orden descendente en B)

6. **Mover el siguiente número (7) de A a B:**
   - El nodo objetivo de **7** es **6**, ya que **7** es mayor que todos los demás en B. Por lo tanto, **7** se empuja directamente sobre **6**.
   - **Pila A:** `[2]`  
   - **Pila B:** `[7, 6, 5, 4, 3, 1]` (Orden descendente en B)

7. **Mover el siguiente número (2) de A a B:**
   - El nodo objetivo de **2** es **3**, ya que **2** es menor que **3** pero mayor que **1**. Se empuja **2** sobre **3**.
   - **Pila A:** `[]` (vacía)  
   - **Pila B:** `[7, 6, 5, 4, 3, 2, 1]` (Orden descendente en B)

---

### **Fase 2: Ordenar los tres números restantes en A**
En este caso, la fase de ordenar los tres números en A no es necesaria, ya que A está vacío. Así que pasamos directamente a la siguiente fase.

---

### **Fase 3: Mover los números de B a A**

Ahora, vamos a devolver los números de B a A, manteniendo el orden ascendente en A. Recordemos que en B, los números están en orden descendente.

1. **Mover 7 desde B a A:**
   - El nodo objetivo de **7** en A es el número **2**, ya que **7** es mayor que todos los demás números en A.
   - **Pila A:** `[7]`  
   - **Pila B:** `[6, 5, 4, 3, 2, 1]`

2. **Mover 6 desde B a A:**
   - El nodo objetivo de **6** en A es **7**, ya que **6** es menor que **7** pero mayor que los demás.
   - **Pila A:** `[6, 7]`  
   - **Pila B:** `[5, 4, 3, 2, 1]`

3. **Mover 5 desde B a A:**
   - El nodo objetivo de **5** en A es **6**, porque **5** es menor que **6** pero mayor que los demás.
   - **Pila A:** `[5, 6, 7]`  
   - **Pila B:** `[4, 3, 2, 1]`

4. **Mover 4 desde B a A:**
   - El nodo objetivo de **4** en A es **5**, ya que **4** es menor que **5** pero mayor que **3**.
   - **Pila A:** `[4, 5, 6, 7]`  
   - **Pila B:** `[3, 2, 1]`

5. **Mover 3 desde B a A:**
   - El nodo objetivo de **3** en A es **4**, ya que **3** es menor que **4** pero mayor que **2**.
   - **Pila A:** `[3, 4, 5, 6, 7]`  
   - **Pila B:** `[2, 1]`

6. **Mover 2 desde B a A:**
   - El nodo objetivo de **2** en A es **3**, ya que **2** es menor que **3** pero mayor que **1**.
   - **Pila A:** `[2, 3, 4, 5, 6, 7]`  
   - **Pila B:** `[1]`

7. **Mover 1 desde B a A:**
   - El nodo objetivo de **1** en A es **2**, ya que **1** es el número más pequeño y debe ir al fondo de la pila.
   - **Pila A:** `[1, 2, 3, 4, 5, 6, 7]`  
   - **Pila B:** `[]` (vacía)

---

### **Resultado Final:**
La pila A está ordenada en orden ascendente:

```
[1, 2, 3, 4, 5, 6, 7]
```

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
                                 
