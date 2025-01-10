/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:57:57 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 18:10:49 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int number;
	int	i = 0;

	number = tab[0];
	while(len)
	{
		if(number < tab[i])
			number = tab[i];
		len--;
		i++;
	}
	return (number);
}
