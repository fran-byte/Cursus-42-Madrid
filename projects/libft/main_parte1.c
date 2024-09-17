#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {       
        printf("Funciones disponibles: ft_strlen, ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_strlcpy, ft_strlcat, ft_toupper, ft_tolower, ft_strchr, ft_strrchr, ft_strncmp, ft_memchr, ft_memcmp, ft_strnstr, ft_atoi, ft_strdup, ft_calloc\n");
        return 1;
    }
//ft_strlen
    if (ft_strcmp(argv[1], "ft_strlen") == 0)
    {        
        printf("Testeando ft_strlen:\n");
        printf("Test 1: string vacía\n");
        printf("Resultado: %u\n", ft_strlen(""));
        printf("Test 2: string normal\n");
        printf("Resultado: %u\n", ft_strlen("Hello, World!"));
        printf("Test 3: string con caracteres especiales\n");
        printf("Resultado: %u\n", ft_strlen("!!@#$#^*&*()"));
    }
//ft_memset    
    else if (ft_strcmp(argv[1], "ft_memset") == 0) 
    {        
        char buf[50] = "Hello, World!";
        printf("Testeando ft_memset:\n");
        printf("Test 1: Rellenar con un carácter\n");
        ft_memset(buf, '*', 5);
        printf("Resultado: %s\n", buf);
        printf("Test 2: Rellenar con un carácter en una string vacía\n");
        char buf2[50] = "";
        ft_memset(buf2, 'a', 3);
        printf("Resultado: %s\n", buf2);
    }
//ft_bzero	
	else if (ft_strcmp(argv[1], "ft_bzero") == 0)
	{        
        char buf[50] = "Hello, World!";
        printf("Testeando ft_bzero:\n");
        ft_bzero(buf, 5);
        printf("Resultado: %s\n", buf);
    }
//ft_memcpy
	else if (ft_strcmp(argv[1], "ft_memcpy") == 0)
	{        
        char dest[50];
        const char src[] = "Hello, World!";
        printf("Testeando ft_memcpy:\n");
        printf("Test 1: Copiar parte de la string\n");
        ft_memcpy(dest, src, 5);
        dest[5] = '\0'; // Ojo! con esto nos aseguramos de que la string esté terminada
        printf("Resultado: %s\n", dest);
    }
//ft_memmove
	else if (ft_strcmp(argv[1], "ft_memmove") == 0)
	{        
        char buf[50] = "Hello, World!";
        printf("Testeando ft_memmove:\n");
        printf("Test 1: Mover parte de la string\n");
        ft_memmove(buf + 6, buf, 5);
        buf[11] = '\0'; // Ojo! con esto nos aseguramos de que la string esté terminada
        printf("Resultado: %s\n", buf);
    }
//ft_strlcpy	
	else if (ft_strcmp(argv[1], "ft_strlcpy") == 0)
	{        
        char dest[50];
        const char src[] = "Hello, World!";
        printf("Testeando ft_strlcpy:\n");
        printf("Test 1: Copiar string completa\n");
        printf("Resultado: %u\n", ft_strlcpy(dest, src, sizeof(dest)));
        printf("Destino: %s\n", dest);
        printf("Test 2: Copiar con tamaño menor\n");
        printf("Resultado: %u\n", ft_strlcpy(dest, src, 5));
        printf("Destino: %s\n", dest);
    }
//ft_strlcat	
	else if (ft_strcmp(argv[1], "ft_strlcat") == 0)
	{     
        char dest[50] = "Hello, ";
        const char src[] = "World!";
        printf("Testeando ft_strlcat:\n");
        printf("Test 1: Concatenar string\n");
        printf("Resultado: %u\n", ft_strlcat(dest, src, sizeof(dest)));
        printf("Destino: %s\n", dest);
    }
//ft_toupper	
	else if (ft_strcmp(argv[1], "ft_toupper") == 0)
	{        
        printf("Testeando ft_toupper:\n");
        printf("Test 1: Convertir minúscula a mayúscula\n");
        printf("Resultado: %c\n", ft_toupper('a'));
        printf("Test 2: Carácter ya en mayúscula\n");
        printf("Resultado: %c\n", ft_toupper('A'));
    }
//ft_tolower	
	else if (ft_strcmp(argv[1], "ft_tolower") == 0)
	{
        
        printf("Testeando ft_tolower:\n");
        printf("Test 1: Convertir mayúscula a minúscula\n");
        printf("Resultado: %c\n", ft_tolower('A'));
        printf("Test 2: Carácter ya en minúscula\n");
        printf("Resultado: %c\n", ft_tolower('a'));
    }
