/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:33:00 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 16:16:35 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i = 0;
	int j = 0;
	int	count = 0;

	while(s[i])
	{
		while(accept[j])
		{
			if(s[i] == accept[j])
			{
				count++;
				j = 0;
				break;
			}
			j++;
		}
		i++;
	}
	return (count);
}
