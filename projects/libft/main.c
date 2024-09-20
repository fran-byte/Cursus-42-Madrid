/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parte1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:49 by frromero          #+#    #+#             */
/*   Updated: 2024/09/19 20:24:13 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
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

*/

void test_isalpha() 
{
    printf("   __   _             _                 _           _             \n");
    printf("  / _| | |_          (_)  ___    __ _  | |  _ __   | |__     __ _ \n");
    printf(" | |_  | __|         | | / __|  / _` | | | | '_ \\  | '_ \\   / _` |\n");
    printf(" |  _| | |_          | | \\__ \\ | (_| | | | | |_) | | | | | | (_| |\n");
    printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_| | .__/  |_| |_|  \\__,_|\n");
    printf("             |_____|                       |_|                         \n");
    printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
    printf("tr_isalpha('1'): %d\n\n", ft_isalpha('1'));
}

void test_isdigit() 
{
    printf("   __   _             _             _   _           _   _   \n");
    printf("  / _| | |_          (_)  ___    __| | (_)   __ _  (_) | |_ \n");
    printf(" | |_  | __|         | | / __|  / _` | | |  / _` | | | | __|\n");
    printf(" |  _| | |_          | | \\__ \\ | (_| | | | | (_| | | | | |_ \n");
    printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_|  \\__, | |_|  \\__|\n");
    printf("             |_____|                        |___/          \n");
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("ft_isdigit('f'): %d\n", ft_isdigit('f'));
}

void test_isalnum() 
{
    printf("   __   _             _                 _                             \n");
    printf("  / _| | |_          (_)  ___    __ _  | |  _ __    _   _   _ __ ___  \n");
    printf(" | |_  | __|         | | / __|  / _` | | | | '_ \\  | | | | | '_ ` _ \\ \n");
    printf(" |  _| | |_          | | \\__ \\ | (_| | | | | | | | | |_| | | | | | | |\n");
    printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_| |_| |_|  \\__,_| |_| |_| |_|\n");
    printf("             |_____|                                                 \n");
    printf("ft_isalnum('5'): %d\n", isalnum('5'));
    printf("ft_isalnum('f'): %d\n", isalnum('f'));
    printf("ft_isalnum('?'): %d\n", isalnum('?'));
}

void test_ascii() 
{
    printf("   __   _             _                              _   _ \n");
    printf("  / _| | |_          (_)  ___    __ _   ___    ___  (_) (_)\n");
    printf(" | |_  | __|         | | / __|  / _` | / __|  / __| | | | |\n");
    printf(" |  _| | |_          | | \\__ \\ | (_| | \\__ \\ | (__  | | | |\n");
    printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |___/  \\___| |_| |_|\n");
    printf("             |_____|                                      \n");
    printf("ft_sascii('5'): %d\n", ft_isascii('5'));
    printf("ft_isascii('f'): %d\n", ft_isascii('f'));
    printf("ft_isascii('Ç'): %d\n", ft_isascii(128));
}

void test_isprint() 
{
    printf("   __   _             _                        _           _   \n");
    printf("  / _| | |_          (_)  ___   _ __    _ __  (_)  _ __   | |_ \n");
    printf(" | |_  | __|         | | / __| | '_ \\  | '__| | | | '_ \\  | __|\n");
    printf(" |  _| | |_          | | \\__ \\ | |_) | | |    | | | | | | | |_ \n");
    printf(" |_|    \\__|  _____  |_| |___/ | .__/  |_|    |_| |_| |_|  \\__|\n");
    printf("             |_____|           |_|                            \n");
    printf("ft_isprint('5'): %d\n", ft_isprint('5'));
    printf("ft_isprint('\\n'): %d\n", ft_isprint('\n'));
}

void test_strlen() 
{
    printf("   __   _                   _            _                \n");
    printf("  / _| | |_           ___  | |_   _ __  | |   ___   _ __  \n");
    printf(" | |_  | __|         / __| | __| | '__| | |  / _ \\ | '_ \\ \n");
    printf(" |  _| | |_          \\__ \\ | |_  | |    | | |  __/ | | | |\n");
    printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|  \\___| |_| |_|\n");
    printf("             |_____|                                      \n");
    const char *str = "Hola mundo 42!";
	printf("*str = \"Hola mundo 42!\"");
    printf("ft_strlen(\"%s\"): %zu\n", str, ft_strlen(str));
}

