/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:32 by frromero          #+#    #+#             */
/*   Updated: 2024/12/09 23:15:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Counts the number of nodes in a singly linked list. It iterates through
   the list, starting from the node passed as argument*/

#include "../inc/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
