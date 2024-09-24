/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:32:54 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 08:34:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if the character is alphabetic, returning Non-Zero for true */ 
/* and 0 for false */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