void test_memset() 
{
    printf("   __   _                                                         _   \n");
    printf("  / _| | |_           _ __ ___     ___   _ __ ___    ___    ___  | |_ \n");
    printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\  / __|  / _ \\ | __|\n");
    printf(" |  _| | |_          | | | | | | |  __/ | | | | | | \\__ \\ |  __/ | |_ \n");
    printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_| |___/  \\___|  \\__|\n");
    printf("             |_____|                                                  \n");
    char str[50] = "Hola Mundo 42!!";
    printf("Nuestra string: %s\n", str);
    ft_memset(str, '*', 5);
    printf("ft_memset(str, '*', 5): %s\n", str);
}

void test_bzero() 
{
    printf("   __   _             _                                 \n");
    printf("  / _| | |_          | |__    ____   ___   _ __    ___  \n");
    printf(" | |_  | __|         | '_ \\  |_  /  / _ \\ | '__|  / _ \\ \n");
    printf(" |  _| | |_          | |_) |  / /  |  __/ | |    | (_) |\n");
    printf(" |_|    \\__|  _____  |_.__/  /___|  \\___| |_|     \\___/ \n");
    printf("             |_____|                                    \n");
    char str[50] = "Hola Mundo 42!!";
    printf("Nuestra string: %s\n", str);
    ft_bzero(str, 5);
    printf("ft_bzero(str, 5): %s\n", str);
}

void test_memcpy() 
{
    printf("   __   _                                                                 \n");
    printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___   _ __    _   _ \n");
    printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ \\  | | | |\n");
    printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | |_) | | |_| |\n");
    printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| | .__/   \\__, |\n");
    printf("             |_____|                                       |_|      |___/	\n");
    char src[50] = "Hola Mundo 42!!";
    char dest[50];
    printf("Probando memcpy:\n");
    printf("Nuestra string: %s\n", src);
	printf("ft_memcpy(dest, src, strlen(src) + 1): %s\n", src);
    ft_memcpy(dest, src, ft_strlen(src) + 1);
    printf("Resultado: %s\n", dest);
}

void test_memmove() 
{
    printf("   __   _                                                                             \n");
    printf("  / _| | |_           _ __ ___     ___   _ __ ___    _ __ ___     ___   __   __   ___ \n");
    printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\  | '_ ` _ \\   / _ \\  \\ \\ / /  / _ \\n");
    printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | | | | | | | (_) |  \\ V /  |  __/\n");
    printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_| |_| |_| |_|  \\___/    \\_/    \\___|\n");
    printf("             |_____|                                                                  \n");
    char str[50] = "Hola Mundo 42!!";
    printf("Nuestra string: %s\n", str);
    printf("ft_memmove(str + 5, str, strlen(str) - 5)\n");
    printf("Mueve la parte de la cadena hacia la derecha\n");
    ft_memmove(str + 5, str, ft_strlen(str) - 5);
    printf("Resultado: %s\n", str);
}

