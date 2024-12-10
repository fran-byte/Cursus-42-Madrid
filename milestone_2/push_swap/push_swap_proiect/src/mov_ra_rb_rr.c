/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_ra_rb_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:09:50 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:23:06 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Movements: reverse A - reverse B - Double-Revese A & B  */

#include "../inc/push_swap.h"

void	ra(t_list *stack_a)
{
	t_list	*current_a;
	int		temp_a;

	if (!stack_a || !stack_a->next)
		return ;
	temp_a = *stack_a->number;
	current_a = stack_a;
	while (current_a->next != NULL)
	{
		*current_a->number = *current_a->next->number;
		current_a = current_a->next;
	}
	*current_a->number = temp_a;
	write(1, "ra\n", 3);
}

void	rb(t_list *stack_b)
{
	t_list	*current_b;
	int		temp_b;

	if (!stack_b || !stack_b->next)
		return ;
	temp_b = *stack_b->number;
	current_b = stack_b;
	while (current_b->next != NULL)
	{
		*current_b->number = *current_b->next->number;
		current_b = current_b->next;
	}
	*current_b->number = temp_b;
	write(1, "rb\n", 3);
}

void	ra_rr(t_list *stack_a)
{
	t_list	*current_a;
	int		temp_a;

	if (!stack_a || !stack_a->next)
		return ;
	temp_a = *stack_a->number;
	current_a = stack_a;
	while (current_a->next != NULL)
	{
		*current_a->number = *current_a->next->number;
		current_a = current_a->next;
	}
	*current_a->number = temp_a;
}

void	rb_rr(t_list *stack_b)
{
	t_list	*current_b;
	int		temp_b;

	if (!stack_b || !stack_b->next)
		return ;
	temp_b = *stack_b->number;
	current_b = stack_b;
	while (current_b->next != NULL)
	{
		*current_b->number = *current_b->next->number;
		current_b = current_b->next;
	}
	*current_b->number = temp_b;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra_rr(*stack_a);
	rb_rr(*stack_b);
	write(1, "rr\n", 3);
}
