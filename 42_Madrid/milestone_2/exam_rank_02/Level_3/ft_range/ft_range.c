/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:01:33 by frromero          #+#    #+#             */
/*   Updated: 2025/01/06 19:48:06 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*array;
	int dist = 0;
	int i = 0;

	dist = abs(end - start) + 1;
	array = (int *)malloc((sizeof int) * dist);
	if(!array)
		return(NULL);
	if(start < end)
		{
			while(start <= end)
			{
				array[i] = start;
				i++;
				start++;
			}
		}
	else
			{
			while(start >= end)
			{
				array[i] = start;
				i++;
				start--;
			}
		}
	return(array);
}
