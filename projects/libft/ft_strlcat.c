/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:51:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 23:04:08 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dst, const char *src, unsigned int size)
{
    unsigned int i;
    int z;

    z = ft_strlen(dst);
    i = 0;
    if(size == 0)
        return (ft_strlen(dst) + ft_strlen(src));
    while (src[i] !='\0' && i < size - 1)
    {
        dst[i+z] = src[i];
        i++;
    }
    dst[i+z] = '\0';
    return (ft_strlen(dst) + ft_strlen(src));
}