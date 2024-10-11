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

void extract_formt(const char *str_tokens, va_list vargs, int *index)
{
    if (*str_tokens == 'c')
    {
        char c = (char)va_arg(vargs, int);
        write(1, &c, 1);
        (*index)++;
    }
    else if (*str_tokens == 's')
    {
        char *str = va_arg(vargs, char *);
        if (str == NULL)
            str = "(null)";
        while (*str)
        {
            write(1, str, 1);
            (*index)++;
            str++;
        }
    }
}

int ft_printf(const char *str_tokens, ...)
{
    va_list vargs;
    int index = 0;

    if (str_tokens == NULL)
    {
      write(1, "(null)", 6);
      return;
    }
    va_start(vargs, str_tokens);
    while (*str_tokens)
    {
      if (*str_tokens == '%' && *(str_tokens + 1))
      {
          str_tokens++;
          extract_formt(str_tokens, vargs, &index);
      }
      else
      {
          write(1, str_tokens, 1);
          index++;
      }
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