//ft_strchr	
	else if (ft_strcmp(argv[1], "ft_strchr") == 0)
	{        
        printf("Testeando ft_strchr:\n");
        printf("Test 1: Encontrar carácter\n");
        printf("Resultado: %s\n", ft_strchr("Hello, World!", 'W'));
        printf("Test 2: Carácter no encontrado\n");
        printf("Resultado: %s\n", ft_strchr("Hello, World!", 'z'));
    }
//ft_strrchr	
	else if (ft_strcmp(argv[1], "ft_strrchr") == 0)
	{        
        printf("Testeando ft_strrchr:\n");
        printf("Test 1: Encontrar último carácter\n");
        printf("Resultado: %s\n", ft_strrchr("Hello, World!", 'o'));
        printf("Test 2: Carácter no encontrado\n");
        printf("Resultado: %s\n", ft_strrchr("Hello, World!", 'z'));
    }
//ft_strncmp
	else if (ft_strcmp(argv[1], "ft_strncmp") == 0)
	{        
        printf("Testeando ft_strncmp:\n");
        printf("Test 1: Comparar strings iguales hasta n\n");
        printf("Resultado: %d\n", ft_strncmp("Hello", "Hello", 5));
        printf("Test 2: Comparar strings donde s1 es menor\n");
        printf("Resultado: %d\n", ft_strncmp("Hello", "World", 5));
        printf("Test 3: Comparar strings donde s1 es mayor\n");
        printf("Resultado: %d\n", ft_strncmp("World", "Hello", 5));
        printf("Test 4: Comparar strings vacías\n");
        printf("Resultado: %d\n", ft_strncmp("", "", 4));
    }
//ft_memchr	
	else if (ft_strcmp(argv[1], "ft_memchr") == 0)
	{        
        const char buf[] = "Hello, World!";
        printf("Testeando ft_memchr:\n");
        printf("Test 1: Encontrar carácter\n");
        printf("Resultado: %s\n", (char *)ft_memchr(buf, 'W', sizeof(buf)));
        printf("Test 2: Carácter no encontrado\n");
        printf("Resultado: %s\n", (char *)ft_memchr(buf, 'z', sizeof(buf)));
    }
//ft_memcmp	
	else if (ft_strcmp(argv[1], "ft_memcmp") == 0)
	{        
        const char buf1[] = "Hello";
        const char buf2[] = "Hellz";
        printf("Testeando ft_memcmp:\n");
        printf("Test 1: Comparar memoria\n");
        printf("Resultado: %d\n", ft_memcmp(buf1, buf2, 5));
        printf("Test 2: Comparar memoria con contenido igual\n");
        printf("Resultado: %d\n", ft_memcmp(buf1, buf1, 5));
    } 
//ft_strnstr	
	else if (ft_strcmp(argv[1], "ft_strnstr") == 0)
	{       
        printf("Testeando ft_strnstr:\n");
        printf("Test 1: Encontrar substring\n");
        printf("Resultado: %s\n", ft_strnstr("Hello, World!", "World", 12));
        printf("Test 2: Substring no encontrada\n");
        printf("Resultado: %s\n", ft_strnstr("Hello, World!", "Earth", 12));
    }
	else if (ft_strcmp(argv[1], "ft_atoi") == 0)
//ft_atoi	
	{       
        printf("Testeando ft_atoi:\n");
        printf("Test 1: string normal\n");
        printf("Resultado: %d\n", ft_atoi("12345"));
        printf("Test 2: string con espacios\n");
        printf("Resultado: %d\n", ft_atoi("   6789"));
        printf("Test 3: string con caracteres no numéricos\n");
        printf("Resultado: %d\n", ft_atoi("42abc"));
    }
//ft_strdup	
	else if (ft_strcmp(argv[1], "ft_strdup") == 0)
	{        
        printf("Testeando ft_strdup:\n");
        char *dup1 = ft_strdup("Hello, World!");
        printf("Resultado: %s\n", dup1);
        free(dup1);
        printf("Test 2: string vacía\n");
        char *dup2 = ft_strdup("");
        printf("Resultado: %s\n", dup2);
        free(dup2);
    }
//ft_calloc	
	else if (ft_strcmp(argv[1], "ft_calloc") == 0)
	{        
        printf("Testeando ft_calloc:\n");
        int *arr = (int *)ft_calloc(5, sizeof(int));
        if (arr) {
            for (int i = 0; i < 5; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
            free(arr);
        }
        printf("Test 2: Tamaño cero\n");
        char *zero_size = (char *)ft_calloc(0, 10);
        printf("Resultado: %p\n", zero_size);
        free(zero_size);
    }
    else 
    {
        printf("ft_Función no reconocida.\n");
        return 1;
    }
    return 0;
}
