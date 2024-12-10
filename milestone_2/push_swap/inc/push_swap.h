/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:49:16 by frromero          #+#    #+#             */
/*   Updated: 2024/11/22 19:39:26 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list
{
	int *number;
	struct s_list *prev;
	struct s_list *next;
}t_list;

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>	// borrar * * * * ************************************
#include <string.h> // borrar * * * * ************************************

void	program_error();
void	program_exit();
int	ft_atoi(const char *str);
void	check_input(int argc, char **argv);
t_list	*init_stack_a(int argc, char **argv, t_list *new_node, t_list **lst);
t_list	*init_stack_b(t_list *new_nodeb, t_list **lstb);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(int *number);
int	ft_lstsize(t_list *lst);
void	print_numbers(void *number);  // BORRAR esta función imprimiremos con write()
void	sa(t_list *lst);
void	ra(t_list *lst);
void	rra(t_list *lst);
void	sb(t_list *lstb);
void	rb(t_list *lstb);
void	rrb(t_list *lstb);
void	rrr(t_list *lst, t_list *lstb);
void	rr(t_list *lst, t_list *lstb);
void	ss(t_list *lst, t_list *lstb);
/*En este caso modificaremos la dirección de lst es necesario pasar el puntero
y no una copia como en el resto*/
void	pb(t_list **lst, t_list **lstb);
void	pa(t_list **lst, t_list **lstb);
void	del(void *number);
char	**one_argument(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif
