/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:54:23 by frromero          #+#    #+#             */
/*   Updated: 2025/01/07 16:23:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if(argc > 1)
	{
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				if((argv[i][j] >= 'A' && argv[i][j] <= 'Z')
					&& argv[i][j + 1] != ' ')
						argv[i][j] = argv[i][j] + 32;
				if((argv[i][j] >= 'a' && argv[i][j] <= 'z')
					&& argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
						argv[i][j] = argv[i][j] - 32;
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}