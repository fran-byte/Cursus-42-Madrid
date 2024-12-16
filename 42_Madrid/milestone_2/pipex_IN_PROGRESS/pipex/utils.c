/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:20:13 by frromero          #+#    #+#             */
/*   Updated: 2024/12/16 21:37:05 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"pipex.h"

void check_input(int argc)
{
	if (argc != 5)
	{
		write(2, "\nUsage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n\n", 46);
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
