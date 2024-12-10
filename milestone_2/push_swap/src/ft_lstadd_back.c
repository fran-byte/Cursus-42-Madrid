/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:18 by frromero          #+#    #+#             */
/*   Updated: 2024/11/20 16:55:32 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node 'new' to the end of the list 'lst'.
   1. If the list is empty, 'new' becomes the head.
   2. If the list is not empty, find the last node and update its 'next' to point to 'new'. */


#include "../inc/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}
