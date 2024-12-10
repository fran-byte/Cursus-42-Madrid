/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:57:26 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:47 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reverse rotation (rra) and reverse rotation (rrb).*/

#include "../inc/push_swap.h"

void rrr(t_list *lst, t_list *lstb)
{
	rra(lst);
	rrb(lstb);
	write(1, "rrr\n", 4);
}
