/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:32:54 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 10:18:40 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if a character is an alphabetic letter (A-Z or a-z) */

#include "libft.h"

int ft_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z'))
        return (1);
    return (0);
}