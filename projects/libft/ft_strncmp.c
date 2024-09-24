/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:46:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 15:52:38 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares the first `n` characters of two strings (`s1` and `s2`). */
/* Returns a negative, zero, or positive integer based on the comparison */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s1 == *s2 && i < n - 1 && *s1)
		i++;
		s1++;
		s2++;
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
