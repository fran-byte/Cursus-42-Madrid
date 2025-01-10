/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:10:51 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 19:21:26 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return((octet >> 4)| (octet << 4));
}
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
int main (void)
{
	print_bits(swap_bits(18));
}
