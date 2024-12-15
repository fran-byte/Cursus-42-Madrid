/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:44:15 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:36:50 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Sortings for 3, 4 and 5 numbers */

#include "../inc/push_swap.h"

void	sort_three(t_list *stack_a)
{
	if ((*stack_a->number) > (*stack_a->next->number)
		&& (*stack_a->next->number) > (*stack_a->next->next->number))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a->next->next->number) > (*stack_a->number)
		&& (*stack_a->number) > (*stack_a->next->number))
	{
		rra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a->next->number) > (*stack_a->next->next->number)
		&& (*stack_a->next->next->number) > (*stack_a->number))
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a->next->number) > (*stack_a->number)
		&& (*stack_a->number) > (*stack_a->next->next->number))
		rra(stack_a);
	else if ((*stack_a->number) > (*stack_a->next->next->number)
		&& (*stack_a->next->next->number) > (*stack_a->next->number))
		ra(stack_a);
}

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	int		dist;

	current_a = stack_a;
	dist = dist_node(&current_a, minimum(&current_a, -1));
	if (dist == 1)
		ra(current_a);
	else if (dist == 2)
	{
		ra(current_a);
		ra(current_a);
	}
	else if (dist == 3)
		rra(current_a);
	if (is_sorted(current_a) == 1)
		return ;
	pb(&current_a, &stack_b);
	sort_three(current_a);
	pa(&current_a, &stack_b);
}

static void	rotate_by_dist(t_list *current_a, int dist)
{
	if (dist == 1)
		ra(current_a);
	else if (dist == 2)
	{
		ra(current_a);
		ra(current_a);
	}
	else if (dist == 3)
	{
		if (ft_lstsize(current_a) == 5)
		{
			rra(current_a);
			rra(current_a);
		}
		else
			rra(current_a);
	}
	else if (dist == 4)
	{
		if (ft_lstsize(current_a) == 5)
			rra(current_a);
	}
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	int		dist;

	current_a = stack_a;
	while (ft_lstsize(current_a) > 3)
	{
		dist = dist_node(&current_a, minimum(&current_a, -1));
		rotate_by_dist(current_a, dist);
		pb(&current_a, &stack_b);
		assign_indices(current_a);
	}
	sort_three(current_a);
	while (ft_lstsize(stack_b) > 0)
	{
		pa(&current_a, &stack_b);
		if ((*current_a->number) > (*current_a->next->number))
			sa(current_a);
	}
}
