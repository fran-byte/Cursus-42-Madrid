/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_measure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:15:37 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:33:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	Helper functions for stack operations: assign indices based on value order,
	find maximum/minimum indices excluding a number,
	and calculate node distance. */

void	assign_indices(t_list *stack)
{
	t_list	*current;
	t_list	*temp;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		temp = stack;
		while (temp)
		{
			if (*temp->number < *current->number)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	maximum(t_list **stack, int number)
{
	t_list	*current;
	int		max_index;

	current = *stack;
	max_index = current->index;
	while (current->next)
	{
		current = current->next;
		if ((current->index > max_index) && current->index != number)
			max_index = current->index;
	}
	return (max_index);
}

int	minimum(t_list **stack, int number)
{
	t_list	*current;
	int		min_index;

	current = *stack;
	min_index = current->index;
	while (current->next)
	{
		current = current->next;
		if ((current->index < min_index) && current->index != number)
			min_index = current->index;
	}
	return (min_index);
}

int	dist_node(t_list **stack, int index)
{
	t_list	*current;
	int		dist_node;

	dist_node = 0;
	current = *stack;
	while (current)
	{
		if (current->index == index)
			break ;
		dist_node++;
		current = current->next;
	}
	return (dist_node);
}
