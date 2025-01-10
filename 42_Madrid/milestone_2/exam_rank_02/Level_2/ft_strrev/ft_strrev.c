/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:55:16 by frromero          #+#    #+#             */
/*   Updated: 2025/01/04 13:16:30 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int	i = 0;
	int	lenght = 0;
	char	tmp;

	while(str[lenght])
		lenght++;
	lenght = lenght -1;
	while(lenght >= i)
	{
		tmp = str[lenght];
		str[lenght] = str[i];
		str[i] = tmp;
		i++;
		lenght--;
	}
	return (str);
}
