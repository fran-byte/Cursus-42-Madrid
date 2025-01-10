/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:27:44 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 11:54:04 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	int j;

	if(!s1 || !s2)
		return(0);
	while(s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if(s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return(NULL);
}

