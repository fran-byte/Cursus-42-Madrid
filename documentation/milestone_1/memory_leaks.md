# Memory Leaks
Las fugas de memoria en C son un problema común y grave, sobre todo en programas de larga duración o en sistemas que necesitan administrar eficientemente sus recursos. En C, las fugas de memoria ocurren cuando se asigna memoria en el heap (con `malloc`, `calloc`, `realloc`, etc.) y no se libera adecuadamente (con `free`). Esto hace que la memoria asignada permanezca ocupada incluso cuando ya no es necesaria, lo cual puede degradar el rendimiento e incluso llevar a fallos del programa por falta de memoria.

Para buscar y corregir fugas de memoria, hay varias herramientas y métodos que los programadores de C utilizan. 

### 1. ¿Qué es una fuga de memoria?

En términos generales, una fuga de memoria ocurre cuando se reserva memoria y luego se pierde la referencia a ella sin liberarla. Existen dos tipos principales de fugas:

- **Fuga clásica**: Se asigna memoria, pero nunca se libera.
- **Fuga de memoria "inaccesible"**: Es un bloque de memoria que ha sido asignado y referenciado por algún puntero, pero eventualmente se pierde la referencia al puntero (por ejemplo, al sobrescribirlo).

### 2. Herramientas para detectar fugas de memoria

#### a) Sanitizers (como `-fsanitize=leak` y `-fsanitize=address`)

`-fsanitize=leak` es una opción del compilador que habilita el *Leak Sanitizer*, una herramienta que detecta fugas de memoria en tiempo de ejecución. Al compilar un programa con `-fsanitize=leak`, el compilador inserta verificaciones para rastrear asignaciones y liberar memoria, y al finalizar el programa muestra un informe de las fugas encontradas.

Otra opción relacionada es `-fsanitize=address`, que habilita el *Address Sanitizer*, una herramienta aún más completa que puede detectar una gama de errores de memoria, como:
- Acceso a memoria fuera de los límites de un arreglo.
- Acceso a memoria después de haber sido liberada.
- Fugas de memoria.

**Ventajas**:
- Los *sanitizers* son fáciles de configurar (como ves en tu ejemplo).
- Funcionan en tiempo de ejecución, lo que permite detectar errores en el contexto del programa.
  
**Desventajas**:
- Aumentan el tiempo de ejecución y el uso de memoria.
- Están limitados al entorno en el que se ejecuta el programa, por lo que pueden no detectar fugas en todos los caminos de ejecución.

#### b) Valgrind

Valgrind es una de las herramientas más utilizadas para depurar fugas de memoria y otros problemas de administración de memoria. Funciona como un entorno de ejecución en el que puedes ejecutar tu programa, y éste interceptará todas las llamadas a funciones de memoria (`malloc`, `free`, `new`, `delete`, etc.).

Para usar Valgrind, puedes ejecutar un programa compilado con el comando:

```bash
valgrind --leak-check=full ./a.out
```

Valgrind ofrece un informe muy detallado que incluye:
- La cantidad de memoria no liberada.
- Las direcciones de memoria y los tamaños de los bloques perdidos.
- Los *backtraces* para identificar dónde se asignó y perdió cada bloque.

**Ventajas**:
- Detecta una amplia gama de problemas de memoria.
- Da informes detallados sobre cada fuga y permite rastrear exactamente dónde ocurrió.

**Desventajas**:
- Es relativamente lento.
- Puede ser menos eficaz en programas extremadamente grandes o en aplicaciones en tiempo real.

#### c) Herramientas de depuración integradas en IDEs (como Visual Studio, Xcode, etc.)

Algunos IDEs también tienen herramientas de depuración que detectan fugas de memoria. Por ejemplo, Visual Studio tiene un *Debugger Memory Leak Detection* para programas en C/C++. Estas herramientas suelen ser cómodas y fáciles de usar, pero también pueden tener limitaciones según la complejidad del programa.

### 3. Compilación y uso de sanitizers para depurar

Tu comando:
```bash
cc -fsanitize=leak -static-libsan get_next_line.c get_next_line_utils.c && ./a.out
```

Aquí, `-fsanitize=leak` activa el *Leak Sanitizer*, y `-static-libsan` asegura que las bibliotecas del sanitizer estén vinculadas estáticamente, lo cual es útil para portabilidad y para garantizar que el binario generado contenga todo lo necesario.

Al ejecutar `./a.out`, si hay alguna fuga de memoria, el *Leak Sanitizer* generará un informe en el que detallará las fugas detectadas.

### 4. Estrategias para corregir fugas de memoria

Para corregir fugas de memoria, es importante:
- **Revisar cada `malloc` y `free`**: Por cada asignación de memoria, asegúrate de tener una función `free` correspondiente.
- **Usar punteros inteligentes** (en otros lenguajes como C++): Aunque en C puro no existen punteros inteligentes, este concepto nos recuerda la importancia de tener una referencia clara de quién es responsable de liberar la memoria.
- **Inicializar punteros a `NULL` y verificar antes de liberar**: Esto ayuda a evitar dobles liberaciones y accesos a punteros inválidos.

### 5. Buenas prácticas para evitar fugas de memoria

- **Organizar y documentar bien la asignación y liberación de memoria**.
- **Usar funciones de control de errores adecuadas** para manejar salidas tempranas.
- **Desarrollar pruebas unitarias** que cubran diferentes casos y caminos de ejecución.
  
### Resumen

Las fugas de memoria son un problema común en C, y herramientas como *Leak Sanitizer*, *Address Sanitizer* y *Valgrind* son esenciales para detectarlas. 
