/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:00 by frromero          #+#    #+#             */
/*   Updated: 2025/01/10 15:43:00 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			while(argv[2][j] != '\0')
			{
				if(argv[1][i] == argv[2][j])
					break;
				j++;
			}
			i++;
			if(argv[2][j] == '\0' && argv[1][i] == '\0')
				{
					write(1, "0", 1);
					write(1, "\n", 1);
					return(0);
				}
		}
		write(1, "1", 1);
	}
	write(1, "\n", 1);
	return(0);
}
