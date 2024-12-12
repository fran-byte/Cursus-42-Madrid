<p align="center" width="100%"><a href="milestone_2/"><img src="../../img/milestone_2/pipex.png" width="72" />


# pipex

-El proyecto pipex  es un desafío en el que se reproduce el comportamiento de las tuberías `|` y redirecciones de entrada/salida de la shell usando C.

# Símbolo | 

- Redirige el output del comando de la izquierda al input del comando de la derecha, reproduciendo el comportamiento del comando `|` en la shell, usando C.

 - La ejecución es de la siguiente forma: `./pipex infile cmd1 cmd2 outfile`, y se comporta como la línea en la shell:  `< infile cmd1 | cmd2 > outfile`.

## El flujo básico para dos comandos sería:

    - Abrir el archivo de entrada [infile] y redirigirlo al stdin (standar input).
    - Crear una tubería entre cmd1 y cmd2.
    - Redirigir la salida de cmd1 al extremo de escritura del pipe.
    - Redirigir la entrada de cmd2 al extremo de lectura del pipe.
    - Abrir el archivo de salida [outfile] y redirigirlo al stdout.

---

## RESOLVIENDO DUDAS:

Flujos en la Terminal

- En un sistema UNIX (como Linux o macOS), los procesos se comunican a través de lo que se llama **flujos estándar**. Hay tres flujos principales:

## 1- stdin (Standard Input): 

- Fuente predeterminada la entrada estándar. Por defecto, es el **TECLADO**
- Pudes cargar datos tambien desde **ARCHIVOS** (con redirección <)
- o cargar esos datos desde la **Salida** de **OTROS COMANDOS** como (**pipes |**)
  
## 2- stdout (Standard Output):

- **PANTALLA** del Terminal (predeterminado)
- **ARCHIVOS** (con redirección > o >>)
- Entrada de **OTROS COMANDOS** (pipes |)


## 3- stderr (Standard Error):
- Es el flujo de error estándar, utilizado para imprimir mensajes de error, también redirigible.
- **Pantalla** del Terminal (por defecto).
- **Archivos** (con redirección 2> o 2>>).
- **Combinación** de stderr y stdout (con &> o 2>&1).
- **Redirección a /dev/null** (descartar los errores).
- **Archivos especiales** de dispositivos en /dev (como /dev/tty, /dev/console, etc.).
- **Archivos de registro** del sistema (logs).
- Redirección a **otros procesos** o programas (a través de pipes o comandos).
- Entrada en **programas gráficos** o **interfaces interactivas.**



## Proceso de redirección con <

`< infile grep a1 | wc -w > outfile`

- En ese caso, el símbolo < redirige el contenido de `infile` a `standard input` de modo que cuando `grep` se lee desde standard input, obtiene el contenido de infile.

- Utilicemos una sintaxis más fácil de entender que funcione de la misma manera.

`grep a1 < infile | wc -w > outfile`

Cuando usas el operador < para redirigir un archivo a un comando, el sistema realiza los siguientes pasos internos:

- **El archivo se abre**: El sistema operativo abre el archivo especificado (infile) y obtiene un descriptor de archivo, que es un número que hace referencia al archivo en la memoria.

- **El contenido del archivo se pasa a stdin**: El archivo se lee secuencialmente línea por línea, y cada línea de texto se envía al flujo de entrada estándar (stdin) del comando que está recibiendo la redirección.

- En términos técnicos, el archivo no se "almacena" en algún lugar especial, sino que el contenido se coloca en el buffer (un área de memoria temporal) que maneja el flujo de entrada estándar del proceso. El proceso recibe estos datos como si estuvieran siendo introducidos por el usuario, **pero en realidad son leídos desde el archivo**.

- **El comando lee desde stdin**: El comando, como grep en tu ejemplo, recibe los datos desde stdin como si el usuario los hubiera tecleado y el comando procesa esos datos de acuerdo con su lógica (por ejemplo, buscando un patrón).



---

