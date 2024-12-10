/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:45 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 09:57:18 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Frees the memory of the node 'lst', first using the function 'del' to
   free the number of the node, and then freeing the node itself. The
   'next' pointer is not freed, as only the given node is affected. */

#include "../inc/push_swap.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return;
	del(lst->number);
	free(lst);
}
