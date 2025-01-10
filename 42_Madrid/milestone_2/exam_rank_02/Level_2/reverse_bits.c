/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:47:02 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 19:09:59 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char result;
	while(i >= 0)
	{
		result = (result * 2 +(octet % 2));
		octet = octet / 2;
		i--;
	}
	return(result);
}
