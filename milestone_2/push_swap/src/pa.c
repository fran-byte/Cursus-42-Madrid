/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:36:54 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 17:52:04 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pa: Put the first element from stack b and places it on stack a.*/

#include "../inc/push_swap.h"

void pa(t_list **lst, t_list **lstb)
{
	t_list *new_node_a = NULL;
	t_list *stacka;
	t_list *tmp;
	int temp;

	if (!lst || !*lst) // Si la lista está vacía o el puntero es NULL
		return;

	// Creamos nodo en B y añadimos a la lista de B
	stacka = init_stack_b(new_node_a ,lst);

	// Apuntamos a la cabecera de stack B
	stacka = *lst;

	// Copiamos el valor (no la dirección) del primer nodo de A
	temp = *(*lstb)->number;
	// Asignamos ese valor al primer nodo de B
	*stacka->number = temp;
	write(1, "pa\n", 3);


	// Trabajamos el stack A
	tmp = (*lstb)->next;		 // Copiamos en un ptr temporal la dirección del siguiente nodo de A
	ft_lstdelone(*lstb, del); // Eliminamos el nodo actual de A
	*lstb = tmp;				 // Actualizamos la cabecera de A al siguiente nodo


}
