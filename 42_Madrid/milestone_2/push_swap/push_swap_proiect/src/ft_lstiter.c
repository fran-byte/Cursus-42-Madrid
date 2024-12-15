/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:52 by frromero          #+#    #+#             */
/*   Updated: 2024/11/20 07:38:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates through each node of the linked list 'lst' and applies the
   function 'f' to the content of every node*/

#include "../inc/push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->number);
		lst = lst->next;
	}
}
