/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:51:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/19 18:18:36 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t sz_dst;
    size_t sz_src;

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
