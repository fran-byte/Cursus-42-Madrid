/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:31:41 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 21:37:28 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the length of a string */

#include "libft.h"

int ft_strlen (const char *str)
{
    int i;

    i = 0;
    while(str[i] != 0)
    {
           i++;
    }
    return (i);
}