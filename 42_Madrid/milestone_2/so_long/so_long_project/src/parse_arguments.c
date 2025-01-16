/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:14:46 by frromero          #+#    #+#             */
/*   Updated: 2025/01/16 20:00:44 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/so_long.h"
# include "../inc/so_long_data.h"

/* Validates program arguments and opens the map file:
   - Checks if the number of arguments is exactly 2
   - Verifies ".ber" extension. */

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
