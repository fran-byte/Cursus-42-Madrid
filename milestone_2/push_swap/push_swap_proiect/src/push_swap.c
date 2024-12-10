/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:31:22 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:31:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Main function for the push_swap program.
	Initializes two stacks (stack_a and stack_b), processes input arguments,
	assigns indices for sorting, and executes the sorting algorithm.
	Frees allocated memory for both stacks before exiting. */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check(argc, argv, &stack_a);
	assign_indices(stack_a);
	algorithm(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
}
