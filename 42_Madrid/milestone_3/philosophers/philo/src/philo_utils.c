/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:07:27 by frromero          #+#    #+#             */
/*   Updated: 2025/01/31 17:52:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * @brief Gets the current timestamp in milliseconds.
 * @return The current timestamp in milliseconds.
 */
long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*
 * @brief Pauses the execution for a specified amount of time in milliseconds.
 * @param time_in_ms The time to sleep in milliseconds.
 */
void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = get_timestamp();
	while (get_timestamp() - start_time < time_in_ms)
		usleep(100);
}

/*
 * @brief Converts a string to an integer, similar to the standard atoi function.
 * @param str The string to convert.
 * @return The converted integer value.
 */
int	atoi_philo(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	return (sign * result);
}

/*
 * @brief Calculates the length of a string, similar to the standard
 * strlen function.
 * @param str The string to calculate the length of.
 * @return The length of the string.
 */
size_t	strlen_philo(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
