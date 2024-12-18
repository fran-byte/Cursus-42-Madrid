/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:20:13 by frromero          #+#    #+#             */
/*   Updated: 2024/12/18 16:38:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/pipex.h"

void check_input(int argc)
{
	if (argc != 5)
	{
		write(2, "\nUsage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n\n", 46);
		exit(EXIT_FAILURE);
	}
}
