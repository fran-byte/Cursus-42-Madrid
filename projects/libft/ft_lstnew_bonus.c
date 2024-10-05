/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:26 by frromero          #+#    #+#             */
/*   Updated: 2024/10/05 22:16:08 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Creates a new node using malloc. The member variable 'content' is initialized
with the content of the parameter 'content'. The 'next' variable is initialized
to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
