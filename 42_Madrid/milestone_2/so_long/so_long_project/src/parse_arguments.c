/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:14:46 by frromero          #+#    #+#             */
/*   Updated: 2025/01/27 16:10:32 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/so_long_data.h"

/**
 * Validates the program's command-line arguments and opens the map file.
 *
 * This function performs the following checks:
 * - Ensures that the program receives exactly 2 arguments.
 * - Verifies that the map file has the correct `.ber` extension.
 *
 * If any of these checks fail, it terminates the program with an error message.
 * If the arguments are valid, it opens the map file for reading.
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv The array of command-line arguments.
 *
 * @return The file descriptor of the opened map file.
 */
int	parse_arguments(int argc, char **argv)
{
	int	ln;
	int	fd;

	if (argc != 2)
		x_error("Error\nWrong Number of Arguments\n");
	ln = ft_strlen(argv[1]);
	if (!(argv[1][ln - 1] == 'r' && argv[1][ln - 2] == 'e'
		&& argv[1][ln - 3] == 'b' && argv[1][ln - 4] == '.'))
		x_error("Error\nInvalid Map extension. It must end with  .ber\n");
	fd = open_file(argv);
	return (fd);
}
