<p align="center" width="100%"><a href="milestone_2/"><img src="../../img/milestone_2/pipex.png" width="72" />


# pipex

-El proyecto pipex  es un desafío en el que se reproduce el comportamiento de las tuberías `|` y redirecciones de entrada/salida de la shell usando C.

 Esquema del Programa



# Símbolo | 

- Redirige el output del comando de la izquierda al input del comando de la derecha, reproduciendo el comportamiento del comando `|` en la shell, usando C.

 - La ejecución es de la siguiente forma: `./pipex infile cmd1 cmd2 outfile`, y se comporta como la línea en la shell:

 - `< infile cmd1 | cmd2 > outfile`.

## El flujo básico para dos comandos sería:

    Abrir el archivo de entrada (infile) y redirigirlo al stdin.
    Crear una tubería entre cmd1 y cmd2.
    Redirigir la salida de cmd1 al extremo de escritura del pipe.
    Redirigir la entrada de cmd2 al extremo de lectura del pipe.
    Abrir el archivo de salida (outfile) y redirigirlo al stdout.

# Símbolo < 
- Es un símbolo de "redirección de entrada".

`< infile grep a1 | wc -w > outfile`

- En ese caso, el símbolo < redirige el contenido de `infile` a `standard input` de modo que cuando `grep` se lee desde standard input, obtiene el contenido de infile.

- Utilicemos una sintaxis más fácil de entender que funcione de la misma manera.

`grep a1 < infile | wc -w > outfile`

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

