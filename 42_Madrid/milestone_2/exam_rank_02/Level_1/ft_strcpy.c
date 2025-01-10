/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:31:59 by frromero          #+#    #+#             */
/*   Updated: 2025/01/03 15:55:53 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i= 0;

	while(s2[i] != '\0' )
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
