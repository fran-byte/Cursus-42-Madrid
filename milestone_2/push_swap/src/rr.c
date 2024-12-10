/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:57:26 by frromero          #+#    #+#             */
/*   Updated: 2024/11/21 21:06:29 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reverse rotation (ra) and reverse rotation (rb).*/

#include "../inc/push_swap.h"

void rr(t_list *lst, t_list *lstb)
{
	ra(lst);
	rb(lstb);
	write(1, "rr\n", 3);
}
