/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:56:52 by frromero          #+#    #+#             */
/*   Updated: 2024/09/30 15:56:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Itera la lista ’lst’ y aplica la función ’f’ en el
contenido de cada nodo.*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
