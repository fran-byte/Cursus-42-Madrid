/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:28:27 by frromero          #+#    #+#             */
/*   Updated: 2024/09/24 18:00:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*nw_src;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	nw_src = malloc(j + 1);
	if (nw_src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		nw_src[i] = src[i];
		i++;
	}
	nw_src[i] = '\0';
	return (nw_src);
}
