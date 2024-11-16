
<h1 align="center" width="100%">Recursos para ExamRank02</h1>


<p align="center" width="100%"><img src="../examrank02.png" width="102" />


# alpha_mirror
- Forma fácil y rápida si son simples caracteres alpha, es introducir un un `char []` en orden inverso:
  ``` char [] = "zyxwvutsrqponmlkjihgfedcba"``` y recorrerlo con un indice cuando se a `a` será índice de `0` que equivaldrá a `z`

```text  
Nombre de la tarea: alpha_mirror
Archivos esperados: alpha_mirror.c
Funciones permitidas: escribir
--------------------------------------------------------------------------------
 
Escriba un programa llamado alpha_mirror que tome una cadena y muestre esta cadena
después de reemplazar cada carácter alfabético por el carácter alfabético opuesto
carácter, seguido de una nueva línea.
 
'a' se convierte en 'z', 'Z' se convierte en 'A'
'd' se convierte en 'w', 'M' se convierte en 'N'
 
etcétera.
 
El caso no cambia.
 
Si el número de argumentos no es 1, muestra solo una nueva línea.
 
Ejemplos:
 
$>./alpha_mirror "abc"
zix
$>./alpha_mirror "Mi caballo es increíble." | gato -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | gato -e
$
$>
```
