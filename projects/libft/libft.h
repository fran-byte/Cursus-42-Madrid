/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:56 by frromero          #+#    #+#             */
/*   Updated: 2024/09/19 18:06:13 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

unsigned int ft_strlen(const char *str);
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
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
