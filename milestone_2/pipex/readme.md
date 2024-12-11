# pipex

 - Reproduce el comportamiento del comando `|` en la shell, usando C.

 - La ejecución es de la siguiente forma: `./pipex infile cmd1 cmd2 outfile`, y se comporta como la línea en la shell: `< infile cmd1 | cmd2 > outfile`.

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

### 2. **Cómo hacer pipex con dos procesos hijos**

- En lugar de tener un solo hijo ejecutando un comando, puedes dividir el trabajo en dos procesos hijos. Cada hijo ejecutará uno de los comandos (`cmd1` y `cmd2`), y el proceso padre simplemente supervisará su ejecución. El proceso padre esperará a que ambos hijos terminen.

### 3. **La función `access()`**

- Cuando el comando no se encuentra, como al intentar ejecutar un archivo que no existe, el programa debería verificar si el comando es accesible antes de intentar ejecutarlo. - Esto se logra usando la función `access()`, que verifica si el archivo (o comando) existe y es ejecutable.

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

