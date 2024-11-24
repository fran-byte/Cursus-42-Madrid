# LLDB

### 1. **Instalar LLDB**

En muchas distribuciones de Ubuntu, LLDB está disponible en el gestor de paquetes. Para instalarlo, abre una terminal y ejecuta:

```bash
sudo apt update
sudo apt install lldb
```

### 2. **Compilar el Programa con Información de Depuración**

Antes de depurar con LLDB, compila tu programa en C con la opción `-g`. Esta opción permite a LLDB acceder a los símbolos de depuración, como nombres de variables y números de línea.

```bash
gcc -g -o programa programa.c
```

Este comando crea un ejecutable llamado `programa` con información de depuración incluida.

### 3. **Iniciar LLDB**

Para comenzar la depuración, inicia LLDB y carga el programa:

```bash
lldb ./programa
```

Esto abrirá el entorno de LLDB y te mostrará un prompt interactivo (`(lldb)`). Desde aquí, puedes comenzar a depurar.

### 4. **Comandos Básicos de LLDB**

#### A. **Establecer Puntos de Interrupción (Breakpoints)**

Los breakpoints detienen la ejecución en una línea específica para inspeccionar el estado del programa.

- Para agregar un breakpoint en una función:
  ```bash
  (lldb) break set -n nombre_funcion
  ```

- Para agregar un breakpoint en una línea específica:
  ```bash
  (lldb) break set -f archivo.c -l numero_linea
  ```

Ejemplo:
```bash
(lldb) break set -n main
(lldb) break set -f programa.c -l 15
```

#### B. **Ejecutar el Programa**

Después de establecer breakpoints, ejecuta el programa con:

```bash
(lldb) run
```

LLDB ejecutará el programa y se detendrá en el primer breakpoint.

#### C. **Controlar la Ejecución**

- **Paso a Paso (Step In)**: Entra en una función para inspeccionar sus detalles.
  ```bash
  (lldb) step
  ```

- **Paso Sobre (Step Over)**: Ejecuta la línea actual y se mueve a la siguiente, sin entrar en funciones.
  ```bash
  (lldb) next
  ```

- **Continuar (Continue)**: Reanuda la ejecución hasta el siguiente breakpoint.
  ```bash
  (lldb) continue
  ```

#### D. **Inspeccionar Variables**

- **Mostrar el Valor de una Variable**: Muestra el valor de una variable específica.
  ```bash
  (lldb) print nombre_variable
  ```

- **Listar Variables Locales**: Muestra todas las variables locales en el contexto actual.
  ```bash
  (lldb) frame variable
  ```

#### E. **Obtener Información de la Pila (Stack Trace)**

Si el programa falla, el stack trace muestra la secuencia de funciones que llevaron al error:

```bash
(lldb) bt
```

Esto es útil para rastrear dónde y cómo ocurrió un error.

#### F. **Salir de LLDB**

Para terminar la sesión de LLDB, usa:

```bash
(lldb) quit
```

### 5. **Ejemplo Completo de una Sesión de Depuración en LLDB**

Supongamos que tienes un programa sencillo en `programa.c` con una función llamada `mi_funcion`. Aquí tienes un flujo de trabajo básico:

1. **Compila el programa**:

   ```bash
   gcc -g -o programa programa.c
   ```

2. **Inicia LLDB**:

   ```bash
   lldb ./programa
   ```

3. **Establece un breakpoint en `main` y otro en `mi_funcion`**:

   ```bash
   (lldb) break set -n main
   (lldb) break set -n mi_funcion
   ```

4. **Ejecuta el programa**:

   ```bash
   (lldb) run
   ```

5. **Inspecciona variables y controla la ejecución**:

   - Cuando se detenga en `main`, lista las variables locales:
     ```bash
     (lldb) frame variable
     ```

   - Avanza al siguiente breakpoint (`mi_funcion`) con `continue`:
     ```bash
     (lldb) continue
     ```

   - Dentro de `mi_funcion`, revisa una variable:
     ```bash
     (lldb) print nombre_variable
     ```

6. **Salir de LLDB**:

   ```bash
   (lldb) quit
   ```

# Comandos Abreviados de LLDB

1. **Puntos de Interrupción (Breakpoints)**:
   - Para poner un breakpoint, en lugar de `break set -n nombre_funcion`, puedes simplemente usar:
     ```bash
     (lldb) b nombre_funcion
     ```
   - Para poner un breakpoint en una línea específica:
     ```bash
     (lldb) b archivo.c:numero_linea
     ```
   - Ejemplo:
     ```bash
     (lldb) b main
     (lldb) b programa.c:15
     ```

2. **Ejecutar el Programa**:
   - En lugar de escribir `run`, puedes usar solo `r`:
     ```bash
     (lldb) r
     ```

3. **Control de Ejecución**:
   - **Paso a Paso (Step In)**:
     - En lugar de `step`, puedes usar `s`:
       ```bash
       (lldb) s
       ```

   - **Paso Sobre (Step Over)**:
     - En lugar de `next`, solo escribe `n`:
       ```bash
       (lldb) n
       ```

   - **Continuar Ejecución**:
     - En lugar de `continue`, simplemente usa `c`:
       ```bash
       (lldb) c
       ```

4. **Inspeccionar Variables**:
   - Para ver una variable, puedes abreviar `print nombre_variable` con solo `p`:
     ```bash
     (lldb) p nombre_variable
     ```

5. **Stack Trace**:
   - Para ver el stack trace (traza de pila), en vez de `bt` (backtrace), puedes usar `bt` sin cambios, ya que es una de las formas más cortas:
     ```bash
     (lldb) bt
     ```

6. **Salir de LLDB**:
   - Puedes escribir solo `q` en lugar de `quit`:
     ```bash
     (lldb) q
     ```
