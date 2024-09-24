/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:15:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 08:32:10 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Zeroes out `n` bytes of memory starting from the location pointed to by `s`*/
/* It is used to initialize memory to zero.*/

/*Zeroes out the memory for the given number of bytes starting from a location*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = s;
	while (i < n)
	{
		buf[i] = '0';
		i++;
	}
}
