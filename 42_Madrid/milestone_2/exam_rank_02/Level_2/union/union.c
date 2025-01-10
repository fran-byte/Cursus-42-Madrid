/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:40:12 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 20:12:18 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int j = 0;
	char rep[256] = {0};

	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			if(!rep[(int)argv[1][i]])
			{
				rep[(int)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		while(argv[2][j] != '\0')
		{
			if(!rep[(int)argv[2][j]])
			{
				rep[(int)argv[2][j]] = 1;
				write(1, &argv[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
