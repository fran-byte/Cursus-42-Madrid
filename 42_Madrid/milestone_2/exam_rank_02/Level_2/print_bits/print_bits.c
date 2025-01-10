/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:11:46 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 18:45:42 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char bit;
	while(i >=0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
