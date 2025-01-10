/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:32:17 by frromero          #+#    #+#             */
/*   Updated: 2025/01/07 12:11:13 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>

void ft_gcd(int a, int b)
{
	int n = 0;
	int gcd = 1;

	if (a > b)
		n = a;
	else
		n = b;
	while(1)
	{
		if(n % b == 0 && n % a == 0)
		{
			printf("%d", n);
			break;
		}
		n++;
	}
}


int	main(int argc, char **argv)
{
	if(argc == 3)
		ft_gcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return(0);
}
