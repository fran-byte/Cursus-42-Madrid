/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:29:23 by frromero          #+#    #+#             */
/*   Updated: 2024/09/27 21:23:31 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_cnt(char const *s, char c)
{
	char	*str;
	int	w_cnt;
	int	is_word;
	int	i;

	str = s;
	w_cnt= 0;
	is_word = 0;
	i = 0;
	while(str[i] != '\0')
	{
			if (str[i] != c && is_word != 1)
			{
				is_word = 1;
				w_cnt++;
			}
			else if (str[i] == c)
				is_word = 0;
			i++;
	}
	return (w_cnt);
}


char	**ft_split(char const *s, char c)
{
	word_count(s, c);
}
