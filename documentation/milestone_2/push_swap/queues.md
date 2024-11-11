
### **Características Principales de las Colas**

- **Orden de procesamiento:** FIFO, donde el primer elemento en entrar es el primero en salir.
- **Acceso limitado:** Solo se permite agregar elementos al final de la cola (también llamado "enqueue") y eliminar elementos desde el frente de la cola (también llamado "dequeue").
- **Usos típicos:** Las colas son ideales para tareas donde los elementos necesitan ser procesados en el mismo orden en el que llegan, como en la impresión de documentos, gestión de tareas, o sistemas de atención de clientes.

### **Operaciones Básicas en una Cola**

1. **Enqueue (inserción)**: Agrega un elemento al final de la cola.
2. **Dequeue (eliminación)**: Elimina el elemento del frente de la cola.
3. **Peek (frente)**: Permite ver el elemento al frente de la cola sin eliminarlo.
4. **isEmpty**: Comprueba si la cola está vacía.

### **Ejemplo de una Cola**

Imagina que tenemos una cola vacía, y realizamos estas operaciones:

1. **Enqueue(10)**: La cola ahora contiene `[10]`.
2. **Enqueue(20)**: La cola ahora contiene `[10, 20]`.
3. **Enqueue(30)**: La cola ahora contiene `[10, 20, 30]`.
4. **Dequeue()**: Se elimina el `10`, quedando la cola `[20, 30]`.
5. **Peek()**: El elemento al frente de la cola es `20`, pero no se elimina.

### **Implementación Básica en C**

Una cola se puede implementar usando una lista enlazada, donde un puntero apunta al frente y otro al final. Aquí un ejemplo básico de la operación `enqueue` y `dequeue` en C:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_queue {
    t_node *front;
    t_node *rear;
} t_queue;

// Funciones para la cola
void enqueue(t_queue *queue, int value);
int dequeue(t_queue *queue);
int peek(t_queue *queue);

int main() {
    t_queue queue = {NULL, NULL};

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue)); // Imprime 10
    printf("Dequeued element: %d\n", dequeue(&queue)); // Elimina 10

    return 0;
}

void enqueue(t_queue *queue, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dequeue(t_queue *queue) {
    if (queue->front == NULL) return -1; // Error si está vacía
    t_node *temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return value;
}

int peek(t_queue *queue) {
    if (queue->front == NULL) return -1; // Error si está vacía
    return queue->front->value;
}
```

### **¿Por Qué es Útil Conocer las Colas?**

Aunque las colas no son una parte central del proyecto, entenderlas te ayuda a dominar los conceptos de flujo de datos, lo cual es importante para estructuras de datos en general. Al igual que las pilas, las colas permiten manejar datos en orden y modelar procesos en los que los elementos deben seguir una secuencia específica, lo cual también tiene aplicaciones en la optimización de algoritmos y la gestión de tareas.
