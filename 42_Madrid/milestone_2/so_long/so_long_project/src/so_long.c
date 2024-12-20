/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:38:43 by frromero          #+#    #+#             */
/*   Updated: 2024/12/20 21:01:08 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"
# include "../inc/so_long_data.h"


int	main(int argc, char **argv)
{
	int fd;

	fd = parse(argc, argv);
	check_map(fd);

	return (0);
}
