/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:31:41 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 08:54:08 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Calculates the length of the string, excluding the null-terminating */
/* byte ('\0'). Returns the total number of characters */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
