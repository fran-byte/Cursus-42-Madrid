/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:37:32 by frromero          #+#    #+#             */
/*   Updated: 2025/01/03 17:02:42 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *rev_print(char *str)
{

	int	lenght = 0;

	while(str[lenght])
		lenght++;

	while(--lenght >= 0)
	{
		write(1, &str[lenght], 1);
	}
	write(1, "\n", 1);
	return (str);
}
