/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exit_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:48:59 by frromero          #+#    #+#             */
/*   Updated: 2024/12/20 20:45:39 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/so_long.h"

void	general_error(void)
{
	write(2, &"Error\n", 6);
	exit(EXIT_FAILURE);
}
void	map_error(void)
{
	write(2, &"Map Error\n", 10);
	exit(EXIT_FAILURE);
}
void	argument_error(void)
{
	write(2, &"Argument Error\n", 15);
	exit(EXIT_FAILURE);
}
void	x_error(char *x)
{
	write(2, x, ft_strlen(x));
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	write(2, &"Open File Error\n", 16);
	exit(EXIT_FAILURE);
}
