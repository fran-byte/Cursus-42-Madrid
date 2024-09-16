/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:56 by frromero          #+#    #+#             */
/*   Updated: 2024/09/16 23:49:51 by frromero         ###   ########.fr       */
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
unsigned int ft_strlcat(char *dst, const char *src, unsigned int size);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);

int ft_strncmp(const char *s1, const char *s2, unsigned int n);
int ft_toupper(char c);
int ft_tolower(char c);


#endif