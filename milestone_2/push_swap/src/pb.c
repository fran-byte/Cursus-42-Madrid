/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:40 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:38 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pb: Put the first element from stack a and places it on stack b.*/

#include "../inc/push_swap.h"

void del(void *number)
{
	free(number);
}

#include "../inc/push_swap.h"

void pb(t_list **lst, t_list **lstb) // FUNCION EN PRUEBAS **** CON ERRORES ***
{
	t_list *new_node_b = NULL;
	t_list *stackb;
	t_list *tmp;
	int temp;

	if (!lst || !*lst) // Si la lista está vacía o el puntero es NULL
		return;

	// Creamos nodo en B y añadimos a la lista de B
	stackb = init_stack_b(new_node_b ,lstb);

	// Apuntamos a la cabecera de stack B
	stackb = *lstb;

	// Copiamos el valor (no la dirección) del primer nodo de A
	temp = *(*lst)->number;
	// Asignamos ese valor al primer nodo de B
	*stackb->number = temp;
	write(1, "pb\n", 3);


	// Trabajamos el stack A
	tmp = (*lst)->next;		 // Copiamos en un ptr temporal la dirección del siguiente nodo de A
	ft_lstdelone(*lst, del); // Eliminamos el nodo actual de A
	*lst = tmp;				 // Actualizamos la cabecera de A al siguiente nodo


}
