/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:23:03 by frromero          #+#    #+#             */
/*   Updated: 2024/09/20 15:49:18 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character is an ASCII value between 0 and 127 */

#include "libft.h"

int ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
