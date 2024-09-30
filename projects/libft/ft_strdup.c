/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:28:27 by frromero          #+#    #+#             */
/*   Updated: 2024/09/28 09:56:18 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*nw_str;

	i = 0;
	j = ft_strlen(s1) + 1;
	nw_str = malloc(j);
	if (nw_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		nw_str[i] = s1[i];
		i++;
	}
	nw_str[i] = '\0';
	return (nw_str);
}
