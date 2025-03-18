
### Capítulo 1: Fundamentos de C

#### Temas Teóricos

**Variables y tipos de datos:**

- **Tipos básicos:**
  - `int`: Utilizado para representar números enteros. Ejemplo: `int edad = 25;`
  - `char`: Utilizado para representar caracteres individuales. Ejemplo: `char letra = 'A';`
  - `float`: Utilizado para representar números de punto flotante de precisión simple. Ejemplo: `float altura = 1.75;`
  - `double`: Utilizado para representar números de punto flotante de doble precisión. Ejemplo: `double peso = 70.5;`

- **Modificadores:**
  - `short`: Modificador que reduce el tamaño de almacenamiento de un entero. Ejemplo: `short int edad = 25;`
  - `long`: Modificador que aumenta el tamaño de almacenamiento de un entero. Ejemplo: `long int poblacion = 1000000;`
  - `unsigned`: Modificador que indica que una variable solo puede contener valores positivos. Ejemplo: `unsigned int contador = 0;`

- **Declaración, inicialización y alcance (scope):**
  - **Declaración:** Proceso de definir una variable. Ejemplo: `int numero;`
  - **Inicialización:** Proceso de asignar un valor inicial a una variable. Ejemplo: `int numero = 10;`
  - **Alcance (scope):** Contexto dentro del cual una variable es accesible. Las variables pueden tener alcance local (dentro de una función) o global (en todo el programa).

- **Representación de datos y memoria:**
  - Cada tipo de dato tiene un tamaño específico en memoria. Por ejemplo, un `int` suele ocupar 4 bytes.
  - La representación en memoria afecta cómo se almacenan y manipulan los datos.

**Operadores y expresiones:**

- **Operadores aritméticos:**
  - `+` (suma), `-` (resta), `*` (multiplicación), `/` (división), `%` (módulo).
  - Ejemplo: `int suma = 5 + 3;`

- **Operadores lógicos:**
  - `&&` (AND lógico), `||` (OR lógico), `!` (NOT lógico).
  - Ejemplo: `if (a && b) { /* código */ }`

- **Operadores relacionales:**
  - `==` (igual a), `!=` (diferente de), `<` (menor que), `>` (mayor que), `<=` (menor o igual que), `>=` (mayor o igual que).
  - Ejemplo: `if (a == b) { /* código */ }`

- **Operadores bit a bit:**
  - `&` (AND bit a bit), `|` (OR bit a bit), `^` (XOR bit a bit), `~` (NOT bit a bit), `<<` (desplazamiento a la izquierda), `>>` (desplazamiento a la derecha).
  - Ejemplo: `int resultado = a & b;`

- **Precedencia y asociatividad de operadores:**
  - La precedencia determina el orden en que se evalúan los operadores en una expresión.
  - La asociatividad determina el orden en que se evalúan los operadores con la misma precedencia.
  - Ejemplo: `int resultado = 5 + 3 * 2;` (La multiplicación se evalúa antes que la suma).

- **Evaluación de expresiones complejas:**
  - Combinación de múltiples operadores para crear expresiones más complejas.
  - Ejemplo: `int resultado = (a + b) * (c - d);`

#### Ejercicios y Ejemplos Prácticos

**Función básica estilo libft:**

- **Crear funciones fundamentales:**
  - Ejemplo de `ft_strlen`:
    ```c
    size_t ft_strlen(const char *str) {
        size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }
    ```

  - Ejemplo de `ft_strcmp`:
    ```c
    int ft_strcmp(const char *s1, const char *s2) {
        while (*s1 && (*s1 == *s2)) {
            s1++;
            s2++;
        }
        return *(unsigned char *)s1 - *(unsigned char *)s2;
    }
    ```

  - Ejemplo de `ft_strdup`:
    ```c
    char *ft_strdup(const char *s) {
        char *dup = malloc(ft_strlen(s) + 1);
        if (dup) {
            strcpy(dup, s);
        }
        return dup;
    }
    ```

- **Enfocar en el manejo correcto de memoria, argumentos y retorno de valores:**
  - Asegurarse de que las funciones gestionen correctamente la memoria y los argumentos, y que devuelvan los valores esperados.

**Manipulación de cadenas:**

- **Ejercitar operaciones con cadenas:**
  - Ejemplo de concatenación de cadenas:
    ```c
    char *ft_strcat(char *dest, const char *src) {
        char *d = dest;
        while (*d) d++;
        while ((*d++ = *src++));
        return dest;
    }
    ```

  - Ejemplo de comparación de cadenas:
    ```c
int ft_strncmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    } else {
        return *(unsigned char *)s1 - *(unsigned char *)s2;
    }
}
    ```

  - Ejemplo de copia de cadenas:
    ```c
    char *ft_strcpy(char *dest, const char *src) {
        char *d = dest;
        while ((*d++ = *src++));
        return dest;
    }
    ```


