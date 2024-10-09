/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:49 by frromero          #+#    #+#             */
/*   Updated: 2024/10/08 01:09:16 by frromero         ###   ########.fr       */
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
#include <assert.h>

/*
// Definición de la estructura t_list
typedef struct s_list {
	void *content;
	struct s_list *next;
} t_list;

*/
void info() {
    printf(
        "\n****************************************************\n"
        "\n* Información de testeo de las funciones de libft: *\n"
        "\n****************************************************\n"
        "\nEjecución individual                  : ./[program] ft_islapha"
        "\nEjecución de funciones obligatorias   : ./[program] ft_mandatory"
        "\nEjecución de funciones obligatorias + Bonus: ./[program] ft_bonus\n\n"
	    "\n* NOTAS A TENER EN CUENTA:\n" \
	    "Parte 1 - Funciones basadas en la libreía libc,\n" \
	    "replicado la función Original e igualmente podrían tener 'Segmentation\n" \
	    "Fault' si le pasamos un puntero/string nulo, tanto a la función original\n" \
	    "como clonada(ft_:)\n\n"
    );
    printf("Funciones de string:\n");
    printf("ft_strlen / strlen - Si le pasamos una String o puntero nulo,\n"
           "'Segmentation fault (core dumped)'%s\n",
           "\nft_memset / memset - Si le pasamos una String o puntero nulo,\n"
           "'Segmentation fault (core dumped)'%s\n",
           "\nft_bzero  / bzero (Obsoleta) - Si le pasamos una String o puntero nulo,\n"
           "'Segmentation fault (core dumped)'%s\n",
           "\nft_memcpy / memcpy - Si le pasamos una String o puntero nulo, a src o dst\n"
           "'Segmentation fault (core dumped)'%s\n",
           "\nft_memmove / memmove - Si le pasamos una String o puntero nulo, a src o dst\n"
           "'Segmentation fault (core dumped)'%s\n",
           "\nft_memchr(const void *s, int c, size_t n) - Intentaría acceder a memoria\n"
           "a través del puntero s.%s\n",
           "\nft_memcmp(const void *s1, const void *s2, size_t n) - Podría comparar\n"
           "punteros nulos entre sí.%s\n",
           "\nft_strlcpy(char *dst, const char *src, size_t size) - Si dst es nulo,\n"
           "intentaría escribir en una dirección inválida.%s\n",
           "\nft_strlcat(char *dst, const char *src, size_t size) - Similar a strlcpy,\n"
           "podría causar errores si dst es nulo.%s\n",
           "\nft_strdup(const char *s1) - Intentaría crear una copia de una cadena\n"
           "a partir de un puntero nulo.%s\n",
           "");
    printf("Funciones de memoria:\n");
    printf("ft_substr(char const *s, unsigned int start, size_t len) - 'DOPADA' NULL\n"
           "si falla la reserva de memoria.%s\n",
           "\nft_strjoin(char const *s1, char const *s2) - 'DOPADA' NULL si falla la\n"
           "reserva de memoria.%s\n",
           "\nft_strtrim(char const *s1, char const *set) - 'DOPADA' NULL si falla la\n"
           "reserva de memoria.%s\n",
           "\nft_itoa(int n) - 'DOPADA' NULL si falla la reserva de memoria.%s\n",
           "\nft_split(char const *s, char c) - 'DOPADA' NULL si falla la reserva de\n"
           "memoria.%s\n",
           "\nft_strmapi(char const *s, char (*f)(unsigned int, char)) - 'DOPADA' NULL\n"
           "si falla la reserva de memoria.%s\n",
           "\nft_striteri(char *s, void (*f)(unsigned int, char*)) - 'DOPADA' NULL\n"
           "si falla la reserva de memoria.%s\n",
           "\nft_putstr_fd(char *s, int fd) - Si s es nulo, intentaría escribir en una\n"
           "dirección inválida.%s\n",
           "\nft_putendl_fd(char *s, int fd) - Similar a putstr, podría causar errores\n"
           "si s es nulo.%s\n",
           "\nft_putnbr_fd(int n, int fd) - No debería causar errores de segmentación,\n"
           "pero podría hacerlo si se usa incorrectamente.%s\n",
           "");
    printf("Funciones de lista:\n");
    printf("ft_lstnew(void *content) - Podría intentar usar el contenido de un puntero\n"
           "nulo.%s\n",
           "\nft_lstadd_front(t_list **lst, t_list *new) - Podría intentar modificar\n"
           "una estructura a través de un puntero nulo.%s\n",
           "\nft_lstadd_back(t_list **lst, t_list *new) - Similar a ft_lstadd_front,\n"
           "podría causar errores si lst es nulo.%s\n",
           "\nft_lstdelone(t_list *lst, void (*del)(void *)) - Podría intentar liberar\n"
           "memoria a través de un puntero nulo.%s\n",
           "\nft_lstclear(t_list **lst, void (*del)(void *)) - Podría intentar liberar\n"
           "múltiples elementos a través de punteros nulos.%s\n",
           "\nft_lstiter(t_list *lst, void (*f)(void *)) - Podría intentar iterar sobre\n"
           "una lista a través de punteros nulos.%s\n",
           "\nft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) - Podría\n"
           "intentar mapear una lista utilizando punteros nulos.%s\n",
           "");
}
}
void test_isalpha()
{
	int resultA;
	int resultA_original;
	int result1;
	int result1_original;
	int result300;
	int result300_original;

	resultA = ft_isalpha('A');
	resultA_original = isalpha('A');
	result1 = ft_isalpha('1');
	result1_original = isalpha('1');
	result300 = ft_isalpha(300);
	result300_original = isalpha(300);
	printf("\n==================================\n");
	printf("           ft _ isalpha           \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░░▀▄░░░▄▀░░░░░\n");
	printf("	░░░░▄█▀███▀█▄░░░░\n");
	printf("	░░░█▀███████▀█░░░\n");
	printf("	░░░█░█▀▀▀▀▀█░█░░░\n");
	printf("	░░░░░░▀▀░▀▀░░░░░░\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
		printf("==================================\n");
	/* TEST 1*/
	printf("ft_isalpha('A'): %d\n", resultA);
	printf("isalpha(''): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isalpha('1'): %d\n", result1);
	printf("isalpha('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isalpha(300): %d\n", result300);
	printf("isalpha(300): %d\n\n", result300_original);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_isdigit()
{
	int resultA;
	int resultA_original;
	int result1;
	int result1_original;
	int result300;
	int result300_original;

	resultA = ft_isdigit('A');
	resultA_original = isdigit('A');
	result1 = ft_isdigit('1');
	result1_original = isdigit('1');
	result300 = ft_isdigit(300);
	result300_original = isdigit(300);
	printf("\n==================================\n");
	printf("           ft _ isdigit           \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░░▄▄████▄▄░░░░░\n");
	printf("	░░░▄██████████▄░░░\n");
	printf("	░▄██▄██▄██▄██▄██▄░\n");
	printf("	░░░▀█▀░░▀▀░░▀█▀░░░\n");
	printf("	░░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░░░░░░░░░░░░░░░\n");
	printf("==================================\n");
	printf("ft_isdigit('A'): %d\n", resultA);
	printf("isdigit('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isdigit('1'): %d\n", result1);
	printf("isdigit('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isdigit(300): %d\n", result300);
	printf("isdigit(300): %d\n\n", result300_original);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_isalnum()
{
	int resultA;
	int resultA_original;
	int result1;
	int result1_original;
	int result300;
	int result300_original;

	resultA = ft_isalnum('A');
	resultA_original = isalnum('A');
	result1 = ft_isalnum('1');
	result1_original = isalnum('1');
	result300 = ft_isalnum(300);
	result300_original = isalnum(300);
	printf("\n==================================\n");
	printf("           ft _ isalnum           \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("	░░░▄░▀▄░░░▄▀░▄░░░\n");
	printf("	░░░█▄███████▄█░░░\n");
	printf("	░░░███▄███▄███░░░\n");
	printf("	░░░▀█████████▀░░░\n");
	printf("	░░░░▄▀░░░░░▀▄░░░░\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("==================================\n");
	printf("ft_isalnum('A'): %d\n", resultA);
	printf("isalnum('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isalnum('1'): %d\n", result1);
	printf("isalnum('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isalnum(300): %d\n", result300);
	printf("isalnum(300): %d\n\n", result300_original);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_isascii()
{
	int resultA;
	int resultA_original;
	int result1;
	int result1_original;
	int result300;
	int result300_original;

	resultA = ft_isascii('A');
	resultA_original = isascii('A');
	result1 = ft_isascii('1');
	result1_original = isascii('1');
	result300 = ft_isascii(300);
	result300_original = isascii(300);
	printf("\n==================================\n");
	printf("           ft _ isascii           \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░▄▄████▄▄░░░░░\n");
	printf("	░░░██████████░░░░\n");
	printf("	░░░██▄▄██▄▄██░░░░\n");
	printf("	░░░░▄▀▄▀▀▄▀▄░░░░░\n");
	printf("	░░░▀░░░░░░░░▀░░░░\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("==================================\n");
	printf("ft_isascii('A'): %d\n", resultA);
	printf("isascii('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isascii('1'): %d\n", result1);
	printf("isascii('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isascii(300): %d\n", result300);
	printf("isascii(300): %d\n\n", result300_original);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_isprint()
{
	int resultA;
	int resultA_original;
	int result1;
	int result1_original;
	int result300;
	int result300_original;

	resultA = ft_isprint('A');
	resultA_original = isprint('A');
	result1 = ft_isprint('1');
	result1_original = isprint('1');
	result300 = ft_isprint(300);
	result300_original = isprint(300);
	printf("\n==================================\n");
	printf("           ft _ isprint           \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░░░▄██▄░░░░░░░\n");
	printf("	░░░░▄██████▄░░░░░\n");
	printf("	░░░███▄██▄███░░░░\n");
	printf("	░░░░░▄▀▄▄▀▄░░░░░░\n");
	printf("	░░░░▀░▀░░▀░▀░░░░░\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("==================================\n");
	printf("ft_isprint('A'): %d\n", resultA);
	printf("isprint('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isprint('1'): %d\n", result1);
	printf("isprint('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isprint(300): %d\n", result300);
	printf("isprint(300): %d\n\n", result300_original);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strlen()
{
	printf("\n==================================\n");
	printf("           ft _ strlen            \n");
	printf("==================================\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("	░░░░░░░░▄░░░░░░░░\n");
	printf("	░░░░░░░███░░░░░░░\n");
	printf("	░░▄███████████▄░░\n");
	printf("	░░█████████████░░\n");
	printf("	░░█████████████░░\n");
	printf("	░░░░░░░░░░░░░░░░░\n");
	printf("==================================\n");

	// Test 1

	const char *str = "Hola mundo 42!";
	printf("*str = Hola mundo 42!\n\n");
	printf("ft_strlen( %s ): %zu\n\n", str, ft_strlen(str));
	printf("strlen( %s ): %zu\n\n", str, strlen(str));

	// TEST2
	//const char *str_null = NULL;
	// Llamar a ft_strlen  con un puntero nulo = (segmentación fault)
	//printf("Llamar a ft_strlen  con un puntero nulo\n\n");
	//size_t longitud = ft_strlen(str_null);
	//printf("Longitur: %zu", longitud);

	// TEST3
	//const char *str_null = NULL;
	// Llamar a strlen Original con un puntero nulo = (segmentación fault)
	//printf("Llamar a strlen  con un puntero nulo\n\n");
	//size_t longitud2 = strlen(str_null);
	//printf("Longitur: %zu", longitud2);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_memset()
{
	printf("\n==================================\n");
	printf("           ft _ memset          \n");
	printf("==================================\n");
	printf("	⠀⠀⠀⠀⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠁⠀⠀⣴⣶⡄⠀⣶⣶⡄⠀⣴⣶⡄\n");
	printf("	⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠀⠙⠋⠁⠀⠉⠋⠁⠀⠙⠋⠀\n");
	printf("	⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("==================================\n");
	// TEST1
	char str[50] = "Hola Mundo 42!!";
	char str2[50] = "Hola Mundo 42!!";
	printf("Nuestra string: %s\n", str);
	ft_memset(str, '*', 5);
	memset(str2, '*', 5);
	printf("ft_memset(str, '*', 5): %s\n", str);
	printf("memset(str, '*', 5): %s\n", str);

	// TEST2  Llamar a ft_memset con un puntero nulo = (segmentación fault)
	//char *str_null = NULL;
	//printf("Llamar a ft_menset con un puntero nulo\n\n");
	//ft_memset(str_null, '*', 5);
	//printf("ft_memset(str_null, '*', 5): %s\n", str);

	// TEST3  Llamar a memset con un puntero nulo = (segmentación fault)
	//char *str_null = NULL;
	//printf("Llamar a menset con un puntero nulo\n\n");
	//memset(str_null, '*', 5);
	//printf("memset(str_null, '*', 5): %s\n", str);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");

}

void test_bzero() //  REVISAR SI TRABAJA LA ORIGINAL, NO FUNCIONA ********
{
	printf("\n==================================\n");
	printf("           ft _ bzero            \n");
	printf("==================================\n");
	printf("	⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣦⠀\n");
	printf("	⠀⠀⠀⠀⣰⣿⡟⢻⣿⡟⢻⣧\n");
	printf("	⠀⠀⠀⣰⣿⣿⣇⣸⣿⣇⣸⣿\n");
	printf("	⠀⠀⣴⣿⣿⣿⣿⠟⢻⣿⣿⣿\n");
	printf("	⣠⣾⣿⣿⣿⣿⣿⣤⣼⣿⣿⠇\n");
	printf("	⢿⡿⢿⣿⣿⣿⣿⣿⣿⣿⡿⠀\n");
	printf("	⠀⠀⠈⠿⠿⠋⠙⢿⣿⡿⠁⠀\n");
	printf("==================================\n");
	char str[50] = "Hola Mundo 42!!";
	char str2[50] = "Hola Mundo 42!!";
	size_t size = strlen(str);
	printf("Nuestra string: %s\n", str);
	size_t n = 5;
	ft_bzero(str, n);
	bzero(str2, n);
	printf("\nft_bzero(str, 5): %s\n", str);
	printf("bzero(str, 5): %s\n", str2);
	printf("\nComo no podemos imprimir una cadena que ya empieza por  '\\0'");
    // Imprimir cadena después de ft_bzero
    printf("\n\nCadena después de ft_bzero: \n");
    size_t i = 0;
    while (i < size) {
        printf("str[%zu]: '%c' (ASCII: %d)\n", i, str[i], str[i]);
        i++; // Incrementamos el índice
    }

	// Imprimir cadena después de bzero
    printf("\n\nCadena después de bzero: \n");
    size_t i2 = 0;
    while (i2 < size) {
        printf("str[%zu]: '%c' (ASCII: %d)\n", i2, str2[i2], str2[i2]);
        i2++; // Incrementamos el índice
    }

	//TEST2  Llamar a ft_bzero con un puntero nulo = (segmentación fault)
	//char *str_null = NULL;
	//printf("Llamar a ft_bzero con un puntero nulo\n\n");
	//ft_bzero(str_null, 5);
	//printf("ft_bzero(str_null, 5): %s\n", str);

	//Función Original OBSOLETA
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_memmove()
{
	printf("\n==================================\n");
	printf("           ft _ memmove           \n");
	printf("==================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⣀⡴⢧⣀⠀⠀⣀⣠⠤⠤⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠘⠏⢀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠈⠙⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢶⣶⣒⣶⠦⣤⣀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⢀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣟⠲⡌⠙⢦⠈⢧⠀\n");
	printf("⠀⠀⠀⣠⢴⡾⢟⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡴⢃⡠⠋⣠⠋⠀\n");
	printf("⠐⠀⠞⣱⠋⢰⠁⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⢖⣋⡥⢖⣫⠔⠋⠀⠀⠀\n");
	printf("⠈⠠⡀⠹⢤⣈⣙⠚⠶⠤⠤⠤⠴⠶⣒⣒⣚⣩⠭⢵⣒⣻⠭⢖⠏⠁⢀⣀⠀⠀⠀⠀\n");
	printf("⠠⠀⠈⠓⠒⠦⠭⠭⠭⣭⠭⠭⠭⠭⠿⠓⠒⠛⠉⠉⠀⠀⣠⠏⠀⠀⠘⠞⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢤⣀⠀⠀⠀⠀⠀⠀⣀⡤⠞⠁⠀⣰⣆⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠘⠿⠀⠀⠀⠀⠀⠈⠉⠙⠒⠒⠛⠉⠁⠀⠀⠀⠉⢳⡞⠉⠀⠀⠀⠀⠀\n");
	printf("==================================\n");


	//TEST1
	char src[50] = "Hola Mundo 42!!";
	char dest[50] = "***** 42!!";
	printf("src %s\n", src);
	printf("dst %s\n\n", dest);
	printf("ft_memmove(dest, src, 5)\n");
	ft_memmove(dest, src, 4);
	printf("Resultado dst : %s\n\n", dest);

	//TEST2
	char src2[50] = "Hola Mundo 42!!";
	char dest2[50] = "***** 42!!";
	printf("memmove(dest, src, 5)\n");
	memmove(dest2, src2, 4);
	printf("Resultado dst : %s\n\n", dest2);

	//TEST3  Con puntero NULO a src ft_memmove
	//char *src3 = NULL;
	//char dest3[50] = "***** 42!!";
	//printf("ft_memmove(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//ft_memmove(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST4  Con puntero NULO a dst ft_memmove
	//char *dest3 = NULL;
	//char src3[50] = "***** 42!!";
	//printf("ft_memmove(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//ft_memmove(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST5  Con puntero NULO a src memmove
	//char *src3 = NULL;
	//char dest3[50] = "***** 42!!";
	//printf("memmove(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//memmove(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST6  Con puntero NULO a dst memmove
	//char *dest3 = NULL;
	//char src3[50] = "***** 42!!";
	//printf("memmove(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//memmove(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");

}

void test_memcpy()
{
	printf("\n==================================\n");
	printf("           ft _ memcpy            \n");
	printf("==================================\n");
	printf("	⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠇⡠⠊⠉⠙⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠘⠀⠌⢠⣤⣤⠀⠈⠳⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠸⣅⠀⢯⣿⡿⢀⢀⠀⠈⢵⣖⠒⠒⠠⢄⡀⠀⠀\n");
	printf("	⠀⠱⡀⠀⠀⠀⣿⣿⡷⠀⡡⠛⡄⠀⠀⠈⢱⠀⠀\n");
	printf("	⠀⠀⠹⣎⠀⠀⠉⠉⢁⣼⣠⠊⢹⡄⠤⡀⠀⡇⠀\n");
	printf("	⠀⠀⠀⠈⢳⣄⠀⡠⢂⠸⡌⠙⣎⠀⠀⠈⢢⡅⠀\n");
	printf("	⠀⠀⠀⠀⠀⡝⡙⠒⠿⣤⠟⢲⢾⠿⡢⣄⠀⠁⠀\n");
	printf("	⠀⠀⠀⠀⠀⢇⠇⠀⠀⢨⡀⠀⠳⣕⠰⣌⢢⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠈⠺⠤⢀⣀⣙⣦⡀⠀⠙⠢⢄⣣⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁\n");
	printf("==================================\n");
//TEST1
	char src[50] = "Hola Mundo 42!!";
	char dest[50] = "***** 42!!";
	printf("src %s\n", src);
	printf("dst %s\n\n", dest);
	printf("ft_memcpy(dest, src, 5)\n");
	ft_memcpy(dest, src, 4);
	printf("Resultado dst : %s\n\n", dest);

	//TEST2
	char src2[50] = "Hola Mundo 42!!";
	char dest2[50] = "***** 42!!";
	printf("memcpy(dest, src, 5)\n");
	memcpy(dest2, src2, 4);
	printf("Resultado dst : %s\n\n", dest2);

	//TEST3  Con puntero NULO a src ft_memcpy
	//char *src3 = NULL;
	//char dest3[50] = "***** 42!!";
	//printf("ft_memcpy(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//ft_memcpy(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST4  Con puntero NULO a dst ft_memcpy
	//char *dest3 = NULL;
	//char src3[50] = "***** 42!!";
	//printf("ft_memcpy(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//memcpy(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST5  Con puntero NULO a src memcpy
	//char *src3 = NULL;
	//char dest3[50] = "***** 42!!";
	//printf("memcpy(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//memcpy(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);

	//TEST6  Con puntero NULO a dst memcpy
	//char *dest3 = NULL;
	//char src3[50] = "***** 42!!";
	//printf("memcpy(dest, src, 5)\n");
	//printf("src %s\n", src3);
	//printf("dst %s\n\n", dest3);
	//memcpy(dest3, src3, 4);
	//printf("Resultado dst : %s\n\n", dest3);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strlcpy()
{
	printf("\n==================================\n");
	printf("           ft _ strlpy            \n");
	printf("==================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡶⠟⠛⠛⠛⠛⠻⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠋⣼⣿⠇⠀⠀⠀⠀⠀⠙⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⣠⣤⣶⠀⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⣶⣤⣄⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⣴⠿⠿⣿⣿⣧⡈⠛⠷⠶⢶⣶⣶⡶⠶⠾⠛⢁⣼⣿⡿⠿⠿⣦⠀⠀⠀\n");
	printf("⠀⠀⢸⡇⢰⣶⡄⢹⣿⣿⣷⣶⣦⣤⣤⣤⣤⣴⣶⣾⣿⣿⠋⢰⣶⠆⢸⡇⠀⠀\n");
	printf("⠀⠀⠀⠳⣄⣉⣁⣼⣿⣿⣿⣿⡿⠋⣁⣈⠙⢿⣿⣿⣿⣿⣦⣈⣁⣤⠟⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠙⠛⠿⢿⣿⣿⣿⣧⡈⠛⠛⢁⣼⣿⣿⣿⡿⠿⠛⠋⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢉⣉⣉⠁⠈⣉⣉⡉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀\n");
	printf("==================================\n");

	// TEST 1
	char src[] = "Hola Mundo 42!!";
	char dest[20];
	char src2[] = "Hola Mundo 42!!";
	char dest2[20];
	size_t result = ft_strlcpy(dest, src, sizeof(dest));
	printf("ft_strlcpy(dest, src, sizeof(dest)): %zu\n", result);
	printf("Destino: %s\n\n", dest);
	size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
	printf("strlcpy(dest, src, sizeof(dest)): %zu\n", result2);
	printf("Destino: %s\n", dest2);

	// TEST 2 size_t lo dejaos a 0

	char src3[] = "Hola Mundo 42!!";
	char dest3[20];
	char src4[] = "Hola Mundo 42!!";
	char dest4[20];
	size_t result3 = ft_strlcpy(dest3, src3, 0);
	printf("\nft_strlcpy(dest, src, 0): %zu\n", result3);
	printf("Destino: %s\n\n", dest3);
	size_t result4 = ft_strlcpy(dest4, src4, 0);
	printf("strlcpy(dest, src, 0): %zu\n", result4);
	printf("Destino: %s\n", dest4);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}
void test_strlcat()
{
	printf("\n==================================\n");
	printf("           ft _ strlcat           \n");
	printf("==================================\n");
	printf("  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⠀⠀⠀⣠⣶⠟⠋⠉⠀⠀⠀⠀⠈⠙⣷⡶⠖⠄⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⢀⣤⣶⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⣼⠟⢿⡄⠀⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⠀⢰⡟⠀⢈⠻⢷⡄⡆⠀⡆⠀⡸⠯⢄⠀⢻⡄⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⣠⠟⠀⡰⠁⠀⢀⣽⣾⣤⣷⣾⣦⠀⠀⠑⡀⢻⣄⠀⠀⠀⠀\n");
	printf("  ⠀⠀⢀⣴⠋⠀⠀⡇⠀⠀⠸⠿⠃⠀⠇⠙⠋⠀⠀⠀⡇⠀⠙⢷⣄⠀⠀\n");
	printf("  ⠀⣰⠟⠁⠀⠀⠀⢇⠀⠀⠀⠀⡼⠀⠘⡄⠀⠀⠀⢀⠇⠀⠀⠀⠙⢧⡀\n");
	printf("  ⢸⠃⠀⠀⠀⢀⣀⠈⠓⠠⠐⠋⠀⠀⠀⠈⠑⠒⠒⠉⠀⣠⡄⠀⠀⠀⢻\n");
	printf("  ⢿⠀⠀⠀⠀⣆⢈⣣⠤⠤⠖⠒⠒⠒⠒⠒⠒⠲⠶⠤⠾⣀⣆⠀⠀⢀⡼\n");
	printf("  ⠘⢷⣤⣀⣈⣉⣀⣤⣤⠶⠶⠶⠶⠶⠶⠶⠶⠶⣶⢤⣤⣤⣤⣤⠶⠛⠁\n");
	printf("  ⢀⣠⡤⠼⢯⣥⣄⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄⠀⠀⠀⠀⠀⠀⠀\n");
	printf("  ⣼⠋⣀⣀⣀⣀⡀⠈⠉⠳⢤⡀⠀⠀⠀⠀⠀⠀⠀⢸⣇⣤⣤⣄⣀⡀⠀⠀\n");
	printf("  ⢿⡎⠔⡡⠊⡠⠊⡱⢄⠀⠀⢹⣄⡀⠀⠀⢀⣀⣴⠟⠁⠀⠀⠀⠉⠻⡆⠀\n");
	printf("  ⠈⠳⣤⣀⠈⠀⠊⠠⠊⠃⣀⣼⠏⠉⠉⠉⠉⠙⢧⣄⡀⠀⠀⠀⣀⣴⠇⠀\n");
	printf("  ⠀⠀⠀⠉⠛⠛⠓⠒⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠋⠉⠀⠀⠀\n");

	// TEST 1

	char dest[30] = "Hola";
	char src[] = "Hola Mundo!";
	size_t result = ft_strlcat(dest, src, sizeof(dest));
	printf("\nsrc[] = 'Hola Mundo!'\n");
	printf("dest[30] = 'Hola'");
	printf("\nResultado de strlcat: %zu\n", result);
	printf("Destino: %s\n", dest);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_toupper()
{
	printf("\n=========================================\n");
	printf("           ft _ toupper                   \n");
	printf("==========================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⣛⣫⣭⣥⣤⣶⣦⣬⣭⡛⠷⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⢀⣴⠞⢩⣶⣿⣿⣿⣿⠿⠿⠿⠛⣯⣽⣶⣿⣷⣬⡻⣷⣄⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⢂⣴⣶⣶⣿⣿⣿⣿⡆⣿⣿⣿⣿⣿⣿⣿⣌⠻⣧⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⢠⡞⣽⣿⣿⣿⢣⣿⣿⣿⣿⣿⣿⣿⣿⣧⢹⣿⣿⣿⣿⣿⣿⣿⣦⡙⣷⡀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⢠⣟⣼⣿⣿⣿⢃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢘⠿⣿⣿⣿⣿⣿⣿⣿⣷⣸⣷⣄⠀⠀⠀\n");
	printf("⠀⠀⣴⣿⣿⣿⣿⣿⡏⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⣿⣷⣦⡽⠟⠛⠉⠉⠀⠈⠉⠙⠻⢷⣄⠀\n");
	printf("⢀⣾⠋⠀⣿⣿⣿⡿⣡⠹⣿⣿⣿⣿⣿⣿⣿⣿⡿⠴⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⡆\n");
	printf("⣼⡇⠀⠀⠙⢿⣟⣼⣿⣧⣿⣿⡿⠿⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⢸⡇\n");
	printf("⢻⡇⠀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣶⣾⣿⡇⢹⡆⠀⢀⡾⠁\n");
	printf("⠈⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⡶⡟⠉⠉⣿⣿⣿⣿⡇⠀⣷⡴⠛⠀⠀\n");
	printf("⠀⠀⠉⠓⢦⣤⣀⣀⣀⣀⣀⣤⣤⣤⠶⢶⣿⣿⣿⣿⣿⠃⢹⡀⠀⠘⠻⠿⠛⠀⢠⡿⠁⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠹⣆⢻⡀⠀⠀⠈⢧⠀⠀⠀⠙⠛⠻⡟⠁⠀⠀⠻⣤⣀⠀⠀⣀⣴⠟⠁⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠘⢷⣵⣄⠀⠀⠈⢷⡀⠀⠀⠀⠀⠹⣦⡀⠀⠀⠀⣉⣭⡿⠋⠁⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⣦⣤⣀⣙⣲⣤⣀⣀⣀⣀⣉⣽⡿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠙⠛⠛⠋⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	// TEST 1

	char c = 'a';
	char b = '5';

	printf("ft_toupper('%c') = %c\n", c, ft_toupper(c));
	printf("toupper('%c') = %c\n", c, toupper(c));

	// TEST 2

	printf("ft_toupper('%c') = %c\n", b, ft_toupper(b));
	printf("toupper('%c') = %c\n", b, toupper(b));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_tolower()
{
	printf("\n=========================================\n");
	printf("           ft _ tolower                  \n");
	printf("==========================================\n");
	printf("  ⣴⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣶⠀\n");
	printf("  ⣿⣿⡿⢿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠿⣿⣿⠇\n");
	printf("  ⢻⣿⣇⠀⠙⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠟⠀⢰⣿⣿⠀\n");
	printf("  ⢸⣿⣿⡄⠀⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠐⠃⠀⠀⣾⣿⡏⠀\n");
	printf("  ⠀⢿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠗⠀\n");
	printf("  ⠀⠘⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⡏⠅⠀\n");
	printf("  ⠀⠀⢹⣿⣿⣇⢀⣀⣤⣶⣶⣶⣦⣤⣄⡀⢠⣿⣿⡿⠐⠀⠀\n");
	printf("  ⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠈⠀⠀\n");
	printf("  ⠀⠀⠀⠀⢸⡟⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⣿⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⢸⡇⠀⠀⠈⠉⠛⠛⠉⠉⠀⠀⢠⡟⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⢸⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡇⠀⠀⠀⠐⠀\n");
	printf("  ⠀⠀⠀⠀⠀⢻⣿⣿⣦⠀⠀⠀⠀⣠⣾⣿⣿⠁⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⠀⠻⣿⣿⠀⠀⠀⠀⢻⣿⡿⠁⠀⠀⠀⠀⠀⠀\n");
	printf("  ⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠸⠋⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	char c = 'A';
	char b = '5';

	// TEST 1

	printf("ft_tolower('%c') = %c\n", c, ft_tolower(c));
	printf("tolower('%c') = %c\n", c, tolower(c));

	// TEST 1

	printf("ft_tolower('%c') = %c\n", b, ft_tolower(b));
	printf("tolower('%c') = %c\n", b, tolower(b));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strchr()
{
	printf("\n=========================================\n");
	printf("           ft _ strchr                    \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣾⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⣠⣴⣿⡿⠟⠛⠋⣽⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀\n");
	printf("	⠀⠀⢀⣾⣿⠟⠁⠀⠀⠀⣼⣿⣿⠏⢸⣿⣿⡏⠻⣿⣷⡀⠀⠀\n");
	printf("	⠀⢠⣿⡟⠁⠀⠀⠀⠀⣼⣿⣿⡟⠀⢸⣿⣿⡇⠀⠈⢻⣿⡄⠀\n");
	printf("	⢠⣿⡟⠀⠀⠀⠀⠀⣼⣿⣿⡿⠀⠀⢸⣿⣿⡇⠀⠀⠀⢻⣿⡄\n");
	printf("	⣸⣿⠇⠀⠀⠀⠀⣼⣿⣿⣿⠁⠀⠀⠘⢿⣿⡇⠀⠀⠀⠘⣿⣇\n");
	printf("	⢿⣿⠀⠀⠀⠀⣰⣿⣿⣿⣇⣀⣀⣀⣼⣦⡙⠇⠀⠀⠀⠀⣿⡿\n");
	printf("	⢸⣿⡇⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡦⠀⠀⠀⢸⣿⡇\n");
	printf("	⠀⢿⣿⡀⣸⣿⣿⣿⠟⠉⠉⠉⠉⠉⣿⠟⣡⡆⠀⠀⢀⣿⡿⠀\n");
	printf("	⠀⠈⠛⣰⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠠⠾⠿⠇⠀⣠⣿⡿⠁⠀\n");
	printf("	⠀⠀⣰⣿⣿⣿⡟⣀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣾⡿⠋⠀⠀⠀\n");
	printf("	⠀⣰⣿⣿⣿⡿⠰⠿⣿⣶⣶⣶⣶⣶⣶⣿⠿⠟⠉⠀⠀⠀⠀⠀\n");
	printf("	⠀⠉⠉⠉⠉⠁⠀⠀⠀⠈⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");

	// TEST 1

	char str[] = "Hola, mundo";
	char *result = ft_strchr(str, 'm');
	if (result)
	{
		printf("Buscando ft_strchr(str, 'm') en: 'Hola, mundo'\n");
		printf("Puntero a la primera 'm' : %s\n\n", result);
	}
	else
	{
		printf("No encontrado\n");

	}

	// TEST 2

	char str2[] = "Hola, mundo";
	char *result2 = strchr(str2, 'm');
	if (result2)
	{
		printf("Buscando strchr(str, 'm') en: 'Hola, mundo'\n");
		printf("Puntero a la primera 'm' : %s\n", result2);
	}
	else
	{
		printf("No encontrado\n");
	}
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strrchr()
{
	printf("\n=========================================\n");
	printf("           ft _ strrchr                   \n");
	printf("==========================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠖⠅⠀⠈⠲⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣦⢠⡴⠚⡇⣰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡞⠹⡤⠴⢇⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢃⠄⢀⡠⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡩⡇⠀⢓⠠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠊⡠⢂⠂⠀⠘⠈⢂⠀⢂⠱⡄⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⠂⡇⢀⣤⣀⠀⢁⢀⣕⠂⢆⢱⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⡌⠀⢿⡶⠿⡿⠀⢰⠡⢸⡀⠈⢋⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⢾⡋⠄⠐⢀⠎⠁⠎⢃⠀⠀⡄⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⡠⢎⠀⡌⠀⠃⠄⠀⡘⠀⢰⠀⠀⣄⡀⣇⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⣀⠀⠀⠀⣼⠂⢀⡗⠀⢠⠃⠈⠀⠐⠒⢹⠀⠀⢱⠈⠉⡂⠀⠀⠀⠀\n");
	printf("⠀⠀⠙⡍⠢⢎⣠⠒⠁⠀⠀⡘⠀⣸⢀⡀⠄⢚⡀⠀⠈⢆⠁⢸⠀⠀⠀⠀\n");
	printf("⢀⢴⢽⡳⠰⡸⠁⠀⠀⠀⡐⠃⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⢦⠜⡀⠀⠀⠀\n");
	printf("⠈⠁⢈⡿⠁⠀⠀⠀⠠⠊⠈⠀⠀⢄⠀⠀⠀⠀⠀⠇⠀⠀⠈⠃⣁⣩⣦⠄\n");
	printf("⠀⠀⠈⠀⠀⠀⠀⡐⠁⠀⠀⠀⠀⡜⠙⡄⠀⠀⠀⠈⡄⠀⠀⣇⣯⡷⢕⣄\n");
	printf("⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⡠⠊⠀⠀⠐⡄⠀⠀⠀⠙⠀⠀⠛⠀⠀⠀⠁\n");
	printf("===========================================\n");
	// TEST 1

	char str[] = "Hello, World!!";
	char *result = ft_strrchr(str, 'o');
	printf("Buscando ft_strrchr(str, 'o') en: 'Hello, World!!'\n");
	if (result)
	{
		printf("Puntero a la última 'o' : %s\n\n", result);
	}
	else
	{
		printf("No encontrado\n\n");
	}

	// TEST 2

	char str2[] = "Hello, World!!";
	char *result2 = strrchr(str2, 'o');
	printf("Buscando strrchr(str, 'o') en: 'Hello, World!!'\n");
	if (result2)
	{
		printf("Puntero a la última 'o' : %s\n", result2);
	}
	else
	{
		printf("No encontrado\n");
	}
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strncmp()
{
	printf("\n=========================================\n");
	printf("           ft _ strncmp                   \n");
	printf("==========================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠤⠶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⡀⣤⣤⡊⢁⣽⠶⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⡉⠻⣿⣏⠀⣼⡁⠷⢾⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⢀⣿⣿⡿⠛⣇⣀⣀⣁⣠⠿⣇⡀⢺⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠈⢿⣿⢷⣾⣬⣇⠉⣉⣶⠴⢿⣻⡿⠤⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠛⠙⠾⠏⠀⣿⣡⣤⣤⣄⣀⢙⣄⣠⣽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣟⠩⢿⣋⢹⣿⣛⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⠋⡼⠙⢮⠁⠈⢉⣿⡁⢹⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⢀⣠⢤⣶⣤⣀⣠⣾⣵⡞⠀⠀⢈⡇⠠⠊⠘⢹⣿⡾⡷⣄⠴⠚⣉⡙⠲⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⢀⡠⠚⠁⠉⠉⠁⢁⡞⠉⢛⡟⠀⠀⣠⣾⣅⠀⠀⢆⠀⡏⢦⡈⢿⣆⡉⠀⠀⠀⠈⠻⣆⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⡴⣯⠀⠀⠀⢀⣀⡴⢋⢈⡴⡏⠀⢠⣾⣿⣿⣿⡟⣒⠒⠛⣷⣠⠍⠢⡿⠹⣷⣦⡀⠀⠀⠘⣧⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠷⡏⠀⠀⣴⣿⣿⣖⣲⠏⠀⠘⡄⢹⡟⠁⠀⠀⢫⠙⠻⢍⣹⣿⡄⠀⢹⣾⣿⡿⠃⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⢀⡟⠀⠀⢧⣿⣟⣿⠃⠀⠀⢀⡇⠀⢳⡀⠀⠰⡀⠱⡄⠀⣸⣉⣷⡀⠀⠉⠉⠀⠀⠀⠀⡀⢸⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⣿⠀⢠⣄⠀⠀⠀⠀⢠⡴⠏⡙⠀⠀⣾⡻⣦⠀⠴⣤⢿⡄⡟⠘⡍⡻⠦⡄⠀⠀⣀⣤⡾⣡⠏⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠹⡀⢠⠀⠉⠉⠉⠉⠚⠓⠉⠁⠀⠀⣿⠱⡈⠣⡀⠠⠀⢿⠁⢀⣧⠉⠑⠒⠒⠩⠵⠿⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠱⡼⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⢹⣶⢷⡄⠤⣼⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⢸⠘⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣻⠏⠒⢧⡴⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠘⠶⣯⠼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡁⠀⣤⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠉⠛⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠀⣰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠻⣄⢤⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	// TEST 1

	char *str1 = "Hola";
	char *str2 = "Hola42Madrid";
	printf("str1: 'Hola'\n");
	printf("str2: 'Hola42Madrid'\n");
	printf("ft_strncmp(str1, str2, 4) = %d\n", ft_strncmp(str1, str2, 4));
	printf("ft_strncmp(str1, str2, 6) = %d\n", ft_strncmp(str1, str2, 6));

	// TEST 2

	char *str3 = "Hola";
	char *str4 = "Hola42Madrid";
	printf("\n\nstr1: 'Hola'\n");
	printf("str2: 'Hola42Madrid'\n");
	printf("strncmp(str1, str2, 4) = %d\n", strncmp(str3, str4, 4));
	printf("strncmp(str1, str2, 6) = %d\n", strncmp(str3, str4, 6));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_memchr()
{
	printf("\n=========================================\n");
	printf("           ft _ memchr                    \n");
	printf("==========================================\n");
	printf("	⣿⣶⡄⠀⡀⠀⣤⣴⣶⡄⢠⣶⣦⣤⠀⢀⠀⢠⣶⣿\n");
	printf("	⣿⣿⡇⢸⣿⠀⣿⣿⣿⡇⢸⣿⣿⣿⠀⣿⡇⢸⣿⣿\n");
	printf("	⢿⣿⡇⢸⣿⠀⣿⣿⣿⡇⢸⣿⣿⣿⠀⣿⡇⢸⣿⡿\n");
	printf("	⠈⢻⡇⢸⣿⠀⢿⣿⣿⣇⣸⣿⣿⡟⠀⣿⡇⢸⡟⠁\n");
	printf("	⣷⡄⠁⠸⣿⡀⠘⣿⣿⣿⣿⣿⣿⠃⢀⣿⠇⠈⢠⣾\n");
	printf("	⣿⣿⣆⠀⠻⣿⣦⡈⠻⣿⣿⠟⢁⣴⡿⠟⠀⣰⣿⣿\n");
	printf("	⣿⣿⣿⣷⣦⣄⡉⠛⠀⢹⡏⠀⠛⢁⣠⣴⣿⣿⣿⣿\n");
	printf("	⢿⡛⠛⠻⢿⣿⣿⣷⡄⢸⡇⢠⣾⣿⣿⡿⠟⠛⢛⡿\n");
	printf("	⢸⣿⣆⠀⠀⠈⠉⠛⠁⠈⠁⠈⠛⠉⠁⠀⠀⣰⣿⡇\n");
	printf("	⠈⢿⣿⣿⣿⣿⣧⠀⢿⣿⣿⡿⠀⣼⣿⣿⣿⣿⡿⠁\n");
	printf("	⠀⢀⣉⠉⢿⣿⣿⡄⠈⣉⣉⠁⢠⣿⣿⡿⠉⣉⡀⠀\n");
	printf("	⠀⠀⢻⣧⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⣸⡟⠀⠀\n");
	printf("	⠀⠀⠈⠛⠃⣠⣿⣿⣿⣿⣿⣿⣿⣿⣇⠈⠛⠁⠀⠀\n");
	printf("	⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	// TEST 1

	char str[] = "Hola42Madrid";
	char *result = ft_memchr(str, '4', strlen(str));
	printf("str: 'Hola42Madrid'\n");
	printf("ft_memchr(str, '4', strlen(str))");
	if (result)
	{
		printf("\nEncontrado: '4' %s\n", result);
	}
	else
	{
		printf("No encontrado\n");
	}

	// TEST 2

	char str2[] = "Hola42Madrid";
	char *result2 = memchr(str2, '4', strlen(str2));
	printf("\n\nstr: 'Hola42Madrid'\n");
	printf("memchr(str, '4', strlen(str))");
	if (result2)
	{
		printf("\nEncontrado: '4' %s\n", result2);
	}
	else
	{
		printf("No encontrado\n");
	}
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_memcmp()
{
	printf("\n=========================================\n");
	printf("           ft _ memcmp                    \n");
	printf("==========================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⠖⠛⠛⠉⠛⠓⠶⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⣠⣔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⣪⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⡄⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⡸⣡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢄⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⣿⠇⠀⢀⠀⡄⠀⣄⠀⠀⠱⣤⣀⠀⠀⠱⣄⠈⣆⢸⡛⠛⠳⠶⣤⣄⡀\n");
	printf("⣤⠴⠖⢻⠀⢠⢿⢰⢧⠀⢏⠑⠤⢄⣈⣢⣌⡁⠒⠻⠥⣸⢸⢦⠀⠀⠀⠀⠈⠉\n");
	printf("⠀⠀⠀⢸⡄⡜⠘⡏⠈⠳⢜⣆⠀⠀⠀⠀⠀⠀⠀⠀⠐⢹⠫⣸⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⢸⡹⣇⠀⠀⠀⠀⠀⠈⠁⠀⡀⠀⠀⠀⣀⣤⣶⣿⡟⠥⣀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠉⢿⠛⠛⢳⢶⣄⣀⣠⠀⢡⣀⣴⣾⡻⠁⠀⢸⠃⠀⠀⠑⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠸⣆⠀⠀⠛⠉⢀⡼⠆⢸⢲⠤⣀⠀⠀⢸⠉⡇⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⣿⠑⡀⠀⡰⠁⠙⠒⡖⠁⠀⠀⠙⢆⠘⠀⢹⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⡠⢿⡀⠁⢰⠁⠀⠀⠀⠃⠀⠀⡀⠀⠀⠂⠀⡾⠉⠉⠉⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠔⠉⠀⠈⠻⣄⠘⢠⣒⡒⣒⣶⣊⣥⣬⣇⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠈⢍⢁⡀⠤⠄⣀⠠⠀⣰⠃⠀⠀⠀⠀⢀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⢀⡀⠀⠀⠸⣦⣀⣀⣀⢀⣀⣀⣀⡴⠋⠀⣀⠤⠖⠊⠁⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠈⠉⠑⠒⠭⣉⠉⠉⠉⠉⠁⢀⠔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠤⣀⣀⠔⠁⠀\n");
	printf("===========================================\n");
	// TEST1

	char *str1 = "Hola42Madrid";
	char *str2 = "Hola42Madrid";
	char *str3 = "Hola43";

	printf("\n*str1 = Hola42Madrid\n");
	printf("*str2 = Hola42Madrid\n");
	printf("*str3 = Hola42Madrid\n\n");
	printf("ft_memcmp(str1, str2, 4) = %d\n", ft_memcmp(str1, str2, 4));
	printf("ft_memcmp(str1, str3, 6) = %d\n", ft_memcmp(str1, str3, 6));

	// TEST2

	char *str4 = "Hola42Madrid";
	char *str5 = "Hola42Madrid";
	char *str6 = "Hola43";
	printf("\nmemcmp(str1, str2, 4) = %d\n", memcmp(str4, str5, 4));
	printf("memcmp(str1, str3, 6) = %d\n", memcmp(str4, str6, 6));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strnstr()
{
	printf("\n=========================================\n");
	printf("           ft _ strnstr                   \n");
	printf("==========================================\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⢠⢶⠤⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⣠⡟⠞⢃⢈⢃⡢⣔⠭⡁⠒⢤⡀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⡔⣟⣍⠀⠘⡄⢆⠀⠉⠐⢭⣵⣄⠙⢆⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⢰⡐⢳⠱⣦⠀⠈⢆⠢⡀⠀⠀⠙⢷⡱⣌⢆⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠟⡀⠀⢣⠀⠑⢄⠀⠑⢌⠢⡀⠀⠈⠙⠾⣿⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⡀⢧⠀⠀⠐⠔⣄⠑⠀⡀⠇⢀⣩⣝⢦⣄⣿⡆⠀\n");
	printf("⠀⠀⠀⠀⠀⣇⠈⢧⡀⠀⠀⠈⠋⢆⣌⡓⣬⡙⠢⡤⣬⢚⣹⡀\n");
	printf("⠀⠀⠀⠀⠀⠸⡡⡈⠪⣰⠦⣄⡀⠀⠈⠘⡇⠈⢢⠤⠓⢕⣀⡇\n");
	printf("⠀⠀⠀⠀⠀⠀⢱⠒⠒⠚⠓⢢⢍⣁⡠⢖⣵⠖⠐⢧⠡⢠⡟⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⣸⠇⢸⡯⡘⠀⠀⣠⢞⠏⣼⠁⠀\n");
	printf("⠀⠀⠀⠀⠀⢀⠃⠀⠀⠀⠀⠫⢣⢈⣧⠈⢆⣴⡟⢁⠔⡍⠀⠀\n");
	printf("⠀⠀⠀⣠⣔⣿⠏⠰⣤⠢⣀⠀⢀⠉⠑⠫⣾⠻⠤⡡⠔⠁⠀⠀\n");
	printf("⠀⠀⣰⡟⣽⡕⠈⡼⢋⠒⠓⡏⢏⠆⣄⡀⠘⡆⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⡰⡫⠊⠁⠀⣸⠔⠁⠀⢠⣽⢚⠒⢞⢡⠷⡿⢦⡀⠀⠀⠀⠀\n");
	printf("⢰⠟⠀⣀⡤⠶⠓⠛⠛⠓⠻⡇⢺⠀⢀⠊⠐⠁⠀⠁⠀⠀⠀⠀\n");
	printf("⠀⠀⠋⠁⠀⠀⠀⠀⠀⠀⠀⠰⡈⡄⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢣⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");

	// TEST 1

	char *str = "Hola42Madrid";
	char *substr = "42Madrid";
	char *result = ft_strnstr(str, substr, strlen(substr));

	printf("\n*str = 'Hola42Madrid'\n");
	printf("*substr = '42Madrid'\n");
	printf("ft_strnstr(str, substr, ft_strlen(substr))");
	if (result)
	{
		printf("Encontrado: %s\n", result);
	}
	else
	{
		printf("No encontrado\n");
	}

	// TEST 2

	char *str2 = "Hola42Madrid";
	char *substr2 = "";
	char *result2 = ft_strnstr(str2, substr2, strlen(substr2));

	printf("\n*str = 'Hola42Madrid'\n");
	printf("*substr = ''\n");
	printf("ftstrnstr(str, substr, ft_strlen(substr))");
	if (result2)
	{
		printf("Encontrado: %s\n", result2);
	}
	else
	{
		printf("No encontrado\n");
	}
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_atoi()
{
	printf("\n=========================================\n");
	printf("           ft _ atoi                      \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣾⣿⣿⣿⣿⣷⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⠟⠛⠛⠻⠿⠿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⣠⣾⣿⣿⡿⢟⣿⡿⣼⣿⣿⣶⣤⣤⣦⣤⣀⠉⠻⢿⣿⣿⣷⣄⠀⠀⠀\n");
	printf("	⠀⠀⣴⣿⣿⡿⠋⠀⣼⡿⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣀⠀⠙⢿⣿⣿⣦⠀⠀\n");
	printf("	⠀⣼⣿⣿⡟⠁⠀⢸⡿⣱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣿⣿⣿⣧⠀\n");
	printf("	⢰⣿⣿⡟⠀⠀⠀⠀⠁⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣱⣿⣿⣿⡆\n");
	printf("	⣾⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠈⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢱⣿⠛⣿⣿⣷\n");
	printf("	⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢐⣛⣻⡿⠿⠿⣿⠿⢿⣿⣿⣿⢣⣿⠏⠀⣿⣿⣿\n");
	printf("	⢿⣿⣿⡄⠀⠀⠀⠀⠀⠀⢀⡿⠿⢿⣿⣿⣿⠃⠀⠀⠈⠙⠃⠛⠋⠀⢠⣿⣿⡿\n");
	printf("	⠸⣿⣿⣧⠀⠀⠀⠀⠀⠀⠾⣿⣿⣿⣷⣶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠇\n");
	printf("	⠀⢻⣿⣿⣧⡀⠀⠀⠀⣾⣿⣿⣶⣶⣿⠍⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⡟⠀\n");
	printf("	⠀⠀⠻⣿⣿⣷⣄⠀⣴⣶⣾⣿⣭⣽⡟⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠟⠀⠀\n");
	printf("	⠀⠀⠀⠙⢿⣿⣿⣷⣾⣭⣭⣿⣛⡛⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⡿⠋⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⣿⣿⣧⣤⣤⣤⣶⣶⣿⣿⣿⣿⠟⠋⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⢿⣿⣿⣿⣿⡿⠿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	char *num_str = "     123459";
	char *neg_num_str = "-9576";
	char *invalid_num_str = " 12asd34";
	char *num_str_invalid1 = "--123459";
	char *num_str_invalid2 = "+a9576";
	char *num_str_invalid3 = "  ++12asd34";

	printf("ft_atoi(\"%s\") = %d\n", num_str, ft_atoi(num_str));
	printf("ft_atoi(\"%s\") = %d\n", neg_num_str, ft_atoi(neg_num_str));
	printf("ft_atoi(\"%s\") = %d\n", invalid_num_str, ft_atoi(invalid_num_str));
	printf("ft_atoi(\"%s\") = %d\n", num_str_invalid1, ft_atoi(num_str_invalid1));
	printf("ft_atoi(\"%s\") = %d\n", num_str_invalid2, ft_atoi(num_str_invalid2));
	printf("ft_atoi(\"%s\") = %d\n", num_str_invalid3, ft_atoi(num_str_invalid3));

	// Test Original function
	printf("\n\nOriginal function:\n\n");
	printf("atoi(\"%s\") = %d\n", num_str, atoi(num_str));
	printf("atoi(\"%s\") = %d\n", neg_num_str, atoi(neg_num_str));
	printf("atoi(\"%s\") = %d\n", invalid_num_str, atoi(invalid_num_str));
	printf("atoi(\"%s\") = %d\n", num_str_invalid1, atoi(num_str_invalid1));
	printf("atoi(\"%s\") = %d\n", num_str_invalid2, atoi(num_str_invalid2));
	printf("atoi(\"%s\") = %d\n", num_str_invalid3, atoi(num_str_invalid3));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_calloc()
{
	printf("\n=========================================\n");
	printf("           ft _ calloc                    \n");
	printf("==========================================\n");
	printf("	⠰⣶⣶⣶⣄⠀⠀⠀⢀⣀⠀⠀⣠⣄⡀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠻⣿⣿⣿⡀⠀⠀⣿⠿⠷⢾⡏⠉⣿⣄⢀⣿⣷⡆⠀⠀\n");
	printf("	⢀⣠⣬⡁⢸⣿⣶⣿⣿⡇⠀⣾⡇⠀⣿⡏⠛⢻⣿⢧⣤⠀\n");
	printf("	⢸⣿⡿⡿⢻⠇⠀⢿⣿⡇⣠⣿⡇⣼⡿⠀⠀⣼⡏⢠⣾⠀\n");
	printf("	⢸⣿⡀⢀⣿⠀⣴⠈⣿⣿⣿⣿⣿⣿⠃⣾⣤⣿⠀⣼⣿⠀\n");
	printf("	⢸⣿⣧⢸⣿⣧⣿⣇⣿⣿⣿⣿⣿⣿⣾⣿⣿⣏⣼⣿⣿⠀\n");
	printf("	⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄\n");
	printf("	⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁\n");
	printf("	⠀⢹⣿⣿⣿⣿⣿⠉⠙⣿⣿⣿⣿⣿⡯⠉⢻⣿⣿⣿⣿⠀\n");
	printf("	⠀⠸⣿⣿⣿⣧⡀⠀⣠⣿⣿⣿⣿⣄⠀⢀⣼⣿⣿⣿⠇⠀\n");
	printf("	⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀\n");
	printf("	⠀⠀⠘⣿⣿⣿⣿⣿⡿⠿⠿⢿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀\n");
	printf("	⠀⠀⠀⠘⣿⣿⣿⣿⣷⣄⣀⣀⣠⣿⣿⣿⣿⠏⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⠿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");

	//Test1
	int i = 0;
	int *arr = (int *)ft_calloc(5, sizeof(int));
	printf("int *arr = (int *)ft_calloc(5, sizeof(int))\n");
	while (i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);

	//Test2
		int i2 = 0;
	int *arr2 = (int *)calloc(5, sizeof(int));
	printf("\nint *arr = (int *)calloc(5, sizeof(int))\n");
	while (i2 < 5)
	{
		printf("arr[%d] = %d\n", i2, arr2[i2]);
		i2++;
	}
	free(arr2);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_strdup()
{
	printf("\n=========================================\n");
	printf("           ft _ strdup                    \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀\n");
	printf("	⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀\n");
	printf("	⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀\n");
	printf("	⢰⣿⣿⠏⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⢹⣿⣿⡄\n");
	printf("	⢸⣿⣿⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⣿⣿⡇\n");
	printf("	⢸⣿⣿⡆⠀⠀⠸⣿⣿⠟⢹⡏⠻⣿⣿⠃⠀⠀⢸⣿⣿⡇\n");
	printf("	⢸⣿⣿⣧⠀⠀⠀⠈⠁⢀⣸⣇⠀⠈⠁⠀⠀⠀⣼⣿⣿⠇\n");
	printf("	⠀⣿⣿⣿⣷⣀⡀⠀⣴⣿⣿⣿⣷⣄⠀⢀⣀⣾⣿⣿⣿⠀\n");
	printf("	⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⢿⣿⣿⣿⠇⠀\n");
	printf("	⠀⠀⢻⣿⡝⠃⠈⠟⠉⣿⡟⢹⣿⠁⠻⠃⠈⢻⣿⡏⠀⠀\n");
	printf("	⠀⠀⠀⢻⣿⣄⢀⡄⠀⠘⠁⠀⠃⠀⢠⣄⣰⣿⡟⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠻⣿⣿⣿⠀⣼⡄⢠⣧⠀⣿⣿⣿⠏⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠈⠻⣿⣷⣿⣧⣼⣿⣷⣿⠟⠁⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
    // Test1

    char *str = "Hola42Madrid";
    char *duplicated = ft_strdup(str);

    printf("ft_strdup(str)\n");
    printf("Cadena original: %s\n", str);
    printf("Cadena duplicada: %s\n", duplicated);
    free(duplicated);

    // Test2

    char *str2 = "Hola42Madrid";
    char *duplicated2 = strdup(str2);

    printf("\nstrdup(str)\n");
    printf("Cadena original: %s\n", str2);
    printf("Cadena duplicada: %s\n\n", duplicated2);
    free(duplicated2);

    // TEST 3 Puntero NULO a nuestra ft

    //char *str3 = NULL;
    //printf("\nstrdup(str)\n");
    //printf("Cadena original: %s\n", str3);
    //char *duplicated3 = ft_strdup(str3);


    //printf("Cadena duplicada: %s\n", duplicated3);
    //free(duplicated3);

     //TEST 4 Puntero NULO a la ORIGINAL

    //char *str3 = NULL;
    //char *duplicated3 = ft_strdup(str3);

    //printf("\nstrdup(str)\n");
    //printf("Cadena original: %s\n", str3);
    //printf("Cadena duplicada: %s\n", duplicated3);
    //free(duplicated3);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_substr()
{
	printf("\n=========================================\n");
	printf("           ft _ substr                    \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⣴⡿⢛⣿⣿⣿⣿⣿⣿⣿⣿⡛⢿⣦⡀⠀⠀⠀\n");
	printf("	⠀⠀⣰⣿⡟⠀⠀⣿⣿⠿⠛⠛⠿⣿⣿⠀⠀⢻⣿⣆⠀⠀\n");
	printf("	⠀⣰⣿⣿⣿⡀⠀⠹⣿⠀⠀⠀⠀⣿⠏⠀⢀⣿⣿⣿⣧⠀\n");
	printf("	⢠⣿⣿⣿⣿⣿⣦⣤⣘⣇⠀⠀⣸⣁⣤⣴⣿⣿⣿⣿⣿⡄\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⠟⠛⠛⠻⣿⣿⣿⣿⠟⡛⠛⠻⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣇⠀⠚⠛⠓⠈⠛⠛⠁⠚⠛⠓⠀⣹⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣷⣤⣤⣄⠀⠀⠀⠀⣠⣤⣤⣾⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⣦⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⠘⠻⠿⣿⣿⣿⣿⣿⣿⠛⠛⠛⠛⣿⣿⣿⣿⣿⣿⠿⠟⠃\n");
	printf("	⠀⠀⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠉⠋⠉⠉⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	// TEST 1

	char *str = "Hola mundo";
	char *sub = ft_substr(str, 5, 5);

	printf("\nstr: 'Hola mundo'\n");
	printf("\nft_substr(str, 5 ,5)\n");
	printf("Subcadena: %s\n\n", sub);
	free(sub);


	char *str2 = "Hola mundo";
	char *sub2 = ft_substr(str2, 5, 5);

	printf("\n\nstr: 'Hola mundo'\n");
	printf("\nsubstr(str, 5 ,5)\n");
	printf("Subcadena: %s\n\n", sub2);
	free(sub2);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}
void test_strjoin()
{
	printf("\n=========================================\n");
	printf("           ft _ strjoin                   \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀\n");
	printf("	⠀⠀⣠⣿⣿⣿⡿⠻⣿⣿⣿⣿⣿⣿⠟⢿⣿⣿⣿⣆⠀⠀\n");
	printf("	⠀⢠⣿⣿⣯⣉⣿⣄⣹⣿⣿⣿⣿⣏⣠⣟⡉⣽⣿⣿⡄⠀\n");
	printf("	⠀⢸⣿⣿⠟⠛⠉⠉⠛⠻⣿⣿⠟⠛⠉⠙⠛⢿⣿⣿⡇⠀\n");
	printf("	⣠⣾⣿⣿⣶⣾⡀⠀⣴⣦⣾⣷⣴⣆⠀⣀⣷⣾⣿⣿⣷⡄\n");
	printf("	⢻⣿⣿⣿⣧⠈⢿⡀⠹⣄⣈⣁⣰⠏⢠⡿⠀⣼⣿⣿⣿⡇\n");
	printf("	⠀⣿⣿⣿⣿⣧⠀⣿⣀⣹⣿⣿⣇⣠⣿⠀⣼⣿⣿⣿⣿⠀\n");
	printf("	⠀⣿⣿⣿⣿⣿⡿⠿⠛⠛⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣿⠀\n");
	printf("	⠀⢿⣿⣿⣿⣿⣀⣀⣤⣴⣶⣶⣦⣤⣀⣀⣿⣿⣿⣿⡟⠀\n");
	printf("	⠀⠘⣿⣿⣿⡟⢻⣿⠉⣿⡇⢸⣿⠉⣿⡟⢻⣿⣿⣿⠁⠀\n");
	printf("	⠀⠀⠸⣿⣿⡇⢸⣿⠀⣿⡇⢸⣿⠀⣿⡇⢸⣿⣿⠇⠀⠀\n");
	printf("	⠀⠀⠀⠹⣿⡇⢸⣿⠀⣿⡇⢸⣿⠀⣿⡇⢸⣿⠏⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠁⠈⠉⠀⠉⠁⠈⠉⠀⠉⠁⠈⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	char const *str1 = "Hola mundo";
	char const *str2 = " 42!!!";
	char *str3 = ft_strjoin(str1, str2);

	printf("\n str1: 'Hola mundo'\n");
	printf("\n str2: ' 42!!!'\n");
	printf("\nft_strjoin(str1, str2): %s\n\n", str3);
	free(str3);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}


void test_strtrim()
{
	printf("\n=========================================\n");
	printf("           ft _ strtrim                   \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⠀⠀\n");
	printf("	⠀⢀⣾⣿⡄⠀⠀⠀⢀⣤⡶⠿⠛⠛⠛⠛⠛⠛⠿⢶⣤⡀⠀⠀⠀⢠⣿⣷⡀⠀\n");
	printf("	⠀⣸⣿⣿⣧⠀⣠⣾⠟⠉⣠⣴⣶⣶⠀⠀⣶⣶⣦⣄⠉⠻⣷⣄⠀⣼⣿⣿⣇⠀\n");
	printf("	⢀⣿⣿⣿⣿⣶⡟⠁⠀⢸⣿⣿⣿⣿⠀⠀⣿⣿⣿⣿⡇⠀⠈⢻⣶⣿⣿⣿⣿⡀\n");
	printf("	⢸⣿⣿⣿⣿⣿⣷⡄⠀⢸⣿⣿⣿⣿⣤⣤⣿⣿⣿⣿⡇⠀⢠⣾⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣾⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇\n");
	printf("	⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀\n");
	printf("	⠀⠈⣿⣿⣿⣿⣿⡎⠙⠻⢿⣿⣿⡇⠀⠀⢸⣿⣿⡿⠟⠋⢱⣿⣿⣿⣿⣿⠁⠀\n");
	printf("	⠀⠀⠈⢿⣿⣿⣿⣿⣦⡀⠀⠙⢿⣷⣄⣠⣾⡿⠋⠀⢀⣴⣿⣿⣿⣿⡿⠁⠀⠀\n");
	printf("	⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠉⠻⢿⣿⣿⣿⠟⠛⠉⠉⠛⠻⣿⣿⣿⡿⠟⠉⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠀⠀⠀⠀⠀⠀⠀⠀⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
    // TEST1 recortar los espacios de inicio y fin (3 espacios)
    char *str = " ..  Hola mundo ..  ";
    char *set = "' .'";

	printf("str: %s\n", str);
	printf("set: %s\n", set);
    printf("Cadena recortada: '%s'\n\n", ft_strtrim(str, set));
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}


void test_split()
{
	printf("\n=========================================\n");
	printf("           ft _ split                     \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⣾⣿⣿⣿⣿⣿⣿⣷⣦⣤⡀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⠿⠛⠛⠉⠉⠛⠛⠿⣿⣿⣿⣿⣿⣦⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⣼⣿⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣿⣧⠀⠀⠀\n");
	printf("	⢰⣶⣶⣿⣿⠏⠀⠀⠀⠀⠀⣠⣾⣿⣿⣷⣄⠀⠀⠀⠀⠀⠙⢿⣿⣶⣶⡆\n");
	printf("	⠈⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠁\n");
	printf("	⢰⣶⣶⣶⣶⡄⠀⠀⠀⠀⠀⠙⢿⣿⣿⡿⠋⠀⠀⠀⠀⠀⢀⣴⣶⣶⣶⡆\n");
	printf("	⠀⠀⠀⢻⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣿⣿⡟⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠻⣿⣿⣿⣿⣷⣶⣤⣄⣀⣀⣠⣤⣶⣾⣿⣿⣿⣿⠟⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⢿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠁⠀⠀⠀⠀⠀⠀⠀\n");
	printf("===========================================\n");
	char	**result;

	const char *str = "¡Hola, Mundo 42!";
	char c = ' ';
	int i = 0;
	result = ft_split(str, c);
	printf("\n*str = '¡Hola, Mundo 42!'\n");
	printf("*c = ' '\n\n");
	while (result && result[i] != NULL)
	{
        printf("Indice %d: %s\n", i + 1, result[i]);
        i++;
	}
	printf("\n");
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_itoa()
{
	printf("\n=========================================\n");
	printf("           ft _ itoa                      \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠶⠶⠶⠶⠶⠶⢀⣾⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⣀⡴⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⢠⣿⡿⠀⠙⠳⢦⣀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⣠⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⠃⠀⠀⠀⠀⠉⠳⣄⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣇⣠⣴⡶⠀⠀⠀⠀⠈⠳⣄⠀⠀⠀\n");
	printf("	⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠙⣆⠀⠀\n");
	printf("	⠀⣰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀\n");
	printf("	⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⢿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄\n");
	printf("	⢸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⢠⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇\n");
	printf("	⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⠃⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿\n");
	printf("	⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣷⣾⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿\n");
	printf("	⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇\n");
	printf("	⠈⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠁\n");
	printf("	⠀⠘⣇⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃⠀\n");
	printf("	⠀⠀⠘⢧⠀⠀⠀⠀⠀⠀⠘⠋⠉⣼⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠃⠀⠀\n");
	printf("	⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⢰⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠈⠳⣤⡀⠀⠀⢀⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠞⠁⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⠂⣾⣿⠃⠀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡿⠁⠉⠛⠛⠛⠛⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("==========================================\n");

	int num = 35;
	printf("ft_itoa(%d) = %s\n\n", num, ft_itoa(num));
	printf("itoa(%d) = %s\n\n", num, ft_itoa(num));
}
char  aux_strmapi(unsigned int i, char c)
{
	// Utilizaremos solo uno de los 2 argumentos
	printf("\nNuestro indice: %d",i);
	if(c >= 'A' && c <= 'Z')
		c = (c + 32);
	return(c);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}
void test_strmapi()
{
	printf("\n=========================================\n");
	printf("           ft _ strmapi                   \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⣀⣤⣤⣶⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀\n");
	printf("	⣀⣴⣶⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀\n");
	printf("	⠁⠀⠀⠈⠉⠛⣿⣿⣿⣿⣿⣷⣦⣀⢠⣆⣸⡆⢀⣤⣿⣿⣿⣿⣿⣿⠟⠋⠉⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠸⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠏⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("==========================================\n");
  	char s[] = "HOLA MUNDO!!";
	printf("Indice de nuestra string = %s", s);
	printf("\nLa devolución de ft_strmapi(s, aux_strmapi) = %s\n", ft_strmapi(s, aux_strmapi));
}
void  aux_striteri(unsigned int a, char *s)
{
	// Utilizaremos solo uno de los 2 argumentos
	printf("\nNuestro indice: %d",a);
	if(s[0] >= 'a' && s[0] <= 'z')
		s[0] = (s[0] - 32);
}
void test_striteri()
{
	printf("\n=========================================\n");
	printf("           ft _ striteri                  \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⣼⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⣧⠀⠀\n");
	printf("	⠀⣴⡿⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⢿⣦⠀\n");
	printf("	⢰⣿⣇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣸⣿⡆\n");
	printf("	⠀⠙⣿⣿⣿⣿⠀⢈⣉⡛⠛⠿⢿⣿⣿⡿⠿⠛⢛⣉⡁⠀⣿⣿⣿⣿⠋⠀\n");
	printf("	⠀⠀⠙⢿⣿⣿⣇⠘⠿⠿⠟⢀⣴⣿⣿⣦⡀⠻⠿⠿⠃⣸⣿⣿⡿⠋⠀⠀\n");
	printf("	⠀⠀⠀⠀⣿⣿⣿⣷⣦⣴⣶⣿⡿⠛⠛⢿⣿⣶⣦⣴⣾⣿⣿⣿⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠘⣿⣏⠛⢿⡿⠛⠁⠀⠀⠀⠀⠈⠛⢿⡿⠛⣹⣿⠃⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠹⣿⣆⠀⠀⠀⣤⣴⣶⣶⣦⣤⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠹⣿⣧⡀⠀⠉⠀⠀⠀⠀⠉⠀⢀⣼⣿⠏⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣤⡀⠀⠀⠀⠀⢀⣤⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣿⣶⣤⣤⣶⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("==========================================\n");
	char s[] = "hola mundo!!";
	printf("\nIndice de nuestra string = %s", s);
	ft_striteri(s, aux_striteri);
	printf("\nConvertida a Mayúsculas = %s\n", s);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_putchar_fd()
{
	printf("\n=========================================\n");
	printf("           ft _ putchar_fd                \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⠛⠛⠛⠛⠛⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⣄⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⢀⡿⠀⠀⢀⣀⣤⡴⠶⠶⢦⣤⣀⡀⠀⠀⢻⡆⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠘⣧⡀⠛⢻⡏⠀⠀⠀⠀⠀⠀⠉⣿⠛⠂⣼⠇⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⢀⣤⡴⠾⢷⡄⢸⡇⠀⠀⠀⠀⠀⠀⢀⡟⢀⡾⠷⢦⣤⡀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⡾⢁⣀⣀⣀⣻⣆⣻⣦⣤⣀⣀⣠⣴⣟⣡⣟⣁⣀⣀⣀⢻⡄⠀⠀⠀\n");
	printf("	⠀⠀⢀⡾⠁⣿⠉⠉⠀⠀⠉⠁⠉⠉⠉⠉⠉⠀⠀⠈⠁⠈⠉⠉⣿⠈⢿⡄⠀⠀\n");
	printf("	⠀⠀⣾⠃⠀⣿⠀⠀⠀⠀⠀⠀⣠⠶⠛⠛⠷⣤⠀⠀⠀⠀⠀⠀⣿⠀⠈⢷⡀⠀\n");
	printf("	⠀⣼⠃⠀⠀⣿⠀⠀⠀⠀⠀⢸⠏⢤⡀⢀⣤⠘⣧⠀⠀⠀⠀⠀⣿⠀⠀⠈⣷⠀\n");
	printf("	⢸⡇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠘⢧⣄⠁⠈⣁⣴⠏⠀⠀⠀⠀⠀⣿⠀⠀⠀⠘⣧\n");
	printf("	⠈⠳⣦⣀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠻⠶⠶⠟⠀⠀⠀⠀⠀⠀⠀⣿⠀⢀⣤⠞⠃\n");
	printf("	⠀⠀⠀⠙⠷⣿⣀⣀⣀⣀⣀⣠⣤⣤⣤⣤⣀⣤⣠⣤⡀⠀⣤⣄⣿⡶⠋⠁⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⢿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿⠀⠀⠀⠀⠀\n");
	printf("==========================================\n");
	int	i;
	i = 0;
	char s[] = "Hola mundo!!";
	printf("\nIterando esta string: Hola mundo!!  hacia ft_putchar_fd()\n");
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_putstr_fd()
{
	printf("\n=========================================\n");
	printf("           ft _ putstr_fd                 \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⣶⡤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠠⣤⣤⣤⣤⣄⡀⣿⣿⣷⣳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣼⣿⣿⣿⣇⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣾⣿⣿⣿⣿⣷⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⡿⠗⠂⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⣤⣴⣾⣟⣿⣿⣿⠟⢀⣿⠟⢁⣟⡿⢻⣿⣷⣤⠤⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠉⠙⠛⢟⢹⣽⠙⠦⣨⣋⡴⠚⢋⣇⣾⠟⠋⠉⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⠓⢷⡏⠍⣴⠀⠁⠀⡶⠚⠛⠓⠂⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⢀⡌⡿⡤⡘⠃⢠⡊⠁⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⣠⣤⣾⡟⣿⣴⢏⡀⠓⠰⠼⣠⠑⠀⠀⢶⣼⡟⢲⣴⡀⠀⠀⠀⠀\n");
	printf("	⠀⠀⡖⣭⠓⣿⣾⡏⣿⣿⣦⣵⠀⠀⠀⡆⠀⢠⣶⣿⣿⢩⣼⣿⠘⣥⠒⡄⡄\n");
	printf("	⠀⣼⡇⣿⡰⡄⣿⡵⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢢⢜⢣⠱⢠⠒⣱⡅\n");
	printf("	⣼⣿⣿⣸⡗⣷⡘⣷⢋⢶⣛⢿⣿⣿⣿⣿⣿⠿⢋⡴⢋⡌⢂⠧⣘⡣⣡⣿⣿\n");
	printf("==========================================\n");

	char s[] = "Hola mundo!!";
	printf("\nHola mundo!!  =  Hacia ft_putstr_fd()\n");
	ft_putstr_fd(s, 1);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_putendl_fd()
{
	printf("\n=========================================\n");
	printf("           ft _ putendl_fd                 \n");
	printf("==========================================\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣶⣶⣶⣶⣆⢰⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿⠀⣿⣿⣿⣿⣶⣄⡀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⠃⠀⣿⠿⠛⠀⠻⢿⣿⣿⣿⣿⣿⣦⠀⠀⠀⠀\n");
	printf("	⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠃⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀\n");
	printf("	⠀⢠⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⢛⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀\n");
	printf("	⠀⣾⣿⣿⣿⣿⣿⠿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀\n");
	printf("	⢸⣿⣿⣿⣿⣛⡉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⢠⡈⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣟⣉⣁⠀⠀⠀⠀⠀⠀⠀⠀⣻⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠇⠀⠀⣠⣴⣿⣿⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
	printf("	⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠙⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇\n");
	printf("	⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠈⠁⠀⢨⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀\n");
	printf("	⠀⠈⢿⣿⣿⣿⣿⣿⠿⢿⣿⡇⠀⠀⠀⠀⠀⣤⠀⢸⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀\n");
	printf("	⠀⠀⠈⢿⣿⣿⣿⠁⣴⣾⡿⠁⠀⠀⠀⠀⠀⠘⡇⢸⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀\n");
	printf("	⠀⠀⠀⠀⠙⢿⣿⡀⠿⣿⡧⠀⠀⠀⠀⠀⠀⢠⡄⢸⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠙⠻⢶⣤⣤⣾⠀⠀⠀⠀⢠⣼⡇⢸⣿⡿⠟⠋⠀⠀⠀⠀⠀⠀\n");
	printf("	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠃⠀⠀⠀⠠⠿⠟⠃⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("==========================================\n");
	char s[] = "Hola mundo!!";
	printf("\nHola mundo!!   =  Hacia ft_putendl_fd()\n");
	ft_putendl_fd(s, 1);
	printf("Aquí estamos después del salto de línea de ft_putendl\n");
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}

void test_putnbr_fd()
{
	printf("\n=========================================\n");
	printf("           ft _ putnbr_fd                 \n");
	printf("==========================================\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⡀⠀⢀⣀⠀⠀⡀⠀⠀⠀⠀⠀⠀\n");
	printf("		⢰⣦⣄⣾⠻⣦⡾⠻⣦⡟⠹⣦⡾⢻⣤⡾⢷⣀⣴⡆\n");
	printf("		⢸⡇⠙⠃⠀⠙⠁⠀⠉⠀⠀⠉⠀⠀⠛⠀⠈⠛⢹⡇\n");
	printf("		⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n");
	printf("		⠘⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n");
	printf("		⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n");
	printf("		⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇\n");
	printf("		⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀\n");
	printf("		⢀⡿⠀⣀⣠⣄⣀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣀⡀⢿⡄\n");
	printf("		⠸⣷⠟⠉⠀⠀⠉⠻⣦⠀⠀⢠⡾⠋⠁⠀⠈⠙⢾⡇\n");
	printf("		⢰⡏⠀⠀⣀⡀⠀⠀⠸⡇⠀⡿⠀⠀⢀⣀⠀⠀⠈⣷\n");
	printf("		⠸⣇⠀⠀⠛⠃⠀⠀⢰⡇⠀⣧⠀⠀⠘⠛⠁⠀⢀⡿\n");
	printf("		⢀⡿⣦⡀⠀⠀⢀⣠⡟⠀⠀⠘⣧⣀⠀⠀⠀⣠⣾⡇\n");
	printf("		⢸⢩⠈⠙⠛⠛⠋⠁⠳⣤⣤⡼⠃⠉⠛⠛⠛⠉⡨⣳\n");
	printf("		⠘⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠃\n");
	printf("		⠀⠘⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡃⠀\n");
	printf("==========================================\n");

	char s[] = "12345";
	printf("\nEl entero: 12345   =  Hacia ft_putnbr_fd()\n");
	ft_putendl_fd(s, 1);
	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
}



// Función para liberar la memoria del contenido
void	del(void *content)
{
	free(content);
}

// Función para imprimir el contenido (Pero.....asumimos que es un string)
void	print_content(void *content)
{
	printf("%s\n", (char *)content);  // Lo casteamos primero a char *
}

// Función que transforma el contenido (duplicar string en este caso)
void	*duplicate_content(void *content)
{
	char *str = (char *)content; // Lo casteamos primero
	char *new_str = strdup(str); // Usamos strdup para duplicar el string
	return (new_str);
}
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
int	test_bonus(void)
{
	t_list	*lst = NULL;
	t_list	*new_node;
	t_list	*last_node;
	t_list	*mapped_lst;
	t_list	*tmp;

	printf("\n▗▄▄▖  ▗▄▖ ▗▖  ▗▖▗▖ ▗▖ ▗▄▄▖\n");
	printf("▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌▐▌   \n");
	printf("▐▛▀▚▖▐▌ ▐▌▐▌ ▝▜▌▐▌ ▐▌ ▝▀▚▖\n");
	printf("▐▙▄▞▘▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘▗▄▄▞▘\n\n");

	printf("⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠤⠶⠦⣤⣄⣀⣀⡤⠶⢶⣶⠤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⢀⡤⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠃⠉⠛⢾⣏⠀⠀⠀⣈⣹⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⢀⡶⡫⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠙⢷⡴⠛⠉⠀⠀⠙⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⣰⠋⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⡆⢀⠀⠀⢷⣄⡀⠀⠀⠀⠎⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⢠⠏⢸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⣶⣦⠀⣼⠁⠉⠙⠳⣤⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⣼⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣦⡄⠀⠀⠀⣼⠷⣄⠀⠀⠀⠈⢷⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⢿⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⣠⠞⢁⣀⡿⠟⢲⣦⡀⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠸⣄⠘⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡄⠘⢿⡠⢲⣿⢋⡷⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠹⣦⡹⣤⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⢶⡏⠀⠀⠀⢳⡀⠘⢷⣈⣩⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⡏⠙⠿⠲⡶⠶⣶⠒⠒⠋⠙⠏⠀⡼⠁⠀⠀⠀⠀⢿⣤⠞⢹⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⢹⡶⢤⡾⠁⠀⠈⠳⠦⣄⡠⠴⠊⠁⠀⠀⠀⠀⠀⠀⠁⠀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⣹⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⢀⡼⠁⣤⠖⢲⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⣶⡄⠉⢳⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⢠⡟⠀⠀⠀⣠⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⢚⣥⠟⠁⠀⠀⠀⠹⣷⣶⣍⠛⢶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⣾⠀⠀⣠⠞⣿⠀⠀⠀⠀⠀⣀⣀⣴⣖⣿⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠈⢻⡝⣧⠀⢻⡟⢷⡄⠀⠀⠀⠀⠀⠀\n");
	printf("⢿⣷⠟⠁⠀⠙⠓⠒⠒⠿⠯⠿⠶⠛⠉⠙⠛⠛⢦⡀⠀⠀⠀⠀⠀⠀⠀⢠⡇⢸⣧⠈⣿⡄⠙⣆⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣤⣀⠀⠀⠀⣠⡞⠀⢸⣿⠀⠈⣷⠀⠸⣧⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⡾⢸⡟⠉⡿⠒⢺⡍⠀⠀⣸⡟⠀⠀⢹⡇⠀⠹⣆⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⢸⣿⣸⣇⠀⣸⣷⣀⡴⡏⠀⣠⡶⠟⠁⠀⠀⢻⡆⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣯⡿⠸⣿⠈⠙⡷⣟⠉⠉⢠⠇⠻⣯⠀⠀⠀⠀⠀⠈⢳⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣼⠀⠀⢻⠀⢸⠁⣿⠀⠀⣾⡟⠀⢸⡿⣧⠀⠀⠀⠀⠸⡆⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠹⣆⠀⠸⡇⡿⠀⢿⠀⢰⠃⠀⢀⣾⠁⢹⡄⠀⠀⠀⠀⣿⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡶⣒⠚⢓⣶⣯⠍⠛⠛⠻⣦⠀⣿⡇⠀⠸⣦⡏⠄⢀⣾⠃⠀⢸⡇⠀⠀⠀⠀⢹⡀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣤⣿⣿⣉⣿⣭⣿⣷⣦⡄⠺⣇⢹⡇⠀⠀⡿⠀⢀⣾⠋⠀⠀⢸⡇⠀⠀⠀⠀⢹⡇\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⢀⡞⢁⣀⣠⣿⣧⣥⣦⣀⡈⠻⠇⠰⣿⡌⣿⠀⣼⠁⢀⣾⠃⠀⠀⠀⢸⡇⠀⠀⠀⠀⢸⡇\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠈⢷⣤⠶⠴⣄⣽⠿⠿⠿⢿⣇⠀⠀⢹⣿⣾⣷⡇⣰⠟⠁⠀⠀⠀⢀⣾⡇⠀⠀⠀⠀⣸⠁\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⢠⡏⠀⣤⣴⡾⢧⣴⣶⣤⣄⡉⠀⠀⠀⢻⠛⠛⢻⡟⠒⠒⠒⠒⠒⠛⠉⠀⠀⠀⠀⢀⣿⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠻⣆⠀⠀⠀⠀⣴⡇⢸⣿⢷⣄⠀⠀⢸⡇⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠦⣀⣠⡟⢀⣼⣫⣬⠿⠦⣤⡞⠀⠀⢠⡟⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡾⠏⣿⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠀⠀⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠷⠶⠶⠿⠇\n\n\n");

    	printf("+-------------------+\n");
    	printf("| lst (ptr a        |\n");
    	printf("| puntero t_list)   |  <--- 1. Este es el puntero que se pasa a las funciones\n");
    	printf("+-------------------+\n");
     	printf("         |\n");
     	printf("         v\n");
    	printf("+-------------------+\n");
    	printf("| lst_head (ptr a   |  <--- 2. Este es el puntero(lst actual) que apunta al primer nodo\n");
    	printf("| el primer nodo)   |\n");
    	printf("+-------------------+\n");
    	printf("          |\n");
    	printf("          v\n");
    	printf("+-------------------+       +-------------------+       +-------------------+\n");
    	printf("|     Nodo 1        |  +--->|     Nodo 2        |  +--->|     Nodo 3        |--->NULL\n");
    	printf("+-------------------+  |    +-------------------+  |    +-------------------+\n");
    	printf("| content           |  |    | content           |  |    | content           |\n");
    	printf("| (e.g., Dato 1)    |  |    | (e.g., Dato 2)    |  |    | (e.g., Dato 3)    |\n");
    	printf("+-------------------+  |    +-------------------+  |    +-------------------+\n");
    	printf("| next  (&dirección)|--+    | next  (&dirección)|--+    |next  (&dirección) |\n");
    	printf("|-------------------|       |-------------------|       |-------------------|\n");



	// Crear nodos y añadirlos a la lista
	new_node = ft_lstnew(strdup("Nodo 1"));
	ft_lstadd_back(&lst, new_node);//Empezamos añadiendo 1 Nodo
	new_node = ft_lstnew(strdup("Nodo 2"));
	ft_lstadd_back(&lst, new_node);// este lo enviamos atrás
	new_node = ft_lstnew(strdup("Nodo 3"));
	ft_lstadd_front(&lst, new_node); // Este al frente
	new_node = ft_lstnew(strdup("Nodo 4"));
	ft_lstadd_front(&lst, new_node); // Volvemos a añadir al frente

	// Imprimir la lista completa
	printf("\nLista después de añadir nodos:\n");
	printf("\nft_lstiter(lst, print_content)\n");
	ft_lstiter(lst, print_content);

	// Tamaño de la lista
	printf("\nTamaño de la lista ft_lstsize(lst) : %d\n", ft_lstsize(lst));

	// Último nodo
	last_node = ft_lstlast(lst);
	printf("\nÚltimo nodo ft_lstlast(lst) : %s\n", (char *)last_node->content);

	// Crear una nueva lista mapeada
	mapped_lst = ft_lstmap(lst, duplicate_content, del);
	printf("\nLista mapeada (duplicada) ft_lstiter(mapped_lst, print_content) :\n");
	ft_lstiter(mapped_lst, print_content);

	// Borrar el primer nodo (Nodo 1)
	printf("\nBorrar el primer Nodo:\n");
	tmp = lst->next;        // Guarda el siguiente nodo antes de borrar
	ft_lstdelone(lst, del); // Borra el nodo actual
	lst = tmp;              // Avanza al siguiente nodo

	// Imprimir lista después de borrar un nodo
	printf("\nLista después de borrar Nodo ft_lstiter(lst, print_content) :\n");
	ft_lstiter(lst, print_content);

	// Limpiar toda la lista
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped_lst, del);

	printf("\nLista vacía después de limpiar ft_lstclear(&lst, del) y ft_lstclear(&mapped_lst, del) :\n");
	if (lst == NULL)
		printf("\nLa lista está vacía.\n");
	if (mapped_lst == NULL)
		printf("\nLa lista mapeada está vacía.\n");

	printf("\n-------- TEST COMPLETED ---------\n");
	printf("==================================\n\n");
	return 0;
}


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Uso: %s <funcion>\n", argv[0]);
		return 1;
	}
	/* Parte 1 Funciones de libc */
	if (strcmp(argv[1], "ft_isalpha") == 0)
		test_isalpha();
	else if (strcmp(argv[1], "ft_help") == 0)
		info();
	else if (strcmp(argv[1], "ft_isdigit") == 0)
		test_isdigit();
	else if (strcmp(argv[1], "ft_isalnum") == 0)
		test_isalnum();
	else if (strcmp(argv[1], "ft_isascii") == 0)
		test_isascii();
	else if (strcmp(argv[1], "ft_isprint") == 0)
		test_isprint();
	else if (strcmp(argv[1], "ft_strlen") == 0)
		test_strlen();
	else if (strcmp(argv[1], "ft_memset") == 0)
		test_memset();
	else if (strcmp(argv[1], "ft_bzero") == 0)
		test_bzero();
	else if (strcmp(argv[1], "ft_memcpy") == 0)
		test_memcpy();
	else if (strcmp(argv[1], "ft_memmove") == 0)
		test_memmove();
	else if (strcmp(argv[1], "ft_strlcpy") == 0)
		test_strlcpy(); // OBSOLETO
	else if (strcmp(argv[1], "ft_strlcat") == 0)
		test_strlcat(); // OBSOLETO
	else if (strcmp(argv[1], "ft_toupper") == 0)
		test_toupper();
	else if (strcmp(argv[1], "ft_tolower") == 0)
		test_tolower();
	else if (strcmp(argv[1], "ft_strchr") == 0)
		test_strchr();
	else if (strcmp(argv[1], "ft_strrchr") == 0)
		test_strrchr();
	else if (strcmp(argv[1], "ft_strncmp") == 0)
		test_strncmp();
	else if (strcmp(argv[1], "ft_memchr") == 0)
		test_memchr();
	else if (strcmp(argv[1], "ft_memcmp") == 0)
		test_memcmp();
	else if (strcmp(argv[1], "ft_strnstr") == 0)
		test_strnstr(); // OBSOLETO
	else if (strcmp(argv[1], "ft_atoi") == 0)
		test_atoi();
	else if (strcmp(argv[1], "ft_calloc") == 0)
		test_calloc();
	else if (strcmp(argv[1], "ft_strdup") == 0)
		test_strdup();
	/*	Parte 2 - Funciones adicionales	*/
	else if (strcmp(argv[1], "ft_substr") == 0)
		test_substr(); // OBSOLETO
	else if (strcmp(argv[1], "ft_strjoin") == 0)
		test_strjoin(); // OBSOLETO
	else if (strcmp(argv[1], "ft_strtrim") == 0)
		test_strtrim(); // OBSOLETO
	else if (strcmp(argv[1], "ft_split") == 0)
		test_split();
	else if (strcmp(argv[1], "ft_itoa") == 0)
		test_itoa();
	else if (strcmp(argv[1], "ft_strmapi") == 0)
		test_strmapi();
	else if (strcmp(argv[1], "ft_striteri") == 0)
		test_striteri();
	else if (strcmp(argv[1], "ft_putchar_fd") == 0)
		test_putchar_fd();
	else if (strcmp(argv[1], "ft_putstr_fd") == 0)
		test_putstr_fd();
	else if (strcmp(argv[1], "ft_putendl_fd") == 0)
		test_putendl_fd();
	else if (strcmp(argv[1], "ft_putnbr_fd") == 0)
		test_putnbr_fd();
	/* ** BONUS individual ** */
	/*else if (strcmp(argv[1], "ft_lstnew") == 0)
		test_lstnew();
	else if (strcmp(argv[1], "ft_lstadd_front") == 0)
		test_lstadd_front();
	else if (strcmp(argv[1], "ft_lstsize") == 0)
		test_lstsize();
	else if (strcmp(argv[1], "ft_lstlast") == 0)
		test_lstlast();
	else if (strcmp(argv[1], "ft_lstadd_back") == 0)
		test_lstadd_back();
	else if (strcmp(argv[1], "ft_lstdelone") == 0)
		test_lstdelone();
	else if (strcmp(argv[1], "ft_lstclear") == 0)
		test_lstclear();
	else if (strcmp(argv[1], "ft_lstiter") == 0)
		test_lstiter();
	else if (strcmp(argv[1], "ft_lstmap") == 0)
		test_lstmap();
	 All (+Bonus)
	else if (strcmp(argv[1], "all_bonus") == 0)
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
		test_strlcpy(); // OBSOLETO
		test_strlcat(); // OBSOLETO
		test_toupper();
		test_tolower();
		test_strchr();
		test_strrchr();
		test_strncmp();
		test_memchr();
		test_memcmp();
		test_strnstr(); // OBSOLETO
		test_atoi();
		test_calloc();
		test_strdup();
		test_substr();	// OBSOLETO
		test_strjoin(); // OBSOLETO
		test_strtrim(); // OBSOLETO
		test_split();
		test_itoa();
		test_strmapi();
		test_striteri();
		test_putchar_fd();
		test_putstr_fd();
		test_putendl_fd();
		test_putnbr_fd();

		test_lstnew();
		test_lstadd_front();
		test_lstsize();
		test_lstlast();
		test_lstadd_back();
		test_lstdelone();
		test_lstclear();
		test_lstiter();
		test_lstmap();
	}*/
	else if (strcmp(argv[1], "ft_mandatory") == 0)
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
		test_strlcpy(); // OBSOLETO
		test_strlcat(); // OBSOLETO
		test_toupper();
		test_tolower();
		test_strchr();
		test_strrchr();
		test_strncmp();
		test_memchr();
		test_memcmp();
		test_strnstr(); // OBSOLETO
		test_atoi();
		test_calloc();
		test_strdup();
		test_substr();	// OBSOLETO
		test_strjoin(); // OBSOLETO
		test_strtrim(); // OBSOLETO
		test_split();
		test_itoa();
		test_strmapi();
		test_striteri();
		test_putchar_fd();
		test_putstr_fd();
		test_putendl_fd();
		test_putnbr_fd();
	}
	else if (strcmp(argv[1], "ft_bonus") == 0)
		test_bonus();
	else
		printf("Funcion no encontrada: %s\n", argv[1]);

	return 0;
 /* NOTAS para tu make y compilación:

cc -Wall -Werror -Wextra -c main.c -o main.o

cc main.o -L. -lft -z noexecstack -o name_program  (Enlaza main.o con libft.a y crea el ejecutable)

-L  (enlazador )
. (directorio Actual)
-lft -l le dice al enlazador que lo que sigue es la biblioteca (ft) se obvia lb
-z noexecstack  Medida de seguridad para evita la ejecucion de codigo malicioso en este enlace (OPCIONAL)
-o (opcional) le dice al compilador/enlazador que el output file  debetener un nombre especifico
name_program (ejecutable)

}
