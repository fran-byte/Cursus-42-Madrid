/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:16 by frromero          #+#    #+#             */
/*   Updated: 2024/10/07 17:50:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list 'lst' and applies the function 'f' to the content of each
node. Creates a list resulting from the correct and successive application of
the function 'f' over each node. The 'del' function is used to delete the
content of a node, if necessary.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current_node;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	current_node = lst;
	while (current_node)
	{
		new_content = f(current_node->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			free(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current_node = current_node->next;
	}
	return (new_list);
}
