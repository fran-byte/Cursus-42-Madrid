# ESTRUCTURAS


### 1. ¿Qué es una estructura?

En C, una **estructura** es un conjunto de variables agrupadas bajo un mismo nombre, que pueden ser de diferentes tipos. Los elementos de la estructura se llaman **miembros** o **campos**, y las estructuras permiten organizar datos relacionados de manera lógica.

---

### 2. Declaración de una estructura

Para definir una estructura, utilizamos la palabra clave `struct`, seguida del nombre de la estructura y sus miembros. Por ejemplo, una estructura `Persona`:

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};
```

Esta estructura `Persona` tiene tres campos:
- `nombre`: un arreglo de caracteres para almacenar el nombre.
- `edad`: un entero para almacenar la edad.
- `altura`: un `float` para almacenar la altura en metros.

---

### 3. Crear e inicializar una estructura

Para crear e inicializar una variable de tipo `struct Persona`:

```c
int main() {
    struct Persona persona1;

    // Asignar valores a los campos de persona1
    strcpy(persona1.nombre, "Alice");
    persona1.edad = 30;
    persona1.altura = 1.65;

    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);
    printf("Altura: %.2f\n", persona1.altura);

    return 0;
}
```

En este ejemplo, hemos creado la estructura `persona1` y le hemos asignado valores a cada campo. La función `strcpy` se usa para asignar una cadena al campo `nombre`.

---

### 4. Uso de estructuras con punteros

Podemos manipular estructuras usando punteros, lo que es útil para modificar el contenido de una estructura desde una función.

```c
#include <stdio.h>

void actualizarEdad(struct Persona *p, int nuevaEdad) {
    p->edad = nuevaEdad;
}

int main() {
    struct Persona persona1 = {"Alice", 30, 1.65};

    printf("Edad antes de actualizar: %d\n", persona1.edad);

    // Actualizar la edad usando un puntero
    actualizarEdad(&persona1, 35);

    printf("Edad después de actualizar: %d\n", persona1.edad);

    return 0;
}
```

Aquí, el operador `->` permite acceder a los campos de una estructura a través de un puntero. La función `actualizarEdad` modifica la edad de `persona1` directamente.

---

### 5. Estructuras anidadas

Una estructura puede contener otra estructura. Por ejemplo, para añadir una dirección a `Persona`:

```c
struct Direccion {
    char calle[50];
    int numero;
    char ciudad[50];
};

struct Persona {
    char nombre[50];
    int edad;
    float altura;
    struct Direccion direccion;
};
```

Y en el `main`, podemos asignar valores a los campos anidados:

```c
int main() {
    struct Persona persona1;

    strcpy(persona1.nombre, "Bob");
    persona1.edad = 28;
    persona1.altura = 1.80;
    strcpy(persona1.direccion.calle, "Avenida Principal");
    persona1.direccion.numero = 123;
    strcpy(persona1.direccion.ciudad, "Ciudad X");

    printf("Nombre: %s\n", persona1.nombre);
    printf("Ciudad: %s\n", persona1.direccion.ciudad);

    return 0;
}
```

---

### 6. Arreglos de estructuras

También podemos crear un arreglo de estructuras para almacenar múltiples registros. Vamos a definir un arreglo de `struct Persona` y recorrerlo con `while`.

```c
#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 3

int main() {
    struct Persona personas[MAX_PERSONAS] = {
        {"Alice", 30, 1.65, {"Calle A", 101, "Ciudad A"}},
        {"Bob", 25, 1.70, {"Calle B", 102, "Ciudad B"}},
        {"Charlie", 35, 1.75, {"Calle C", 103, "Ciudad C"}}
    };

    int i = 0;
    while (i < MAX_PERSONAS) {
        printf("Nombre: %s, Edad: %d, Altura: %.2f, Ciudad: %s\n",
               personas[i].nombre, personas[i].edad, personas[i].altura, personas[i].direccion.ciudad);
        i++;
    }

    return 0;
}
```

Aquí estamos usando un ciclo `while` para recorrer el arreglo `personas` y mostrar los datos de cada persona.

---

### 7. Estructuras y funciones

Las estructuras se pueden pasar a funciones por valor (una copia) o por referencia (un puntero). Vamos a ver un ejemplo:

```c
void imprimirPersona(struct Persona p) {
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
    printf("Altura: %.2f\n", p.altura);
}

