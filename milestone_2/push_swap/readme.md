<p align="center" width="100%"><a href="milestone_2/"><img src="../documentation/milestone_2/push_swap.png" width="72" />

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
## Estrategia:
- Se elige un algoritmo de ordenación adecuado (por ejemplo, insertion sort, selection sort, quick sort, etc.) adaptado a las operaciones permitidas en las pilas.
## Implementación:
Se implementa el algoritmo utilizando las instrucciones básicas para mover los elementos entre las pilas y ordenarlas.
## 5. Optimización:
## Reducir movimientos:
Se buscan formas de minimizar el número de instrucciones necesarias para ordenar los números.
## Heurísticas:
- Se pueden utilizar heurísticas para tomar decisiones más eficientes durante la ordenación.
## Análisis de complejidad:
- Se evalúa la eficiencia del algoritmo en términos de tiempo y espacio.
## 6. Salida:
## Impresión de instrucciones:
- El programa imprime la secuencia de instrucciones utilizadas para ordenar los números.
## Verificación:
- Se puede implementar un módulo de verificación para asegurarse de que la secuencia de instrucciones ordena correctamente los números.
