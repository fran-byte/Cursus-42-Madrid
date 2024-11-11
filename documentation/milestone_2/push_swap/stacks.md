
### **¿Qué es una Pila (Stack)?**

Una **pila** es una estructura de datos **lineal** que sigue el principio de **último en entrar, primero en salir (LIFO)**. Esto significa que el último elemento insertado en la pila es el primero en ser retirado.

Imagina una pila de platos: si pones un plato encima de la pila, cuando quieras sacar un plato, sacarás el de arriba, no el de abajo. La pila sigue este comportamiento de **apilar** (push) y **desapilar** (pop).

#### **Características Claves de las Pilas:**
- **Acceso restringido:** Solo puedes acceder al elemento en la parte superior de la pila (el "top").
- **Operaciones básicas:** `push`, `pop`, `peek` (o `top`).
- **Propósito:** Son útiles cuando necesitas mantener un orden de elementos en un modo de "último en entrar, primero en salir", como en la gestión de funciones recursivas, undo/redo en editores, y problemas como el que tienes entre manos.

### **Operaciones Básicas en una Pila**

#### 1. **Push**: Insertar un elemento en la pila.
Cuando insertas un nuevo elemento en la pila, lo colocas en la parte superior de la misma. Esta operación es rápida y toma **O(1)** tiempo porque solo modifica el puntero al último elemento.

```c
void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    new_node->value = value;
    new_node->next = *stack; // El nuevo nodo apunta al anterior top
    *stack = new_node;       // La pila ahora apunta al nuevo nodo
}
```

#### 2. **Pop**: Eliminar el elemento superior de la pila.
Al eliminar un elemento, simplemente se mueve el puntero que apunta a la pila hacia el siguiente elemento, y el nodo superior se libera. Esto también es **O(1)**.

```c
int pop(t_stack **stack) {
    if (*stack == NULL) {
        return -1;  // O un código de error si la pila está vacía
    }
    t_stack *temp = *stack;
    int value = temp->value;  // Obtener el valor a devolver
    *stack = (*stack)->next;  // La pila apunta al siguiente nodo
    free(temp);               // Liberar el nodo de la memoria
    return value;
}
```

#### 3. **Peek** o **Top**: Ver el elemento superior sin eliminarlo.
La operación de "peek" permite observar el valor en la parte superior de la pila sin alterarla. Es una operación de **O(1)**.

```c
int peek(t_stack *stack) {
    if (stack == NULL) {
        return -1;  // O un código de error si la pila está vacía
    }
    return stack->value;  // Devuelve el valor del primer nodo
}
```

#### 4. **isEmpty**: Verificar si la pila está vacía.
Es importante saber si la pila está vacía antes de intentar hacer operaciones `pop` o `peek`. Esto previene errores.

```c
int isEmpty(t_stack *stack) {
    return stack == NULL;  // Devuelve 1 si la pila está vacía, 0 si no
}
```

### **Cómo Funciona una Pila:**

A continuación, te explico cómo la pila manipula los datos y cómo estas operaciones afectan a su estado:

#### **Ejemplo de una Pila**

Imagina que tienes una pila vacía y realizas las siguientes operaciones:

1. **Push(10)**: La pila contiene `[10]`.
2. **Push(20)**: La pila contiene `[20, 10]` (20 está en la parte superior).
3. **Push(30)**: La pila contiene `[30, 20, 10]` (30 está en la parte superior).
4. **Pop()**: El valor `30` es retirado, y la pila ahora contiene `[20, 10]`.
5. **Peek()**: El valor en la parte superior de la pila es `20`.

### **Representación Gráfica de una Pila**

Imagina que tenemos los siguientes valores en una pila, de arriba hacia abajo:

```
Top -> [30] -> [20] -> [10] -> NULL
```

- **`Push(40)`**: La pila ahora tiene `40` en la parte superior:
  ```
  Top -> [40] -> [30] -> [20] -> [10] -> NULL
  ```

- **`Pop()`**: Se elimina el `40` y la pila se reduce a:
  ```
  Top -> [30] -> [20] -> [10] -> NULL
  ```

### **Piloto de Operaciones en una Pila**

Vamos a realizar un conjunto de operaciones en una pila paso a paso:

1. **Inicialización**:
   - La pila está vacía: `NULL`.

2. **Push(5)**:
   - La pila se convierte en: `[5]`.

3. **Push(10)**:
   - La pila se convierte en: `[10, 5]`.

4. **Push(20)**:
   - La pila se convierte en: `[20, 10, 5]`.

5. **Pop()**:
   - Se elimina el valor `20`, y la pila se convierte en: `[10, 5]`.

6. **Peek()**:
   - El valor en la parte superior es `10`.

7. **Pop()**:
   - Se elimina el valor `10`, y la pila se convierte en: `[5]`.

8. **Pop()**:
   - Se elimina el valor `5`, y la pila está vacía: `NULL`.

### **Implementación Básica de una Pila**

En C, una pila suele implementarse con una **lista enlazada**, donde cada nodo contiene un valor y un puntero al siguiente nodo. En este caso, la pila tendría un puntero al nodo superior (top) de la pila.

```c
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

// Funciones
void push(t_stack **stack, int value);
int pop(t_stack **stack);
int peek(t_stack *stack);
int isEmpty(t_stack *stack);

int main() {
    t_stack *stack = NULL;  // Pila vacía

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 20);

    printf("Top element: %d\n", peek(stack));  // Debería imprimir 20
    printf("Popped element: %d\n", pop(&stack));  // Debería eliminar 20

    return 0;
}

void push(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(t_stack **stack) {
    if (*stack == NULL) {
        return -1;  // Error si la pila está vacía
    }
    t_stack *temp = *stack;
    int value = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

int peek(t_stack *stack) {
    if (stack == NULL) {
        return -1;  // Error si la pila está vacía
    }
    return stack->value;
}

int isEmpty(t_stack *stack) {
    return stack == NULL;
}
```

### **¿Por Qué Usar Pilas?**

Las pilas son increíblemente útiles cuando necesitas **procesar datos en orden inverso**, o cuando deseas asegurar que los elementos se procesen en el orden en que fueron añadidos, pero eliminando siempre el último añadido.

**Aplicaciones comunes de las pilas incluyen:**
- **Evaluación de expresiones matemáticas** (por ejemplo, notación posfija o infija).
- **Recursión** (la pila de llamadas de funciones en la memoria de un programa funciona como una pila).
- **Algoritmos de deshacer y rehacer** (como en editores de texto).
- **Gestión de rutas en algoritmos de búsqueda** (por ejemplo, DFS).

### **Conclusión**

Las pilas son una estructura de datos fundamental y muy poderosa. Comprender cómo funcionan las operaciones básicas de `push`, `pop` y `peek` y cómo gestionar su memoria es esencial para implementar algoritmos eficientes que manejen colecciones de datos de manera controlada. Las pilas son especialmente útiles para simular situaciones en las que el orden de procesamiento es crítico.
