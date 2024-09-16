/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:56 by frromero          #+#    #+#             */
/*   Updated: 2024/09/17 00:29:46 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

unsigned int ft_strlen(const char *str);
void *ft_memset(void *s, int c, unsigned int n);
void ft_bzero(void *s, unsigned int n);
void *ft_memcpy(void *dest, const void *src, unsigned int n);
void *ft_memmove(void *dest, const void *src, unsigned int n);
unsigned int ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
unsigned int ft_strlcat(char *dst, const char *src, unsigned int dstsize);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, unsigned int n);
void *ft_memchr(const void *s, int c, unsigned int n);
int ft_memcmp(const void *s1, const void *s2, unsigned int n);
char *ft_strnstr(const char *haystack, const char *needle, unsigned int len);
int ft_atoi(const char *str);
char *ft_strdup(const char *s1);
void *ft_calloc(unsigned int count, unsigned int size);


#endif