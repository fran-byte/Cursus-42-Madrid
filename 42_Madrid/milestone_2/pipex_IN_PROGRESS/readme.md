


# pipex (recursos)

-El proyecto pipex  es un desafío en el que se reproduce el comportamiento de las tuberías `|` y redirecciones de entrada/salida de la shell usando C.

<p align="center" width="100%"><a href="milestone_2/"><img src="../../img/milestone_2/Unix_pipe_and_fork.png" width="512"/></p>

# Símbolo |

- Redirige el output del comando de la izquierda al input del comando de la derecha, reproduciendo el comportamiento del comando `|` en la shell, usando C.

 - La ejecución es de la siguiente forma: `./pipex infile cmd1 cmd2 outfile`, y se comporta como la línea en la shell:  `< infile cmd1 | cmd2 > outfile`.

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


## El flujo básico para dos comandos sería:

    - Abrir el archivo de entrada [infile] y redirigirlo al stdin (standar input)
    - Crear una tubería entre cmd1 y cmd2.
    - Redirigir la salida de cmd1 al extremo de escritura del pipe.
    - Redirigir la entrada de cmd2 al extremo de lectura del pipe.
    - Abrir el archivo de salida [outfile] y redirigirlo al stdout (standar output)

## Proceso de redirección con <

`< infile grep a1 | wc -w > outfile`

- En ese caso, el símbolo < redirige el contenido de `infile` a `standard input` de modo que cuando `grep` se lee desde standard input, obtiene el contenido de infile.

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

# Símbolo <<


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

`< infile grep a1 | wc -w > outfile`

```
                       Shell (Padre)
                            |
              -----------------------------------
              |                                 |
        grep (Hijo 1)                     wc (Hijo 2)
              |                                 |
        Lee de infile                Lee de pipe y escribe
                                            en outfile

```
### 2. **Cómo hacer pipex con dos procesos hijos**

- En lugar de tener un solo hijo ejecutando un comando, puedes dividir el trabajo en dos procesos hijos. Cada hijo ejecutará uno de los comandos (`cmd1` y `cmd2`), y el proceso padre simplemente supervisará su ejecución. El proceso padre esperará a que ambos hijos terminen.


```
# ./pipex infile cmd1 cmd2 outfile

pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
 
# pipe() Enviamos la salida del 1º execve() como entrada al 2º execve()
# fork() Abrimos 2 procesos (two commands) en un solo programa
# dup2() intercambia nuestros archivos con stdin y stdout
```



## Configurando el pipe
``` 
void    pipex(int f1, int f2)
{
    int end[2];    pipe(end);
}

// pipe() toma un array de dos int y los enlaza
// lo que se hace en end[0] es visible en end[1], y viceversa
// pipe() asigna un fd a cada extremo
// Los fds son descriptores de archivos
// dado que los archivos se pueden leer y escribir, al obtener un fd cada uno, los dos extremos pueden comunicarse
// end[1] escribirá en su propio fd, y end[0] leerá el fd de end[1] y escribirá en el suyo propio

```
## Procesos fork()

```
void    pipex(int f1, int f2)
{
    int   end[2];
    pid_t parent;    pipe(end);
    parent = fork();
    if (parent < 0)
         return (perror("Fork: "));
    if (!parent) // si fork() devuelve 0, estamos en el proceso hijo
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}

// fork() divide el proceso en dos subprocesos -> paralelos, simultáneos, ocurren al mismo tiempo
// devuelve 0 para el proceso hijo, un valor distinto de cero para el proceso padre, y -1 en caso de error
```
## File Descriptors (FD)

pipex se ejecuta de esta forma: `./pipex infile cmd1 cmd2 outfile`
Los FDs 0, 1 y 2 están asignados por defecto a `stdin`, `stdou`t y `stderr`
infile, outfile, el pipe, stdin y stdout son todos `FDs`
En Linux, puedes verificar tus fds actualmente abiertos con el comando `ls -la /proc/$$/fd`

```
Nuestra tabla de fds ahora se ve así:

                           -----------------    
                 0         |     stdin     |  
                           -----------------    
                 1         |     stdout    |    
                           -----------------    
                 2         |     stderr    |  
                           -----------------
                 3         |     infile    |  // open()
                           -----------------
                 4         |     outfile   |  // open()
                           -----------------
                 5         |     end[0]    | 
                           -----------------
                 6         |     end[1]    |  
                           -----------------
```

## Intercambiando fds con dup2()
- Para el proceso hijo, queremos que `infile` sea nuestro stdin (como entrada), y `end[1]` sea nuestro stdout (escribimos en `end[1]` la salida de `cmd1`)
En el proceso padre, queremos que `end[0]` sea nuestro stdin (`end[0]` lee de `end[1]` la salida de `cmd1`), y outfile sea nuestro stdout (escribimos en él la salida de `cmd2`)
Visualmente,
```
// cada cmd necesita un stdin (entrada) y devuelve una salida (a stdout)
   
    infile                                             outfile
como stdin para cmd1                              como stdout para cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           salida                               lee end[1]
    se escribe en end[1]              y envía la salida de cmd1 a cmd2
                                 
       (end[1] se convierte                 (end[0] se convierte 
        en stdout de cmd1)                    en stdin de cmd2)

```

## Intercambiamos fds a stdin/stdout con dup2()
El MAN nos dice:

`int dup2(int fd1, int fd2)` : cerrará fd2 y duplicará el valor de fd2 en fd1
dicho de otra manera, redirigirá fd1 a fd2


### 3. **La función `access()`**

- Cuando el comando no se encuentra, como al intentar ejecutar un archivo que no existe, el programa debería verificar si el comando es accesible antes de intentar ejecutarlo.
- Esto se logra usando la función `access()`, que verifica si el archivo (o comando) existe y es ejecutable.
- `int access(const char *pathname, int mode);`
- `access()` Comprueba si el programa puede acceder al archivo pathname.

`mode` especifica las comprobaciones de accesibilidad que se realizaránr:
`F_OK`comprueba la existencia del archivo.
`R_OK`,` W_OK`, y `X_OK`comprueba si el archivo existe y otorga permisos de lectura, escritura y ejecución, respectivamente.

- En caso de éxito (se conceden todos los permisos solicitados), se devuelve `cero`. En caso de error (se deniega al menos un bit de mode, un permiso solicitado o se produce algún otro error), se devuelve `-1` y `errno` se configura de forma adecuada.

``` 
access()
 |
 |-- Verifica si el archivo (o comando) es accesible
      |
      |-- Comprueba si el archivo existe y es ejecutable
      :     |-- int access(const char *pathname, int mode)
      :     |-- mode especifica las comprobaciones de accesibilidad:
      :           |-- F_OK: existencia del archivo
      :           |-- R_OK: permisos de lectura
      :           |-- W_OK: permisos de escritura
      :           |-- X_OK: permisos de ejecución
      :
      |-- Devuelve 0 si se conceden todos los permisos solicitados
      |-- Devuelve -1 y configura errno en caso de error
```


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

[links:]( https://www.cs.buap.mx/~hilario_sm/slide/SO-1/Pipe.pdf)