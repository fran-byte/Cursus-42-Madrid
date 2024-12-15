/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:25:44 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:55:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - calculate_move: Determines the number of moves needed to place a node a
   the top of the stack.
   - move_nodes: Moves a specified node to the top of the stack using rotation
   operations.
   - last_step: Ensures the stack is sorted by moving the smallest element to
   the top if needed.
   - turkish_algorithm: Implements the sorting algorithm */

#include "../inc/push_swap.h"

static int	calculate_move(t_list *stack, t_list *node)
{
	int		pos;
	int		total_size;
	t_list	*current;

	pos = 0;
	total_size = ft_lstsize(stack);
	current = stack;
	while (current != NULL && current != node)
	{
		pos++;
		current = current->next;
	}
	if (pos <= total_size / 2)
		return (pos);
	else
		return (- (total_size - pos));
}

static void	move_nodes(t_list **stack_a, t_list *node_a)
{
	int	move_a;

	move_a = calculate_move(*stack_a, node_a);
	while (move_a > 0)
	{
		ra(*stack_a);
		move_a--;
	}
	while (move_a < 0)
	{
		rra(*stack_a);
		move_a++;
	}
}

static void	last_step(t_list *stack_a)
{
	t_list	*small_number;

	if (is_sorted(stack_a) == 1)
		return ;
	small_number = find_smallest_in_a(stack_a);
	move_nodes(&stack_a, small_number);
}

void	turkish_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list	**current_a;
	t_list	**current_b;
	t_list	*lowest_cost_node;
	t_list	*target;

	current_a = stack_a;
	current_b = stack_b;
	pb(current_a, current_b);
	pb(current_a, current_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		lowest_cost_node = find_lowest_cost_node_b(*current_a, *current_b);
		target = find_target(lowest_cost_node, *current_b);
		move_nodes_to_top(stack_a, stack_b, lowest_cost_node, target);
		pb(current_a, current_b);
	}
	sort_three(*stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		lowest_cost_node = find_lowest_cost_node_a(*current_b, *current_a);
		target = find_target_a(lowest_cost_node, *current_a);
		move_nodes_to_top_end(stack_a, stack_b, lowest_cost_node, target);
		pa(current_a, current_b);
	}
	last_step(*stack_a);
}
