/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:07:51 by frromero          #+#    #+#             */
/*   Updated: 2024/12/10 20:24:34 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   This file validates input for the `push_swap` program. (MULTI-ARGUMENTS)
   - `inputs_are_digits`: Ensures inputs are valid numbers or signs.
   - `inputs_has_dup`: Checks for duplicate numbers.
   - `int_check_limit`: Validates integer range for all inputs.
   - `check_input`: Main function coordinating all validations.
*/

#include "../inc/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	inputs_are_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') ||
				(argv[i][j] == '-' || argv[i][j] == '+')))
				program_error();
			j++;
		}
	}
}

static void	inputs_has_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				program_error();
			j++;
		}
		i++;
	}
}

static void	int_check_limit(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_atoi(argv[i]);
}

void	check_with_multiple_args(int argc, char **argv)
{
	if (argc > 2)
	{
		inputs_are_digits(argc, argv);
		inputs_has_dup(argc, argv);
		int_check_limit(argc, argv);
	}
}
