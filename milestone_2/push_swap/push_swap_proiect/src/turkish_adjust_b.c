/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_adjust_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:54:23 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:45:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*find_largest_in_b(t_list *stack_b)
{
	t_list	*current;
	t_list	*target;
	int		largest;

	current = stack_b;
	target = NULL;
	largest = INT_MIN;
	while (current != NULL)
	{
		if (*(current->number) > largest)
		{
			largest = *(current->number);
			target = current;
		}
		current = current->next;
	}
	return (target);
}

t_list	*find_target(t_list *a_node, t_list *stack_b)
{
	t_list	*current;
	t_list	*target;
	int		largest_smaller;

	current = stack_b;
	target = NULL;
	largest_smaller = INT_MIN;
	while (current != NULL)
	{
		if (*(current->number) < *(a_node->number)
			&& *(current->number) > largest_smaller)
		{
			largest_smaller = *(current->number);
			target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = find_largest_in_b(stack_b);
	return (target);
}

static int	calculate_cost(t_list *node, t_list *stack_a, t_list *stack_b)
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
	target = find_target(node, stack_b);
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

t_list	*find_lowest_cost_node_b(t_list *stack_a, t_list *stack_b)
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
		cost = calculate_cost(current, stack_a, stack_b);
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