### Capítulo 2: Estructuras de Control

#### Temas Teóricos

**Condicionales:**

- **Instrucciones `if`, `if-else`, y `switch`:**
  - **`if`:** Permite ejecutar un bloque de código si una condición es verdadera.
    ```c
    if (condicion) {
        // Código a ejecutar si la condición es verdadera
    }
    ```
  - **`if-else`:** Permite ejecutar un bloque de código si una condición es verdadera y otro bloque si es falsa.
    ```c
    if (condicion) {
        // Código a ejecutar si la condición es verdadera
    } else {
        // Código a ejecutar si la condición es falsa
    }
    ```
  - **`switch`:** Permite seleccionar una de varias opciones basadas en el valor de una expresión.(No la utilizaremos en el cursus de 42 Madrid)
    ```c
    switch (expresion) {
        case valor1:
            // Código a ejecutar si expresion == valor1
            break;
        case valor2:
            // Código a ejecutar si expresion == valor2
            break;
        default:
            // Código a ejecutar si ninguna de las opciones anteriores coincide
    }
    ```

- **Operador ternario y evaluación de condiciones complejas:** (No la utilizaremos en el cursus de 42 Madrid)
  - **Operador ternario (`?:`):** Permite evaluar una expresión y devolver un valor basado en una condición.
    ```c
    condicion ? valor_si_verdadero : valor_si_falso;
    ```
  - **Evaluación de condiciones complejas:** Uso de operadores lógicos para combinar múltiples condiciones.
    ```c
    if (condicion1 && (condicion2 || condicion3)) {
        // Código a ejecutar si condicion1 es verdadera y (condicion2 o condicion3) es verdadera
    }
    ```

**Bucles:**

- **Bucles `for`, `while` y `do-while`:**
  - **`for`:** Utilizado para iterar un número específico de veces. (No la utilizaremos en el cursus de 42 Madrid)
    ```c
    for (inicializacion; condicion; incremento) {
        // Código a ejecutar en cada iteración
    }
    ```
  - **`while`:** Utilizado para iterar mientras una condición sea verdadera.
    ```c
    while (condicion) {
        // Código a ejecutar mientras la condición sea verdadera
    }
    ```
  - **`do-while`:** Similar a `while`, pero garantiza que el bloque de código se ejecute al menos una vez. (No la utilizaremos en el cursus de 42 Madrid)
    ```c
    do {
        // Código a ejecutar al menos una vez
    } while (condicion);
    ```

- **Buenas prácticas para evitar bucles infinitos y optimizar iteraciones:**
  - Asegurarse de que la condición del bucle eventualmente se vuelva falsa.
  - Evitar modificaciones innecesarias dentro del bucle que puedan afectar el rendimiento.
  - Utilizar variables de control adecuadas y mantener el código dentro del bucle lo más eficiente posible.

#### Ejercicios y Ejemplos Prácticos

**Lectura de caracteres (Estilo `get_next_line`):**

