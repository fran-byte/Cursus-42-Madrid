/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:42:52 by frromero          #+#    #+#             */
/*   Updated: 2024/09/22 08:55:32 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert a character from uppercase to lowercase */

#include "libft.h"

int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
