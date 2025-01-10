/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:22:11 by frromero          #+#    #+#             */
/*   Updated: 2025/01/03 19:40:42 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	char c;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			c = 0;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				c = 'a' + 'z' - argv[1][i];
				write (1, &c, 1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				c = 'A' + 'Z' - argv[1][i];
				write (1, &c, 1);
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
