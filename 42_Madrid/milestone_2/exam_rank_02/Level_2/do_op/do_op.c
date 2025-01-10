/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:55:30 by frromero          #+#    #+#             */
/*   Updated: 2025/01/03 20:06:15 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if(argv[2][0] == '+')
			printf("%d\n", (atoi(argv[1]) + atoi(argv[3])));
		if(argv[2][0] == '-')
			printf("%d\n", (atoi(argv[1]) - atoi(argv[3])));
		if(argv[2][0] == '*')
			printf("%d\n", (atoi(argv[1]) * atoi(argv[3])));
		if(argv[2][0] == '/')
			printf("%d\n", (atoi(argv[1]) / atoi(argv[3])));
	}
	return (0);
}
