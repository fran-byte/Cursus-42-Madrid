/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:46:06 by frromero          #+#    #+#             */
/*   Updated: 2024/09/17 00:39:23 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    unsigned int i;

    i =0;    
    while(s1[i] == s2[i] && i < n)      
        i++;
    return (s1[i] - s2[i]);
}