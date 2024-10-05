/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:45 by frromero          #+#    #+#             */
/*   Updated: 2024/10/05 22:20:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes a node 'lst' as a parameter and frees the memory of its content using
the 'del' function provided as a parameter, in addition to freeing the node
itself. The memory of 'next' should not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
