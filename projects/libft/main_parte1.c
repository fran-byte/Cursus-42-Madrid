#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
/*
// Definición de la estructura t_list
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

// Prototipos de funciones
t_list *lstnew(void *content);
void test_memset();
void test_bzero();
void test_memcpy();
void test_memmove();
void test_strlcpy();
void test_strlcat();
void test_toupper();
void test_tolower();
void test_strchr();
void test_strrchr();
void test_strncmp();
void test_memchr();
void test_memcmp();
void test_strlen();
void test_strdup();
void test_strnstr();
void test_atoi();
void test_calloc();
void test_substr();
void test_strjoin();
void test_strtrim();
void test_split();
void test_itoa();
void test_strmapi();
void test_striteri();
void test_putchar_fd();
void test_putstr_fd();
void test_putendl_fd();
void test_putnbr_fd();
void test_lstnew();
void test_lstadd_front();
void test_lstsize();
void test_lstlast();
void test_lstadd_back();
void test_lstdelone();
void test_lstclear();
void test_lstiter();
void test_lstmap();
*/
// Implementaciones
// isalpha: Prueba si un carácter es alfabético
void test_isalpha() {
    printf("Probando isalpha:\n");
    printf("isalpha('A'): %d\n", isalpha('A'));
    printf("isalpha('1'): %d\n", isalpha('1'));
}

// isdigit: Prueba si un carácter es un dígito
void test_isdigit() {
    printf("Probando isdigit:\n");
    printf("isdigit('5'): %d\n", isdigit('5'));
    printf("isdigit('f'): %d\n", isdigit('f'));
}
// isalnum: Prueba si un carácter es un dígito o carácter es alfabético (TESTEAR DE NUEVO)
void test_isalnum() {
    printf("Probando isalnum:\n");
    printf("isalnum('5'): %d\n", isalnum('5'));
    printf("isalnum('f'): %d\n", isalnum('f'));
    printf("isalnum('?'): %d\n", isalnum('?'));
}
// isdigit: Prueba si un carácter es un isascii
void test_isascii() {
    printf("Probando isdigit:\n");
    printf("isascii('5'): %d\n", isascii('5'));
    printf("isascii('f'): %d\n", isascii('f'));
}
// isdigit: Prueba si un carácter imprimible
void test_isprint() {
    printf("Probando isdigit:\n");
    printf("isprint('5'): %d\n", isprint('5'));
    printf("isprint('barra inv n'): %d\n", isprint('\n'));
}

// strlen: Prueba la longitud de una cadena
void test_strlen() {
    const char *str = "Hola mundo 42!";
    printf("Probando strlen:\n");
    printf("strlen(\"%s\"): %zu\n", str, strlen(str));
}

// memset: Prueba la función memset
void test_memset() {
    char str[50] = "Hola Mundo 42!!";
    printf("Probando memset:\n");    
    printf("Nuestra string: %s\n", str);
    memset(str, '*', 5);
    printf("Sobre escribimos con '*' hasta el indice 5: %s\n", str);
}

// bzero: Prueba la función bzero
void test_bzero() {
    char str[50] = "Hola Mundo 42!!";
    printf("Probando bzero:\n");    
    printf("Nuestra string: %s\n", str);
    bzero(str, 5);
    printf("Sobre escribimos con '0' hasta el indice 5: %s\n", str);
}

// memcpy: Prueba la función memcpy
void test_memcpy() {
    char src[50] = "Hola Mundo 42!!";
    char dest[50];
    printf("Probando memcpy:\n");
    printf("Nuestra string: %s\n", src);
    memcpy(dest, src, strlen(src) + 1);
    printf("Resultado: %s\n", dest);
}

// memcpy: Prueba la función memmove
void test_memmove() {
    char str[50] = "Hola Mundo 42!!";
    printf("Probando memmove:\n");    
    printf("Nuestra string: %s\n", str);
    printf("memmove(str + 5, str, strlen(str) - 5)\n");
    printf("Mueve la parte de la cadena hacia la derecha\n");
    memmove(str + 5, str, strlen(str) - 5); 
    printf("Resultado: %s\n", str);
}

// calloc: Prueba la función calloc
void test_calloc() {
    int i = 0;    
    int *arr = (int *)calloc(5, sizeof(int));
    printf("Probando calloc:\n");
    while(i < 5)
    {       
        printf("arr[%d] = %d\n", i, arr[i]);
         i++;
    }
    free(arr);
}

// strdup: Prueba la función strdup
void test_strdup() {    
    char *str = "Cadena a duplicar";   
    char *duplicated = strdup(str);
    printf("Probando strdup:\n");
    printf("Cadena original: %s\n", str);
    printf("Cadena duplicada: %s\n", duplicated);
    free(duplicated);
}

