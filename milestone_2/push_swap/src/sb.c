/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:40 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 20:31:35 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap (sb) swaps the values of the first two nodes in the list.
   The values of the first and second nodes are exchanged.*/

#include "../inc/push_swap.h"

void sb(t_list *lstb)
{
	t_list *secondb;
	int *tempb;

	if (!lstb || !lstb->next)
		return ;
	secondb = lstb->next;
	tempb = lstb->number;
	lstb->number = secondb->number;
	secondb->number = tempb;
	write(1, "sb\n", 3);
}
