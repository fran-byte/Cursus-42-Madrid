/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:47 by frromero          #+#    #+#             */
/*   Updated: 2024/09/27 18:39:31 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Convert an integer into its string representation*/

static void	ft_isnegat(size_t size, char *str, long nbr)
{
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	size = 0;
	nbr = n;
	if (n <= 0)
	{
		nbr = -nbr;
		size = 1;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!(str))
		return (0);
	ft_isnegat(size, str, nbr);
	return (str);
}
