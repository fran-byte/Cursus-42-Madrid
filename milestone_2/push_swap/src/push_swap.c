/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:31:22 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 22:53:35 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"



int main(int argc, char **argv)
{
	t_list *lst = NULL;     // Puntero a la cabeza de la lista enlazada (inicialmente vacía)
	t_list *new_node = NULL; // Puntero temporal que apunta a un nuevo nodo durante su creación
	t_list *lstb = NULL;     // Puntero a la cabeza de la lista enlazada (inicialmente vacía)

	check_input(argc, argv);
	init_stack_a(argc, argv, new_node, &lst);
	//init_stack_b(new_nodeb, &lstb);

	// Imprimimos Pila A y Pila B

	printf("\nPila a:\n");
	ft_lstiter(lst, print_numbers);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);


	// Hacemos pb e Imprimimos Pila A y Pila B
	printf("\nHacemos pb:\n");
	pb(&lst, &lstb);
	printf("\nPila a:\n");
	ft_lstiter(lst, print_numbers);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);

	// Hacemos pb e Imprimimos Pila A y Pila B
	printf("\nHacemos pb:\n");
	pb(&lst, &lstb);
	printf("\nPila a:\n");
	ft_lstiter(lst, print_numbers);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);

	printf("\nHacemos sb:\n");
	sb(lstb);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);

	printf("\nHacemos pb:\n");
	pb(&lst, &lstb);
	printf("\nPila a:\n");
	ft_lstiter(lst, print_numbers);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);

	printf("\nHacemos pa:\n");
	pa(&lst, &lstb);
	printf("\nPila a:\n");
	ft_lstiter(lst, print_numbers);
	printf("\nPila b:\n");
	ft_lstiter(lstb, print_numbers);

	ft_lstclear(&lst, del);
	printf("\nPila a BORRADA !!\n");
	ft_lstiter(lst, print_numbers);

	ft_lstclear(&lstb, del);
	printf("\nPila b BORRADA !!\n");
	ft_lstiter(lstb, print_numbers);

	return (0);
}