- **Implementar un bucle que lea datos carácter a carácter o por bloques, gestionando correctamente el buffer y la terminación de la lectura:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  #define BUFFER_SIZE 1024

  char *get_next_line(FILE *file) {
      char *line = malloc(BUFFER_SIZE);
      if (!line) return NULL;

      int c, i = 0;
      while ((c = fgetc(file)) != EOF && c != '\n') {
          line[i++] = c;
          if (i >= BUFFER_SIZE - 1) {
              BUFFER_SIZE *= 2;
              line = realloc(line, BUFFER_SIZE);
              if (!line) return NULL;
          }
      }
      line[i] = '\0';
      return (c == EOF && i == 0) ? NULL : line;
  }

  int main() {
      FILE *file = fopen("archivo.txt", "r");
      if (!file) return 1;

      char *line;
      while ((line = get_next_line(file)) != NULL) {
          printf("%s\n", line);
          free(line);
      }

      fclose(file);
      return 0;
  }
  ```

- **Introducir el manejo de errores y la verificación de fin de archivo (EOF):**
  - Asegurarse de que el archivo se abre correctamente antes de intentar leer.
  - Verificar si se ha alcanzado el final del archivo (EOF) y manejar adecuadamente la memoria asignada.



### Capítulo 3: Funciones

#### Temas Teóricos

**Definición y declaración de funciones:**

- **Prototipos:** Un prototipo de función es una declaración de la función que especifica su nombre, tipo de retorno y parámetros, pero no su implementación. Esto permite al compilador verificar las llamadas a la función antes de que se defina completamente.
  ```c
  int suma(int a, int b); // Prototipo de función
  ```

- **Ámbito de variables (locales y globales):**
  - **Variables locales:** Definidas dentro de una función y accesibles solo dentro de esa función.
    ```c
    void funcion() {
        int local = 10; // Variable local
    }
    ```
  - **Variables globales:** Definidas fuera de cualquier función y accesibles desde cualquier parte del programa.
    ```c
    int global = 20; // Variable global
    void funcion() {
        global = 30; // Acceso a variable global
    }
    ```

- **Recursividad:** Una función es recursiva si se llama a sí misma. La recursividad puede ser útil para resolver problemas que se pueden dividir en subproblemas similares.
  ```c
  int factorial(int n) {
      if (n == 0) return 1;
      else return n * factorial(n - 1);
  }
  ```

**Conceptos de parámetros por valor y por referencia:**

- **Parámetros por valor:** Los valores de los argumentos se copian en los parámetros de la función. Los cambios en los parámetros no afectan a los argumentos originales.
  ```c
  void incrementar(int x) {
      x++;
  }
  ```

- **Parámetros por referencia:** Se pasa la dirección de los argumentos, permitiendo que los cambios en los parámetros afecten a los argumentos originales.
  ```c
  void incrementar(int *x) {
      (*x)++;
  }
  ```

**Funciones avanzadas:**

- **Uso de funciones con número variable de argumentos (variadic functions) y la biblioteca `<stdarg.h>`:**
  - Las funciones variádicas permiten pasar un número variable de argumentos. Se utilizan con la biblioteca `<stdarg.h>`.
  ```c
  #include <stdarg.h>
  void imprimir(const char *formato, ...) {
      va_list args;
      va_start(args, formato);
      while (*formato) {
          if (*formato == 'd') {
              int i = va_arg(args, int);
              printf("%d ", i);
          } else if (*formato == 'c') {
              char c = va_arg(args, int);
              printf("%c ", c);
          }
          formato++;
      }
      va_end(args);
      printf("\n");
  }
  ```

#### Ejercicios y Ejemplos Prácticos

**Función de impresión personalizada (Estilo `ft_printf`):**

- **Crear una función que imite funcionalidades básicas de `printf`, manejando formatos simples (caracteres, enteros, cadenas):**
  ```c
  #include <stdarg.h>
  #include <stdio.h>

  void ft_printf(const char *format, ...) {
      va_list args;
      va_start(args, format);
      while (*format) {
          if (*format == '%') {
              format++;
              if (*format == 'd') {
                  int i = va_arg(args, int);
                  printf("%d", i);
              } else if (*format == 'c') {
                  char c = va_arg(args, int);
                  printf("%c", c);
              } else if (*format == 's') {
                  char *s = va_arg(args, char *);
                  printf("%s", s);
              }
          } else {
              putchar(*format);
          }
          format++;
      }
      va_end(args);
  }

  int main() {
      ft_printf("Entero: %d, Caracter: %c, Cadena: %s\n", 42, 'A', "Hola Mundo");
      return 0;
  }
  ```

- **Profundizar en la conversión de tipos y formateo de salida:**
  - Asegurarse de que la función maneje correctamente la conversión de tipos y el formateo de salida para diferentes tipos de datos.
  - Implementar manejo de errores y validación de formatos.



### Capítulo 4: Punteros y Listas Anidadas

#### Temas Teóricos

**Punteros:**

- **Conceptos básicos:**
  - Un puntero es una variable que almacena la dirección de memoria de otra variable.
  - Declaración de punteros: `int *ptr;`
  - Asignación de punteros: `int a = 10; int *ptr = &a;`
  - Desreferenciación: Acceder al valor almacenado en la dirección de memoria apuntada por el puntero: `int valor = *ptr;`

- **Aritmética de punteros y relación con arrays:**
  - Los punteros pueden ser incrementados o decrementados para apuntar a diferentes posiciones de memoria.
  - Relación con arrays: El nombre de un array es un puntero al primer elemento del array.
    ```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
