/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:27 by frromero          #+#    #+#             */
/*   Updated: 2024/11/19 21:22:09 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Utility functions for push_swap to handle program errors
   and ensure clean exits.
*/

#include "../inc/push_swap.h"

void program_error()
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void program_exit()
{
	exit(EXIT_SUCCESS);
}
