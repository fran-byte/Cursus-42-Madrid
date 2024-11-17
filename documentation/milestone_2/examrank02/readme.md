
<h1 align="center" width="100%">Recursos para ExamRank02</h1>


<p align="center" width="100%"><img src="../examrank02.png" width="102" />
 <h3 align="center">👉 <a href="readme.md#spoiler-level-3">Spolier Level 3</a> 👈 - 👉 <a href="#">Spolier Level 4</a> 👈</h3>

- Simplemente haré un repaso a los puntos esenciles de cada ejercicio omitiendo el Level 1.
# Level 2

## alpha_mirror
- Forma fácil y rápida si son simples caracteres alpha, es introducir un un `char []` en orden inverso:
  ``` char [] = "zyxwvutsrqponmlkjihgfedcba"``` y recorrerlo con un índice, es decir, cuando el índice `0` sea `a` su nuevo índice de `0` equivaldrá a `z`

```text  
Nombre de la tarea: alpha_mirror
Archivos esperados: alpha_mirror.c
Funciones permitidas: write
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

- Vamos a ir imprimiendo los caracteres si son minúsculas y cuando encuentre una mayúscula imprima una barra baja y la misma letra en minúscula.

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

- Un ```while``` que entrará en él cuando s1 y s2 tengan contenido y sus índices sean iguales, entonces vamos incrementando  ```while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])``` en el momento que dejen de ser iguales hacemos la operación de resultado ```return (s1[i] - s2[i]);```

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
- Y finalmente volcamos el temporal sobre `str` de esta forma ```str[length - 1 - i] = temporary;``` que será el string a devolver.
  
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
## ft_strspn

- Esta función calcula la longitud del segmento inicial de `s` que consta únicamente de caracteres en `accept`.
- Es decir el índice de `s` del primer caracter que difiera de  `accept` si son todos iguales devolverá el indice completo de iterar `s`
- En esta comparación ft_strspn("Hola mundo", "Hola Mundo"); nos devolverá el indice dode está `m` es decir `s[5]`

- Podemos crear dos funciones una `principal size_t	ft_strspn(const char *s, const char *accept);` donde iteraremos sobre nuestra string `s` hasta encontrar en accept `if (ft_strchr(accept, s[i]) == 0)` ese caracter de `s[i]` para ello llamamos a la función `ft_strchr` que nos de volverá algo diferente a 0 cuando lo encuentre y en ese momento haremos un `break`para salirnos del `while` y ese índice es el que devolveremos.

```
Nombre de la tarea: ft_strspn
Archivos esperados: ft_strspn.c
Funciones permitidas: Ninguna
-------------------------------------------------- -------------

Reproducir exactamente el comportamiento de la función strspn. 
(man strspn).

La función debe crearse un prototipo de la siguiente manera:

size_t	ft_strspn(const char *s, const char *accept);
```
## inter

- Para llevar el control de los caracteres impresos y no volver a imprimir un repetido, creamos esta array de chars unsigned char `is_repeat[256] = {0};` y lo inicializamos a `0`
- Ahora crearemos dos `while` anidados el exterior `while(s1[i] != '\0')` iterará sobre `s1` dentro tendremos una condicional que dará paso a otro while si se cumple `if (s1[i] == s2[j])` y dentro de este a su vez una condicional más `if (is_repeat[s1[i]] != 1)` que veremos si `is_repeat`fue modificado o no si permanece en `0` es que ese caracter no es repetido y lo imprimiremos y asignaremos a esa posición un `1` para no volver a repetirla `is_repeat[s1[i]] = 1;` 

```
Nombre de la tarea: inter
Archivos esperados: inter.c
Funciones permitidas: write
-------------------------------------------------- ------------------------------

Escriba un programa que tome dos cadenas y muestre, sin dobles, el
caracteres que aparecen en ambas cadenas, en el orden en que aparecen en la primera
cadena.

Se printará seguido por un \n.

Si el número de argumentos no es 2, el programa muestra \n.

Ejemplos:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
```

## is_power_of_2

- Para este ejercicio solo tener encuenta esta formula ```return (n & (n - 1)) == 0;``` y un caso base si number = 0, retornaremos 0.
- Donde restamos a number -1 y 

```
Nombre de la tarea: is_power_of_2
Archivos esperados: is_power_of_2.c
Funciones permitidas: Ninguna
-------------------------------------------------- ------------------------------

Escribe una función que determine si un número dado es una potencia de 2.

Esta función devuelve 1 si el número dado es una potencia de 2; en caso contrario, devuelve 0.

Su función debe declararse de la siguiente manera:
int	    is_power_of_2(unsigned int n);
```

## last_word

- El código tendrá dos `while (str[i])`  con una condición `if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)` que viene a ser, que mientras encuentre un ```str[i] == " "``` y ```[i+1]``` sea ascii imprimible alojaremos en ```j = i + 1``` (es decir j será el inicio de la palabra) con esto conseguiremos mientras iteramos sobre ```str[i]``` dejar en `j` el índice dde la última palabra.
- Y ya teniendo este índice vamos a recorrer j ``` str[j] >= 33 && str[j] <= 127 ``` mientras sea imprimible e iremos imprimiendo.
```
Nombre de la tarea: last_word
Archivos esperados: last_word.c
Funciones permitidas: write
-------------------------------------------------- ---------------------

Escriba un programa que tome una cadena y muestre su última palabra seguida de \n.

Una palabra es una sección de cadena delimitada por espacios/tabulaciones o por el inicio/final de
la cuerda.

