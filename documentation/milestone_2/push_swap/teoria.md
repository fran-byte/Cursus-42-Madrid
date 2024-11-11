
### **¿Qué es la Teoría de Complejidad Algorítmica?**

La teoría de complejidad algorítmica evalúa cuántos **recursos** (tiempo y espacio de memoria) consume un algoritmo en función del tamaño de la entrada (n). Esto es vital porque un algoritmo que funciona rápido para pocas entradas puede volverse ineficiente o incluso inviable con datos grandes.

### **Big O Notation (Notación Big O)**

La **notación Big O** describe el comportamiento del tiempo de ejecución o el uso de memoria de un algoritmo en función de la entrada. Nos da una medida de cómo crece el tiempo de ejecución o el espacio requerido cuando aumenta el tamaño del problema.

- **O(f(n))** significa que el tiempo de ejecución o espacio de un algoritmo crecerá a lo sumo a un ritmo de **f(n)** para entradas grandes.
- Ignora constantes y términos menores, lo cual nos permite centrarnos en el crecimiento de la complejidad en función del tamaño de la entrada.

### **Por qué es Importante la Complejidad Algorítmica**

Elegir el algoritmo adecuado con una complejidad baja es crucial para:
- **Asegurar eficiencia** en términos de tiempo de ejecución y espacio.
- **Reducir costos computacionales** y hacer que el código sea escalable.
- **Evitar algoritmos innecesariamente lentos** o que consuman mucha memoria.

### **Análisis de Complejidad Temporal y Espacial**

1. **Complejidad Temporal**: Analiza cuánto tiempo toma un algoritmo para ejecutarse en función del tamaño de la entrada.
2. **Complejidad Espacial**: Evalúa cuánta memoria consume el algoritmo mientras se ejecuta.

---

## **Clases de Complejidad Común en Algoritmos**

### **1. O(1): Complejidad Constante**

- **Descripción**: La ejecución no depende del tamaño de la entrada; el algoritmo siempre tarda lo mismo.
- **Ejemplos**: Acceder a un elemento en un array por índice o comprobar si un número es par o impar.
- **Ventaja**: Muy rápida, ideal para operaciones básicas.
- **Ejemplo de código**:

```c
int obtener_primero(int *array) {
    return array[0]; // Tiempo constante
}
```

### **2. O(log n): Complejidad Logarítmica**

- **Descripción**: La complejidad logarítmica ocurre cuando el tiempo de ejecución aumenta lentamente, incluso si el tamaño de la entrada crece rápido. Normalmente se presenta en algoritmos que dividen el problema a la mitad en cada paso.
- **Ejemplos**: Búsqueda binaria en un array ordenado.
- **Ventaja**: Muy eficiente en problemas grandes.
- **Ejemplo de código**:

```c
int busqueda_binaria(int *array, int n, int target) {
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        if (array[medio] == target)
            return medio;
        else if (array[medio] < target)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}
```

### **3. O(n): Complejidad Lineal**

- **Descripción**: El tiempo de ejecución crece linealmente con el tamaño de la entrada. Si duplicamos el tamaño de la entrada, el tiempo de ejecución también se duplica.
- **Ejemplos**: Recorrer un array o una lista, o realizar una búsqueda lineal.
- **Ventaja**: Razonablemente rápido; útil cuando necesitas evaluar cada elemento una sola vez.
- **Ejemplo de código**:

```c
int buscar_elemento(int *array, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (array[i] == target)
            return i;
    }
    return -1;
}
```

### **4. O(n log n): Complejidad Logarítmica Lineal**

- **Descripción**: Común en algoritmos de ordenación eficientes. Aquí, el algoritmo realiza un número de operaciones proporcional a **n** (por ejemplo, recorriendo cada elemento) y en cada recorrido también realiza una operación de complejidad **log n**.
- **Ejemplos**: Algoritmos de ordenación como mergesort y heapsort.
- **Ventaja**: Eficiente para ordenaciones y combinaciones.
- **Ejemplo de código** (ordenación merge):

```c
void merge(int *array, int izquierda, int media, int derecha) {
    // Fusionar las sublistas ordenadas (proceso que tarda O(n))
}

void mergesort(int *array, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int media = (izquierda + derecha) / 2;
        mergesort(array, izquierda, media);
        mergesort(array, media + 1, derecha);
        merge(array, izquierda, media, derecha); // Combina las dos mitades
    }
}
```

### **5. O(n²): Complejidad Cuadrática**

- **Descripción**: La complejidad cuadrática ocurre cuando el tiempo de ejecución es proporcional al cuadrado del tamaño de la entrada. Común en algoritmos donde tienes bucles anidados.
- **Ejemplos**: Ordenación burbuja, ordenación por inserción.
- **Desventaja**: Ineficiente para tamaños de entrada grandes.
- **Ejemplo de código**:

```c
void ordenacion_burbuja(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
```

### **Resumen de Complejidades Comunes**

| Notación Big O | Nombre       | Ejemplo de Algoritmo                | Rendimiento              |
|----------------|--------------|-------------------------------------|--------------------------|
| O(1)           | Constante    | Acceso a un índice en array         | Excelente                |
| O(log n)       | Logarítmica  | Búsqueda binaria                    | Muy bueno                |
| O(n)           | Lineal       | Recorrido de array                  | Razonable                |
| O(n log n)     | Logarítmica Lineal | Ordenación por mergesort          | Aceptable para ordenar   |
| O(n²)          | Cuadrática   | Ordenación burbuja                  | Pobre para grandes datos |

---

## **Cómo Aplicar la Teoría de Complejidad en Algoritmos**

1. **Identifica las operaciones dominantes**: Busca los bucles y las recursiones, ya que a menudo dictan la complejidad.
2. **Simplifica la expresión**: Omite términos constantes y menores. En un algoritmo con operaciones **O(n + n log n)**, el término **n log n** dominará para entradas grandes.
3. **Evalúa eficiencia**: Piensa en qué pasará si aumentas el tamaño de la entrada (n). Para proyectos que involucran grandes volúmenes de datos, selecciona algoritmos con complejidades **O(n log n)** o mejores.

---

### **Consejos Prácticos para el Proyecto**

Para este proyecto en particular, es probable que necesites **optimizar los movimientos de tus pilas** y analizar cómo reducir la cantidad de operaciones. Algunos consejos útiles incluyen:

- **Minimiza los bucles anidados** para evitar complejidades como O(n²).
- **Considera algoritmos de ordenación eficientes** si necesitas ordenar los elementos, usando complejidades cercanas a O(n log n).
- **Usa el análisis de casos peor, medio y mejor**: Algunas operaciones pueden ser optimizadas para casos específicos.

Con esta comprensión de la complejidad algorítmica, estarás bien posicionado para evaluar y mejorar el rendimiento de tus algoritmos en cualquier proyecto que desarrolles.
