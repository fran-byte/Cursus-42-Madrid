/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_adjust_top_end.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:21:55 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:48:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* - calculate_move: Computes the number of moves needed to bring a node to the
    top of the stack.
   - execute_single_stack_moves_a: Executes the rotations required to move a
   node to the top of stack a.
   - execute_single_stack_moves_b: Executes the rotations required to move a
   node to the top of stack b.
   - execute_moves: Performs simultaneous rotations on both stacks, optimizing
   the moves.
   - move_nodes_to_top_end: Moves a node from stack_a and a target node from
   stack_b to the top of their respective stacks.  */

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

static void	execute_single_stack_moves_a(t_list **stack, int moves)
{
	while (moves > 0)
	{
		ra(*stack);
		moves--;
	}
	while (moves < 0)
	{
		rra(*stack);
		moves++;
	}
}

static void	execute_single_stack_moves_b(t_list **stack, int moves)
{
	while (moves > 0)
	{
		rb(*stack);
		moves--;
	}
	while (moves < 0)
	{
		rrb(*stack);
		moves++;
	}
}

static void	execute_moves(t_list **stack_a, t_list **stack_b, int move_a,
	int move_b)
{
	while (move_a > 0 && move_b > 0)
	{
		rr(stack_a, stack_b);
		move_a--;
		move_b--;
	}
	while (move_a < 0 && move_b < 0)
	{
		rrr(stack_a, stack_b);
		move_a++;
		move_b++;
	}
	execute_single_stack_moves_a(stack_a, move_a);
	execute_single_stack_moves_b(stack_b, move_b);
}

void	move_nodes_to_top_end(t_list **stack_a, t_list **stack_b,
	t_list *target_a, t_list *node_b)
{
	int	move_a;
	int	move_b;

	move_a = calculate_move(*stack_a, node_b);
	move_b = calculate_move(*stack_b, target_a);
	execute_moves(stack_a, stack_b, move_a, move_b);
}
