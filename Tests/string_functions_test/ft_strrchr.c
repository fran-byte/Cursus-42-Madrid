/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:40:08 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 17:33:11 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;
    int sz_s;
    
    i = 0;
    sz_s = ft_strlen(s);

    while(sz_s >= 0)
    {
        if (s[sz_s] == c)
        {
            return ((char *)&s[sz_s]);
            
        }
        sz_s--;
    }
    return (0);
}