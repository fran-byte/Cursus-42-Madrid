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
    printf("Probando strlen:\n");
    const char *str = "Hola mundo 42!";
    printf("strlen(\"%s\"): %zu\n", str, strlen(str));
}
/*
// memset: Prueba la función memset
void test_memset() {
    printf("Probando memset:\n");
    char str[50] = "Esta es una cadena original";
    printf("Antes de memset: %s\n", str);
    memset(str, '-', 4);
    printf("Despues de memset: %s\n", str);
}

// bzero: Prueba la función bzero
void test_bzero() {
    printf("Probando bzero:\n");
    char str[50] = "Hola mundo";
    printf("Antes de bzero: %s\n", str);
    bzero(str, 4);
    printf("Despues de bzero: %s\n", str);
}

// memcpy: Prueba la función memcpy
void test_memcpy() {
    printf("Probando memcpy:\n");
    char src[50] = "Texto original";
    char dest[50];
    memcpy(dest, src, strlen(src) + 1);
    printf("Resultado: %s\n", dest);
}

// memcpy: Prueba la función memmove
void test_memmove() {
    printf("Probando memmove:\n");
    char str[50] = "Hola, Hola, Hola";
    memmove(str + 5, str, strlen(str) - 5);  // Mueve la parte de la cadena hacia la derecha
    printf("Resultado: %s\n", str);
}

// calloc: Prueba la función calloc
void test_calloc() {
    printf("Probando calloc:\n");
    int *arr = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
}

// strdup: Prueba la función strdup
void test_strdup() {
    printf("Probando strdup:\n");
    char *str = "Cadena a duplicar";
   
    char *duplicated = strdup(str);
    printf("Cadena original: %s\n", str);
    printf("Cadena duplicada: %s\n", duplicated);
    free(duplicated);
}

// atoi: Prueba la función atoi
void test_atoi() {
    printf("Probando atoi:\n");
    char *num_str = "12345";
    char *neg_num_str = "-9876";
    char *invalid_num_str = "12abc34";
    printf("atoi(\"%s\") = %d\n", num_str, atoi(num_str));
    printf("atoi(\"%s\") = %d\n", neg_num_str, atoi(neg_num_str));
    printf("atoi(\"%s\") = %d\n", invalid_num_str, atoi(invalid_num_str));
}
*/
// strlcpy: Prueba la función strlcpy
void test_strlcpy() {
    printf("Probando strlcpy:\n");
    char src[] = "Texto de origen";
    char dest[20];
    size_t result = strlcpy(dest, src, sizeof(dest));
    printf("Resultado de strlcpy: %zu\n", result);
    printf("Destino: %s\n", dest);
}
/*
// strlcat: Prueba la función strlcat
void test_strlcat() {
    printf("Probando strlcat:\n");
    char dest[30] = "Hola";
    char src[] = " Mundo!";
    size_t result = strlcat(dest, src, sizeof(dest));
    printf("Resultado de strlcat: %zu\n", result);
    printf("Destino: %s\n", dest);
}

// toupper: Prueba la función toupper
void test_toupper() {
    printf("Probando toupper:\n");
    char c = 'a';
    printf("toupper('%c') = %c\n", c, toupper(c));
}

// tolower: Prueba la función tolower
void test_tolower() {
    printf("Probando tolower:\n");
    char c = 'A';
    printf("tolower('%c') = %c\n", c, tolower(c));
}

// strchr: Prueba la función strchr
void test_strchr() {
    printf("Probando strchr:\n");
    char str[] = "Hola, mundo";
    char *result = strchr(str, 'm');
    if (result) {
        printf("Encontrado: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// strrchr: Prueba la función strrchr
void test_strrchr() {
    printf("Probando strrchr:\n");
    char str[] = "Hola, mundo, mundo";
    char *result = strrchr(str, 'm');
    if (result) {
        printf("Última ocurrencia: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// strncmp: Prueba la función strncmp
void test_strncmp() {
    printf("Probando strncmp:\n");
    char *s1 = "Hola";
    char *s2 = "Holanda";
    printf("strncmp(s1, s2, 4) = %d\n", strncmp(s1, s2, 4));
    printf("strncmp(s1, s2, 6) = %d\n", strncmp(s1, s2, 6));
}

// memchr: Prueba la función memchr
void test_memchr() {
    printf("Probando memchr:\n");
    char str[] = "Hola mundo";
    char *result = memchr(str, 'm', strlen(str));
    if (result) {
        printf("Encontrado: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// memcmp: Prueba la función memcmp
void test_memcmp() {
    printf("Probando memcmp:\n");
    char *str1 = "Hola";
    char *str2 = "Hola";
    char *str3 = "Holb";
    printf("memcmp(str1, str2, 4) = %d\n", memcmp(str1, str2, 4));
    printf("memcmp(str1, str3, 4) = %d\n", memcmp(str1, str3, 4));
}

// strnstr: Prueba la función strnstr
void test_strnstr() {
    printf("Probando strnstr:\n");
    char *haystack = "Este es un ejemplo";
    char *needle = "un";
    char *result = strnstr(haystack, needle, strlen(haystack));
    if (result) {
        printf("Encontrado: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

// substr: Prueba la función substr
void test_substr() {
    printf("Probando substr:\n");
    char *str = "Hola mundo";
    char *sub = strndup(str + 5, 5);  // "mundo"
    printf("Subcadena: %s\n", sub);
    free(sub);
}

// strjoin: Prueba la función strjoin
void test_strjoin() {
    printf("Probando strjoin:\n");
    char *s1 = "Hola";
    char *s2 = " Mundo";
    char *joined = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(joined, s1);
    strcat(joined, s2);
    printf("Cadena unida: %s\n", joined);
    free(joined);
}

// strtrim: Prueba la función strtrim
void test_strtrim() {
    printf("Probando strtrim:\n");
    char *str = "   Hola mundo   ";
    char *trimmed = str + 3; // Simulación de recortar los espacios de inicio y fin
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
    printf("Probando itoa:\n");
    int num = 12345;
    char buffer[20];
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

    // Compara el argumento ingresado con el nombre de las funciones a testear
    if (strcmp(argv[1], "isalpha") == 0) test_isalpha();
    else if (strcmp(argv[1], "isdigit") == 0) test_isdigit();
    else if (strcmp(argv[1], "isalnum") == 0) test_isalnum();
    else if (strcmp(argv[1], "isascii") == 0) test_isascii();
    else if (strcmp(argv[1], "isprint") == 0) test_isprint();
    else if (strcmp(argv[1], "strlen") == 0) test_strlen();
 /*   else if (strcmp(argv[1], "memset") == 0) test_memset();
    else if (strcmp(argv[1], "bzero") == 0) test_bzero();
    else if (strcmp(argv[1], "memcpy") == 0) test_memcpy();
    else if (strcmp(argv[1], "memmove") == 0) test_memmove();*/
    else if (strcmp(argv[1], "strlcpy") == 0) test_strlcpy();
  /*  else if (strcmp(argv[1], "strlcat") == 0) test_strlcat();
    else if (strcmp(argv[1], "toupper") == 0) test_toupper();
    else if (strcmp(argv[1], "tolower") == 0) test_tolower();
    else if (strcmp(argv[1], "strchr") == 0) test_strchr();
    else if (strcmp(argv[1], "strrchr") == 0) test_strrchr();
    else if (strcmp(argv[1], "strncmp") == 0) test_strncmp();
    else if (strcmp(argv[1], "memchr") == 0) test_memchr();
    else if (strcmp(argv[1], "memcmp") == 0) test_memcmp();
    else if (strcmp(argv[1], "strnstr") == 0) test_strnstr();
    else if (strcmp(argv[1], "atoi") == 0) test_atoi();
    else if (strcmp(argv[1], "calloc") == 0) test_calloc();
    else if (strcmp(argv[1], "strdup") == 0) test_strdup();
    else if (strcmp(argv[1], "substr") == 0) test_substr();
    else if (strcmp(argv[1], "strjoin") == 0) test_strjoin();
    else if (strcmp(argv[1], "strtrim") == 0) test_strtrim();
    else if (strcmp(argv[1], "split") == 0) test_split();
    else if (strcmp(argv[1], "itoa") == 0) test_itoa();
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
