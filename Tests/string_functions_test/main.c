/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:46:13 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 21:42:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>  

int main() {
    printf("Testing <string.h> functions:\n");

    // Prueba de strlcpy
    char dest1[50];
    char src[] = "Hello, World!";
    int size_dest1 = ft_strlen(dest1);
    int len = ft_strlcpy(dest1, src, size_dest1);
    printf("strlcpy: Copied \"%s\" to dest. Length: %d. Dest: \"%s\"\n", src, len, dest1);

    // Prueba de strlcat
    char dest2[50] = "Initial";
    char append[] = " - Appended";
    int size_dest2 = ft_strlen(dest2);
    len = ft_strlcat(dest2, append, size_dest2);
    printf("strlcat: Appended \"%s\" to dest2. Length: %d. Dest2: \"%s\"\n", append, len, dest2);

    // Prueba de strlen
    printf("strlen: Length of \"%s\": %d\n", src, ft_strlen(src));

    // Prueba de strchr
    char *p = ft_strchr(src, 'o');
    if (p != 0) {  
        printf("strchr: First occurrence of 'o': %s\n", p);
    } else {
        printf("strchr: First occurrence of 'o': Not found\n");
    }

    // Prueba de strrchr
    p = ft_strrchr(src, 'l');
    if (p != 0) { 
        printf("strrchr: Last occurrence of 'l': %s\n", p);
    } else {
        printf("strrchr: Last occurrence of 'l': Not found\n");
    }

    /*// Prueba de strncmp
    int cmp = ft_strncmp(src, "Hello, World", 5);
    printf("strncmp: Comparing \"%s\" and \"Hello, World\" for 5 chars: %d\n", src, cmp);*/
    return 0;
}