#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "ft_printf.h"

void compare_prints(int test_num, int print_ft, int print_real) {
    if (print_ft == print_real) {
        printf("\e[32mTEST %d OK\e[0m\n", test_num);  // Verde para OK
    } else {
        printf("\e[31mTEST %d KO\e[0m\n", test_num);  // Rojo para KO
        printf("Línea 1 (ft_printf): '%d' (Longitud: %d)\n", print_ft, print_ft);
        printf("Línea 2 (printf): '%d' (Longitud: %d)\n", print_real, print_real);
    }
}

int main() {
    int index_print_ft, index_print_real;

    // Declaración de variables
    char str2 = 'B';
    char str3[] = "Hola Mundo!";
    int *ptr4 = NULL;
    int str5 = 42;
    int str6 = -42;
    unsigned int str7 = 4294967295; // UINT_MAX
    unsigned int str8 = 255;
    unsigned int str9 = 255;

	printf("\n\e[32m* * * TEST - ft_printf * * *\e[0m\n\n");
    // Pruebas para el carácter y la cadena
    index_print_ft = ft_printf("TEST 1 . Porcentaje: %% > char: %c > str: %s .\n", str2, str3);
    index_print_real = printf("TEST 1 . Porcentaje: %% > char: %c > str: %s .\n", str2, str3);
    compare_prints(1, index_print_ft, index_print_real);

    // Pruebas para puntero (puntero no nulo)
    index_print_ft = ft_printf("TEST 2 . Puntero (ptr4) = %p .\n", (void*)&str3);
    index_print_real = printf("TEST 2 . Puntero (ptr4) = %p .\n", (void*)&str3);
    compare_prints(2, index_print_ft, index_print_real);

    // Pruebas para %d y %i con valores positivos
    index_print_ft = ft_printf("TEST 3 . Valor positivo d = %d = Valor positivo i = %i .\n", str5, str5);
    index_print_real = printf("TEST 3 . Valor positivo d = %d = Valor positivo i = %i .\n", str5, str5);
    compare_prints(3, index_print_ft, index_print_real);

    // Pruebas para %d y %i con valores negativos
    index_print_ft = ft_printf("TEST 4 . Valor negativo d = %d = Valor negativo i = %i .\n", str6, str6);
    index_print_real = printf("TEST 4 . Valor negativo d = %d = Valor negativo i = %i .\n", str6, str6);
    compare_prints(4, index_print_ft, index_print_real);

    // Pruebas para %u (unsigned int)
    index_print_ft = ft_printf("TEST 5 . Valor unsigned u = %u .\n", str7);
    index_print_real = printf("TEST 5 . Valor unsigned u = %u .\n", str7);
    compare_prints(5, index_print_ft, index_print_real);

    // Pruebas para %x (hexadecimal en minúscula)
    index_print_ft = ft_printf("TEST 6 . Valor hexadecimal minusculas x = %x .\n", str8);
    index_print_real = printf("TEST 6 . Valor hexadecimal minusculas x = %x .\n", str8);
    compare_prints(6, index_print_ft, index_print_real);

    // Pruebas para %X (hexadecimal en mayúscula)
    index_print_ft = ft_printf("TEST 7 . Valor hexadecimal mayusculas X = %X .\n", str9);
    index_print_real = printf("TEST 7 . Valor hexadecimal mayusculas X = %X .\n", str9);
    compare_prints(7, index_print_ft, index_print_real);

    // Test 8: Puntero nulo
    void *ptr_null = NULL;
    index_print_ft = ft_printf("TEST 8 . Puntero nulo: %p\n", ptr_null);
    index_print_real = printf("TEST 8 . Puntero nulo: %p\n", ptr_null);
    compare_prints(8, index_print_ft, index_print_real);

    // Test 9: Valor mínimo de long como puntero
    long long_min = LONG_MIN;
    index_print_ft = ft_printf("TEST 9 . Valor minimo de long: %p\n", (void*)long_min);
    index_print_real = printf("TEST 9 . Valor minimo de long: %p\n", (void*)long_min);
    compare_prints(9, index_print_ft, index_print_real);

    // Test 10: Valor máximo de long como puntero
    long long_max = LONG_MAX;
    index_print_ft = ft_printf("TEST 10 . Valor maximo de long: %p\n", (void*)long_max);
    index_print_real = printf("TEST 10 . Valor maximo de long: %p\n", (void*)long_max);
    compare_prints(10, index_print_ft, index_print_real);

    // Test 11: Valor máximo de unsigned long como puntero
    unsigned long ulong_max = ULONG_MAX;
    index_print_ft = ft_printf("TEST 11 . Valor maximo de unsigned long: %p\n", (void*)ulong_max);
    index_print_real = printf("TEST 11 . Valor maximo de unsigned long: %p\n", (void*)ulong_max);
    compare_prints(11, index_print_ft, index_print_real);

    // Test 12: Valor negativo de unsigned long como puntero
    long ulong_neg = -ULONG_MAX;
    index_print_ft = ft_printf("TEST 12 . Valor negativo de unsigned long: %p\n", (void*)ulong_neg);
    index_print_real = printf("TEST 12 . Valor negativo de unsigned long: %p\n", (void*)ulong_neg);
    compare_prints(12, index_print_ft, index_print_real);

    return 0;
}
