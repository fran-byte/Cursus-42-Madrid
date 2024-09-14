/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:56 by frromero          #+#    #+#             */
/*   Updated: 2024/09/14 19:24:12 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int ft_isalpha(char c);
int ft_isalnum(char c);
int ft_isdigit(char c);
int ft_isascii(char c);
int ft_isprint(char c);
int ft_strlen (char *str);
unsigned int ft_strlcpy(char *dst, const char *src, unsigned int size);


#endif