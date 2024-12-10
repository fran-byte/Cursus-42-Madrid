/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:26 by frromero          #+#    #+#             */
/*   Updated: 2024/11/20 16:40:47 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Creates a new node for a singly linked list using malloc. The number
   of the node is initialized with the provided parameter 'number', and
   the 'next' pointer is set to NULL. The node is not yet linked to a list.*/

#include "../inc/push_swap.h"

t_list	*ft_lstnew(int *number)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
