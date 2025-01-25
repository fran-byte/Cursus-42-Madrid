# Teoría de Fondo para Philoshophers

## Programando con POSIX Threads

### Conceptos Básicos de los Hilos

1. **Definición de Hilos:**
   - **Hilo:** Es la unidad más pequeña de procesamiento que puede ser programada por un sistema operativo.
   - **Multitarea:** Permiten que un programa realice múltiples tareas simultáneamente dentro del mismo proceso.

2. **Ventajas de Usar Hilos:**
   - **Concurrencia:** Permiten que diferentes partes de un programa se ejecuten simultáneamente, mejorando la eficiencia.
   - **Compartición de Recursos:** Los hilos dentro del mismo proceso comparten el mismo espacio de direcciones, facilitando la comunicación y el intercambio de datos.
   - **Menor Sobrecarga:** Crear y gestionar hilos es menos costoso en términos de recursos del sistema comparado con la creación de procesos completos.

### Creación y Gestión de Hilos

Para trabajar con hilos en C, se utiliza la biblioteca POSIX Threads (pthreads).

#### Ejemplo Básico:

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    int *num = (int *)arg;
    printf("Hola desde el hilo %d\n", *num);
    return NULL;
}

int main() {
    pthread_t thread;
    int thread_arg = 1;

    // Crear un hilo
    if (pthread_create(&thread, NULL, thread_function, &thread_arg) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    // Esperar a que el hilo termine
    if (pthread_join(thread, NULL) != 0) {
        perror("Error al esperar el hilo");
        return 1;
    }

    printf("Hilo terminado\n");
    return (0);
}
```

## Explicación del Ejemplo:

- **Función del Hilo:** `thread_function` es la función que será ejecutada por el hilo.
- **Creación del Hilo:** `pthread_create` se utiliza para crear un hilo, pasando la función y su argumento.
- **Esperar al Hilo:** `pthread_join` se utiliza para esperar a que el hilo termine.

### Sincronización de Hilos

Para evitar condiciones de carrera y asegurar que los hilos no interfieran entre sí, se utilizan mecanismos de sincronización como los mutex.

#### Ejemplo con Mutex:

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;
int counter = 0;

void *increment_counter(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[2];

    // Inicializar el mutex
    pthread_mutex_init(&lock, NULL);

    // Crear dos hilos
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            perror("Error al crear el hilo");
            return 1;
        }
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < 2; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error al esperar el hilo");
            return 1;
        }
    }

    // Destruir el mutex
    pthread_mutex_destroy(&lock);

    printf("Valor final del contador: %d\n", counter);
    return 0;
}
```
#### Explicación del Ejemplo:

**Mutex**: pthread_mutex_t lock se utiliza para proteger el acceso a la variable counter.

**Sección Crítica**: Los hilos incrementan el contador dentro de una sección crítica protegida por el mutex.
