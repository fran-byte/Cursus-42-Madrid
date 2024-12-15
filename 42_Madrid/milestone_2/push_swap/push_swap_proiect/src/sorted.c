/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:54 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 17:12:17 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	Checks if the stack is sorted in ascending order.
	Returns 1 if sorted, otherwise 0. */

#include "../inc/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (*(lst->number) > *(lst->next->number))
			return (0);
		lst = lst->next;
	}
	return (1);
}
