/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:24 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 19:55:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reverse rotation (rrb) moves the value of the last node to the first position,
  and shifts all other nodes values one step forward.*/

#include "../inc/push_swap.h"

void rrb(t_list *lstb)
{
	t_list *currentb;
	t_list *lastb;
	int tempb;

	if (!lstb || !lstb->next)
		return;
	lastb = ft_lstlast(lstb);
	tempb = *lastb->number;
	currentb = lastb->prev;
	while (currentb != NULL)
	{
		*currentb->next->number = *currentb->number;
		currentb = currentb->prev;
		write(1, "rrb\n", 4);
	}
	*lstb->number = tempb;
	write(1, "rrb\n", 4);
}
