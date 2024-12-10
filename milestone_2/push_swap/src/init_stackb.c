/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stackb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:03:46 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:39 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* initializes a linked list node are added to the front of the list. */

#include "../inc/push_swap.h"

t_list *init_stack_b(t_list *new_nodeb, t_list **lstb)
{
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = 0;
	new_nodeb = ft_lstnew(ptr);
	if (!new_nodeb)
	{
		free(ptr);
		return (NULL);
	}
	ft_lstadd_front(lstb, new_nodeb);
	return(*lstb);
}
