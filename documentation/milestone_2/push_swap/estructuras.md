### 1. **Definición Básica de una Estructura en C**

Una **estructura** en C agrupa diferentes tipos de datos bajo un mismo nombre.

Ejemplo:

```c
struct Student {
    char name[50];
    int age;
    float grade;
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
    grade calificacion;
} Student;

int main() {
    Student student1;  // Usamos el alias "Student" directamente

    // Asignar valores
    student1.age = 20;
    student1.grade = 8.5;
    snprintf(student1.name, sizeof(student1.name), "Juan Pérez");

    // Imprimir los valores
    printf("Nombre: %s\n", student1.name);
    printf("Edad: %d\n", student1.age);
    printf("Calificación: %.2f\n", student1.grade);

    return 0;
}
```

Ahora, puedes declarar una variable de tipo `Student` sin usar `struct`:
