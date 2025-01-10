/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:31:11 by frromero          #+#    #+#             */
/*   Updated: 2025/01/06 10:38:09 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int	main(int argc, char **argv)
{
	int flag = 0;
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i] == ' '|| argv[1][i] == '\t')
				i++;
		while(argv[1][i])
		{
			if(argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;
			if(argv[1][i] != ' ' || argv[1][i] != '\t')
			{
				if(flag == 1)
					write(1, " ", 1);
				write(1, &argv[1][i], 1);
				flag = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