// atoi: Prueba la función atoi
void test_atoi() {    
    char *num_str = "123459";
    char *neg_num_str = "-9576";
    char *invalid_num_str = "12asd34";
    printf("Probando atoi:\n");
    printf("atoi(\"%s\") = %d\n", num_str, atoi(num_str));
    printf("atoi(\"%s\") = %d\n", neg_num_str, atoi(neg_num_str));
    printf("atoi(\"%s\") = %d\n", invalid_num_str, atoi(invalid_num_str));
}
/*
// strlcpy: Prueba la función strlcpy
void test_strlcpy() {
    printf("Probando strlcpy:\n");
    char src[] = "Texto de origen";
    char dest[20];
    size_t result = strlcpy(dest, src, sizeof(dest));
    printf("Resultado de strlcpy: %zu\n", result);
    printf("Destino: %s\n", dest);
}

// strlcat: Prueba la función strlcat
void test_strlcat() {
    printf("Probando strlcat:\n");
    char dest[30] = "Hola";
    char src[] = " Mundo!";
    size_t result = strlcat(dest, src, sizeof(dest));
    printf("Resultado de strlcat: %zu\n", result);
    printf("Destino: %s\n", dest);
}
*/
// toupper: Prueba la función toupper
void test_toupper() {
    char c = 'a';
    printf("Probando toupper:\n");    
    printf("toupper('%c') = %c\n", c, toupper(c));
}

// tolower: Prueba la función tolower
void test_tolower() {
    char c = 'A';
    printf("Probando tolower:\n");    
    printf("tolower('%c') = %c\n", c, tolower(c));
}

