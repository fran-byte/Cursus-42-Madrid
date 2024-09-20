/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:29:23 by frromero          #+#    #+#             */
/*   Updated: 2024/09/20 15:50:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character is printable (ASCII 32-126) */

#include "libft.h"

int ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
