/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:56 by frromero          #+#    #+#             */
/*   Updated: 2024/09/15 21:37:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdio.h> 

//int ft_isalpha(char c);
//int ft_isalnum(char c);
//int ft_isdigit(char c);
//int ft_isascii(char c);
//int ft_isprint(char c);
int ft_strlen (const char *str);
unsigned int ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int ft_strlcat(char *dst, const char *src, unsigned int size);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);

int ft_toupper(char c);
int ft_tolower(char c);

void test_string_functions();
int main();


#endif