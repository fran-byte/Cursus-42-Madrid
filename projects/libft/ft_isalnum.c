/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:50:13 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 10:18:28 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character  is alphanumeric (A-Z, a-z, or 0-9) */

#include "libft.h"

int ft_isalnum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z') || c >= '0' && c <= '9')
        return (1);
    return (0);
}