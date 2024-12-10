/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:06:04 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 19:45:34 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rotation (ra) moves the value of the first node to the last position,
   and shifts all other nodes' values one step backward.*/

#include "../inc/push_swap.h"

void ra(t_list *lst)
{
	t_list *current;
	int temp;

	if (!lst || !lst->next)
		return;
	temp = *lst->number;
	current = lst;
	while (current->next != NULL)
	{
		*current->number = *current->next->number;
		current = current->next;
		write(1, "ra\n", 3);
	}
	*current->number = temp;
	write(1, "ra\n", 3);
}
