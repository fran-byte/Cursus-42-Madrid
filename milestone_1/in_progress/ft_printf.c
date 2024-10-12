/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:28:22 by frromero          #+#    #+#             */
/*   Updated: 2024/10/12 16:07:48 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_num(unsigned long long number_vargs, int base, int *index)
{
	if (base == 0)
	{
		if (number_vargs >= 10)
			put_num(number_vargs / 10, 0, index);
		*index += write(1, &"0123456789"[number_vargs % 10], 1);
	}
	else if (base == 1)
	{
		if (number_vargs >= 16)
			put_num(number_vargs / 16, 1, index);
		*index += write(1, &"0123456789abcdef"[number_vargs % 16], 1);
	}
	else if (base == 2)
	{
		if (number_vargs >= 16)
			put_num(number_vargs / 16, 2, index);
		*index += write(1, &"0123456789ABCDEF"[number_vargs % 16], 1);
	}
}

static void	put_pointer(va_list vargs, int *index)
{
	unsigned long long	ptr_address;

	ptr_address = va_arg(vargs, unsigned long long);
	if (ptr_address == 0)
	{
		*index += write(1, "(nil)", 5);
		return ;
	}
	*index += write(1, "0x", 2);
	put_num(ptr_address, 1, index);
}

static void	extract_formt_two(char const *format, va_list vargs, int *index)
{
	int	nb;

	if (*format == 'd' || *format == 'i')
	{
		nb = va_arg(vargs, int);
		if (nb < 0)
		{
			*index += write(1, "-", 1);
			put_num((unsigned long long)(-(long long)nb), 0, index);
		}
		else
			put_num((unsigned long long)(nb), 0, index);
	}
	else if (*format == 'u')
		put_num(va_arg(vargs, unsigned int), 0, index);
	else if (*format == 'x')
		put_num(va_arg(vargs, unsigned int), 1, index);
	else if (*format == 'X')
		put_num(va_arg(vargs, unsigned int), 2, index);
	else if (*format == 'p')
		put_pointer(vargs, index);
	else if (*format == '%')
		(*index) += write(1, "%", 1);
}

static void	extract_formt(char const *format, va_list vargs, int *index)
{
	char	c;
	char	*str;

	if (format == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	else if (*format == 'c')
	{
		c = (char)va_arg(vargs, int);
		(*index) += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		str = va_arg(vargs, char *);
		if (str == NULL)
			str = "(null)";
		while (*str++)
			(*index) += write(1, str - 1, 1);
	}
	else
		extract_formt_two(format, vargs, index);
}

int	ft_printf(char const *format, ...)
{
	va_list	vargs;
	int		index;

	index = 0;
	va_start(vargs, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			extract_formt(++format, vargs, &index);
		else
			index += write(1, format, 1);
		format++;
	}
	va_end(vargs);
	return (index);
}
