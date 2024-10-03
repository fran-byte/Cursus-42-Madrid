/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:46 by frromero          #+#    #+#             */
/*   Updated: 2024/10/03 21:22:55 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For each character in the string 's', applies the function 'f' with the
index of each character within 's' and the address of the character itself as
parameters, which can be modified if necessary.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (i2 < i)
		{
			(*f)(i2, s);
			s++;
			i2++;
		}
	}
}
