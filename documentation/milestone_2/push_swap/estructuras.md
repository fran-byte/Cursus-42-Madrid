### 1. **Definición Básica de una Estructura en C**

Una estructura en C es un tipo de datos compuesto que permite agrupar diferentes tipos de datos bajo un mismo nombre. A diferencia de los tipos de datos básicos (como int, char, float), una estructura puede contener miembros de distintos tipos. Esto es útil cuando queremos representar objetos o entidades que tienen varias características, como un estudiante que tiene un nombre, edad y calificación.

En el siguiente ejemplo estamos definiendo una estructura llamada Student que tiene tres miembros: un nombre, una edad y una calificación. Cada miembro puede ser de un tipo de datos diferente.

[Video sobre estructuras en C](https://www.youtube.com/watch?v=gW42twUueUE)
 
Una **estructura** en C agrupa diferentes tipos de datos bajo un mismo nombre.

Ejemplo:

```c
struct Student {     
    char name[50];  //
    int age;        //   Propiedades
    float grade;    //
};
```

### 2. **Usando `typedef` para simplificar la declaración**

`typedef` es una palabra clave que se utiliza para crear un alias o un nombre más corto para un tipo de dato.  `typedef` te permite evitar escribir `struct` cada vez que declares una variable de tipo estructura.


```c
Student student1;
```

### 3. **Ejemplo con `typedef`**

```c
#include <stdio.h>

// Definición de la estructura con typedef
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

int main() {
    Student student1;  // Usamos el alias "Student" directamente

    // Asignar valores
    student1.age = 20;
    student1.grade = 8.5;
    snprintf(student1.name, sizeof(student1.name), "Juan Pérez");

    // Imprimir los valores
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Grade: %.2f\n", student1.grade);

    return 0;
}
```

Ahora, puedes declarar una variable de tipo `Student` sin usar `struct`:


### 4. **Estructura y Punteros**

Cuando usas punteros, puedes crear una estructura dinámicamente en memoria y acceder a sus miembros mediante el operador **`->`**, en lugar de usar el operador de punto (**`.`**) como lo harías con una variable directa.

### 2. **Declaración y asignación con punteros**

Para usar punteros con estructuras, debes seguir estos pasos:

1. Declarar un puntero a la estructura.
2. Usar la función `malloc()` (o cualquier otro método para asignar memoria dinámica) para asignar espacio para la estructura.
3. Acceder a los miembros de la estructura usando el operador **`->`**.

### 5. **Ejemplo con punteros y asignación dinámica**

Supongamos que tenemos la misma estructura `Student` con un puntero para manipular sus datos dinámicamente.

#### Sin punteros:

```c
Student student1;
student1.age = 20;
student1.grade = 8.5;
```

#### Con punteros:

```c
#include <stdio.h>
#include <stdlib.h>  // Necesario para usar malloc
#include <string.h>  // Necesario para usar strncpy

// Definición de la estructura con typedef
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

int main() {
    // Declarar un puntero a una estructura Student
    Student *student1 = (Student *)malloc(sizeof(Student));

    // Verificar si malloc no falla
    if (student1 == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;  // Salir del programa si no hay memoria disponible
    }

    // Asignar valores directamente usando el puntero y el operador "->"
    student1->age = 20;
    student1->grade = 8.5;

    // Usamos strncpy para asignar el nombre de forma segura
    // Copiar hasta 49 caracteres (1 espacio para '\0' al final)
    strncpy(student1->name, "Juan Pérez", sizeof(student1->name) - 1);

    // Asegurar que la cadena esté terminada en '\0'
    student1->name[sizeof(student1->name) - 1] = '\0';

    // Imprimir los valores usando el puntero
    printf("Name: %s\n", student1->name);
    printf("Age: %d\n", student1->age);
    printf("Grade: %.2f\n", student1->grade);

    // Liberar la memoria al final
    free(student1);

    return 0;
}

```

### 6. **Explicación del código con punteros**

- **`Student *student1`**: Creamos un puntero a una estructura de tipo `Student`.
- **`malloc(sizeof(Student))`**: Usamos `malloc` para asignar memoria dinámica para la estructura `Student`. El tamaño de la memoria asignada es el tamaño de la estructura.
- **`student1->age = 20;`**: Usamos el operador `->` para acceder y asignar valores a los miembros de la estructura a través del puntero.
- **`free(student1);`**: Es importante liberar la memoria que hemos asignado con `malloc` cuando ya no la necesitamos, usando `free()`.

### 7. **Ventajas de usar punteros**

- **Eficiencia**: Usar punteros permite manipular estructuras de forma más eficiente, ya que puedes pasar punteros a funciones en lugar de pasar grandes cantidades de datos (copias de estructuras).
- **Memoria dinámica**: Puedes asignar memoria dinámica para estructuras, lo que es útil si no sabes cuántas estructuras necesitarás durante la ejecución del programa (por ejemplo, en estructuras de datos dinámicas como listas enlazadas, pilas, colas, etc.).

### 8. **Explicación sobre estructuras anidadas**

En C, **estructuras anidadas** son estructuras que contienen otras estructuras dentro de ellas. Es decir, puedes definir una estructura dentro de otra estructura como un campo. Este tipo de estructuras se usa comúnmente para modelar objetos más complejos, donde cada campo de la estructura principal puede representar una subestructura con su propia definición de campos.

#### **Sintaxis de estructuras anidadas**
En una estructura anidada, se puede declarar un tipo de estructura dentro de otra de la siguiente manera:

```c
struct Outer {
    int x;
    struct Inner {
        int y;
        int z;
    } inner;  // Definición de la estructura interna como un campo de la estructura externa
};
```

En este caso:
- `Outer` es la estructura principal.
- `Inner` es la estructura anidada dentro de `Outer`.
- Puedes acceder a los campos de la estructura anidada usando el operador de acceso a miembros (`.` o `->`).

### 8.1. **Modificación del código para añadir una estructura anidada (`address`)**

Modidicamos el código anterior y añadimos una estructura anidada que representa una **dirección** (`address`), que puede tener campos como `street`, `city`, `zipCode`, etc. Esta estructura estará anidada dentro de la estructura `Student`.

### **Código modificado con la estructura anidada `address`:**

```c
#include <stdio.h>
#include <stdlib.h>  // Necesario para usar malloc
#include <string.h>  // Necesario para usar strncpy

// Definición de la estructura Address (anidada dentro de Student)
typedef struct {
    char street[100];
    char city[50];
    int zipCode;
} Address;

// Definición de la estructura Student con la estructura Address anidada
typedef struct {
    char name[50];
    int age;
    float grade;
    Address address;  // Dirección anidada dentro de Student
} Student;

int main() {
    // Declarar un puntero a una estructura Student
    Student *student1 = (Student *)malloc(sizeof(Student));

    // Verificar si malloc no falla
    if (student1 == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;  // Salir del programa si no hay memoria disponible
    }

    // Asignar valores directamente usando el puntero y el operador "->"
    student1->age = 20;
    student1->grade = 8.5;

    // Usamos strncpy para asignar el nombre de forma segura
    strncpy(student1->name, "Juan Pérez", sizeof(student1->name) - 1);
    student1->name[sizeof(student1->name) - 1] = '\0';  // Asegurarse que la cadena termine en '\0'

    // Asignar valores a la dirección utilizando la estructura anidada Address
    strncpy(student1->address.street, "Calle Ficticia 123", sizeof(student1->address.street) - 1);
    student1->address.street[sizeof(student1->address.street) - 1] = '\0';  // Asegurarse de que termine en '\0'

    strncpy(student1->address.city, "Ciudad Imaginaria", sizeof(student1->address.city) - 1);
    student1->address.city[sizeof(student1->address.city) - 1] = '\0';  // Asegurarse de que termine en '\0'

    student1->address.zipCode = 12345;

    // Imprimir los valores usando el puntero
    printf("Name: %s\n", student1->name);
    printf("Age: %d\n", student1->age);
    printf("Grade: %.2f\n", student1->grade);

    // Imprimir la dirección usando la estructura anidada
    printf("Address:\n");
    printf("Street: %s\n", student1->address.street);
    printf("City: %s\n", student1->address.city);
    printf("Zip Code: %d\n", student1->address.zipCode);

    // Liberar la memoria al final
    free(student1);

    return 0;
}
```

### **Explicación del código modificado:**

1. **Estructura `Address`:**
   - Se ha creado una estructura adicional llamada `Address` que contiene tres campos:
     - `street`: un arreglo de caracteres para almacenar la calle.
     - `city`: un arreglo de caracteres para almacenar la ciudad.
     - `zipCode`: un entero para almacenar el código postal.
   
2. **Estructura `Student` modificada:**
   - Dentro de la estructura `Student`, se ha añadido un campo de tipo `Address` llamado `address`. Esto hace que cada estudiante tenga una dirección asociada a su registro, lo que hace que la estructura `Student` contenga otra estructura dentro de ella.
   
3. **Asignación de valores a la dirección:**
   - Al igual que antes, se utiliza **`strncpy()`** para asignar valores a los campos `street` y `city` de la estructura `address` de forma segura.
   - El valor de `zipCode` se asigna directamente, ya que es un campo entero.

4. **Impresión de los valores:**
   - Al final del programa, además de imprimir el nombre, la edad y la calificación del estudiante, también imprimimos los valores de la dirección usando `student1->address.street`, `student1->address.city` y `student1->address.zipCode`.

### **Acceso a miembros de una estructura anidada:**

- Para acceder a los campos de la estructura anidada, usamos el operador **`->`** cuando estamos trabajando con punteros (como en este caso). 
- En el caso de la dirección, se accede mediante **`student1->address.street`**, **`student1->address.city`** y **`student1->address.zipCode`**.

### **Salida esperada:**

Cuando ejecutes el programa, debería imprimir algo similar a esto:

```
Name: Juan Pérez
Age: 20
Grade: 8.50
Address:
Street: Calle Ficticia 123
City: Ciudad Imaginaria
Zip Code: 12345
```

### **Resumen:**

- Las **estructuras anidadas** te permiten incluir una estructura dentro de otra para modelar datos más complejos.
- En el ejemplo, la estructura `Student` contiene una estructura `Address`, lo que permite almacenar información de la dirección del estudiante junto con su nombre, edad y calificación.
- Usamos **`strncpy()`** para manejar las cadenas de texto de forma segura y evitar desbordamientos de búfer.

Si tienes más preguntas o necesitas más detalles, ¡no dudes en preguntar!


