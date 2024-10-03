/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:36:53 by frromero          #+#    #+#             */
/*   Updated: 2024/10/03 21:20:52 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function locates the first occurrence of the substring `tiny` in the
 * string `big`, searching within the first `len` characters of `big`. If `tiny`
 * is an empty string, it returns `big`. It returns a pointer to the start of
 * the located substring, or NULL if the substring is not found within the
 * specified length.*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *tiny, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (*tiny == '\0')
		return ((char *)big);
	while (big[b] != '\0')
	{
		l = 0;
		while (big[b + l] == tiny[l] && (b + l) < len)
		{
			if (big[b + l] == '\0' && tiny[l] == '\0')
				return ((char *)&big[b]);
			l++;
		}
		if (tiny[l] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (0);
}
