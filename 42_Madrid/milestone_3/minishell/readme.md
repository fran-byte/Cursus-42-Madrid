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

1️⃣ Hacer que la shell lea comandos y los imprima (readline()).
   En esta parte debemos gestionar:
  
- `' '` Comilla simple NO INTERPRETARÁ los metacaracteres y debe ser tratado como una cadena literal:

  **minishell>** echo 'Esto no es un comando; ni un metacaracter'
 
- `" "` Comilla doble NO INTERPRETARÁ los metacaracteres con EXCEPCIÓN del simbolo `$` ya que lo utilizaremos para dirigirnos a variables:

  **minishell>** saludo = "42 Madrid"

  **minishell>** "Hola $saludo"
  
- Por otro lado no se deben interpretar las comillas sin cerrar ni los caracteres especiales: \ (barra invertida) o ; (punto y coma).


.....

2️⃣ Separar los comandos en tokens (ls -l → ["ls", "-l"]).

3️⃣ Ejecutar comandos con execve() (ls, pwd, echo).

4️⃣ Implementar built-ins (cd, pwd, exit).

5️⃣ Añadir pipes (|) y redirecciones (<, >, >>, <<).

6️⃣ Manejar señales (Ctrl+C, Ctrl+D (Ctrl+\ no debe de hacer nada).

7️⃣ Y finalmente si no queremos que nos tiren el proyecto, depurar errores y comprobar memory leaks.