Si el número de parámetros no es 1 o no hay palabras, muestre una nueva línea.

Ejemplo:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
```
## max

- Para conseguir el número mayor del array de enteros utilizaremos una variable ```int result;``` donde iremos dejando en una iteración cada  ```tab[i]``` solo en el caso que ```result``` sea menor que ```tab[i]```, es decir solo se irá almacenado en ```result``` el número mayor.


```
Nombre de la tarea: max.
Archivos esperados: max.c
Funciones permitidas:
-------------------------------------------------- ------------------------------

Escribe la siguiente función:

int max(int* tab, unsigned int len);

El primer parámetro es una matriz de int, el segundo es el número de elementos en
la matriz.

La función devuelve el número más grande encontrado en la matriz.

Si la matriz está vacía, la función devuelve 0.
```

## print_bits

- Un **byte** (`char`) tiene 8 bits, por lo que usaremos un contador `int i = 8;` para recorrerlos y una variable `unsigned char bit;` para almacenar cada bit.  

- La idea es usar un bucle `while` que decremente `i` de 8 a 0. En cada iteración, aplicamos un desplazamiento de bits (`>>`) para mover el bit que queremos analizar al extremo menos significativo, seguido de una operación AND (`& 1`) para aislarlo.  

- La expresión clave es:  
```c
bit = (octet >> i & 1) + '0';
```  
- Esto extrae el bit correspondiente y lo convierte a su representación ASCII ('0' o '1') para imprimirlo. Así, procesamos e imprimimos todos los bits del byte uno por uno. 

```
Nombre de la tarea: print_bits
Archivos esperados: print_bits.c
Funciones permitidas: write
-------------------------------------------------- ------------------------------

Escribe una función que tome un byte y lo imprima en binario SIN UNA NUEVA LÍNEA
AL FINAL.

Su función debe declararse de la siguiente manera:

void print_bits (unsigned char octet);

Ejemplo, si pasa 2 a print_bits, imprimirá "00000010"
```
## reverse_bits

- Invierte los bits de un **byte**. Usamos `result` para almacenar el resultado y una iteracion de 8 veces.
- En cada iteración:  
- Extraemos el bit menos significativo de `octet` con `(octet % 2)` y lo añadimos a `result` desplazándolo.  
- Eliminamos ese bit de `octet` con `octet / 2`.
- Y al acabar `result` tiene los bits en orden  inverso.

```
Nombre de la asignación: reverse_bits
Archivos esperados: reverse_bits.c
Funciones permitidas:
-------------------------------------------------- ------------------------------

Escribe una función que tome un byte, lo invierta, poco a poco (como la
ejemplo) y devuelve el resultado.

Su función debe declararse de la siguiente manera:

unsigned char	reverse_bits(unsigned char octet);

Ejemplo:

  1 byte
_____________
 0100 0001
     ||
     \/
 1000 0010
```
## snake_to_camel

- Simplemente dentro de un ```while``` cuando localicemos un "_" incrementamos el índice y convertimos a mayúsculas ese caracter ```argv[1][i] = argv[1][i] - 32;```

```
Nombre de la tarea: snake_to_camel
Archivos esperados: snake_to_camel.c
Funciones permitidas: malloc, free, realloc, write
-------------------------------------------------- ------------------------------

Escribe un programa que tome una sola cadena en formato Snake_case
y lo convierte en una cadena en formato lowerCamelCase.

Una cadena Snake_case es una cadena donde cada palabra está en minúsculas, separada por
un guión bajo "_".

Una cadena lowerCamelCase es una cadena donde cada palabra comienza con una letra mayúscula
excepto el primero.
Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$
```
## swap_bits

- Hacemos simples movimientos de desplazamiento de bits ```return ((octet >> 4) | (octet << 4));```

```
Nombre de la tarea: swap_bits
Archivos esperados: swap_bits.c
Funciones permitidas:
-------------------------------------------------- ------------------------------

Escribe una función que tome un byte, intercambie sus mitades (como en el ejemplo) y
devuelve el resultado.

Su función debe declararse de la siguiente manera:

swap_bits de caracteres sin firmar unsigned char swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
```

## union

- Concatena los caracteres de ambas cadenas, asegurándose de imprimir cada carácter solo una vez, en el orden en que aparece por primera vez.
- Usamos un arreglo de 256 elementos marcando así los impresos ```unsigned char seen[256] = {0};```
- Recorre el primer while ```(av[1][i])``` y si ```!seen[(unsigned char)av[1][i]]``` quiere decir que si en ese índice de `seen` no fue visto escribios con write y marcamos como visto y hacemos exactamente lo mismo lo mismo para el segundo while ```(av[2][j])```, ```!seen[(unsigned char)av[2][j]])```
- Si un carácter no ha sido visto previamente, lo imprime y marca como visto. Al marcarlos hay que castearlos a un char ```seen[(unsigned char)av[2][j]] = 1;``` para indexar correctamente el arreglo seen[]

```
Nombre de la tarea: union
Archivos esperados: union.c
Funciones permitidas: write
-------------------------------------------------- ------------------------------

Escriba un programa que tome dos cadenas y muestre, sin dobles, los
caracteres que aparecen en cualquiera de las cadenas.

La pantalla se mostrará en el orden en que aparecen los caracteres en la línea de comando y
irá seguido de un \n.

Si el número de argumentos no es 2, el programa muestra \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
```

<h3 align="center">👉 <a href="readme.md#level-2">Spolier Level 2</a> 👈 - 👉 <a href="#">Spolier Level 4</a> 👈</h3>

## Spoiler Level 3
