/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:25 by frromero          #+#    #+#             */
/*   Updated: 2024/11/20 16:51:56 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node 'new' to the front of the list 'lst'.
   1. Set 'new->next' to point to the current head (*lst).
   2. If the list is not empty, update the current head's 'prev' to 'new'.
   3. Set 'new->prev' to NULL and update *lst to point to 'new'. */


#include "../inc/push_swap.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}
