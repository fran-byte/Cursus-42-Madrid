/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:24:13 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 13:27:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies chars from src to dst (size-1) */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

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
