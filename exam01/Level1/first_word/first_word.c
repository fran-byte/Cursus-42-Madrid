/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:44:19 by frromero          #+#    #+#             */
/*   Updated: 2024/09/12 21:44:42 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int ft_first_word(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_first_word(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
