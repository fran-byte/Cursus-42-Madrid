/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:24:13 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 19:23:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies chars from src to dst (size-1) */

#include "libft.h"

unsigned int ft_strlcpy(char *dst, const char *src, unsigned int size)
{
    unsigned int i;

    i = 0;
    if(size == 0)
        return (ft_strlen(src));
    while (src[i] !='\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}
