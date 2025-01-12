# CÓDIGO COMPLETO ☝🏽 y subjects en las Carpetas

# "Pedacitos" de "Seudo-código" 👇🏽

- ***Después de que hayas practicado ya todo el código*** y los subjects, en las carpetas de este directorio  ☝🏽


- Os dejo "pedacitos" de **seudo-código** exencial de cada uno de los ejercicios:

 <h1> LEVEL 1 </h1>

 # :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket:

## first_word
```
while ( ==32 || ==9)
i++
while ( != 32 && != 9) && argv[1][i])
write (
```
## fizzbuzz
```
i % 3 == 0 && i % 5 == 0
   write(1, "fizzbuzz", 8)
else
   print_nb(i)

Función: print_nb(int i)

str[10] = "0123456789"
   (number > 9)
      print_nb(number / 10) // Recursividad
   write ( &str[number % 10]
```
## ft_putstr
```
while ( *str )
   write
```

## ft_strcpy
```
while ( s2[i] )
   s1[i] = s2[i]
s1[i] = '\0'
```

## ft_strlen
```
while ( str[i] )
   i++
```
## ft_swap
```
tmp = *a
*a = *b
*b = tmp
```
## repeat_alpha
```
rep = argv[1][i] - 'a' + 1
while (rep--)
   write(  &argv[1][i]
```
## rev_print
```
while ( str[i])
   i++
while (--lenght >= 0)
   write( &str[i]
```
## rot_13
```
c = argv[1][i];
if ( >= 'a' &&  <= 'm' )
   c = argv[1][i] + 13
if ( >= 'n' &&  <= 'z' )
   c = argv[1][i] - 13
write ( &c
```
## rotone
```
if ( >= 'a' &&  <= 'y' )
   c = 1
else if( == 'z'   )
   c = -25
c = argv[1][i] + c
write ( &c
```
## search_and_replace
```
if ( [1][i] == [2][0] )
   write( &[3][0]
```
## ulstr
```
if ( >= 'a' &&  <= 'z' )
   c = -32
if ( >= 'A' &&  <= 'Z' )
   c = 32
c = argv[1][i] + c;
write ( &c
```

 <h1> LEVEL 2 </h1>

 # :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket:

## alpha_mirror
```
if ( >= 'a' &&  <= 'z')
   c = 'a' + 'z' - argv[1][i]
   write ( &c
```

## camel_case
```
if ( >= 'A' && <= 'Z' )
   c = argv[1][i] + 32
   write ( " "
   write ( &c
```
## do_op
```
if ( [2][0] == '+' )
   printf ( atoi [1]  + atoi [3]
```
## atoi
int	ft_atoi(const char *str)
```
while( " ")
i++
   if ( + || - )
      if ( + )
         i++
       else
         i++
         sign = -1

while ( >= '0' && <= '9')
   number = 10 * number + (int)str[i] - '0'
   i++
```
## ft_strcmp
int    ft_strcmp(char *s1, char *s2)
```
while (s1[i] != '\0'  &&  s2[i] != '\0' && s1[i] == s2[i])
   i++
return (s1[i] - s2[i])
```

## ft_strcspn
size_t ft_strcspn(const char *s, const char *reject)
```
while (*s)
   while (reject[i] && *s != reject[i])
      i++
   if (reject[i] != '\0')
      return (count)
   i = 0
   count++
   s++;
```
## ft_strdup
char    *ft_strdup(char *src)
```
while (src[i] != '\0')
   i++
new = malloc((sizeof new) * i + 1)

   i = 0;
   while (src[i])
      new[i] = src [i]
      i++
   new[i] = '\0'
```

## ft_strpbrk
char	*ft_strpbrk(const char *s1, const char *s2)
```
if (!s1 || !s2)
   return(0)
while (s1[i])
   j = 0
   while (s2[j])
      if (s1[i] == s2[j])
         return ((char *)&s1[i]) // Retornamos la dirección de ese puntero
      j++
   }
   i++
 }
return(NULL)
```

