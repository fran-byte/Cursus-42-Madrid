/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:47:26 by frromero          #+#    #+#             */
/*   Updated: 2024/12/11 21:19:28 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	We send it to check (check_whith_one_arg) if it is a single argument of
	numbers, send it to check (check_multiple_args) if there are multiple
	arguments ( > 2 ) and we initialize stack_a */

/* Necessary to free integers from the ft_split function.*/

#include "../inc/push_swap.h"

void	check(int argc, char **argv, t_list **stack)
{
	t_list	*new_node;
	int		i;
	char	**argv_split;

	new_node = NULL;
	i = 0;
	if (argc < 2)
		program_exit();
	if (argc == 2)
	{
		while (check_with_one_arg(argc, argv)[i] != NULL)
			i++;
		argv_split = check_with_one_arg(argc, argv);
		init_stack_one_arg(i, argv_split, new_node, stack);
		free_arguments(argv_split);
	}
	else
	{
		check_with_multiple_args(argc, argv);
		init_stack(argc, argv, new_node, stack);
	}
}
