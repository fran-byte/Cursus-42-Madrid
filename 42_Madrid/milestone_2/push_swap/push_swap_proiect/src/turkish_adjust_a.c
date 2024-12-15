/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_adjust_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:56:47 by frromero          #+#    #+#             */
/*   Updated: 2024/12/11 15:35:11 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	- find_smallest_in_a: Finds the smallest element in stack_a and returns it.
	- find_target_a: Finds the smallest element in stack_a that is larger than a
	given node from stack_b, or returns the smallest element if no such node
	exists.
	- calculate_cost_for_a: Calculates the cost (in moves) to place a node from
	stack_b to its correct position in stack_a.
	find_lowest_cost_node_a: Finds the node in stack_a with the lowest move cost
	to place it in stack_b*/

#include "../inc/push_swap.h"

t_list	*find_smallest_in_a(t_list *stack_a)
{
	t_list	*current;
	t_list	*target;
	int		smallest;

	current = stack_a;
	target = NULL;
	smallest = INT_MAX;
	while (current != NULL)
	{
		if (*(current->number) < smallest)
		{
			smallest = *(current->number);
			target = current;
		}
		current = current->next;
	}
	return (target);
}

t_list	*find_target_a(t_list *b_node, t_list *stack_a)
{
	t_list	*current;
	t_list	*target;
	int		smallest_larger;

	smallest_larger = INT_MAX;
	current = stack_a;
	target = NULL;
	while (current != NULL)
	{
		if (*(current->number) > *(b_node->number)
			&& *(current->number) < smallest_larger)
		{
			smallest_larger = *(current->number);
			target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = find_smallest_in_a(stack_a);
	return (target);
}

static int	calculate_cost_for_a(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;
	t_list	*current;

	cost_a = 0;
	cost_b = 0;
	current = stack_a;
	while (current != NULL && current != node)
	{
		cost_a++;
		current = current->next;
	}
	if (cost_a > (ft_lstsize(stack_a)) / 2)
		cost_a = (ft_lstsize(stack_a)) - cost_a;
	target = find_target_a(node, stack_b);
	current = stack_b;
	while (current != NULL && current != target)
	{
		cost_b++;
		current = current->next;
	}
	if (cost_b > (ft_lstsize(stack_b)) / 2)
		cost_b = (ft_lstsize(stack_b)) - cost_b;
	return (cost_a + cost_b);
}

t_list	*find_lowest_cost_node_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;
	t_list	*lowest_cost_node;
	int		lowest_cost;
	int		cost;

	lowest_cost = INT_MAX;
	current = stack_a;
	lowest_cost_node = NULL;
	while (current != NULL)
	{
		cost = calculate_cost_for_a(current, stack_a, stack_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			lowest_cost_node = current;
		}
		else if (cost == lowest_cost && lowest_cost_node == NULL)
			lowest_cost_node = current;
		current = current->next;
	}
	return (lowest_cost_node);
}