## ft_strrev
char    *ft_strrev(char *str)
```
while (str[ln])
   ln++
ln = ln - 1
while (leinght >= i)
   tmp = str[ln]
   str[ln] = str[i]
   str[i] = tmp
   i++
   ln--
```
## ft_strspn
size_t	ft_strspn(const char *s, const char *accept)
```
while ( s[i] )
   while ( accept[j] )
      if ( s[i] == accept[j] )
        count++
        j = 0
        break
      }
      j++
   }
   i++
return ( count )
```
## inter
```
char rep[256] = {0}; // Plantilla para repetidos

while(argv[1][i] != '\0')
   j = 0
      while( [2][j] != '\0')
         if( [1][i] == [2][j] && rep[(int)argv[1][i]] == 0)
            write(  &argv[1][i]   )
            rep[(int)argv[1][i]] = 1 //  MARCADO - REPETIDO
         }
         j++
      }
      i++
```
## is_power_of_2
```
if (n == 0)
   return (0)
return (n & (n - 1)) == 0
```
## last_word
```
while([1][lenght])
   lenght++
   lenght = lenght -1
   while ([1][lenght] == ' ')
      lenght--
   end = lenght   // Marcador de fin de palabra
   while ([1][lenght] >=  33 && [1][lenght] <= 126)
      lenght--
   start = lenght+1  // Marcador inicio de palabra
   while ( start <= end )
      write (  &argv[1][start]
      start++
```
## max
int		max(int* tab, unsigned int len)
```
number = tab[0]
   while ( len )
      if ( number < tab[i] )
         number = tab[i]
      len--
      i++
```

## print_bits
void	print_bits(unsigned char octet)
```
while (i >=0)
   bit = (octet >> i & 1) + '0'
   write ( &bit
```
## reverse_bits
unsigned char	reverse_bits(unsigned char octet)
```
while ( i >= 0 )
   result = ( result * 2 + (octet % 2) )
   octet = octet / 2
```
## snake_to_camel
```
if(argv[1][i] == '_')
   i++
   argv[1][i] = argv[1][i] - 32
   write ( &argv[1][i]
```
## swap_bits
```
return ((octet >> 4) | (octet << 4))
```
## union
```
char rep[256] = {0}; // Plantilla para marcar repetidos

while ( [1][i] != '\0' )
   if(!rep[(int)argv[1][i]])
      rep[(int)argv[1][i]] = 1 // Marcamos repetido en [1]
      write( &argv[1][i]
   i++

while ( [2][j] != '\0' )
   if(!rep[(int)argv[2][j]])
      rep[(int)argv[2][j]] = 1 Marcamos repetido en [2]
      write( &argv[2][j]
   j++
```
## wdmatch
```
while (  [2][j] != '\0' )
   if (argv[1][i] == argv[2][j])
      i++
   j++

   if (  [1][i] == '\0')
      i = 0;
      while ( [1][i])
         write ( &argv[1][i]
         i++
```

 <h1> LEVEL 3 </h1>

  # :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket: :rocket:


# add_prine_sum

```
--> creamos atoi:
int	ft_atoi(char *s)

--> creamos put_nbr:
void	put_nbr(int n)

--> creamos is_prime:
int	is_prime(int num)
{
   int	i = 2

   if (num <= 1)
      return (0)
   // solo se prueben divisores hasta la raíz cuadrada de num
	while (i * i <= num)
	{
           if (num % i == 0) // si es divisible entre i, NO es primo
              return (0)
           i++
	}
	return (1)

--> main:

	while (nbr > 0)
		if ( is_prime(nbr) ) // Si es (true  (1))
			sum = sum + nbr
		nbr--
	put_nbr(sum)

if (ac != 2)
	put_nbr(0)


```

# epur_str

```
while (  ' '||  '\t' )
   i++
   while( [1][i] )
      if( == ' ' ||  == '\t')
         flag = 1
      if( != ' ' ||  != '\t')
         if(flag == 1)
            write ( " "
         write( [1][i]
         flag = 0
      }
      i++
```

# expand_str
Es igual al anterior pero dejando "3 espacios"
```
while (  ' '||  '\t' )
   i++
   while( [1][i] )
      if( == ' ' ||  == '\t')
         flag = 1
      if( != ' ' ||  != '\t')
         if(flag == 1)
            write ( "   " // 3 ESPACIOS
         write( [1][i]
         flag = 0
      }
      i++
```
# atoi_base
igual al atoi pero con base segun el ejercicio hasta base 16:

