/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_sa_sb_pa_pb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:19:01 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:27:04 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	Movements: push A - push B - swap A - swap B - double-swap A & B*/

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = tmp;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = tmp;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	sa(t_list *stack_a)
{
	t_list	*second_a;
	int		*temp_a;

	if (!stack_a || !stack_a->next)
		return ;
	second_a = stack_a->next;
	temp_a = stack_a->number;
	stack_a->number = second_a->number;
	second_a->number = temp_a;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	t_list	*second_b;
	int		*temp_b;

	if (!stack_b || !stack_b->next)
		return ;
	second_b = stack_b->next;
	temp_b = stack_b->number;
	stack_b->number = second_b->number;
	second_b->number = temp_b;
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
