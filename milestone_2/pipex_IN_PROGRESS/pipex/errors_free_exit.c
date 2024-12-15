/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:36:09 by frromero          #+#    #+#             */
/*   Updated: 2024/12/14 18:40:45 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"pipex.h"

void	program_error(void)
{
	write(1, &"Error\n", 6);
	exit(EXIT_FAILURE);
}

void	program_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	del(void *number)
{
	free(number);
}

void	free_arguments(char **str_char)
{
	int	i;

	if (!str_char)
		return ;
	i = 0;
	while (str_char[i] != NULL)
	{
		free(str_char[i]);
		i++;
	}
	free(str_char);
}