int main() {
    struct Persona persona1 = {"Alice", 30, 1.65};
    imprimirPersona(persona1);

    return 0;
}
```

Aquí, la función `imprimirPersona` recibe una copia de `persona1`, por lo que cualquier modificación dentro de la función no afectará al original.

---

### 8. Estructuras con memoria dinámica

Las estructuras también se pueden usar con memoria dinámica, lo cual es útil cuando se desconoce la cantidad exacta de datos de antemano.

```c
#include <stdlib.h>
#include <string.h>

struct Persona *crearPersona(const char *nombre, int edad, float altura) {
    struct Persona *p = (struct Persona *)malloc(sizeof(struct Persona));
    if (p) {
        strcpy(p->nombre, nombre);
        p->edad = edad;
        p->altura = altura;
    }
    return p;
}

int main() {
    struct Persona *persona1 = crearPersona("Alice", 30, 1.65);

    if (persona1) {
        printf("Nombre: %s, Edad: %d, Altura: %.2f\n",
               persona1->nombre, persona1->edad, persona1->altura);
        free(persona1);  // Liberamos la memoria asignada
    }

    return 0;
}
```

Aquí, `malloc` asigna memoria para una `struct Persona` en tiempo de ejecución. No olvides liberar la memoria con `free` para evitar fugas de memoria.

---

### Resumen

- **Declaración de estructuras**: `struct Persona { campos };`.
- **Inicialización y acceso**: `persona1.nombre` para acceder a los campos, `p->nombre` si es un puntero.
- **Arreglos de estructuras**: Se pueden recorrer con `while`.
- **Funciones y estructuras**: Pueden pasarse por valor o por referencia.
- **Memoria dinámica**: Usa `malloc` para estructuras cuando no se conoce el tamaño de antemano y libera con `free` al finalizar.


# LISTAS
### 1. `ft_lstnew_bonus.c`
Esta función crea un nuevo nodo de lista y asigna memoria para él, inicializando el campo de contenido (`content`) y poniendo el puntero `next` a `NULL`. Es la base para poder iniciar una lista.

```c
#include "libft.h"

t_list *ft_lstnew(void *content) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}
```

### 2. `ft_lstadd_front_bonus.c`
Esta función añade un nodo al principio de la lista. Modifica el puntero `head` de la lista para que apunte al nuevo nodo.

```c
#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new) {
    if (new) {
        new->next = *lst;
        *lst = new;
    }
}
```

### 3. `ft_lstsize_bonus.c`
Devuelve el tamaño de la lista, es decir, el número de nodos en ella. Recorre la lista contando los nodos.

```c
#include "libft.h"

int ft_lstsize(t_list *lst) {
    int count = 0;
    while (lst) {
        count++;
        lst = lst->next;
    }
    return count;
}
```

### 4. `ft_lstlast_bonus.c`
Devuelve el último nodo de la lista. Si la lista está vacía, devuelve `NULL`. Recorre la lista hasta encontrar el nodo cuyo `next` es `NULL`.

```c
#include "libft.h"

