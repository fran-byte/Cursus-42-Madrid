/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:38:44 by frromero          #+#    #+#             */
/*   Updated: 2024/10/10 23:11:50 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	ft_put_str_char(char *str_tokens, va_list vargs, int *index)
{
	int	print_char_tokens;
	
	if(!str_tokens)
	{
		write(1, "(null)", 6);
		return;
	}
	else if(str_tokens == 'c')
	{
		print_char_tokens = va_arg(vargs, int);
		write(1, &print_char_tokens, 1);
		str_tokens++;
		*index++;
	}
	else
	{
		while(*str_tokens)
		{	
			print_char_tokens = va_arg(vargs, int);
			write(1, 6print_char_tokens, 1);
			str_tokens++;
			*index++;
		}
	}	
}
static void	process_char(char const *str_tokens, va_list vargs, int *index)
{

}

static void	extract_formt(char const *str_tokens, va_list vargs, int *index)
{
	if(str_tokens == 's' || str_tokens == 'c')
		process_char(str_tokens, vargs, index);
}


int	ft_printf(char const *str_tokens, ...)
{
	va_list	vargs;
	int	index;

	index = 0;
	va_start(vargs, str_tokens);
	while(*str_tokens)
	{
		if(*str_tokens == '%' && *(str_tokens + 1))
		{
			str_tokens++;
			extract_formt(str_tokens, vargs, &index);
		}
		else
		{
			write(1, str_tokens, 1);
			index++;
			str_tokens++;
		}
	str_tokens++;
	}
	va_end(vargs);
	return(index);
}
