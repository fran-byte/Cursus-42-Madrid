/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:24 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 19:45:41 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reverse rotation (rra) moves the value of the last node to the first position,
  and shifts all other nodes values one step forward.*/

#include "../inc/push_swap.h"

void rra(t_list *lst)
{
	t_list *current;
	t_list *last;
	int temp;

	if (!lst || !lst->next)
		return;
	last = ft_lstlast(lst);
	temp = *last->number;
	current = last->prev;
	while (current != NULL)
	{
		*current->next->number = *current->number;
		current = current->prev;
		write(1, "rra\n", 4);
	}
	*lst->number = temp;
	write(1, "rra\n", 4);
}