void test_strlcpy() 
{
printf("   __   _                   _            _                        \n");
printf("  / _| | |_           ___  | |_   _ __  | |   ___   _ __    _   _ \n");
printf(" | |_  | __|         / __| | __| | '__| | |  / __| | '_ \\  | | | |\n");
printf(" |  _| | |_          \\__ \\ | |_  | |    | | | (__  | |_) | | |_| |\n");
printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|  \\___| | .__/   \\__, |\n");
printf("             |_____|                               |_|      |___/ \n");
    char src[] = "Hola Mundo 42!!";
    char dest[20];
    size_t result = ft_strlcpy(dest, src, sizeof(dest));
    printf("ft_strlcpy(dest, src, sizeof(dest)): %zu\n", result);
    printf("Destino: %s\n", dest);rlcat() {
	printf("   __   _                   _            _                  _   \n");
	printf("  / _| | |_           ___  | |_   _ __  | |   ___    __ _  | |_ \n");
	printf(" | |_  | __|         / __| | __| | '__| | |  / __|  / _` | | __|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | (__  | (_| | | |_ \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|  \\___|  \\__,_|  \\__|\n");
	printf("             |_____|                                            \n");
    char dest[30] = "Hola";
    char src[] = " Mundo!";
    size_t result = ft_strlcat(dest, src, sizeof(dest));
    printf("Resultado de strlcat: %zu\n", result);
    printf("Destino: %s\n", dest);
}

void test_toupper() 
{
	printf("   __   _             _                                                 \n");
	printf("  / _| | |_          | |_    ___    _   _   _ __    _ __     ___   _ __ \n");
	printf(" | |_  | __|         | __|  / _ \\  | | | | | '_ \\  | '_ \\   / _ \\ | '__|\n");
	printf(" |  _| | |_          | |_  | (_) | | |_| | | |_) | | |_) | |  __/ | |   \n");
	printf(" |_|    \\__|  _____   \\__|  \\___/   \\__,_| | .__/  | .__/   \\___| |_|   \n");
	printf("            |_____|                       |_|     |_|                 \n");
    char c = 'a';
    printf("ft_toupper('%c') = %c\n", c, ft_toupper(c));
}

void test_tolower() 
{
	printf("   __   _             _             _                                  \n");
	printf("  / _| | |_          | |_    ___   | |   ___   __      __   ___   _ __ \n");
	printf(" | |_  | __|         | __|  / _ \\  | |  / _ \\  \\ \\ /\\ / /  / _ \\ | '__|\n");
	printf(" |  _| | |_          | |_  | (_) | | | | (_) |  \\ V  V /  |  __/ | |   \n");
	printf(" |_|    \\__|  _____   \\__|  \\___/  |_|  \\___/    \\_/\\_/    \\___| |_|   \n");
	printf("             |_____|                                                   \n");
    char c = 'A';
    printf("ft_tolower('%c') = %c\n", c, ft_tolower(c));
}

void test_strchr() 
{
	printf("   __   _                   _                   _            \n");
	printf("  / _| | |_           ___  | |_   _ __    ___  | |__    _ __ \n");
	printf(" | |_  | __|         / __| | __| | '__|  / __| | '_ \\  | '__|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | (__  | | | | | |   \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|     \\___| |_| |_| |_|   \n");
	printf("             |_____|                                         \n");
    char str[] = "Hola, mundo";
    char *result = ft_strchr(str, 'm');
    if (result) {
        printf("Buscando primer caracter 'm' en: 'Hola, mundo'\n");
        printf("Primero: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

void test_strrchr() 
{
	printf("   __   _                   _                          _            \n");
	printf("  / _| | |_           ___  | |_   _ __   _ __    ___  | |__    _ __ \n");
	printf(" | |_  | __|         / __| | __| | '__| | '__|  / __| | '_ \\  | '__|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | |    | (__  | | | | | |   \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|     \\___| |_| |_| |_|   \n");
	printf("             |_____|                                                \n");
    char str[] = "Hello, World!!";
    char *result = ft_strrchr(str, 'o');
    printf("Buscando último caracter 'o' en: 'Hello, World!!'\n");
    if (result) {
        printf("Último: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

void test_strncmp() 
{
	printf("   __   _                   _                                             \n");
	printf("  / _| | |_           ___  | |_   _ __   _ __     ___   _ __ ___    _ __  \n");
	printf(" | |_  | __|         / __| | __| | '__| | '_ \\   / __| | '_ ` _ \\  | '_ \ \n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | | | (__  | | | | | | | |_) |\n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_| |_|  \\___| |_| |_| |_| | .__/ \n");
	printf("             |_____|                                               |_|    \n");
    char *str1 = "Hola";
    char *str2 = "Hola42Madrid";
    printf("str1: 'Hola'\n");
    printf("str2: 'Hola42Madrid'\n");
    printf("ft_strncmp(str1, str2, 4) = %d\n", ft_strncmp(str1, str2, 4));
    printf("ft_strncmp(str1, str2, 6) = %d\n", ft_strncmp(str1, str2, 6));
}

void test_memchr() 
{
	printf("   __   _                                                   _            \n");
	printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___  | |__    _ __ \n");
	printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ \\  | '__|\n");
	printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | | | | | |   \n");
	printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| |_| |_| |_|   \n");
	printf("             |_____|                                                     \n");
    char str[] = "Hola42Madrid";
    char *result = ft_memchr(str, '4', ft_strlen(str));
    printf("str: 'Hola42Madrid'\n");
    printf("ft_memchr(str, '4', ft_strlen(str))");
    if (result) {
        printf("\nEncontrado: '4' %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}


void test_memcmp() 
{
	printf("   __   _                                                                     \n");
	printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___   _ __ ___    _ __  \n");
	printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ ` _ \\  | '_ \ \n");
	printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | | | | | | | |_) |\n");
	printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| |_| |_| |_| | .__/ \n");
	printf("             |_____|                                                   |_|    \n");
    char *str1 = "Hola42Madrid";
    char *str2 = "Hola42Madrid";
    char *str3 = "Hola43";
    printf("\n*str1 = \"Hola42Madrid\"");
    printf("\n*str2 = \"Hola42Madrid\"");
    printf("\n*str3 = \"Hola43\"\n");
    printf("ft_memcmp(str1, str2, 4) = %d\n", ft_memcmp(str1, str2, 4));
    printf("ft_memcmp(str1, str3, 6) = %d\n", ft_memcmp(str1, str3, 6));
}

void test_strnstr() 
{
	printf("   __   _                   _                          _          \n");
	printf("  / _| | |_           ___  | |_   _ __   _ __    ___  | |_   _ __ \n");
	printf(" | |_  | __|         / __| | __| | '__| | '_ \\  / __| | __| | '__|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | | \\__ \\ | |_  | |   \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_| |_| |___/  \\__| |_|   \n");
	printf("             |_____|                                              \n");
    char *str = "Hola42Madrid";
    char *substr = "42";
    char *result = ft_strnstr(str, substr, ft_strlen(str));
	printf("ftstrnstr(str, substr, ft_strlen(str))");
    if (result) {
        printf("Encontrado: %s\n", result);
    } else {
        printf("No encontrado\n");
    }
}

void test_atoi() 
{
	printf("   __   _                     _             _ \n");
	printf("  / _| | |_            __ _  | |_    ___   (_)\n");
	printf(" | |_  | __|          / _` | | __|  / _ \\  | |\n");
	printf(" |  _| | |_          | (_| | | |_  | (_) | | |\n");
	printf(" |_|    \\__|  _____   \\__,_|  \\__|  \\___/  |_|\n");
	printf("             |_____|                          	\n");
    char *num_str = "123459";
    char *neg_num_str = "-9576";
    char *invalid_num_str = "12asd34";
    printf("ft_atoi(\"%s\") = %d\n", num_str, ft_atoi(num_str));
    printf("ft_atoi(\"%s\") = %d\n", neg_num_str, ft_atoi(neg_num_str));
    printf("ft_atoi(\"%s\") = %d\n", invalid_num_str, ft_atoi(invalid_num_str));
}

void test_calloc() 
{
	printf("   __   _                            _   _                \n");
	printf("  / _| | |_            ___    __ _  | | | |   ___     ___ \n");
	printf(" | |_  | __|          / __|  / _` | | | | |  / _ \\   / __|\n");
	printf(" |  _| | |_          | (__  | (_| | | | | | | (_) | | (__ \n");
	printf(" |_|    \\__|  _____   \\___|  \\__,_| |_| |_|  \\___/   \\___|\n");
 	printf("            |_____|                                      \n");
    int i = 0;
    int *arr = (int *)ft_calloc(5, sizeof(int));
	printf("int *arr = (int *)ft_calloc(5, sizeof(int))");
    while(i < 5)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
         i++;
    }
    free(arr);
}

void test_strdup() 
{
	printf("   __   _                   _                _                 \n");
	printf("  / _| | |_           ___  | |_   _ __    __| |  _   _   _ __  \n");
	printf(" | |_  | __|         / __| | __| | '__|  / _` | | | | | | '_ \\ \n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | (_| | | |_| | | |_) |\n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|     \\__,_|  \\__,_| | .__/ \n");
	printf("             |_____|                                    |_|    \n");
    char *str = "Hola42Madrid";
    char *duplicated = ft_strdup(str);
	printf("ft_strdup(str)\n");
    printf("Cadena original: %s\n", str);
    printf("Cadena duplicada: %s\n", duplicated);
    free(duplicated);
}

/*

void test_substr() 
{
    char *str = "Hola mundo";
    char *sub = substr(str + 5, 5);  // "mundo"
    printf("Probando substr:\n");
    printf("Subcadena: %s\n", sub);
    free(sub);
}

void test_strjoin() 
{

}


void test_strtrim() 
{
    char *str = "   Hola mundo   ";
    char *trimmed = str + 3; // Simulación de recortar los espacios de inicio y fin
    printf("Probando strtrim:\n");
    trimmed[strlen(trimmed) - 3] = '\0';  // Simulación de recortar el final
    printf("Cadena recortada: '%s'\n", trimmed);
}

void test_split() 
{
    printf("Probando split:\n");
    char *str = "Hola mundo de C";
    char *token = strtok(str, " ");
    while (token) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }
}

void test_itoa() 
{
    int num = 12345;
    char buffer[20];
    printf("Probando itoa:\n");
    printf("Probando itoa:\n");
    snprintf(buffer, sizeof(buffer), "%d", num);  // Simulación de itoa
    printf("itoa(%d) = %s\n", num, buffer);
}

void test_strmapi() 
{
    printf("Probando strmapi:\n");
    char *str = "abc";
    char *mapped = strdup(str);
    for (int i = 0; mapped[i]; i++) {
        mapped[i] = mapped[i] + 1;  // Simple modificación de la cadena
    }
    printf("Cadena modificada: %s\n", mapped);
    free(mapped);
}

void test_striteri() 
{
    printf("Probando striteri:\n");
    char str[] = "abc";
    for (int i = 0; str[i]; i++) {
        str[i] = str[i] + i;  // Modificación en función de la posición
    }
    printf("Cadena iterada: %s\n", str);
}

void test_putchar_fd() 
{
    printf("Probando putchar_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "A", 1);  // Simulación de putchar_fd
        close(fd);
    }
}

void test_putstr_fd() {
    printf("Probando putstr_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "Hola mundo\n", 11);  // Simulación de putstr_fd
        close(fd);
    }
}

void test_putendl_fd()
{
    printf("Probando putendl_fd:\n");
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        write(fd, "Hola mundo\n", 11);  // Simulación de putendl_fd
        close(fd);
    }
}

void test_putnbr_fd() 
{
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

int main(int argc, char *argv[]) 
{
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
   	else if (strcmp(argv[1], "strlcpy") == 0) test_strlcpy();	// OBSOLETO
    else if (strcmp(argv[1], "strlcat") == 0) test_strlcat();	// OBSOLETO
    else if (strcmp(argv[1], "toupper") == 0) test_toupper();
    else if (strcmp(argv[1], "tolower") == 0) test_tolower();
    else if (strcmp(argv[1], "strchr") == 0) test_strchr();
    else if (strcmp(argv[1], "strrchr") == 0) test_strrchr();
    else if (strcmp(argv[1], "strncmp") == 0) test_strncmp();
    else if (strcmp(argv[1], "memchr") == 0) test_memchr();
    else if (strcmp(argv[1], "memcmp") == 0) test_memcmp();
	else if (strcmp(argv[1], "strnstr") == 0) test_strnstr();	// OBSOLETO
    else if (strcmp(argv[1], "atoi") == 0) test_atoi();
    else if (strcmp(argv[1], "calloc") == 0) test_calloc();
    else if (strcmp(argv[1], "strdup") == 0) test_strdup();
   /* else if (strcmp(argv[1], "substr") == 0) test_substr();  No disponible OBSOLETO
    else if (strcmp(argv[1], "strjoin") == 0) test_strjoin();No disponible OBSOLETO
    else if (strcmp(argv[1], "strtrim") == 0) test_strtrim(); No disponible OBSOLETO
    else if (strcmp(argv[1], "split") == 0) test_split();
    else if (strcmp(argv[1], "itoa") == 0) test_itoa();
    else if (strcmp(argv[1], "strmapi") == 0) test_strmapi();
    else if (strcmp(argv[1], "striteri") == 0) test_striteri();
    else if (strcmp(argv[1], "putchar_fd") == 0) test_putchar_fd();
    else if (strcmp(argv[1], "putstr_fd") == 0) test_putstr_fd();
    else if (strcmp(argv[1], "putendl_fd") == 0) test_putendl_fd();
    else if (strcmp(argv[1], "putnbr_fd") == 0) test_putnbr_fd();
	// BONUS
    else if (strcmp(argv[1], "lstnew") == 0) test_lstnew();
    else if (strcmp(argv[1], "lstadd_front") == 0) test_lstadd_front();
    else if (strcmp(argv[1], "lstsize") == 0) test_lstsize();
    else if (strcmp(argv[1], "lstlast") == 0) test_lstlast();
    else if (strcmp(argv[1], "lstadd_back") == 0) test_lstadd_back();
    else if (strcmp(argv[1], "lstdelone") == 0) test_lstdelone();
    else if (strcmp(argv[1], "lstclear") == 0) test_lstclear();
    else if (strcmp(argv[1], "lstiter") == 0) test_lstiter();
    else if (strcmp(argv[1], "lstmap") == 0) test_lstmap();*/
	else if (strcmp(argv[1], "all") == 0)
		{
			test_isalpha();
			test_isdigit();
			test_isalnum();
			test_isascii();
			test_isprint();
			test_strlen();
			test_memset();
			test_bzero();
			test_memcpy();
			test_memmove();
			test_strlcpy();
			test_strlcat();
			test_toupper();
			test_tolower();
			test_strchr();
			test_strrchr();
			test_strncmp();
			test_memchr();
			test_memcmp();
			test_strnstr();
			test_atoi();
			test_calloc();
			test_strdup();

		}
    else
		printf("Funcion no reconocida: %s\n", argv[1]);

    return 0;
}
