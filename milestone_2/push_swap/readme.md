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
   - **Pila B:** `[2]` (Orden descendente en B)

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

3. **Mover el siguiente número (5) de A a B:**
   - El nodo objetivo de **5** en B es **7**, ya que **5** es menor que **7** pero mayor que **2**. Entonces, **5** se coloca sobre **7**.
   - **Pila A:** `[4, 3, 6, 1]`  
   - **Pila B:** `[7, 5, 2]` (Orden descendente en B)
  
```
A   B
5   7
4   2
3
6
1
```

4. **Mover el siguiente número (4) de A a B:**
   - El nodo objetivo de **4** en B es **5**, ya que **4** es menor que **5** pero mayor que **2**. Entonces, **4** se coloca sobre **5**.
   - **Pila A:** `[3, 6, 1]`  
   - **Pila B:** `[7, 5, 4, 2]` (Orden descendente en B)

5. **Mover el siguiente número (3) de A a B:**
   - El nodo objetivo de **3** en B es **4**, ya que **3** es menor que **4** pero mayor que **2**. Entonces, **3** se coloca sobre **4**.
   - **Pila A:** `[6, 1]`  
   - **Pila B:** `[7, 5, 4, 3, 2]` (Orden descendente en B)

6. **Mover el siguiente número (6) de A a B:**
   - El nodo objetivo de **6** en B es **7**, porque **6** es menor que **7** pero mayor que todos los demás en B. Entonces, **6** se coloca sobre **7**.
   - **Pila A:** `[1]`  
   - **Pila B:** `[7, 6, 5, 4, 3, 2]` (Orden descendente en B)

7. **Mover el siguiente número (1) de A a B:**
   - El nodo objetivo de **1** en B es el número más grande en B (que es **7**). Como **1** es menor que todos los demás, se coloca sobre el número más grande.
   - **Pila A:** `[]` (vacía)  
   - **Pila B:** `[7, 6, 5, 4, 3, 2, 1]` (Orden descendente en B)

---

### **Fase 2: Ordenar los tres números restantes en A**
Dado que la **pila A está vacía**, esta fase no es necesaria.

---

### **Fase 3: Mover los números de B a A**

Ahora vamos a mover los números de **B** a **A**, manteniendo el orden ascendente en **A**. Recordemos que **B** está en orden descendente.

1. **Mover 7 desde B a A:**
   - El nodo objetivo de **7** en A es el número más pequeño en A (que aún no está allí). Como no hay números en A, simplemente empujamos **7**.
   - **Pila A:** `[7]`  
   - **Pila B:** `[6, 5, 4, 3, 2, 1]`

2. **Mover 6 desde B a A:**
   - El nodo objetivo de **6** en A es **7**, porque **6** es menor que **7** pero mayor que los demás. Se coloca **6** sobre **7**.
   - **Pila A:** `[6, 7]`  
   - **Pila B:** `[5, 4, 3, 2, 1]`

3. **Mover 5 desde B a A:**
   - El nodo objetivo de **5** en A es **6**, porque **5** es menor que **6** pero mayor que los demás. Se coloca **5** sobre **6**.
   - **Pila A:** `[5, 6, 7]`  
   - **Pila B:** `[4, 3, 2, 1]`

4. **Mover 4 desde B a A:**
   - El nodo objetivo de **4** en A es **5**, porque **4** es menor que **5** pero mayor que los demás. Se coloca **4** sobre **5**.
   - **Pila A:** `[4, 5, 6, 7]`  
   - **Pila B:** `[3, 2, 1]`

5. **Mover 3 desde B a A:**
   - El nodo objetivo de **3** en A es **4**, porque **3** es menor que **4** pero mayor que los demás. Se coloca **3** sobre **4**.
   - **Pila A:** `[3, 4, 5, 6, 7]`  
   - **Pila B:** `[2, 1]`

6. **Mover 2 desde B a A:**
   - El nodo objetivo de **2** en A es **3**, porque **2** es menor que **3** pero mayor que **1**. Se coloca **2** sobre **3**.
   - **Pila A:** `[2, 3, 4, 5, 6, 7]`  
   - **Pila B:** `[1]`

7. **Mover 1 desde B a A:**
   - El nodo objetivo de **1** en A es el número más pequeño, que debe ir al fondo de la pila. Se coloca **1** en la parte inferior de A.
   - **Pila A:** `[1, 2, 3, 4, 5, 6, 7]`  
   - **Pila B:** `[]` (vacía)

---

### **Resultado Final:**
La pila **A** está ordenada en orden ascendente:

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
                                 
