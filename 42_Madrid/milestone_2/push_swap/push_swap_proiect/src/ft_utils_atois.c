/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_atois.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:34:33 by frromero          #+#    #+#             */
/*   Updated: 2024/12/11 21:37:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* We have two atoi functions, a normal one and a special one that is capable
of freeing memory if there is an error. It will only be used in error checking*/

static int	sign_and_space(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
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
		if (nb > INT_MAX / 10 || (nb == INT_MAX / 10
				&& (str[i] - '0') > INT_MAX % 10))
		{
			program_error();
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

/* Necessary to free integers from the ft_split function.*/

void	ft_atoi_special(const char *str, char **numbers)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = sign_and_space(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > INT_MAX / 10 || (nb == INT_MAX / 10
				&& (str[i] - '0') > INT_MAX % 10))
		{
			free_arguments(numbers);
			program_error();
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
}
