
### **¿Qué es el Ordenamiento?**

El **ordenamiento** es el proceso de reorganizar una colección de datos en un cierto orden, típicamente ascendente o descendente. Es una tarea fundamental en programación porque facilita el acceso y análisis de datos.

Elige el algoritmo de ordenamiento adecuado según:
- **La cantidad de datos**.
- **La complejidad temporal** (velocidad).
- **La complejidad espacial** (memoria).
- **La estabilidad**: Si el algoritmo mantiene el orden de elementos iguales.

### **Clasificación de los Algoritmos de Ordenamiento**

1. **Ordenamiento Basado en Comparación**: Ordena elementos comparándolos entre sí (ej. mergesort, quicksort).
2. **Ordenamiento no Basado en Comparación**: No usa comparaciones directas; adecuado para ciertos tipos de datos (ej. counting sort, radix sort).

---

## **Principales Algoritmos de Ordenamiento**

### **1. Ordenamiento Burbuja (Bubble Sort)**

**Descripción**: Compara elementos adyacentes y los intercambia si están en el orden incorrecto. Repite el proceso hasta que el arreglo esté ordenado.

- **Complejidad Temporal**: O(n²) en el peor y promedio de los casos.
- **Complejidad Espacial**: O(1) (in-place).
- **Estabilidad**: Sí.
- **Uso Ideal**: Solo para datasets muy pequeños o cuando la simplicidad es crucial.

**Ejemplo de código**:

```c
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

---

### **2. Ordenamiento por Inserción (Insertion Sort)**

**Descripción**: Construye el arreglo ordenado de izquierda a derecha, insertando cada elemento en su posición correcta dentro de la porción ya ordenada.

- **Complejidad Temporal**: O(n²) en el peor caso, O(n) en el mejor caso (casi ordenado).
- **Complejidad Espacial**: O(1).
- **Estabilidad**: Sí.
- **Uso Ideal**: Útil para listas pequeñas o casi ordenadas.

**Ejemplo de código**:

```c
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

---

### **3. Ordenamiento por Selección (Selection Sort)**

**Descripción**: Encuentra el mínimo elemento en la parte no ordenada y lo coloca en la posición correspondiente.

- **Complejidad Temporal**: O(n²).
- **Complejidad Espacial**: O(1).
- **Estabilidad**: No.
- **Uso Ideal**: Cuando el espacio de memoria es limitado y el dataset es pequeño.

**Ejemplo de código**:

```c
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

---

### **4. Ordenamiento por Mezcla (Merge Sort)**

**Descripción**: Divide recursivamente el arreglo en mitades, ordena cada mitad y las combina.

- **Complejidad Temporal**: O(n log n) en todos los casos.
- **Complejidad Espacial**: O(n) debido a la memoria adicional requerida para la mezcla.
- **Estabilidad**: Sí.
- **Uso Ideal**: Para listas grandes donde se necesita estabilidad y una complejidad predecible.

**Ejemplo de código**:

```c
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

---

### **5. Ordenamiento Rápido (Quick Sort)**

**Descripción**: Selecciona un **pivote** y particiona el arreglo en elementos menores y mayores al pivote. Luego ordena cada partición recursivamente.

- **Complejidad Temporal**: O(n log n) promedio, O(n²) en el peor caso.
- **Complejidad Espacial**: O(log n) debido a la recursión.
- **Estabilidad**: No.
- **Uso Ideal**: Para listas grandes en las que el espacio adicional es limitado y el peor caso se puede evitar.

**Ejemplo de código**:

```c
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
```

---

### **Comparación de Algoritmos de Ordenamiento**

| Algoritmo         | Complejidad Promedio | Complejidad Peor Caso | Complejidad Espacial | Estabilidad |
|-------------------|----------------------|-----------------------|-----------------------|-------------|
| Bubble Sort       | O(n²)                | O(n²)                 | O(1)                  | Sí          |
| Insertion Sort    | O(n²)                | O(n²)                 | O(1)                  | Sí          |
| Selection Sort    | O(n²)                | O(n²)                 | O(1)                  | No          |
| Merge Sort        | O(n log n)           | O(n log n)            | O(n)                  | Sí          |
| Quick Sort        | O(n log n)           | O(n²)                 | O(log n)              | No          |

---

### **Cómo Elegir el Algoritmo de Ordenamiento Correcto**

1. **Datos Pequeños**: Para arreglos pequeños (menos de 20-30 elementos), algoritmos simples como **insertion sort** o **bubble sort** pueden ser efectivos.
2. **Datos Grandes**: Para grandes volúmenes de datos, se prefiere **quick sort** o **merge sort**.
3. **Estabilidad**: Si necesitas mantener el orden relativo de elementos iguales, usa **merge sort** o **insertion sort**.
4. **Memoria Limitada**: Para restricciones de espacio, **quick sort** es preferible ya que es in-place.
5. **Ordenamiento Completo vs. Parcial**: Si solo necesitas el mayor o menor, algunos algoritmos optimizados (como el **selection sort** parcial) pueden ser más eficientes.

---

### **Consejos para Implementación en Proyectos**

- **Conoce los datos que ordenas**: Tamaño, si son en su mayoría ordenados o al azar, si hay duplicados.
- **Evita lo cuadrático**: Complejidades como O(n²) no escalan bien; en su lugar, intenta usar algoritmos de O(n log n).
- **Optimización**: Aprovecha si los datos están parcialmente ordenados para reducir comparaciones.

---

Con estos conocimientos de algoritmos

 de ordenamiento, estarás listo para optimizar operaciones de datos de manera efectiva y adaptativa en tus proyectos.