```
if( >= '0' &&  <= '9')
   c = str[i] - '0'

else if( >= 'a' && <= 'f')
   c = str[i] - 'a' + 10
.......
...
else
   break
result = result * str_base + c

```
# ft_list_size

```
while ( begin_list->next )
   size++
   begin_list = begin_list->next
```
# ft_range
int	*ft_range(int start, int end)
```
dist = abs( end - start ) + 1
   array = (int *)malloc((sizeof int) * dist)

   if ( start < end )
      while(start <= end)
         array[i] = start
         i++
         start++
   else
     lo contrario si start > end
```

# ft_rrange
int	*ft_rrange(int start, int end)

```
dist = abs(end - start) + 1
   array = malloc((sizeof array) * dist)

   if (end > start)
      while(start <= end)
         array[i] = end
         end--
         i++
    else
       lo contrario si end < start

```

# hidenp

```
while ( [1][i] != '\0')

   while ( [2][j] != '\0')
      if ( [1][i] ==  [2][j])
         break
      j++
   i++

   if ( [2][j] == '\0' &&  [1][i] == '\0')
      write( "0"
      write( "\n"
      return(0)
   write ( "1"

```

# lcm
unsigned int lcm(unsigned int a, unsigned int b)

```
if (a == 0 || b == 0) Si son iguales el lcm = mcm es 0
   return ( 0 )

if (a > b) Dependemos si a o b uno es mayor que el otro
   n = a
else
   n = b

while (1)
   if (n % a == 0 && n % b == 0)
      return (n)
   ++n
```

# paramsum

```
creamos la funcion putnbr:
ft_putnbr:

   if(nb >= 10)
      ft_putnbr(nb / 10); ** RECURSIVIDAD **
   c = nb % 10 + '0'   conversión int a ascii
   write ( &c
}


main:
   if(argc >= 2)
      ft_putnbr(argc - 1) Enviamos el nº de Argumentos
   else
      write(  "0"
```

# pgcd
```
Creamos la función gcd (MCD  Máximo Común Divisor):

void ft_gcd(int a, int b)
{

gcd = 1

if (a > b)
   n = a
else
    n = b

while (1)
   if ( n % b == 0 && n % a == 0 )
      printf("%d", n)
      break
   n++

main:

if(argc == 3)
   ft_gcd ( atoi( argv[1] ), atoi( argv[2] ))
      printf("\n")

```

# print_hex

```
--> creamos la impresion en base 16:

void print_hex(int nb)

char hex[]="0123456789abcdef"
if(nb >= 16)
   print_hex(nb / 16)
write(  &hex[nb % 16]

--> un atoi:

int ft_atoi(char *str)

--> main:
 print_hex(ft_atoi(argv[1]))

```

# rstr_capitalizer

```
while(argv[i])

   j = 0
   while(argv[i][j])

      if ( [i][j] >= 'A' &&  [i][j] <= 'Z') && [i][j + 1] != ' ')
         argv[i][j] = argv[i][j] + 32

      if ( [i][j] >= 'a' && [i][j] <= 'z') && [i][j + 1] == ' ' || [i][j + 1] == '\0')
         argv[i][j] = argv[i][j] - 32

      write( &argv[i][j]
      j++
   write(1, "\n", 1)
   i++
```

# str_capitalizer
```
while(argv[i])
   j = 0
   while(  argv[i][j]  )
      if([i][j] >= 'A' &&  [i][j] <= 'Z')
         [i][j] =  [i][j] + 32

      if(([i][j] >= 'a' && [i][j] <= 'z') && [i][j - 1] == ' ')
         [i][j] = [i][j] - 32

      if([i][0] >= 'a' && [i][0] <= 'z')
         [i][j] = [i][j] - 32

      write(   &argv[i][j]
      j++
   write( "\n"
   i++
```
# tab_mult

```
--> Creamos un atoi:
int	atoi(char *str)

--> un strlen:
int ft_strlen(char *str)

--> un put_nbr:
void put_nbr(int nb)  ** Funcion recursiva **

--> main:

number = x_atoi(argv[1])
while(i < 10)

   c = i + '0'
   result = i * number
   write(1, &c, 1)
   write(  " x "

   str = argv[1]
   write(1,  str,  ft_strlen( argv[1] ))
   write( " = "

   put_nbr(result)
   write(  "\n"

   i++

```