### **1. Abrir el archivo de entrada (`infile`) y redirigirlo al `stdin`**
- El archivo de entrada se abre en modo lectura.
- El descriptor del archivo se conecta a la entrada estándar (`stdin`) del proceso que ejecutará el primer comando. Esto asegura que el comando pueda leer los datos del archivo en lugar de esperar entrada del teclado.
- Se hace redirigiendo `stdin` al descriptor del archivo usando una llamada al sistema.

---

### **2. Crear una tubería entre `cmd1` y `cmd2`**
- Una tubería es un canal de comunicación entre procesos, compuesto por dos extremos:
  - Un extremo para **escribir** datos.
  - Otro extremo para **leer** los datos escritos.
- La función `pipe()` crea este canal de comunicación.
- Este canal se usará para enviar la salida del primer comando (`cmd1`) como entrada para el segundo comando (`cmd2`).

---

### **3. Redirigir la salida de `cmd1` al extremo de escritura del pipe**
- Se redirige la salida estándar (`stdout`) del proceso que ejecuta el primer comando hacia el extremo de escritura del pipe.
- Esto asegura que cualquier salida producida por `cmd1` se envíe al pipe en lugar de aparecer en la pantalla o un archivo.

---

### **4. Redirigir la entrada de `cmd2` al extremo de lectura del pipe**
- Se conecta el extremo de lectura del pipe a la entrada estándar (`stdin`) del proceso que ejecutará el segundo comando.
- Esto permite que `cmd2` reciba como entrada los datos que el primer comando escribió en el pipe.

---

### **5. Abrir el archivo de salida (`outfile`) y redirigirlo al `stdout`**
- El archivo de salida se abre en modo escritura. Si no existe, se crea. Si ya existe, puede sobrescribirse o añadirse al final según el símbolo utilizado (`>` o `>>`).
- El descriptor del archivo se conecta a la salida estándar (`stdout`) del proceso que ejecuta el segundo comando.
- Esto asegura que cualquier salida producida por `cmd2` se escriba en el archivo de salida en lugar de aparecer en la pantalla.

---

Este flujo asegura que los datos pasen correctamente desde el archivo de entrada al primer comando, luego a través del pipe hacia el segundo comando, y finalmente al archivo de salida. Si hay más comandos, el flujo se encadena repitiendo los pasos de las tuberías.

# Símbolo < 
- Es un símbolo de "redirección de entrada".



# Símbolo >> 

- El >> hace casi lo mismo que el > . Reemplaza el contenido del archivo de la derecha con el resultado del comando de la izquierda. El símbolo >> agrega el resultado del comando de la izquierda al final del archivo.

# Símbolo << (para el bonus)


- Es una "redirección" de entrada. Hace que el shell lea desde la entrada estándar hasta que encuentre solo un valor específico LIMITER en la entrada estándar. Veamos el ejemplo del tema.

`cmd << LIMITER | cmd1 >> file`

- Como puedes ver, el primer comando `cat` esperó hasta que escribí LIM y solo LIM en la entrada estándar antes de continuar. Debería pipex hacer lo mismo.

 ## Funciones autorizadas para el proyecto:

 • `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`

• `ft_printf` y cualquier equivalente que TÚ hayas programado.


### 1. **Teoría de fondo — `pipe()`, `fork()`, `dup2()` y `execve()`**

- **`pipe()`**: Crea un canal de comunicación entre dos extremos (en este caso, dos descriptores de archivo). El primer extremo (`end[0]`) se utiliza para leer, y el segundo (`end[1]`) para escribir. Esto permite que un proceso hijo escriba datos en el pipe, y el proceso padre los lea.
- **`fork()`**: Divide el proceso principal en dos procesos (uno hijo y uno padre). Devuelve 0 al proceso hijo y un número mayor que 0 al proceso padre.
- **`dup2()`**: Permite redirigir la entrada y salida estándar a otros descriptores de archivo, por ejemplo, redirigir la salida estándar de un proceso a la entrada de otro.
- **`execve()`**: Ejecuta un comando en el sistema, permitiendo que el proceso cargue y ejecute el binario del comando.

