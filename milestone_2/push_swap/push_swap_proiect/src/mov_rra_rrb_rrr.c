/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rra_rrb_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:15:17 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:24:48 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*	Movements:	inverse-reverse A - inverse-reverse B
				inverse-Double-Revese A & B  */

void	rra(t_list *stack_a)
{
	t_list	*current_a;
	t_list	*last_stack_a;
	int		temp_a;

	if (!stack_a || !stack_a->next)
		return ;
	last_stack_a = ft_lstlast(stack_a);
	temp_a = *last_stack_a->number;
	current_a = last_stack_a->prev;
	while (current_a != NULL)
	{
		*current_a->next->number = *current_a->number;
		current_a = current_a->prev;
	}
	*stack_a->number = temp_a;
	write(1, "rra\n", 4);
}

void	rrb(t_list *stack_b)
{
	t_list	*current_b;
	t_list	*last_stack_b;
	int		temp_b;

	if (!stack_b || !stack_b->next)
		return ;
	last_stack_b = ft_lstlast(stack_b);
	temp_b = *last_stack_b->number;
	current_b = last_stack_b->prev;
	while (current_b != NULL)
	{
		*current_b->next->number = *current_b->number;
		current_b = current_b->prev;
	}
	*stack_b->number = temp_b;
	write(1, "rrb\n", 4);
}

void	rra_rrr(t_list *stack_a)
{
	t_list	*current_a;
	t_list	*last_stack_a;
	int		temp_a;

	if (!stack_a || !stack_a->next)
		return ;
	last_stack_a = ft_lstlast(stack_a);
	temp_a = *last_stack_a->number;
	current_a = last_stack_a->prev;
	while (current_a != NULL)
	{
		*current_a->next->number = *current_a->number;
		current_a = current_a->prev;
	}
	*stack_a->number = temp_a;
}

void	rrb_rrr(t_list *stack_b)
{
	t_list	*current_b;
	t_list	*last_stack_b;
	int		temp_b;

	if (!stack_b || !stack_b->next)
		return ;
	last_stack_b = ft_lstlast(stack_b);
	temp_b = *last_stack_b->number;
	current_b = last_stack_b->prev;
	while (current_b != NULL)
	{
		*current_b->next->number = *current_b->number;
		current_b = current_b->prev;
	}
	*stack_b->number = temp_b;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra_rrr(*stack_a);
	rrb_rrr(*stack_b);
	write(1, "rrr\n", 4);
}
