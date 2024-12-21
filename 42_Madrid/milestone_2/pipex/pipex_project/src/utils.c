/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:20:13 by frromero          #+#    #+#             */
/*   Updated: 2024/12/19 00:27:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Utility functions for input validation, command parsing, memory management,
	and error handling. */

#include "../inc/pipex.h"

void	check_input(int argc, char **argv)
{
	if (argc != 5 || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		write(2, "\nUsage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n\n", 46);
		exit(EXIT_FAILURE);
	}
}

char	**get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	perror(" ");
	exit(EXIT_FAILURE);
}
