/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:14:46 by frromero          #+#    #+#             */
/*   Updated: 2024/12/20 20:45:35 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/so_long.h"
# include "../inc/so_long_data.h"

int	parsing(int argc, char **argv)
{
	int	ln;
	int	fd;

	if (argc != 2)
		argument_error();
	ln = ft_strlen(argv[1]);
	if (!(argv[1][ln - 1] == 'r' && argv[1][ln - 2] == 'e'
		&& argv[1][ln - 3] == 'b' && argv[1][ln - 4] == '.'))
		argument_error();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		file_error();
	return (fd);
}
