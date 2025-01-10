/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:37:38 by frromero          #+#    #+#             */
/*   Updated: 2025/01/06 17:18:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int	main(int argc, char **argv)
{
	int j = 0;
	int i = 0;

	if(argc == 3)
	{
		while(argv[1][i] && argv[2][j])
		{
			if(argv[1][i] == argv[2][j])
			{
				if(argv[1][i + 1] == '\0')
				{
					write(1, "1", 1);
					write(1, "\n", 1);
					return(0);
				}
				j++;
				i++;
			}
			else
				j++;
			if(argv[1][i] && argv[2][j + 1] == '\0')
				break;
		}
		write(1, "0", 1);
		write(1, "\n", 1);
		return(0);
	}
	write(1, "\n", 1);
	return(0);
}
