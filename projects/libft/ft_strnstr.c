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

char	*ft_strnstr(const char *big, const char tiny, size_t len)
{
	size_t	b;
	size_t	t;

	b = 0;
	if (tiny == '\0')
		return ((char *)big);
	while(big[b] != '\0')
	{
		t = 0;
		while(big[b + t] == tiny[t] && (b + t < len))
		{
			if (big[b + t] == '\0' && tiny[t] == '\0')
				return ((char *)&big[b]);
			t++;
		}
		if (tiny[b + t] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (0);
}
