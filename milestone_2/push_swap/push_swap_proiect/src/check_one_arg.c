/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:07:51 by frromero          #+#    #+#             */
/*   Updated: 2024/12/11 21:16:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This file validates input for the `push_swap` program.
	`inputs_are_digits`: Ensures inputs are valid numbers or signs.
	`inputs_has_dup`: Checks for duplicate numbers.
	`int_check_limit`: Validates integer range for all inputs.
	`check_input`: Main function coordinating all validations.*/

/* Necessary to free integers from the ft_split function.*/

#include "../inc/push_swap.h"

static int	inputs_are_digits(int gc, char **gv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gc)
	{
		j = 0;
		while (gv[i][j] != '\0')
		{
			if (!((gv[i][j] >= '0' && gv[i][j] <= '9') ||
				(gv[i][j] == '-' || gv[i][j] == '+')))
			{
				return (-1);
			}
			j++;
		}
	}
	return (0);
}

static int	inputs_has_dup(int gc, char **gv)
{
	int	i;
	int	j;

	i = 0;
	while (i < gc)
	{
		j = i + 1;
		while (j < gc)
		{
			if (ft_strcmp(gv[i], gv[j]) == 0)
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	int_check_limit(int gc, char **gv)
{
	int	i;

	i = -1;
	while (++i < gc)
		ft_atoi_special(gv[i], gv);
}

static int	has_one_element(char **gv)
{
	int	count;

	count = 0;
	if (!gv)
		return (0);
	while (gv[count] != NULL)
	{
		count++;
		if (count > 1)
			return (0);
	}
	return (1);
}

char	**check_with_one_arg(int gc, char **gv)
{
	char	**sp_argv;
	int		i;

	i = 0;
	if (gc == 2)
	{
		sp_argv = one_argument(gv[1], ' ');
		if (has_one_element(sp_argv))
		{
			free_arguments(sp_argv);
			program_exit();
		}
		while (sp_argv[i] != NULL)
			i++;
		if (inputs_are_digits(i, sp_argv) == -1
			|| inputs_has_dup(i, sp_argv) == -1)
		{
			free_arguments(sp_argv);
			program_error();
		}
		int_check_limit(i, sp_argv);
		return (sp_argv);
	}
	return (0);
}
