/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:36:53 by frromero          #+#    #+#             */
/*   Updated: 2024/09/30 17:26:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
