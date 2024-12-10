/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:00 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:38:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Implements the sorting logic based on the size of stack_a. Uses specific
	functions for small sizes and turkish_algorithm for larger lists. */

#include "../inc/push_swap.h"

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL)
		return ;
	if (is_sorted(*stack_a) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
	{
		sa(*stack_a);
		return ;
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(*stack_a);
		return ;
	}
	else if (ft_lstsize(*stack_a) == 4)
	{
		sort_four(*stack_a, *stack_b);
		return ;
	}
	else if (ft_lstsize(*stack_a) == 5)
	{
		sort_five(*stack_a, *stack_b);
		return ;
	}
	turkish_algorithm(stack_a, stack_b);
}
