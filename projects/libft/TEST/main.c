/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:49 by frromero          #+#    #+#             */
/*   Updated: 2024/09/23 18:37:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
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

void test_isalpha()
{
	int	resultA;
	int	resultA_original;
	int	result1;
	int	result1_original;
	int	result300;
	int	result300_original;

	resultA = ft_isalpha('A');
	resultA_original = isalpha('A');
	result1 = ft_isalpha('1');
	result1_original = isalpha('1');
	result300 = ft_isalpha(300);
	result300_original = isalpha(300);
	printf("   __   _             _                 _           _             \n");
	printf("  / _| | |_          (_)  ___    __ _  | |  _ __   | |__     __ _ \n");
	printf(" | |_  | __|         | | / __|  / _` | | | | '_ \\  | '_ \\   / _` |\n");
	printf(" |  _| | |_          | | \\__ \\ | (_| | | | | |_) | | | | | | (_| |\n");
	printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_| | .__/  |_| |_|  \\__,_|\n");
	printf("             |_____|                       |_|                         \n");
	/* TEST 1*/
	printf("ft_isalpha('A'): %d\n", resultA);
	printf("isalpha(''): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isalpha('1'): %d\n", result1);
	printf("isalpha('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isalpha(300): %d\n",result300);
	printf("isalpha(300): %d\n\n", result300_original);
}

void test_isdigit()
{
	int	resultA;
	int	resultA_original;
	int	result1;
	int	result1_original;
	int	result300;
	int	result300_original;

	resultA = ft_isdigit('A');
	resultA_original = isdigit('A');
	result1 = ft_isdigit('1');
	result1_original = isdigit('1');
	result300 = ft_isdigit(300);
	result300_original = isdigit(300);
	printf("   __   _             _             _   _           _   _   \n");
	printf("  / _| | |_          (_)  ___    __| | (_)   __ _  (_) | |_ \n");
	printf(" | |_  | __|         | | / __|  / _` | | |  / _` | | | | __|\n");
	printf(" |  _| | |_          | | \\__ \\ | (_| | | | | (_| | | | | |_ \n");
	printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_|  \\__, | |_|  \\__|\n");
	printf("             |_____|                        |___/          \n");
	printf("ft_isdigit('A'): %d\n", resultA);
	printf("isdigit('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isdigit('1'): %d\n", result1);
	printf("isdigit('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isdigit(300): %d\n",result300);
	printf("isdigit(300): %d\n\n", result300_original);
}

void test_isalnum()
{
	int	resultA;
	int	resultA_original;
	int	result1;
	int	result1_original;
	int	result300;
	int	result300_original;

	resultA = ft_isalnum('A');
	resultA_original = isalnum('A');
	result1 = ft_isalnum('1');
	result1_original = isalnum('1');
	result300 = ft_isalnum(300);
	result300_original = isalnum(300);
	printf("   __   _             _                 _                             \n");
	printf("  / _| | |_          (_)  ___    __ _  | |  _ __    _   _   _ __ ___  \n");
	printf(" | |_  | __|         | | / __|  / _` | | | | '_ \\  | | | | | '_ ` _ \\ \n");
	printf(" |  _| | |_          | | \\__ \\ | (_| | | | | | | | | |_| | | | | | | |\n");
	printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |_| |_| |_|  \\__,_| |_| |_| |_|\n");
	printf("             |_____|                                                 \n");
	printf("ft_isalnum('A'): %d\n", resultA);
	printf("isalnum('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isalnum('1'): %d\n", result1);
	printf("isalnum('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isalnum(300): %d\n",result300);
	printf("isalnum(300): %d\n\n", result300_original);
}

void test_ascii()
{
	int	resultA;
	int	resultA_original;
	int	result1;
	int	result1_original;
	int	result300;
	int	result300_original;

	resultA = ft_isascii('A');
	resultA_original = isascii('A');
	result1 = ft_isascii('1');
	result1_original = isascii('1');
	result300 = ft_isascii(300);
	result300_original = isascii(300);
	printf("   __   _             _                              _   _ \n");
	printf("  / _| | |_          (_)  ___    __ _   ___    ___  (_) (_)\n");
	printf(" | |_  | __|         | | / __|  / _` | / __|  / __| | | | |\n");
	printf(" |  _| | |_          | | \\__ \\ | (_| | \\__ \\ | (__  | | | |\n");
	printf(" |_|    \\__|  _____  |_| |___/  \\__,_| |___/  \\___| |_| |_|\n");
	printf("             |_____|                                      \n");
	printf("ft_isascii('A'): %d\n", resultA);
	printf("isascii('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isascii('1'): %d\n", result1);
	printf("isascii('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isascii(300): %d\n",result300);
	printf("isascii(300): %d\n\n", result300_original);
}

