/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:57:26 by frromero          #+#    #+#             */
/*   Updated: 2024/10/03 21:27:49 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Creates a new node using malloc. The member variable 'content' is initialized
with the content of the parameter 'content'. The 'next' variable is initialized
to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
