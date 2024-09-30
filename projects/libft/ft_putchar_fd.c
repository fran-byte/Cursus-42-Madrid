/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:59:33 by frromero          #+#    #+#             */
/*   Updated: 2024/09/30 15:59:35 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Envía el carácter ’c’ al file descriptor especificado.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
