
### **Introducción a las Listas Enlazadas**

Una **lista enlazada** es una estructura de datos lineal en la que los elementos no están almacenados de forma contigua en memoria. En lugar de eso, cada elemento de la lista (llamado **nodo**) contiene un **valor** (o datos) y un **puntero** que apunta al siguiente nodo. Esto permite que los nodos estén distribuidos por la memoria, sin necesidad de ocupar un bloque contiguo como en los arreglos.

### **Estructura Básica de un Nodo**

Cada nodo en una lista enlazada puede ser representado de la siguiente manera en C:

```c
typedef struct s_node {
    int data;             // Almacena el valor del nodo
    struct s_node *next;  // Puntero al siguiente nodo
} t_node;
```

En este ejemplo:
- **`data`** es el valor que almacena el nodo (puede ser un número, un string, o cualquier tipo de dato).
- **`next`** es un puntero que apunta al siguiente nodo en la lista. Si es el último nodo, este puntero apunta a `NULL`.

### **Tipos de Listas Enlazadas**

Existen varias variaciones de listas enlazadas, y cada una tiene sus propias características y ventajas. Las tres principales son:

1. **Lista Enlazada Simple**:
   - Cada nodo contiene un valor y un puntero al siguiente nodo.
   - El último nodo apunta a `NULL`, indicando el final de la lista.
   
2. **Lista Enlazada Doblemente**:
   - Cada nodo tiene dos punteros: uno que apunta al siguiente nodo y otro que apunta al nodo anterior.
   - Esto permite recorrer la lista en ambas direcciones: hacia adelante y hacia atrás.

3. **Lista Circular**:
   - El último nodo de la lista no apunta a `NULL`, sino que apunta de nuevo al primer nodo, formando un ciclo.
   - Esto puede ser útil para ciertas aplicaciones en las que se necesita recorrer la lista de forma continua.

### **Operaciones Básicas en una Lista Enlazada**

Las listas enlazadas permiten realizar una serie de operaciones esenciales. A continuación, te detallo las más comunes:

#### 1. **Crear un Nodo**
Para crear un nuevo nodo, se debe asignar memoria dinámicamente (por ejemplo, con `malloc` en C) y asignarle un valor y un puntero `next` (inicialmente a `NULL`).

```c
t_node *new_node = (t_node *)malloc(sizeof(t_node));  // Asignar memoria para un nuevo nodo
new_node->data = 10;  // Asignar un valor al nodo
new_node->next = NULL;  // El siguiente nodo es NULL (indica que es el último nodo)
```

#### 2. **Insertar un Nodo al Frente (Al Principio)**
Para insertar un nodo al principio de la lista, simplemente haces que el nuevo nodo apunte al nodo que está al frente (actualmente el primer nodo), y luego actualizas el puntero de la cabeza de la lista para que apunte al nuevo nodo.

```c
void add_front(t_node **head, t_node *new_node) {
    new_node->next = *head;  // El nuevo nodo apunta al nodo actual al frente
    *head = new_node;        // La cabeza de la lista ahora apunta al nuevo nodo
}
```

#### 3. **Insertar un Nodo al Final**
Para insertar un nodo al final de la lista, debes recorrer la lista desde la cabeza hasta encontrar el último nodo (el nodo cuyo puntero `next` es `NULL`). Luego, haces que el último nodo apunte al nuevo nodo.

```c
void add_back(t_node **head, t_node *new_node) {
    if (*head == NULL) {
        *head = new_node;  // Si la lista está vacía, el nuevo nodo es el primer nodo
    } else {
        t_node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // Recorre la lista hasta el último nodo
        }
        temp->next = new_node;  // El último nodo ahora apunta al nuevo nodo
    }
}
```

#### 4. **Eliminar el Primer Nodo**
Para eliminar el primer nodo de la lista, simplemente haces que el puntero de la cabeza apunte al siguiente nodo. Luego, liberas la memoria del nodo eliminado.

```c
void remove_front(t_node **head) {
    if (*head != NULL) {
        t_node *temp = *head;
        *head = (*head)->next;  // La cabeza de la lista ahora apunta al siguiente nodo
        free(temp);             // Libera la memoria del nodo eliminado
    }
}
```

#### 5. **Recorrer la Lista**
Recorrer la lista es una operación común para acceder a todos los nodos y realizar alguna acción sobre sus valores (como imprimirlos o buscar un valor). Empiezas en el primer nodo (cabeza) y sigues los punteros `next` hasta llegar al final (cuando `next` es `NULL`).

```c
void print_list(t_node *head) {
    t_node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);  // Imprime el valor del nodo
        current = current->next;          // Mueve al siguiente nodo
    }
    printf("NULL\n");  // Marca el final de la lista
}
```

#### 6. **Buscar un Nodo**
Para buscar un nodo con un valor específico, debes recorrer la lista y comparar el valor de cada nodo hasta encontrar el que buscas o llegar al final de la lista.

```c
t_node *search_node(t_node *head, int value) {
    t_node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;  // Devuelve el nodo si lo encuentra
        }
        current = current->next;
    }
    return NULL;  // Si no lo encuentra, devuelve NULL
}
```

#### 7. **Eliminar un Nodo Específico**
Eliminar un nodo que no sea el primero implica encontrar el nodo anterior al que deseas eliminar, actualizar su puntero `next` para que apunte al nodo siguiente al que se eliminará, y luego liberar la memoria del nodo eliminado.

```c
void remove_node(t_node **head, int value) {
    t_node *current = *head;
    t_node *prev = NULL;
    
    // Si el nodo a eliminar es el primero
    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    // Busca el nodo a eliminar
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Si no se encuentra el nodo
    if (current == NULL) return;

    prev->next = current->next;  // El nodo anterior apunta al siguiente
    free(current);               // Libera la memoria del nodo eliminado
}
```

### **Ventajas de las Listas Enlazadas**

1. **Inserciones y eliminaciones rápidas**: Las operaciones de inserción o eliminación son rápidas y eficientes, especialmente cuando no necesitas mover elementos como en los arreglos.
2. **Memoria dinámica**: No es necesario reservar un espacio contiguo para los elementos, lo que te permite manejar de manera más flexible la memoria, adaptándola al tamaño de los datos.
3. **Sin límites de tamaño**: A diferencia de los arreglos estáticos, las listas enlazadas pueden crecer y reducir su tamaño de manera dinámica durante la ejecución del programa.

### **Desventajas de las Listas Enlazadas**

1. **Acceso secuencial**: A diferencia de los arreglos, no puedes acceder a un nodo por su índice directamente. Debes recorrer la lista nodo por nodo.
2. **Mayor consumo de memoria**: Cada nodo necesita almacenar un puntero adicional (`next`), lo que incrementa el consumo de memoria en comparación con los arreglos.
3. **Complejidad de implementación**: Las listas enlazadas requieren más código para implementarse y manipularse correctamente en comparación con los arreglos, debido al manejo explícito de punteros.

### **Conclusión**

Las listas enlazadas son una estructura de datos muy útil que permite almacenar colecciones de elementos de forma flexible. Aunque requieren una manipulación más cuidadosa de los punteros y memoria dinámica, ofrecen ventajas importantes cuando se trata de eficiencia en operaciones de inserción y eliminación. Al dominar su implementación y uso, estarás mejor preparado para manejar problemas complejos que involucren la gestión de colecciones de datos.
