/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:09:43 by frromero          #+#    #+#             */
/*   Updated: 2025/01/03 21:15:15 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i = 0;
	int number = 0;
	int	s = 1;

	while(str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		{
			if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+'
				|| str[i + 1] == '-' || str[i + 1] == ' '))
					return (0);
			if (str[i] == '+')
				i++;
			if (str[i] ==  '-')
			{
				s = -1;
				i++;
			}

		}
	while(str[i] >= '0' && str[i] <= '9')
	{
		number = 10 * number + (int)str[i] - '0';
		i++;
	}
	return(number * s);
}
