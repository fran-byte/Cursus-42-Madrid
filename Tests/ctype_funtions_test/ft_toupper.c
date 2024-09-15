/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:31:03 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 22:38:04 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert a character from lowercase to uppercase */

#include "libft.h"

int ft_toupper(char c)
{
    if (c >= 'a' && c <='z')
        {
            return (c - 32);
        }        
    return (c);
}