void test_isprint()
{
	int	resultA;
	int	resultA_original;
	int	result1;
	int	result1_original;
	int	result300;
	int	result300_original;

	resultA = ft_isprint('A');
	resultA_original = isprint('A');
	result1 = ft_isprint('1');
	result1_original = isprint('1');
	result300 = ft_isprint(300);
	result300_original = isprint(300);
	printf("   __   _             _                        _           _   \n");
	printf("  / _| | |_          (_)  ___   _ __    _ __  (_)  _ __   | |_ \n");
	printf(" | |_  | __|         | | / __| | '_ \\  | '__| | | | '_ \\  | __|\n");
	printf(" |  _| | |_          | | \\__ \\ | |_) | | |    | | | | | | | |_ \n");
	printf(" |_|    \\__|  _____  |_| |___/ | .__/  |_|    |_| |_| |_|  \\__|\n");
	printf("             |_____|           |_|                            \n");
	printf("ft_isprint('A'): %d\n", resultA);
	printf("isprint('A'): %d\n\n", resultA_original);
	/* TEST 2*/
	printf("ft_isprint('1'): %d\n", result1);
	printf("isprint('1'): %d\n\n", result1_original);
	/* TEST 3*/
	printf("ft_isprint(300): %d\n",result300);
	printf("isprint(300): %d\n\n", result300_original);
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
	printf("strlen(\"%s\"): %zu\n", str, strlen(str));
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
	char str2[50] = "Hola Mundo 42!!";
	printf("Nuestra string: %s\n", str);
	ft_memset(str, '*', 5);
	memset(str2, '*', 5);
	printf("ft_memset(str, '*', 5): %s\n", str);
	printf("memset(str, '*', 5): %s\n", str);
}

void test_bzero()   //  REVISAR SI TRABAJA LA ORIGINAL, NO FUNCIONA ********
{
	printf("   __   _             _                                 \n");
	printf("  / _| | |_          | |__    ____   ___   _ __    ___  \n");
	printf(" | |_  | __|         | '_ \\  |_  /  / _ \\ | '__|  / _ \\ \n");
	printf(" |  _| | |_          | |_) |  / /  |  __/ | |    | (_) |\n");
	printf(" |_|    \\__|  _____  |_.__/  /___|  \\___| |_|     \\___/ \n");
	printf("             |_____|                                    \n");
	char str[50] = "Hola Mundo 42!!";
	char str2[50] = "Hola Mundo 42!!";
	printf("Nuestra string: %s\n", str);
	ft_bzero(str, 5);
	bzero(str2, 5);
	printf("ft_bzero(str, 5): %s\n", str);
	printf("bzero(str, 5): %s\n", str2);
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
	char str2[50] = "Hola Mundo 42!!";
	printf("Nuestra string: %s\n", str);
	printf("ft_memmove(str + 5, str, strlen(str) - 5)\n");
	printf("Mueve la parte de la cadena hacia la derecha\n");
	ft_memmove(str + 5, str, ft_strlen(str) - 5);
	memmove(str2 + 5, str2, ft_strlen(str2) - 5);
	printf("Resultado: %s\n", str);
	printf("Resultado: %s\n", str2);
}

