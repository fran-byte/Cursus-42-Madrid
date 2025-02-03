 [![COMMONCORE 0](https://img.shields.io/badge/%20<<%20C%20o%20m%20m%20o%20n%20C%20o%20r%20e%20-c988f9)](https://github.com/fran-byte/Cursus-42-Madrid)

<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20minishell%20%20-00008b" style="width:150px;height:40px;"></a>

</div>


# Proyecto Minishell (en fase de borrador)

- Este proyecto consiste en crear nuestra propia `shell`, nuestro propio interprete de comandos,
  una versión reducida de la **Shell de Unix**

  ## Que debe de hacer nuestra shell:
  - Lo primero es mostrar nuestro prompt: **minishell>**
  - Leerá una entrada por la terminal con `readline()` y deberá ser capaz interpretar los comandos
    introducidos en ella (ls, echo, cat, etc.) y guardarlos en el historial.
  - Debe manejar pipes (|), redirecciones (<, >, >>, <<).
  - Debe implementar algunos built-ins (cd, pwd, exit, export, etc.).
  - Debe capturar señales (Ctrl+C, Ctrl+D, Ctrl+\).
 
 ## Algunas líneas de ataque para realizar el proyecto podrían ser estas:

1️⃣ Hacer que la shell lea comandos (readline()).
   En esta parte debemos gestionar:
  
- `' '` Comilla simple NO INTERPRETARÁ los metacaracteres y debe ser tratado como una cadena literal:

  **minishell>** echo 'Esto no es un comando; ni un metacaracter'
 
- `" "` Comilla doble NO INTERPRETARÁ los metacaracteres con EXCEPCIÓN del simbolo `$` ya que lo utilizaremos para dirigirnos a variables:

  **minishell>** saludo = "42 Madrid"

  **minishell>** "Hola $saludo"

 - Manejo de señales: Asgurarse de capturar señales como Ctrl+C y Ctrl+D para manejar las interrupciones y la salida de manera apropiada.
  
- Por otro lado no se deben interpretar las comillas sin cerrar ni los caracteres especiales: \ (barra invertida) o ; (punto y coma).


.....

2️⃣ **Separar los comandos en tokens (ls -l → ["ls", "-l"]).**
- Separar los comandos: se debe dividir la entrada en diferentes comandos o argumentos, separándolos por espacios u otros delimitadores.
- Analizar metacaracteres: Los metacaracteres como |, >, < y & deben ser manejados de forma especial. Esto también incluye el análisis de redirecciones y pipes.

3️⃣ **Ejecutar comandos con execve() (ls, pwd, echo).**
-Para ejecutar los comandos:

**fork()**: Necesitamos crear un nuevo proceso usando fork() para ejecutar el comando. El proceso padre se encargará de esperar el proceso hijo con wait().

**execve()**: Después de hacer el fork, el proceso hijo debe usar execve() para ejecutar el comando con los argumentos proporcionados.
Buscar en el PATH: Si el comando no contiene una ruta absoluta, debemoss buscarlo en las rutas definidas en la variable de entorno PATH.

4️⃣ **Implementar built-ins (cd, pwd, exit).**

-Algunos comandos son internos al shell, como **cd, exit, echo, etc**. Necesitamos implementarlos de forma especial.

cd: Cambia el directorio de trabajo.
exit: Termina el shell.
echo: Imprime texto en la terminal.
env: Muestra las variables de entorno.

5️⃣ **Añadir pipes (|) y redirecciones (<, >, >>, <<).**
- Los pipes permiten ejecutar varios comandos en cadena, donde la salida de un comando se convierte en la entrada de otro. Para esto:

**pipe()**: Crea un pipe utilizando pipe() y redirige las entradas y salidas estándar (stdin, stdout) usando dup2().

**fork()**: Crea procesos hijos para cada comando en el pipeline.

**wait()**: Asegúrate de esperar a que todos los procesos hijos terminen.

- Las redirecciones permiten que la entrada o salida de un comando sea redirigida a un archivo.

**Redirección de salida (>)**: Abre un archivo en modo escritura y redirige la salida estándar (stdout) al archivo.

**Redirección de entrada (<)**: Redirige la entrada estándar (stdin) desde un archivo.

**Redirección de salida append (>>)**: Abre un archivo en modo append para agregar contenido en lugar de sobrescribirlo.

6️⃣ **Manejo de Variables de Entorno**
La minishell debe manejar variables de entorno. Esto incluye poder obtener, establecer y eliminar variables de entorno.

getenv(): Obtiene el valor de una variable de entorno.
setenv(): Establece una variable de entorno.
unsetenv(): Elimina una variable de entorno.
Manejar señales (Ctrl+C, Ctrl+D (Ctrl+\ no debe de hacer nada).

7️⃣ Y finalmente si no queremos que nos tiren el proyecto, depurar errores y comprobar**memory leaks.**