int i = 0;
while (i < 5) {
    printf("%d ", *(ptr + i));
    i++;
}
    ```

- **Punteros a funciones y a estructuras:**
  - Punteros a funciones permiten almacenar la dirección de una función y llamarla a través del puntero.
    ```c
    void funcion(int a) {
        printf("Valor: %d\n", a);
    }
    void (*ptr_func)(int) = funcion;
    ptr_func(10);
    ```
  - Punteros a estructuras permiten acceder a los miembros de una estructura a través del puntero.
    ```c
    struct Persona {
        char nombre[50];
        int edad;
    };
    struct Persona p = {"Juan", 30};
    struct Persona *ptr_p = &p;
    printf("Nombre: %s, Edad: %d\n", ptr_p->nombre, ptr_p->edad);
    ```

**Listas anidadas y estructuras dinámicas:**

- **Introducción a las estructuras de datos dinámicas y al manejo de memoria (`malloc`, `free`):**
  - Las estructuras de datos dinámicas permiten la creación de estructuras cuyo tamaño puede cambiar durante la ejecución del programa.
  - `malloc`: Asigna memoria dinámica.
    ```c
    int *ptr = (int *)malloc(sizeof(int) * 10);
    ```
  - `free`: Libera la memoria asignada dinámicamente.
    ```c
    free(ptr);
    ```

- **Ventajas y desafíos de trabajar con estructuras anidadas:**
  - **Ventajas:** Flexibilidad en el tamaño y estructura de los datos, eficiente uso de memoria.
  - **Desafíos:** Complejidad en la gestión de memoria, riesgo de fugas de memoria.

#### Ejercicios y Ejemplos Prácticos

**Gestión de listas mediante punteros (Inspirado en `push_swap`):**

- **Crear y manipular estructuras enlazadas simples que representen, por ejemplo, una pila o una cola:**
  ```c
  struct Nodo {
      int dato;
      struct Nodo *siguiente;
  };

  void insertar(struct Nodo **cabeza, int nuevo_dato) {
      struct Nodo *nuevo_nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
      nuevo_nodo->dato = nuevo_dato;
      nuevo_nodo->siguiente = *cabeza;
      *cabeza = nuevo_nodo;
  }

  void eliminar(struct Nodo **cabeza) {
      if (*cabeza == NULL) return;
      struct Nodo *temp = *cabeza;
      *cabeza = (*cabeza)->siguiente;
      free(temp);
  }

  void recorrer(struct Nodo *nodo) {
      while (nodo != NULL) {
          printf("%d -> ", nodo->dato);
          nodo = nodo->siguiente;
      }
      printf("NULL\n");
  }

  int main() {
      struct Nodo *cabeza = NULL;
      insertar(&cabeza, 1);
      insertar(&cabeza, 2);
      insertar(&cabeza, 3);
      recorrer(cabeza);
      eliminar(&cabeza);
      recorrer(cabeza);
      return 0;
  }
  ```

- **Ejercitar la inserción, eliminación y recorrido de nodos utilizando punteros:**
  - Implementar funciones para insertar nuevos nodos, eliminar nodos existentes y recorrer la lista para imprimir los datos.

**Representación de estructuras complejas (Estilo `so_long`):**

- **Utilizar listas anidadas para modelar mapas o niveles en un juego, mostrando la interacción entre nodos de datos y estructuras anidadas:**
  ```c
  struct Celda {
      int tipo; // 0: vacío, 1: pared, 2: jugador, etc.
      struct Celda *arriba;
      struct Celda *abajo;
      struct Celda *izquierda;
      struct Celda *derecha;
  };

  struct Celda *crear_celda(int tipo) {
      struct Celda *nueva_celda = (struct Celda *)malloc(sizeof(struct Celda));
      nueva_celda->tipo = tipo;
      nueva_celda->arriba = nueva_celda->abajo = nueva_celda->izquierda = nueva_celda->derecha = NULL;
      return nueva_celda;
  }

  void conectar_celdas(struct Celda *a, struct Celda *b, char direccion) {
      if (direccion == 'U') a->arriba = b;
      else if (direccion == 'D') a->abajo = b;
      else if (direccion == 'L') a->izquierda = b;
      else if (direccion == 'R') a->derecha = b;
  }

  int main() {
      struct Celda *celda1 = crear_celda(0);
      struct Celda *celda2 = crear_celda(1);
      conectar_celdas(celda1, celda2, 'R');
      printf("Celda1 tipo: %d, Celda2 tipo: %d\n", celda1->tipo, celda1->derecha->tipo);
      free(celda1);
      free(celda2);
      return 0;
  }
  ```


### Capítulo 5: Estructuras de Datos

#### Temas Teóricos

**Listas enlazadas:**

- **Listas simples:**
  - Una lista enlazada simple es una colección de nodos donde cada nodo contiene un dato y un puntero al siguiente nodo.
  - Ejemplo:
    ```c
    struct Nodo {
        int dato;
        struct Nodo *siguiente;
    };
    ```

- **Listas dobles:**
  - Una lista doblemente enlazada es una colección de nodos donde cada nodo contiene un dato, un puntero al siguiente nodo y un puntero al nodo anterior.
  - Ejemplo:
    ```c
    struct Nodo {
        int dato;
        struct Nodo *siguiente;
        struct Nodo *anterior;
    };
    ```

- **Listas circulares:**
  - Una lista circular es una lista enlazada donde el último nodo apunta al primer nodo, formando un círculo.
  - Ejemplo:
    ```c
    struct Nodo {
        int dato;
        struct Nodo *siguiente;
    };
    ```

- **Aplicaciones prácticas y gestión dinámica de la memoria:**
  - Las listas enlazadas se utilizan en aplicaciones donde se requiere una estructura de datos dinámica que permita inserciones y eliminaciones eficientes.
  - La gestión dinámica de la memoria es crucial para evitar fugas de memoria y asegurar que los recursos se liberen adecuadamente.

**Pilas y colas:**

- **Fundamentos de pilas (stack):**
  - Una pila es una estructura de datos LIFO (Last In, First Out) donde el último elemento en entrar es el primero en salir.
  - Operaciones básicas: `push` (insertar), `pop` (eliminar), `peek` (consultar el elemento en la cima).
  - Ejemplo:
    ```c
    struct Pila {
        int dato;
        struct Pila *siguiente;
    };
    ```

- **Fundamentos de colas (queue):**
  - Una cola es una estructura de datos FIFO (First In, First Out) donde el primer elemento en entrar es el primero en salir.
  - Operaciones básicas: `enqueue` (insertar), `dequeue` (eliminar), `front` (consultar el primer elemento).
  - Ejemplo:
    ```c
    struct Cola {
        int dato;
        struct Cola *siguiente;
    };
    ```

- **Algoritmos básicos de ordenación y resolución de problemas mediante estas estructuras:**
  - Las pilas y colas se utilizan en algoritmos de ordenación, como el ordenamiento por burbuja y el ordenamiento por selección.
  - También se utilizan en la resolución de problemas como la evaluación de expresiones y la gestión de tareas.

#### Ejercicios y Ejemplos Prácticos

**Listas enlazadas en proyectos tipo `pipex`:**

- **Implementar una lista enlazada para gestionar procesos o comandos, simulando la canalización de datos entre procesos:**
  ```c
  struct Proceso {
      char *comando;
      struct Proceso *siguiente;
  };

  void agregar_proceso(struct Proceso **cabeza, char *comando) {
      struct Proceso *nuevo_proceso = (struct Proceso *)malloc(sizeof(struct Proceso));
      nuevo_proceso->comando = strdup(comando);
      nuevo_proceso->siguiente = *cabeza;
      *cabeza = nuevo_proceso;
  }

  void eliminar_proceso(struct Proceso **cabeza) {
      if (*cabeza == NULL) return;
      struct Proceso *temp = *cabeza;
      *cabeza = (*cabeza)->siguiente;
      free(temp->comando);
      free(temp);
  }

  void recorrer_procesos(struct Proceso *proceso) {
      while (proceso != NULL) {
          printf("Comando: %s\n", proceso->comando);
          proceso = proceso->siguiente;
      }
  }

  int main() {
      struct Proceso *cabeza = NULL;
      agregar_proceso(&cabeza, "ls -l");
      agregar_proceso(&cabeza, "grep txt");
      recorrer_procesos(cabeza);
      eliminar_proceso(&cabeza);
      recorrer_procesos(cabeza);
      return 0;
  }
  ```

- **Ejercitar la inserción, eliminación y búsqueda de elementos:**
  - Implementar funciones para agregar nuevos procesos, eliminar procesos existentes y recorrer la lista para imprimir los comandos.

**Pilas y colas en problemas de ordenación (Inspirado en `push_swap`):**

- **Desarrollar un pequeño algoritmo de ordenación utilizando pilas:**
  ```c
  struct Pila {
      int dato;
      struct Pila *siguiente;
  };

  void push(struct Pila **cima, int nuevo_dato) {
      struct Pila *nuevo_nodo = (struct Pila *)malloc(sizeof(struct Pila));
      nuevo_nodo->dato = nuevo_dato;
      nuevo_nodo->siguiente = *cima;
      *cima = nuevo_nodo;
  }

  int pop(struct Pila **cima) {
      if (*cima == NULL) return -1;
      struct Pila *temp = *cima;
      int dato = temp->dato;
      *cima = (*cima)->siguiente;
      free(temp);
      return dato;
  }

  void ordenar_pila(struct Pila **cima) {
      struct Pila *pila_aux = NULL;
      while (*cima != NULL) {
          int temp = pop(cima);
          while (pila_aux != NULL && pila_aux->dato > temp) {
              push(cima, pop(&pila_aux));
          }
          push(&pila_aux, temp);
      }
      *cima = pila_aux;
  }

  void imprimir_pila(struct Pila *cima) {
      while (cima != NULL) {
          printf("%d ", cima->dato);
          cima = cima->siguiente;
      }
      printf("\n");
  }

  int main() {
      struct Pila *cima = NULL;
      push(&cima, 3);
      push(&cima, 1);
      push(&cima, 4);
      push(&cima, 2);
      imprimir_pila(cima);
      ordenar_pila(&cima);
      imprimir_pila(cima);
      return 0;
  }
  ```

- **Comparar eficiencia y explorar casos de uso de cada estructura:**
  - Analizar la eficiencia del algoritmo de ordenación utilizando pilas.
  - Explorar casos de uso donde las pilas y colas son más adecuadas, como la gestión de tareas y la evaluación de expresiones.


### Capítulo 6: Programación Concurrente

#### Temas Teóricos

**Hilos (threads) en C:**

- **Introducción a la programación multihilo con la biblioteca POSIX (pthread):**
  - La programación multihilo permite ejecutar múltiples hilos de ejecución en paralelo, mejorando la eficiencia y el rendimiento de las aplicaciones.
  - La biblioteca POSIX `pthread` proporciona funciones para crear y gestionar hilos en C.
  - Ejemplo de inclusión de la biblioteca:
    ```c
    #include <pthread.h>
    ```

- **Creación, ejecución y sincronización de hilos:**
  - **Creación de hilos:** Utilizar `pthread_create` para crear nuevos hilos.
    ```c
    void *funcion_hilo(void *arg) {
        printf("Hola desde el hilo\n");
        return NULL;
    }

    int main() {
        pthread_t hilo;
        pthread_create(&hilo, NULL, funcion_hilo, NULL);
        pthread_join(hilo, NULL);
        return 0;
    }
    ```
  - **Ejecución de hilos:** Los hilos ejecutan la función especificada en `pthread_create`.
  - **Sincronización de hilos:** Utilizar `pthread_join` para esperar a que un hilo termine su ejecución.

**Sincronización y comunicación:**

- **Uso de mutex, semáforos y variables de condición para evitar condiciones de carrera:**
  - **Mutex:** Utilizado para asegurar que solo un hilo acceda a una sección crítica del código a la vez.
    ```c
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    void *funcion_hilo(void *arg) {
        pthread_mutex_lock(&mutex);
        // Sección crítica
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    ```
  - **Semáforos:** Utilizados para controlar el acceso a recursos compartidos.
    ```c
    #include <semaphore.h>
    sem_t semaforo;
    sem_init(&semaforo, 0, 1);

    void *funcion_hilo(void *arg) {
        sem_wait(&semaforo);
        // Sección crítica
        sem_post(&semaforo);
        return NULL;
    }
    ```
  - **Variables de condición:** Utilizadas para permitir que los hilos esperen a que ocurra una condición específica.
    ```c
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    void *funcion_hilo(void *arg) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        // Sección crítica
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    ```

- **Manejo de recursos compartidos y prevención de deadlocks:**
  - **Recursos compartidos:** Asegurarse de que los hilos accedan a los recursos compartidos de manera segura utilizando mecanismos de sincronización.
  - **Prevención de deadlocks:** Evitar situaciones donde dos o más hilos se bloquean mutuamente esperando recursos.

#### Ejercicios y Ejemplos Prácticos

**Simulación del problema de los filósofos (Estilo `philosophers`):**

- **Implementar una versión simplificada del problema de los filósofos comiendo:**
  - El problema de los filósofos comiendo es un clásico problema de sincronización que ilustra la gestión de recursos compartidos y la prevención de deadlocks.
  - Ejemplo:
    ```c
    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define NUM_FILOSOFOS 5

    pthread_mutex_t tenedores[NUM_FILOSOFOS];

    void *filosofo(void *num) {
        int id = *(int *)num;
        int izquierda = id;
        int derecha = (id + 1) % NUM_FILOSOFOS;

        while (1) {
            printf("Filósofo %d está pensando\n", id);
            sleep(rand() % 3 + 1);

            pthread_mutex_lock(&tenedores[izquierda]);
            pthread_mutex_lock(&tenedores[derecha]);

            printf("Filósofo %d está comiendo\n", id);
            sleep(rand() % 3 + 1);

            pthread_mutex_unlock(&tenedores[derecha]);
            pthread_mutex_unlock(&tenedores[izquierda]);
        }
        return NULL;
    }

int main() {
    pthread_t hilos[NUM_FILOSOFOS];
    int ids[NUM_FILOSOFOS];
    int i = 0;

    while (i < NUM_FILOSOFOS) {
        pthread_mutex_init(&tenedores[i], NULL);
        ids[i] = i;
        pthread_create(&hilos[i], NULL, filosofo, &ids[i]);
        i++;
    }

    i = 0;
    while (i < NUM_FILOSOFOS) {
        pthread_join(hilos[i], NULL);
        i++;
    }

    i = 0;
    while (i < NUM_FILOSOFOS) {
        pthread_mutex_destroy(&tenedores[i]);
        i++;
    }

    return 0;
}
    ```

- **Enfatizar la sincronización de hilos y la gestión correcta de recursos compartidos para evitar bloqueos:**
  - Asegurarse de que los filósofos adquieran y liberen los tenedores de manera segura utilizando mutex.
  - Implementar mecanismos para evitar deadlocks, como la adquisición de recursos en un orden específico.


### Capítulo 7: Programación de Sistemas

#### Temas Teóricos

**Interacción con el sistema operativo:**

- **Llamadas al sistema (system calls) para la gestión de archivos, procesos y señales:**
  - Las llamadas al sistema son funciones proporcionadas por el sistema operativo que permiten a los programas interactuar con el hardware y otros recursos del sistema.
  - **Gestión de archivos:** `open`, `read`, `write`, `close`.
    ```c
    int fd = open("archivo.txt", O_RDONLY);
    char buffer[100];
    read(fd, buffer, 100);
    close(fd);
    ```
  - **Gestión de procesos:** `fork`, `exec`, `wait`.
    ```c
    pid_t pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", NULL);
    } else {
        wait(NULL);
    }
    ```
  - **Gestión de señales:** `signal`, `kill`.
    ```c
    void manejador(int signo) {
        printf("Señal recibida: %d\n", signo);
    }
    signal(SIGINT, manejador);
    kill(getpid(), SIGINT);
    ```

- **Gestión de entrada/salida (I/O) y redirección de flujos:**
  - **Entrada/salida estándar:** `stdin`, `stdout`, `stderr`.
    ```c
    printf("Salida estándar\n");
    fprintf(stderr, "Error estándar\n");
    ```
  - **Redirección de flujos:** Utilizar `dup2` para redirigir la entrada/salida.
    ```c
    int fd = open("salida.txt", O_WRONLY | O_CREAT, 0644);
    dup2(fd, STDOUT_FILENO);
    printf("Esto se escribe en salida.txt\n");
    close(fd);
    ```

**Procesos y señales:**

- **Creación y manejo de procesos con `fork`, `exec` y `wait`:**
  - **`fork`:** Crea un nuevo proceso duplicando el proceso actual.
    ```c
    pid_t pid = fork();
    if (pid == 0) {
        printf("Proceso hijo\n");
    } else {
        printf("Proceso padre\n");
    }
    ```
  - **`exec`:** Reemplaza el proceso actual con un nuevo programa.
    ```c
    execlp("ls", "ls", NULL);
    ```
  - **`wait`:** Espera a que un proceso hijo termine.
    ```c
    wait(NULL);
    ```

- **Captura y gestión de señales para una comunicación eficaz entre procesos:**
  - **Captura de señales:** Utilizar `signal` para definir manejadores de señales.
    ```c
    void manejador(int signo) {
        printf("Señal recibida: %d\n", signo);
    }
    signal(SIGINT, manejador);
    ```
  - **Envío de señales:** Utilizar `kill` para enviar señales a procesos.
    ```c
    kill(getpid(), SIGINT);
    ```

#### Ejercicios y Ejemplos Prácticos

**Implementación de un shell básico (Estilo `minishell`):**

- **Desarrollar un intérprete de comandos que acepte órdenes básicas, gestione redirecciones y ejecute procesos:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <fcntl.h>

  void ejecutar_comando(char **args) {
      pid_t pid = fork();
      if (pid == 0) {
          execvp(args[0], args);
          perror("execvp");
          exit(EXIT_FAILURE);
      } else if (pid > 0) {
          wait(NULL);
      } else {
          perror("fork");
      }
  }

  void redireccionar(char *archivo, int modo) {
      int fd = open(archivo, modo, 0644);
      if (fd == -1) {
          perror("open");
          exit(EXIT_FAILURE);
      }
      dup2(fd, modo == O_RDONLY ? STDIN_FILENO : STDOUT_FILENO);
      close(fd);
  }

  int main() {
      char linea[1024];
      char *args[64];
      while (1) {
          printf("minishell> ");
          if (!fgets(linea, sizeof(linea), stdin)) break;
          linea[strcspn(linea, "\n")] = '\0';
          int i = 0;
          args[i] = strtok(linea, " ");
          while (args[i] != NULL) {
              i++;
              args[i] = strtok(NULL, " ");
          }
          if (args[0] == NULL) continue;
          if (strcmp(args[0], "exit") == 0) break;
          if (strcmp(args[0], ">") == 0) {
              redireccionar(args[1], O_WRONLY | O_CREAT | O_TRUNC);
              args[0] = args[2];
              args[1] = NULL;
          }
          ejecutar_comando(args);
      }
      return 0;
  }
  ```

