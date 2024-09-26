/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:22:12 by frromero          #+#    #+#             */
/*   Updated: 2024/09/26 16:31:29 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Searches the first `n` bytes of memory area `s` for the byte `c` */
/* Returns a pointer to the first occurrence, or `NULL` if not found */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
