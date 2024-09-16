/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:46:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/17 00:07:05 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    unsigned int i;

    i =0;    
    while(s1[i] == s2[i] && i < n)      
        i++;
    return (s1[i] - s2[i]);
}

int main()
{
    // s1 vacía, s2 vacía
    printf("Ejemplo 1: %d\n", ft_strncmp("", "", 4)); 
    //  0 ('\0' - '\0' = 0)

    // s1 vacía, s2 no vacía
    printf("Ejemplo 1: %d\n", ft_strncmp("", "abc", 4)); 
    //  -97 ('\0' - 'a' = -97)

    // s1 más larga que s2, n mayor que longitud de s2
    printf("Ejemplo 2: %d\n", ft_strncmp("Hello", "Hell", 10)); 
    //  111 ('o' - '\0' = 111)

    // s1 más corta que s2, n mayor que longitud de s1
    printf("Ejemplo 3: %d\n", ft_strncmp("Hi", "Hello", 10)); 
    //  4 ('i' - 'e' = 105 - 101 = 4)

    // s1 y s2 son idénticas hasta el límite n
    printf("Ejemplo 4: %d\n", ft_strncmp("HelloWorld", "Hello", 10)); 
    //  87 ('W' - '\0' = 87)

    // s1 y s2 son iguales hasta n, pero n es mayor que las longitudes
    printf("Ejemplo 5: %d\n", ft_strncmp("Hi", "Hi", 10)); 
    // 0 (porque las cadenas son iguales y n es mayor que la longitud de las cadenas)

    return 0;
}