- **Integrar el manejo de errores y la interpretación de variables de entorno:**
  - Asegurarse de que el shell maneje correctamente los errores de ejecución y redirección.
  - Implementar la interpretación de variables de entorno utilizando `getenv`.
    ```c
    char *path = getenv("PATH");
    printf("PATH: %s\n", path);
    ```


### Capítulo 8: Proyecto Minishell 42

#### Objetivos

- **Integrar y aplicar todos los conceptos aprendidos en el curso:**
  - Utilizar estructuras de datos, funciones, manejo de memoria, concurrencia y comunicación con el sistema operativo.
  - Desarrollar una aplicación completa que demuestre el dominio de estos conceptos.

- **Desarrollar una aplicación completa que combine:**
  - **Estructuras de datos:** Implementar listas enlazadas, pilas y colas para gestionar diferentes componentes de la aplicación.
  - **Funciones:** Crear funciones modulares y reutilizables para diferentes tareas.
  - **Manejo de memoria:** Asegurar una gestión eficiente y segura de la memoria dinámica.
  - **Concurrencia:** Utilizar hilos y mecanismos de sincronización para mejorar el rendimiento.
  - **Comunicación con el sistema operativo:** Utilizar llamadas al sistema para interactuar con el sistema operativo.

#### Propuesta de Proyecto

