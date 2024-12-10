/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:49:16 by frromero          #+#    #+#             */
/*   Updated: 2024/12/10 20:17:02 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				*number;
	int				index;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_atoi_special(const char *str, char **numbers);
int		is_sorted(t_list *lst);
int		ft_strcmp(char *s1, char *s2);
int		minimum(t_list **stack, int number);
int		maximum(t_list **stack, int number);
int		dist_node(t_list **stack, int index);
size_t	ft_strlen(const char *str);
t_list	*find_smallest_in_a(t_list *stack_a);
t_list	*find_lowest_cost_node_b(t_list *stack_a, t_list *stack_b);
t_list	*find_lowest_cost_node_a(t_list *stack_a, t_list *stack_b);
t_list	*find_target(t_list *a_node, t_list *stack_b);
t_list	*find_target_a(t_list *b_node, t_list *stack_a);
t_list	*init_stack_one_arg(int argc, char **argv,
			t_list *new_node, t_list **lst);
t_list	*init_stack(int argc, char **argv, t_list *new_node, t_list **stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int *number);
char	**check_with_one_arg(int gc, char **gv);
char	**one_argument(char *s, char c);
void	free_arguments(char **numbers);
void	move_nodes_to_top(t_list **stack_a, t_list **stack_b,
			t_list *node_a, t_list *target_b);
void	move_nodes_to_top_end(t_list **stack_a, t_list **stack_b,
			t_list *node_b, t_list *target_a);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	del(void *number);
void	assign_indices(t_list *stack);
void	sort_three(t_list *stack_a);
void	sort_four(t_list *stack_a, t_list *stack_b);
void	sort_five(t_list *stack_a, t_list *stack_b);
void	check_with_multiple_args(int argc, char **argv);
void	algorithm(t_list **stack_a, t_list **stack_b);
void	check(int argc, char **argv, t_list **stack_a);
void	program_error(void);
void	program_exit(void);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	turkish_algorithm(t_list **stack_a, t_list **stack_b);

#endif
