/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:40 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 19:45:27 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap (sa) swaps the values of the first two nodes in the list.
   The values of the first and second nodes are exchanged.*/

#include "../inc/push_swap.h"

void sa(t_list *lst)
{
	t_list *second;
	int *temp;

	if (!lst || !lst->next)
		return ;
	second = lst->next;
	temp = lst->number;
	lst->number = second->number;
	second->number = temp;
	write(1, "sa\n", 3);
}
