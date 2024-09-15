/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:47:09 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 18:51:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Declaración de funciones a probar
unsigned int strlcpy(char *dst, const char *src, size_t size);
unsigned int strlcat(char *dst, const char *src, size_t size);

void test_string_functions() {
    printf("Testing <string.h> functions:\n");

    // Prueba de strlcpy
    char dest[50];
    char src[] = "Hello, World!";
    unsigned int len = strlcpy(dest, src, sizeof(dest));
    printf("strlcpy: Copied \"%s\" to dest. Length: %zu. Dest: \"%s\"\n", src, len, dest);

    // Prueba de strlcat
    char dest2[50] = "Initial";
    char append[] = " - Appended";
    len = strlcat(dest2, append, sizeof(dest2));
    printf("strlcat: Appended \"%s\" to dest2. Length: %zu. Dest2: \"%s\"\n", append, len, dest2);

    // Prueba de strlen
    printf("strlen: Length of \"%s\": %zu\n", src, strlen(src));

    // Prueba de strchr
    char *p = strchr(src, 'W');
    printf("strchr: First occurrence of 'W': %s\n", p ? p : "Not found");

    // Prueba de strrchr
    p = strrchr(src, 'o');
    printf("strrchr: Last occurrence of 'o': %s\n", p ? p : "Not found");

    // Prueba de strncmp
    int cmp = strncmp(src, "Hello, World", 5);
    printf("strncmp: Comparing \"%s\" and \"Hello, World\" for 5 chars: %d\n", src, cmp);

    // Prueba de mem functions
    test_mem_functions();
}

void test_mem_functions() {
    printf("\nTesting memory functions:\n");

    char buf[50] = "Hello World";
    char buf2[50];
    char mem_src[50] = "Memory copy source";
    char mem_dest[50];

    // memset
    memset(buf, '*', 5);
    printf("memset: Buffer after memset: \"%s\"\n", buf);

    // bzero
    bzero(buf2, sizeof(buf2));
    printf("bzero: Buffer2 after bzero: \"%s\"\n", buf2);

    // memchr
    char *p = memchr(buf, '*', sizeof(buf));
    printf("memchr: First occurrence of '*' in buf: %s\n", p ? p : "Not found");

    // memcpy
    memcpy(mem_dest, mem_src, strlen(mem_src) + 1);
    printf("memcpy: mem_dest after memcpy: \"%s\"\n", mem_dest);

    // memcmp
    int cmp = memcmp("abc", "abd", 3);
    printf("memcmp: Comparing \"abc\" and \"abd\": %d\n", cmp);

    // memmove
    char overlap[] = "123456789";
    memmove(overlap + 2, overlap, 7);
    overlap[9] = '\0';  // Null-terminate the moved string
    printf("memmove: Overlap buffer after memmove: \"%s\"\n", overlap);
}

int main() {
    test_string_functions();
    return 0;
}