void test_memcpy()
{
	printf("   __   _                                                                 \n");
	printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___   _ __    _   _ \n");
	printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ \\  | | | |\n");
	printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | |_) | | |_| |\n");
	printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| | .__/   \\__, |\n");
	printf("             |_____|                                       |_|      |___/	\n");

	/*TEST 1*/

	char src[50] = "Hola Mundo 42!!";
	char dest[50] = "Hello world 42!! Madrid";
	char src_original[50] = "Hola Mundo 42!!";
	char dest_original[50] = "Hello world 42!! Madrid";

	printf("src: %s\n", src);
	printf("dest: %s\n\n", dest);
	void *result = ft_memcpy(dest, src, strlen(src) + 1);
	void *result_original = memcpy(dest_original, src_original, strlen(src_original) + 1);
	printf("ft_memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result);
	printf("memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result_original);
	// Comparamos ambos resultados
	assert(!strcmp(result, result_original));


	/*TEST 2*/

	char *src2 = 0; //PUNTERO NULO
	char dest2[50] = "Hello world 42!! Madrid";
	char *src_original2 = 0; //PUNTERO NULO
	char dest_original2[50] = "Hello world 42!! Madrid";

	printf("src: %s\n", src2);
	printf("dest: %s\n\n", dest2);
	void *result2 = ft_memcpy(dest2, src2, strlen(src2) + 1);
	void *result_original2 = memcpy(dest_original2, src_original2, strlen(src_original2) + 1);
	printf("ft_memcpy(dest2, src2, strlen(src2) + 1): %s\n", (char *)result2);
	printf("memcpy(dest2, src2, strlen(src2) + 1): %s\n", (char *)result_original2);
	// Comparamos ambos resultados
	assert(!strcmp(result2, result_original2));

	/*TEST 3*/

	char *dest3 = 0; //PUNTERO NULO
	char src3[50] = "Hello world 42!! Madrid";
	char *src_original3 = 0; //PUNTERO NULO
	char dest_original3[50] = "Hello world 42!! Madrid";

	printf("src: %s\n", src3);
	printf("dest: %s\n\n", dest3);
	void *result3 = ft_memcpy(dest3, src3, strlen(src3) + 1);
	void *result_original3 = memcpy(dest_original3, src_original3, strlen(src_original3) + 1);
	printf("ft_memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result3);
	printf("memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result_original3);
	// Comparamos ambos resultados
	assert(!strcmp(result3, result_original3));

	/*TEST 4*/

	char *dest4 = 0; //PUNTERO NULO
	char *src4 = 0; //PUNTERO NULO
	char *src_original4 = 0; //PUNTERO NULO
	char dest_original4[50] = "Hello world 42!! Madrid";

	printf("src: %s\n", src4);
	printf("dest: %s\n\n", dest4);
	void *result4 = ft_memcpy(dest4, src4, strlen(src4) + 1);
	void *result_original4 = memcpy(dest_original4, src_original4, strlen(src_original4) + 1);
	printf("ft_memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result4);
	printf("memcpy(dest, src, strlen(src) + 1): %s\n", (char *)result_original4);
	// Comparamos ambos resultados
	assert(!strcmp(result4, result_original4));
}

void test_strlcpy()
{
	printf("   __   _                   _            _                        \n");
	printf("  / _| | |_           ___  | |_   _ __  | |   ___   _ __    _   _ \n");
	printf(" | |_  | __|         / __| | __| | '__| | |  / __| | '_ \\  | | | |\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | (__  | |_) | | |_| |\n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|  \\___| | .__/   \\__, |\n");
	printf("             |_____|                               |_|      |___/ \n");

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

	//TEST 2 size_t lo dejaos a 0

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
}
void test_strlcat()
{
	printf("   __   _                   _            _                  _   \n");
	printf("  / _| | |_           ___  | |_   _ __  | |   ___    __ _  | |_ \n");
	printf(" | |_  | __|         / __| | __| | '__| | |  / __|  / _` | | __|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | (__  | (_| | | |_ \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_|  \\___|  \\__,_|  \\__|\n");
	printf("             |_____|                                            \n");

	// TEST 1

	char dest[30] = "Hola";
	char src[] = "Hola Mundo!";
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

	//TEST 1

	char c = 'a';
	char b = '5';

	printf("ft_toupper('%c') = %c\n", c, ft_toupper(c));
	printf("toupper('%c') = %c\n", c, toupper(c));

	//TEST 2

	printf("ft_toupper('%c') = %c\n", b, ft_toupper(b));
	printf("toupper('%c') = %c\n", b, toupper(b));
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
	char b = '5';

	//TEST 1

	printf("ft_tolower('%c') = %c\n", c, ft_tolower(c));
	printf("tolower('%c') = %c\n", c, tolower(c));

	//TEST 1

	printf("ft_tolower('%c') = %c\n", b, ft_tolower(b));
	printf("tolower('%c') = %c\n", b, tolower(b));
}

void test_strchr()
{
	printf("   __   _                   _                   _            \n");
	printf("  / _| | |_           ___  | |_   _ __    ___  | |__    _ __ \n");
	printf(" | |_  | __|         / __| | __| | '__|  / __| | '_ \\  | '__|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | (__  | | | | | |   \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|     \\___| |_| |_| |_|   \n");
	printf("             |_____|                                         \n");

	// TEST 1

	char str[] = "Hola, mundo";
	char *result = ft_strchr(str, 'm');
	if (result)
	{
		printf("Buscando ft_strchr(str, 'm') en: 'Hola, mundo'\n");
		printf("Primero: %s\n", result);
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
		printf("Primero: %s\n", result2);
	}
	else
	{
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

	// TEST 1

	char str[] = "Hello, World!!";
	char *result = ft_strrchr(str, 'o');
	printf("Buscando ft_strrchr(str, 'o') en: 'Hello, World!!'\n");
	if (result)
	{
		printf("Último: %s\n", result);
	}
	else
	{
		printf("No encontrado\n");
	}

	// TEST 2

	char str2[] = "Hello, World!!";
	char *result2 = strrchr(str2, 'o');
	printf("Buscando strrchr(str, 'o') en: 'Hello, World!!'\n");
	if (result2)
	{
		printf("Último: %s\n", result2);
	}
	else
	{
		printf("No encontrado\n");
	}

}

void test_strncmp()
{
	printf("   __   _                   _                                             \n");
	printf("  / _| | |_           ___  | |_   _ __   _ __     ___   _ __ ___    _ __  \n");
	printf(" | |_  | __|         / __| | __| | '__| | '_ \\   / __| | '_ ` _ \\  | '_ \\ \n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | | | (__  | | | | | | | |_) |\n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_| |_|  \\___| |_| |_| |_| | .__/ \n");
	printf("             |_____|                                               |_|    \n");

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
}

void test_memchr()
{
	printf("   __   _                                                   _            \n");
	printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___  | |__    _ __ \n");
	printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ \\  | '__|\n");
	printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | | | | | |   \n");
	printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| |_| |_| |_|   \n");
	printf("             |_____|                                                     \n");

	//TEST 1

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

	//TEST 2

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
}

void test_memcmp()
{
	printf("   __   _                                                                     \n");
	printf("  / _| | |_           _ __ ___     ___   _ __ ___     ___   _ __ ___    _ __  \n");
	printf(" | |_  | __|         | '_ ` _ \\   / _ \\ | '_ ` _ \\   / __| | '_ ` _ \\  | '_ \\ \n");
	printf(" |  _| | |_          | | | | | | |  __/ | | | | | | | (__  | | | | | | | |_) |\n");
	printf(" |_|    \\__|  _____  |_| |_| |_|  \\___| |_| |_| |_|  \\___| |_| |_| |_| | .__/ \n");
	printf("             |_____|                                                   |_|    \n");

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
}

void test_strnstr()
{
	printf("   __   _                   _                          _          \n");
	printf("  / _| | |_           ___  | |_   _ __   _ __    ___  | |_   _ __ \n");
	printf(" | |_  | __|         / __| | __| | '__| | '_ \\  / __| | __| | '__|\n");
	printf(" |  _| | |_          \\__ \\ | |_  | |    | | | | \\__ \\ | |_  | |   \n");
	printf(" |_|    \\__|  _____  |___/  \\__| |_|    |_| |_| |___/  \\__| |_|   \n");
	printf("             |_____|                                              \n");

	//TEST 1

	char *str = "Hola42Madrid";
	char *substr = "42Madrid";
	char *result = ft_strnstr(str, substr, strlen(substr));

	printf("\n*str = 'Hola42Madrid'\n");
	printf("*substr = '42Madrid'\n");
	printf("ftstrnstr(str, substr, ft_strlen(substr))");
	if (result)
	{
		printf("Encontrado: %s\n", result);
	}
	else
	{
		printf("No encontrado\n");
	}

	//TEST 2

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

}

int main()
{
    test_strnstr();

    return 0;
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
	while (i < 5)
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
	if (argc < 2)
	{
		printf("Uso: %s <funcion>\n", argv[0]);
		return 1;
	}
	/* Parte 1 Funciones de libc */
	if (strcmp(argv[1], "ft_isalpha") == 0)
		test_isalpha();
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
	/* ** BONUS ** */
	else if (strcmp(argv[1], "ft_lstnew") == 0)
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
	/* All (+Bonus) */
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
		/* BONUS */
		test_lstnew();
		test_lstadd_front();
		test_lstsize();
		test_lstlast();
		test_lstadd_back();
		test_lstdelone();
		test_lstclear();
		test_lstiter();
		test_lstmap();
	}
	else if (strcmp(argv[1], "all_mandatory") == 0)
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
	else
		printf("Funcion no encontrada: %s\n", argv[1]);

	return 0;
}
