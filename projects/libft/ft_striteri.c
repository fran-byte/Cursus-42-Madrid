/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:46 by frromero          #+#    #+#             */
/*   Updated: 2024/09/30 16:00:48 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*A cada carácter de la string ’s’, aplica la función ’f’ dando
como parámetros el índice de cada carácter dentro de ’s’ y la
dirección del propio carácter, que podrá modificarse si es necesario.*/

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
