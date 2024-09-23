/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:36:53 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 09:13:10 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (*little == '\0')
		return ((char *)big);
	while(big[b] != '\0')
	{
		l = 0;
		while(big[b + l] == little[l] && (b + l < len))
		{
			if (big[b + l] == '\0' && little[l] == '\0')
				return ((char *)&big[b]);
			l++;
		}
		if (little[b + l] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (0);
}
