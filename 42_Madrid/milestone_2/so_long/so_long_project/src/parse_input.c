/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:14:46 by frromero          #+#    #+#             */
/*   Updated: 2024/12/26 00:20:59 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/so_long.h"
# include "../inc/so_long_data.h"

int	parse(int argc, char **argv)
{
	int	ln;
	int	fd;

	if (argc != 2)
		x_error("Wrong Number of Arguments\n");
	ln = ft_strlen(argv[1]);
	if (!(argv[1][ln - 1] == 'r' && argv[1][ln - 2] == 'e'
		&& argv[1][ln - 3] == 'b' && argv[1][ln - 4] == '.'))
		x_error("Invalid Map extension. It must end with  .ber\n");
	fd = open_file(argv);
	return (fd);
}
