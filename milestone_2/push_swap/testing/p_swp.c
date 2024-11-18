/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:31:22 by frromero          #+#    #+#             */
/*   Updated: 2024/11/18 21:55:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // Eliminar
#include <stdlib.h>
#include <string.h> // Eliminar

void program_error()
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}
void program_exit()
{
	exit(EXIT_SUCCESS);
}
int inputs_are_digits(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
	}
	return (0);
}
int inputs_has_dup(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
void check_input(int argc, char **argv)
{
	if (argc > 1)
	{
		if (inputs_are_digits(argc, argv) == 1 || inputs_has_dup(argc, argv) == 1)
			program_error();
		if (argc == 2)
			program_exit();
	}
}

int main(int argc, char **argv)
{
	check_input(argc, argv);
	// cuando obtengamos los números de argv hay que chequear los limites del "int"
	return (0);
}
