/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:36:53 by frromero          #+#    #+#             */
/*   Updated: 2024/10/03 21:55:11 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function locates the first occurrence of the substring `substr` in the
 * string `src`, searching within the first `len` characters of `src`. If `substr`
 * is an empty string, it returns `src`. It returns a pointer to the start of
 * the located substring, or NULL if the substring is not found within the
 * specified length.*/

#include "libft.h"

char	*ft_strnstr(const char *src, const char *substr, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (*substr == '\0')
		return ((char *)src);
	while (src[b] != '\0')
	{
		l = 0;
		while (src[b + l] == substr[l] && (b + l) < len)
		{
			if (src[b + l] == '\0' && substr[l] == '\0')
				return ((char *)&src[b]);
			l++;
		}
		if (substr[l] == '\0')
			return ((char *)src + b);
		b++;
	}
	return (NULL);
}
