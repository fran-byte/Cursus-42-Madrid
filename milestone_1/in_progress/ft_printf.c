/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:28:22 by frromero          #+#    #+#             */
/*   Updated: 2024/10/11 20:07:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer(const char *str_tokens, va_list vargs, int *index)
{
	unsigned long long ptr_addres;

	if (*str_tokens == 'p')
	{
		ptr_addres = (unsigned long long)va_arg(vargs, void *);
		if (ptr_addres == 0)
		{
			*index += write(1, "(nil)", 5);
			return ;
		}
		*index += write(1, "0x", 2);
		print_base(ptr_addres, "0123456789abcdef", 16, index);
	}
}
void	put_num(int number_vargs, int base, int *index)
{
	long long int nb;
	
	nb = number_vargs;
	if (nb < 0)
	{
		*index += write(1, "-", 1);
		nb = -nb;
	}
	if (base == 0)
	{
		if (nb >= 10)
			put_num(nb / 10, 0, index);
		*index += write(1, &"0123456789"[nb % 10], 1);
	}
	else if (base == 1 || base == 2)
	{
		if (nb >= 16)
			put_num(nb / 16, base, index);
		if (base == 1)
			*index += write(1, &"0123456789abcdef"[nb % 16], 1);
		else
			*index += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	}
}

void	extract_formt_two(const char *str_tokens, va_list vargs, int *index)
{
	if (*str_tokens == 'd' || *str_tokens == 'i')
		put_num(va_arg(vargs, int), 0, index);
        else if (*str_tokens == 'u')
		put_num(va_arg(vargs, int), 0, index);
	else if (*str_tokens == 'x')
		put_num(va_arg(vargs, int), 1, index);
	else if (*str_tokens == 'X')
		put_num(va_arg(vargs, int), 2, index);
	else if (*str_tokens == 'p')
	        put_pointer(str_tokens, vargs, index);
	else if (*str_tokens == '%')
		(*index) +=  write(1, "%", 1);

}

void	extract_formt(const char *str_tokens, va_list vargs, int *index)
{

	if (str_tokens == NULL)
	{
		write(1, "(null)", 6);
		return ;
    }
	else if (*str_tokens == 'c')
	{
		char c = (char)va_arg(vargs, int);
			(*index) += write(1, &c, 1);
	}
	else if (*str_tokens == 's')
	{
		char *str = va_arg(vargs, char *);
		if (str == NULL)
			str = "(null)";
		while (*str++)
			(*index) += write(1, str-1, 1);
	}
	else
		extract_formt_two(str_tokens, vargs, index);
}

int	ft_printf(const char *str_tokens, ...)
{
	va_list vargs;
	int	index;

	index = 0;
	if (str_tokens == NULL)
	{
		write(1, "(null)", 6);
		return;
	}
	va_start(vargs, str_tokens);
	while (*str_tokens)
	{
		if (*str_tokens == '%' && *(str_tokens + 1))
			extract_formt(++str_tokens, vargs, &index);
		else
			index += write(1, str_tokens, 1);
		str_tokens++;
	}
	va_end(vargs);
	return index;
}

/*int main()
{
    int index_print;

    char str2 = 'B';
    //char *str2 = NULL;
    //char str2[] = "Hola Mundo!";
    index_print = 0;
    index_print = ft_printf("el Caracter es : %c y acabamos", str2);
    printf("\nn.caracteres= : %d", index_print);
    return 0;
}*/
