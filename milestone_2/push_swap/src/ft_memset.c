/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:50:46 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 19:31:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fills memory with a specified byte for a given length, */
/* returns pointer to memory */

#include "../inc/push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*buf;

	i = 0;
	buf = (unsigned char *)s;
	while (i < n)
	{
		buf[i] = c;
		i++;
	}
	return (buf);
}
