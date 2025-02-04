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
 
<p align="center" width="100%"><a href="#"><img src="../../img/milestone_3/minishell.png" width="900" /></a></p>
La minishell debe manejar variables de entorno. Esto incluye poder obtener, establecer y eliminar variables de entorno.