La estructura de la función `pipex` es la siguiente:
- El archivo de entrada (`infile`) se establece como la entrada estándar del primer comando (`cmd1`).
- El comando `cmd1` escribe su salida en el pipe, que luego se pasa al segundo comando (`cmd2`).
- El archivo de salida (`outfile`) recibe la salida del segundo comando.

**Esquema visual**:

```
infile                               outfile
   |                                    |
   |                                    |
   |                                    |
   v                                    v
  cmd1  -->  (lee de infile, escribe en end[1])
                    |
                    v
                 end[1]  <---->  end[0]
                    |
                    v
                 cmd2  -->  (lee de end[0], escribe en outfile)

```



Copiar
grep a1 < infile | wc -w > outfile
De esta manera, podemos ver mejor que el contenido del infilees utilizado por el grepcomando.
### 2. **Cómo hacer pipex con dos procesos hijos**

- En lugar de tener un solo hijo ejecutando un comando, puedes dividir el trabajo en dos procesos hijos. Cada hijo ejecutará uno de los comandos (`cmd1` y `cmd2`), y el proceso padre simplemente supervisará su ejecución. El proceso padre esperará a que ambos hijos terminen.

### 3. **La función `access()`**

- Cuando el comando no se encuentra, como al intentar ejecutar un archivo que no existe, el programa debería verificar si el comando es accesible antes de intentar ejecutarlo.
- Esto se logra usando la función `access()`, que verifica si el archivo (o comando) existe y es ejecutable.
- `int access(const char *pathname, int mode);`
- `access()` Comprueba si el programa puede acceder al archivo pathname.

`mode` especifica las comprobaciones de accesibilidad que se realizaránr:
`F_OK`comprueba la existencia del archivo.
`R_OK`,` W_OK`, y `X_OK`comprueba si el archivo existe y otorga permisos de lectura, escritura y ejecución, respectivamente.

- En caso de éxito (se conceden todos los permisos solicitados), se devuelve cero. En caso de error (se deniega al menos un bit de modeun permiso solicitado o se produce algún otro error), se devuelve -1 y errnose configura de forma adecuada.

### 4. **Problemas comunes encontrados**
- **Cierre incorrecto de extremos del pipe**: Si uno de los extremos del pipe no se cierra correctamente, el proceso en espera no terminará correctamente.
- **Uso de `perror("Error")` para depuración**: Se recomienda usar `perror` para verificar qué está fallando en el programa, especialmente después de llamadas a `fork()` y `execve()`.
- **Derechos de acceso a archivos**: Se debe manejar correctamente los permisos de los archivos cuando se abren con `open()` y asegurarse de que sean legibles y escribibles.

---

1. **Funciones esenciales de UNIX:**
   - **`dup2(2)`**: Redirige descriptores de archivo.
   - **`access(2)`**: Verifica permisos de acceso a archivos.
   - **`execve(2)`**: Ejecuta un programa reemplazando el proceso actual.
   - **`fork(2)`**: Crea un proceso hijo.
   - **`pipe(8)`**: Crea canales unidireccionales para comunicación entre procesos.
   - **`unlink(1)`**: Elimina archivos del sistema.
   - **`wait(2)`**: Suspende el proceso padre hasta que el hijo termine.

2. **Estructura del programa:**
   - **Parsing**: Comprueba argumentos, abre archivos y analiza comandos usando estructuras como `t_pipex`.
   - **Ejecución**: Duplica flujos de entrada/salida con `dup2`, maneja procesos con `fork`, y ejecuta comandos con `execve`.
   - **Limpieza**: Cierra archivos, libera memoria y espera procesos hijos con `wait`.

3. **Errores comunes:**
   - No usar `unlink` para eliminar archivos temporales.
   - No ajustar permisos de archivos según el modo (`here_doc`).
   - No manejar comandos inválidos o archivos inexistentes correctamente.
   - No simular el comportamiento de Bash, donde errores en comandos no detienen el programa.