t_list *ft_lstlast(t_list *lst) {
    if (!lst)
        return NULL;
    while (lst->next)
        lst = lst->next;
    return lst;
}
```

### 5. `ft_lstadd_back_bonus.c`
Añade un nodo al final de la lista. Usa `ft_lstlast` para encontrar el último nodo y enlazar el nuevo nodo al final.

```c
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new) {
    if (!*lst) {
        *lst = new;
    } else {
        t_list *last = ft_lstlast(*lst);
        last->next = new;
    }
}
```

### 6. `ft_lstdelone_bonus.c`
Libera un solo nodo de la lista, aplicando una función `del` a su contenido antes de liberar el nodo en sí. Esto es útil para evitar fugas de memoria.

```c
#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *)) {
    if (lst && del) {
        del(lst->content);
        free(lst);
    }
}
```

### 7. `ft_lstclear_bonus.c`
Libera toda la lista, aplicando `del` a cada nodo y liberando su memoria. Esto es especialmente útil para liberar una lista entera en caso de errores o al final de su uso.

```c
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *)) {
    t_list *temp;

    while (*lst) {
        temp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = temp;
    }
}
```

### 8. `ft_lstiter_bonus.c`
Itera sobre cada nodo de la lista y aplica la función `f` al contenido de cada nodo. Esto permite manipular los datos sin cambiar la estructura de la lista.

```c
#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *)) {
    while (lst) {
        f(lst->content);
        lst = lst->next;
    }
}
```

### 9. `ft_lstmap_bonus.c` (ejemplo proporcionado)
Esta función es una versión más avanzada de `ft_lstiter`. Aplica la función `f` a cada nodo para crear una nueva lista, copiando cada nodo transformado por `f`. Si algo falla (por ejemplo, al asignar memoria para un nuevo nodo), la función usa `del` y `ft_lstclear` para liberar la memoria y evitar fugas.

Vamos a repasar brevemente cómo funciona tu ejemplo de `ft_lstmap`:

- Crea una lista nueva `new_list` y recorre la lista `lst` nodo por nodo.
- Para cada nodo:
  - Aplica `f` al contenido (`content`) del nodo actual.
  - Crea un nuevo nodo `new_node` con el contenido modificado.
  - Si `new_node` no se puede crear (es decir, falla la asignación de memoria), libera todo y sale.
  - Si la asignación es exitosa, añade el nodo a `new_list`.
- Al final, devuelve `new_list` con los datos transformados.

```c
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
    t_list *new_list = NULL;
    t_list *current_node = lst;
    t_list *new_node;
    void *new_content;

    if (!f || !del || !lst)
        return NULL;

    while (current_node) {
        new_content = f(current_node->content);
        new_node = ft_lstnew(new_content);
        if (!new_node) {
            free(new_content);
            ft_lstclear(&new_list, del);
            return NULL;
        }
        ft_lstadd_back(&new_list, new_node);
        current_node = current_node->next;
    }
    return new_list;
}
```

### Ejemplo de uso de `ft_lstmap`

Supón que tienes una lista que contiene enteros, y quieres crear una nueva lista en la que cada valor esté duplicado.

```c
#include "libft.h"
#include <stdio.h>

void *duplicate(void *content) {
    int *dup = malloc(sizeof(int));
    if (dup) {
        *dup = *(int *)content * 2;
    }
    return dup;
}

void delete_int(void *content) {
    free(content);
}

int main() {
    t_list *lst = ft_lstnew(malloc(sizeof(int)));
    *(int *)lst->content = 1;

    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node2->content = 2;
    ft_lstadd_back(&lst, node2);

    t_list *node3 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node3->content = 3;
    ft_lstadd_back(&lst, node3);

    t_list *new_lst = ft_lstmap(lst, &duplicate, &delete_int);

    // Imprimir ambas listas
    ft_lstiter(lst, [](void *content) { printf("%d -> ", *(int *)content); });
    printf("NULL\n");

    ft_lstiter(new_lst, [](void *content) { printf("%d -> ", *(int *)content); });
    printf("NULL\n");

    // Liberar memoria
    ft_lstclear(&lst, &delete_int);
    ft_lstclear(&new_lst, &delete_int);
    return 0;
}
```

Este ejemplo usa `ft_lstmap` para duplicar los valores en una nueva lista, manteniendo la original intacta.
