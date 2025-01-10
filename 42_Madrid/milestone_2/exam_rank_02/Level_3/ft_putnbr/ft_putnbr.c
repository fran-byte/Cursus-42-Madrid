/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:03:48 by frromero          #+#    #+#             */
/*   Updated: 2025/01/07 11:17:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_putnbr(int number)
{
	char	c;

	if(number < 0)
	{
		write(1, "-", 1);
		number = number * (-1);
	}
	if(number >= 10)
		ft_putnbr(number / 10);
	c = number % 10 + '0';
	write(1, &c, 1);
}
