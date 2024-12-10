/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:56:38 by frromero          #+#    #+#             */
/*   Updated: 2024/11/19 21:19:06 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Custom implementation of atoi for `push_swap`.
   Handles spaces, signs, and overflow errors.
*/

#include "../inc/push_swap.h"
#include <limits.h>

static int	sign_and_space(const char *str, int *sign)
{
	int	i;

	i  = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' ||
		str[i + 1] == '+'))
			program_error();
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = sign_and_space(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > INT_MAX / 10 || (nb == INT_MAX / 10 &&
			(str[i] - '0') > INT_MAX % 10))
				program_error();
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