**Aplicación multifuncional:**

- **Desarrollar un mini-sistema de gestión de tareas o un intérprete de comandos extendido:**
  - **Mini-sistema de gestión de tareas:** Crear una aplicación que permita agregar, eliminar y listar tareas, con funcionalidades adicionales como la asignación de prioridades y fechas límite.
  - **Intérprete de comandos extendido:** Ampliar el shell básico desarrollado en el Capítulo 7 para incluir funcionalidades avanzadas como la gestión de variables de entorno, redirección de entrada/salida, y ejecución concurrente de comandos.

- **Incluir módulos para:**
  - **Procesamiento de entradas:** Implementar funciones para leer y parsear comandos o tareas desde la entrada del usuario.
  - **Ejecución de comandos:** Utilizar `fork`, `exec` y `wait` para ejecutar comandos del sistema.
  - **Manejo de estructuras dinámicas:** Utilizar listas enlazadas, pilas y colas para gestionar tareas o comandos.
  - **Funcionalidades concurrentes (opcional):** Utilizar hilos y mecanismos de sincronización para ejecutar tareas o comandos en paralelo.

#### Ejemplo de Proyecto Final

**Mini-sistema de gestión de tareas:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct Tarea {
    char descripcion[256];
    int prioridad;
    struct Tarea *siguiente;
};

