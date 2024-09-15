/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:51:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 12:00:14 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dst, const char *src, unsigned int size)
{
    unsigned int i;
    unsigned int sz_dst;
    unsigned int sz_src;

    sz_dst = ft_strlen(dst);
    sz_src = ft_strlen(src);
    i = 0;
    if (size == 0)
        return (sz_dst + sz_src);
    else if (size <= sz_dst)
        return (sz_dst + sz_src);
    else
    {
        while (src[i] != '\0' && i < (size - sz_dst - 1))
        {
            dst[i + sz_dst] = src[i];
            i++;
        }
        dst[i + sz_dst] = '\0';
        return (sz_src + sz_dst);
    }
}
int main()
{
    char destino[50] = "Era se una vez_";
    char fuente[] = "la tierra.dentro del paraiso que viene siendo tambien la tierra, por ejemplo.";
    printf("\nImprimiendo retorno de la función: ft_strlcat : \n%u", ft_strlcat(destino, fuente, 50));
    printf("\nImprimiendo cadena -dst- : \n%s", destino);

    return 0;
}