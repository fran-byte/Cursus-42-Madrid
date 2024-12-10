/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:06:04 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 19:55:14 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rotation (rb) moves the value of the first node to the last position,
   and shifts all other nodes' values one step backward.*/

#include "../inc/push_swap.h"

void rb(t_list *lstb)
{
	t_list *currentb;
	int tempb;

	if (!lstb || !lstb->next)
		return;
	tempb = *lstb->number;
	currentb = lstb;
	while (currentb->next != NULL)
	{
		*currentb->number = *currentb->next->number;
		currentb = currentb->next;
		write(1, "rb\n", 3);
	}
	*currentb->number = tempb;
	write(1, "rb\n", 3);
}
