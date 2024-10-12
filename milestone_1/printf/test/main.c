
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int index_print_ft, index_print_real;

	char str2 = 'B';
	char str3[] = "Hola Mundo!";
	//int *ptr4 = NULL;
	int str5 = 42;
	int str6 = -42;
	unsigned int str7 = 4294967295; // Unsigned INT_MAX
	unsigned int str8 = 255;
	unsigned int str9 = 255;

	// carácter y la cadena
	index_print_ft = ft_printf(". %% = %c = %s .", str2, str3);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". %% = %c = %s .", str2, str3);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// puntero (puntero no nulo)
	//index_print_ft = ft_printf(". Puntero (ptr4) = %p .", (void *)&str3);
	//printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	//index_print_real = printf(". Puntero (ptr4) = %p .", (void *)&str3);
	//printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// %d y %i con valores positivos
	index_print_ft = ft_printf(". Valor positivo d = %d = Valor positivo i = %i .", str5, str5);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". Valor positivo d = %d = Valor positivo i = %i .", str5, str5);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// %d y %i con valores negativos
	index_print_ft = ft_printf(". Valor negativo d = %d = Valor negativo i = %i .", str6, str6);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". Valor negativo d = %d = Valor negativo i = %i .", str6, str6);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// %u (unsigned int)
	index_print_ft = ft_printf(". Valor unsigned u = %u .", str7);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". Valor unsigned u = %u .", str7);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// %x (hexadecimal en minúscula)
	index_print_ft = ft_printf(". Valor hexadecimal minúsculas x = %x .", str8);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". Valor hexadecimal minúsculas x = %x .", str8);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// %X (hexadecimal en mayúscula)
	index_print_ft = ft_printf(". Valor hexadecimal mayúsculas X = %X .", str9);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf(". Valor hexadecimal mayúsculas X = %X .", str9);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	/*PARA PUNTEROS-------------------------------------------------------------------*/

	// Test 1: Puntero nulo
	void *ptr_null = NULL;
	index_print_ft = ft_printf("Puntero nulo: %p\n", ptr_null);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf("Puntero nulo: %p\n", ptr_null);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// Test 2: Valor mínimo de long como puntero
	long long_min = LONG_MIN;
	index_print_ft = ft_printf("Valor mínimo de long: %p\n", (void *)long_min);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf("Valor mínimo de long: %p\n", (void *)long_min);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// Test 3: Valor máximo de long como puntero
	long long_max = LONG_MAX;
	index_print_ft = ft_printf("Valor máximo de long: %p\n", (void *)long_max);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf("Valor máximo de long: %p\n", (void *)long_max);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// Test 4: Valor máximo de unsigned long como puntero
	unsigned long ulong_max = ULONG_MAX;
	index_print_ft = ft_printf("Valor máximo de unsigned long: %p\n", (void *)ulong_max);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf("Valor máximo de unsigned long: %p\n", (void *)ulong_max);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	// Test 5: Valor negativo de unsigned long como puntero
	long ulong_neg = -ULONG_MAX;
	index_print_ft = ft_printf("Valor negativo de unsigned long: %p\n", (void *)ulong_neg);
	printf("\nft_printf - n.caracteres = : %d\n", index_print_ft);
	index_print_real = printf("Valor negativo de unsigned long: %p\n", (void *)ulong_neg);
	printf("\nprintf - n.caracteres = : %d\n\n", index_print_real);

	return 0;
}
