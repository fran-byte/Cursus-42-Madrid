/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:13:16 by frromero          #+#    #+#             */
/*   Updated: 2025/01/07 13:33:02 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void print_hex(int nb)
{
	char hex[]="0123456789abcdef";
	if(nb >= 16)
		print_hex(nb / 16);
	write(1, &hex[nb % 16], 1);
}
int ft_atoi(char *str)
{
	int number = 0;
	int i = 0;
	char c;

	while(str[i])
	{
		c = str[i] - '0';
		number = number * 10  + c;
		i++;
	}
	return(number);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));

	printf("\n");
	return(0);
}
