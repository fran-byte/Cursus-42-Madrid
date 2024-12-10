/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_mult_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:03:46 by frromero          #+#    #+#             */
/*   Updated: 2024/12/10 17:01:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This program initializes a linked list from command line arguments,
   storing integers as nodes. Each integer is converted from a string using
    `ft_atoi`, and nodes are added to the front of the list. */

#include "../inc/push_swap.h"

t_list	*init_stack(int argc, char **argv, t_list *new_node, t_list **stack)
{
	int	i;
	int	*num;

	i = 0;
	while (++i < argc)
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
			return (NULL);
		*num = ft_atoi(argv[i]);
		new_node = ft_lstnew(num);
		if (!new_node)
		{
			free(num);
			return (NULL);
		}
		ft_lstadd_back(stack, new_node);
	}
	return (*stack);
}