struct Tarea *cabeza = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void agregar_tarea(char *descripcion, int prioridad) {
    pthread_mutex_lock(&mutex);
    struct Tarea *nueva_tarea = (struct Tarea *)malloc(sizeof(struct Tarea));
    strcpy(nueva_tarea->descripcion, descripcion);
    nueva_tarea->prioridad = prioridad;
    nueva_tarea->siguiente = cabeza;
    cabeza = nueva_tarea;
    pthread_mutex_unlock(&mutex);
}

void eliminar_tarea() {
    pthread_mutex_lock(&mutex);
    if (cabeza == NULL) {
        printf("No hay tareas para eliminar\n");
    } else {
        struct Tarea *temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    pthread_mutex_unlock(&mutex);
}

void listar_tareas() {
    pthread_mutex_lock(&mutex);
    struct Tarea *temp = cabeza;
    while (temp != NULL) {
        printf("Tarea: %s, Prioridad: %d\n", temp->descripcion, temp->prioridad);
        temp = temp->siguiente;
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    agregar_tarea("Estudiar C", 1);
    agregar_tarea("Hacer ejercicio", 2);
    listar_tareas();
    eliminar_tarea();
    listar_tareas();
    return 0;
}
```

**Intérprete de comandos extendido:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pthread.h>

void ejecutar_comando(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork");
    }
}

void redireccionar(char *archivo, int modo) {
    int fd = open(archivo, modo, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd, modo == O_RDONLY ? STDIN_FILENO : STDOUT_FILENO);
    close(fd);
}

int main() {
    char linea[1024];
    char *args[64];
    while (1) {
        printf("minishell> ");
        if (!fgets(linea, sizeof(linea), stdin)) break;
        linea[strcspn(linea, "\n")] = '\0';
        int i = 0;
        args[i] = strtok(linea, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        if (args[0] == NULL) continue;
        if (strcmp(args[0], "exit") == 0) break;
        if (strcmp(args[0], ">") == 0) {
            redireccionar(args[1], O_WRONLY | O_CREAT | O_TRUNC);
            args[0] = args[2];
            args[1] = NULL;
        }
        ejecutar_comando(args);
    }
    return 0;
}
```

El proyecto final servirá como una síntesis de las habilidades adquiridas, similar a la integración de múltiples herramientas vistas en los proyectos de 42 Madrid.

