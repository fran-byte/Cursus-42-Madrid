/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:27 by frromero          #+#    #+#             */
/*   Updated: 2024/12/11 21:12:33 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Utility functions for push_swap to handle program errors, free and ensure
	clean exits. */

#include "../inc/push_swap.h"

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

void	free_arguments(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i] != NULL)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
