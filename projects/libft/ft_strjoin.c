/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:26:37 by frromero          #+#    #+#             */
/*   Updated: 2024/09/29 17:01:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_sz;
	char	*str;

	total_sz = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (total_sz + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_sz + 1);
	ft_strlcat(str, s2, total_sz + 1);
	return (str);
}