// strchr: Prueba la función strchr
void test_strchr() {
    char str[] = "Hola, mundo";
    char *result = strchr(str, 'm');
    printf("Probando strchr:\n");
    if (result) {
        printf("Buscando primer caracter 'm' en: 'Hola, mundo'\n");
        printf("Primero: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// strrchr: Prueba la función strrchr
void test_strrchr() {
    char str[] = "Hello, World!!";
    char *result = strrchr(str, 'o');
    printf("Probando strrchr:\n");
    printf("Buscando último caracter 'o' en: 'Hello, World!!'\n");
    if (result) {
        printf("Último: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// strncmp: Prueba la función strncmp
void test_strncmp() {
    char *str1 = "Hola";
    char *str2 = "Hola42Madrid";
    printf("str1: 'Hola'\n");
    printf("str2: 'Hola42Madrid'\n");
    printf("Probando strncmp:\n");
    printf("strncmp(str1, str2, 4) = %d\n", strncmp(str1, str2, 4));
    printf("strncmp(str1, str2, 6) = %d\n", strncmp(str1, str2, 6));
}

// memchr: Prueba la función memchr
void test_memchr() {
    char str[] = "Hola42Madrid";
    char *result = memchr(str, '4', strlen(str));
    printf("Probando memchr:\n");
    printf("str: 'Hola42Madrid'\n");
    printf("memchr(str, '4', strlen(str))");
    if (result) {
        printf("\nEncontrado: '4' %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// memcmp: Prueba la función memcmp
void test_memcmp() {    
    char *str1 = "Hola42Madrid";
    char *str2 = "Hola42Madrid";
    char *str3 = "Hola43";
    printf("Probando memcmp:\n");
    printf("\n*str1 = \"Hola42Madrid\"");
    printf("\n*str2 = \"Hola42Madrid\"");
    printf("\n*str3 = \"Hola43\"\n");
    printf("memcmp(str1, str2, 4) = %d\n", memcmp(str1, str2, 4));
    printf("memcmp(str1, str3, 6) = %d\n", memcmp(str1, str3, 6));
}
/*
// strnstr: Prueba la función strnstr
void test_strnstr() {    
    char *str = "Este es un ejemplo";
    char *substr = "un";
    char *result = strnstr(str, substr, strlen(str));
    printf("Probando strnstr:\n");
    if (result) {
        printf("Encontrado: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// substr: Prueba la función substr
void test_substr() {    
    char *str = "Hola mundo";
    char *sub = substr(str + 5, 5);  // "mundo"
    printf("Probando substr:\n");
    printf("Subcadena: %s\n", sub);
    free(sub);
}

// strjoin: Prueba la función strjoin
void test_strjoin() {

}


// strtrim: Prueba la función strtrim
void test_strtrim() {    
    char *str = "   Hola mundo   ";
    char *trimmed = str + 3; // Simulación de recortar los espacios de inicio y fin
    printf("Probando strtrim:\n");
    trimmed[strlen(trimmed) - 3] = '\0';  // Simulación de recortar el final
    printf("Cadena recortada: '%s'\n", trimmed);
}

// split: Prueba la función split
void test_split() {
    printf("Probando split:\n");
    char *str = "Hola mundo de C";
    char *token = strtok(str, " ");
    while (token) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }
}

// itoa: Prueba la función itoa
void test_itoa() {    
    int num = 12345;
    char buffer[20];
    printf("Probando itoa:\n");
    printf("Probando itoa:\n");
    snprintf(buffer, sizeof(buffer), "%d", num);  // Simulación de itoa
    printf("itoa(%d) = %s\n", num, buffer);
}

// strmapi: Prueba la función strmapi
void test_strmapi() {
    printf("Probando strmapi:\n");
    char *str = "abc";
    char *mapped = strdup(str);
    for (int i = 0; mapped[i]; i++) {
        mapped[i] = mapped[i] + 1;  // Simple modificación de la cadena
    }
    printf("Cadena modificada: %s\n", mapped);
    free(mapped);
}

// striteri: Prueba la función striteri
void test_striteri() {
    printf("Probando striteri:\n");
    char str[] = "abc";
    for (int i = 0; str[i]; i++) {
        str[i] = str[i] + i;  // Modificación en función de la posición
    }
    printf("Cadena iterada: %s\n", str);
}

// putchar_fd: Prueba la función putchar_fd
void test_putchar_fd() {
    printf("Probando putchar_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "A", 1);  // Simulación de putchar_fd
        close(fd);
    }
}

// putstr_fd: Prueba la función putstr_fd
void test_putstr_fd() {
    printf("Probando putstr_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "Hola mundo\n", 11);  // Simulación de putstr_fd
        close(fd);
    }
}

// putendl_fd: Prueba la función putendl_fd
void test_putendl_fd() {
    printf("Probando putendl_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "Hola mundo\n", 11);  // Simulación de putendl_fd
        close(fd);
    }
}

// putnbr_fd: Prueba la función putnbr_fd
void test_putnbr_fd() {
    printf("Probando putnbr_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        char buffer[20];
        int num = 12345;
        snprintf(buffer, sizeof(buffer), "%d", num);  // Simulación de putnbr_fd
        write(fd, buffer, strlen(buffer));
        close(fd);
    }
}
*/

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <funcion>\n", argv[0]);
        return 1;
    }   
    if (strcmp(argv[1], "isalpha") == 0) test_isalpha();
    else if (strcmp(argv[1], "isdigit") == 0) test_isdigit();
    else if (strcmp(argv[1], "isalnum") == 0) test_isalnum();
    else if (strcmp(argv[1], "isascii") == 0) test_isascii();
    else if (strcmp(argv[1], "isprint") == 0) test_isprint();
    else if (strcmp(argv[1], "strlen") == 0) test_strlen();
    else if (strcmp(argv[1], "memset") == 0) test_memset();
    else if (strcmp(argv[1], "bzero") == 0) test_bzero();
    else if (strcmp(argv[1], "memcpy") == 0) test_memcpy();
    else if (strcmp(argv[1], "memmove") == 0) test_memmove();
   /* else if (strcmp(argv[1], "strlcpy") == 0) test_strlcpy();  No disponible OBSOLETO
    else if (strcmp(argv[1], "strlcat") == 0) test_strlcat(); No disponible OBSOLETO */
    else if (strcmp(argv[1], "toupper") == 0) test_toupper();
    else if (strcmp(argv[1], "tolower") == 0) test_tolower();
    else if (strcmp(argv[1], "strchr") == 0) test_strchr();
    else if (strcmp(argv[1], "strrchr") == 0) test_strrchr();
    else if (strcmp(argv[1], "strncmp") == 0) test_strncmp();
    else if (strcmp(argv[1], "memchr") == 0) test_memchr();
    else if (strcmp(argv[1], "memcmp") == 0) test_memcmp();
  /*  else if (strcmp(argv[1], "strnstr") == 0) test_strnstr();  No disponible OBSOLETO */
    else if (strcmp(argv[1], "atoi") == 0) test_atoi();
    else if (strcmp(argv[1], "calloc") == 0) test_calloc();
    else if (strcmp(argv[1], "strdup") == 0) test_strdup();
   /* else if (strcmp(argv[1], "substr") == 0) test_substr();  No disponible OBSOLETO
    else if (strcmp(argv[1], "strjoin") == 0) test_strjoin();No disponible OBSOLETO 
    else if (strcmp(argv[1], "strtrim") == 0) test_strtrim(); No disponible OBSOLETO 
    else if (strcmp(argv[1], "split") == 0) test_split();*/
    /*else if (strcmp(argv[1], "itoa") == 0) test_itoa();
    else if (strcmp(argv[1], "strmapi") == 0) test_strmapi();
    else if (strcmp(argv[1], "striteri") == 0) test_striteri();
    else if (strcmp(argv[1], "putchar_fd") == 0) test_putchar_fd();
    else if (strcmp(argv[1], "putstr_fd") == 0) test_putstr_fd();
    else if (strcmp(argv[1], "putendl_fd") == 0) test_putendl_fd();
    else if (strcmp(argv[1], "putnbr_fd") == 0) test_putnbr_fd();
    else if (strcmp(argv[1], "lstnew") == 0) test_lstnew();
    else if (strcmp(argv[1], "lstadd_front") == 0) test_lstadd_front();
    else if (strcmp(argv[1], "lstsize") == 0) test_lstsize();
    else if (strcmp(argv[1], "lstlast") == 0) test_lstlast();
    else if (strcmp(argv[1], "lstadd_back") == 0) test_lstadd_back();
    else if (strcmp(argv[1], "lstdelone") == 0) test_lstdelone();
    else if (strcmp(argv[1], "lstclear") == 0) test_lstclear();
    else if (strcmp(argv[1], "lstiter") == 0) test_lstiter();
    else if (strcmp(argv[1], "lstmap") == 0) test_lstmap();*/
    else printf("Funcion no reconocida: %s\n", argv[1]);

    return 0;
}
