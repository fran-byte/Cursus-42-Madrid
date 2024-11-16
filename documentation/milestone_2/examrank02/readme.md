
<h1 align="center" width="100%">Recursos para ExamRank02</h1>


<p align="center" width="100%"><img src="../examrank02.png" width="102" />

# Spoiler

- Simplemente haré un repaso a los puntos esenciles de cada código.
  
## alpha_mirror
- Forma fácil y rápida si son simples caracteres alpha, es introducir un un `char []` en orden inverso:
  ``` char [] = "zyxwvutsrqponmlkjihgfedcba"``` y recorrerlo con un índice, es decir, cuando el índice `0` sea `a` su nuevo índice de `0` equivaldrá a `z`

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
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
```

## camel_to_snake

- Vamos a ir imprimiendo los caracteres si son minúsculas y cuando encuenntre una mayúscula imprima una barra baja y el misma letra en minúscula.

```
Nombre de la tarea: camel_to_snake
Archivos esperados: camel_to_snake.c
Funciones permitidas: malloc, free, realloc, write
-------------------------------------------------- ------------------------------

Escribe un programa que tome una sola cadena en formato lowerCamelCase
y lo convierte en una cadena en formato Snake_case.

Una cadena lowerCamelCase es una cadena donde cada palabra comienza con una letra mayúscula
excepto el primero.

Una cadena Snake_case es una cadena donde cada palabra está en minúsculas, separada por
un guión bajo "_".

Ejemplos:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
```

## do_op

- Programa sencillo, donde solo printeamos ya directamente la operación revisando con un condicional el argumento 2 ```printf("%d", (atoi(argv[1]) + atoi(argv[3])));```

``` 
Nombre de la tarea: do_op
Archivos esperados: *.c, *.h
Funciones permitidas: atoi, printf, write
-------------------------------------------------- ------------------------------

Escribe un programa que tenga tres cadenas:
- El primero y el tercero son representaciones de números enteros con signo de base 10.
  que caben en un int.
- El segundo es un operador aritmético elegido entre: + - * / %

El programa debe mostrar el resultado de la operación aritmética solicitada,
seguido de una nueva línea. Si el número de parámetros no es 3, el programa
solo muestra una nueva línea.

Puede asumir que la cadena no tiene errores ni caracteres extraños. Negativo
Los números, en entrada o salida, tendrán uno y solo un '-' inicial. El
El resultado de la operación cabe en un int.

Ejemplos:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
```
## ft_atoi

- Primer ```while``` para avanzar por el ```str++``` entre espacios o tabulacciones.
- Un ```ìf``` para identificar el flag de signo ```sign = -1```
- Otro ```ìf``` para el signo positivo avanzamos ```str++```
- Y ya hacemos la conversión con un ```while``` si son caracteres numéricos aplicamos nuestra fórmula ```result = result * 10 + *str - '0';```

```
Nombre de la asignación: ft_atoi
Archivos esperados: ft_atoi.c
Funciones permitidas: Ninguna
--------------------------------------------------------------------------------

Escriba una función que convierta el argumento de cadena str en un entero (tipo int)
y lo devuelva.

Funciona de forma muy similar a la función estándar atoi(const char *str), consulte el manual.

Su función debe declararse de la siguiente manera:

int ft_atoi(const char *str);
```

## ft_strcmp

- Un ```while``` que entrará s1 y s2 tengan contenido y sus índices sean iguales y vamos incrementando  ```while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])``` en el momento que dejen de ser iguales hacemos la operación de resultado ```return (s1[i] - s2[i]);```

```
Nombre de la asignación: ft_strcmp
Archivos esperados: ft_strcmp.c
Funciones permitidas:
--------------------------------------------------------------------------------

Reproduzca el comportamiento de la función strcmp (man strcmp).

Su función debe declararse de la siguiente manera:

int ft_strcmp(char *s1, char *s2);
```

## ft_strcspn

- Vamos a buscar la primera ocurrencia que se de en ```s[i]``` que esté contenido en ```reject[j]```
- Es decir ```ft_strcspn("Hola Wolrd", "xxxdxxxx"));``` en este ejemeplo devolverá el índice donde está la primera letra coincidente será el índice```[9]```
- Creamos 2 ```while``` anidados el externo recorrerá ```s[i] != '\0'``` y el interno ```reject[j] != '\0'```

```
Nombre de la asignación: ft_strcspn
Archivos esperados: ft_strcspn.c
Funciones permitidas: Ninguna
---------------------------------------------------------------

Reproduzca exactamente el comportamiento de la función strcspn
(man strcspn).

La función debe crearse como prototipo de la siguiente manera:

size_t ft_strcspn(const char *s, const char *reject);
```

## ft_strdup

- Crearemos un espacio de memoria para nuestro duplicado ```strcpy = malloc(sizeof(*strcpy) * (length + 1));``` y luego hacer la copia dentro de un while `src[i]` hasta su fin  `strcpy[i] = src[i];` sin olvidarnos de introducir el fin de string ```\0```
```
Nombre de la asignación: ft_strdup
Archivos esperados: ft_strdup.c
Funciones permitidas: malloc
--------------------------------------------------------------------------------

Reproduzca el comportamiento de la función strdup (man strdup).

Su función debe declararse de la siguiente manera:

char *ft_strdup(char *src);
```

## ft_strpbrk

- Si `!s1 || !s2` no existen salimos.
- Haremos dos `while` anidados el primero `*s1` y un segundo `s2[i]` donde compararemos `if(*s1 == s2[i])` y si son iguales `return (char *) s1;`

```
Nombre de la asignación: ft_strpbrk
Archivos esperados: ft_strpbrk.c
Funciones permitidas: Ninguna
---------------------------------------------------------------

Reproduzca exactamente el comportamiento de la función strpbrk
(man strpbrk).

La función debe crearse como prototipo de la siguiente manera:

char *ft_strpbrk(const char *s1, const char *s2);
```

## ft_strrev

- Creamos un `char temporary;`.
- Iteramos sobre `str` y conseguimos lu longitud `lenght`
- Y ya operamos dentro de nuestro `while (++i < length / 2)` desde `[0]` hasta la mitad de la longitud.
- Almacenamos en `temporary = str[i];`  y a continuacción almacenamos en `str[i] = str[length - 1 - i];` que será la diferencia de la longitud menos el incremento de `[i]` teniendo encuenta siempre un `-1` (ya que `lenght` siempre será uno más que el índice)
- Y finalmente volcamos el temporal sobre `str` de esta forma ```str[length - 1 - i] = temporary;```
  
```
Nombre de la asignación: ft_strrev
Archivos esperados: ft_strrev.c
Funciones permitidas:
--------------------------------------------------------------------------------

Escriba una función que invierta (en el lugar) una cadena.

Debe devolver su parámetro.

Su función debe declararse de la siguiente manera:

char *ft_strrev(char *str);
```
