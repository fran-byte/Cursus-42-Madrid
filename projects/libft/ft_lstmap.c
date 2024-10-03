/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:16 by frromero          #+#    #+#             */
/*   Updated: 2024/10/03 20:56:52 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list 'lst' and applies the function 'f' to the content of each
node. Creates a list resulting from the correct and successive application of
the function 'f' over each node. The 'del' function is used to delete the
content of a node, if necessary.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*curr;
	t_list	*new;
	void	*aux;

	if (!f || !del || !lst)
		return (0);
	first = 0;
	curr = lst;
	while (curr)
	{
		aux = f(curr->content);
		new = ft_lstnew(aux);
		if (!new)
		{
			free(aux);
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, new);
		curr = curr->next;
	}
	return (first);
}
