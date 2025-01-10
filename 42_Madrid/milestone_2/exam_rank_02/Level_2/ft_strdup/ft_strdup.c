/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:04:26 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 11:18:38 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
# include<stdio.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char	*new;

	while(src[i] != '\0')
		i++;
	new = malloc((sizeof new) * i + 1);
	if(!new)
		return(NULL);
	i = 0;
	while(src[i] != '\0')
	{
		new[i] = src [i];
		i++;
	}
	new[i] = '\0';
	return(new);
}
