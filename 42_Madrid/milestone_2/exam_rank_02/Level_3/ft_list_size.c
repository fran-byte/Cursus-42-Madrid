/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:43:09 by frromero          #+#    #+#             */
/*   Updated: 2025/01/06 11:54:56 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int size = 0;

	while(begin_list->next)
	{
		size++;
		begin_list = begin_list->next;
	}
	return(size);
}
