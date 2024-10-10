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
void	ft_put_str_char(char *str, int *index)
{

}
static void	process_char(char const *str_tokens, va_list vargs, int *index)
{

}

static void	extract_formt(char const *str_tokens, va_list vargs, int *index)
{
	if(str_tokens == 's' || str_tokens == 'c')
		process_char(str_tokens, vargs, index);
}


int	ft_printf(char const *str_tokens ...)
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