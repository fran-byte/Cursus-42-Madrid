/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_deaths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:35:35 by frromero          #+#    #+#             */
/*   Updated: 2025/02/01 15:47:01 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * @brief Checks if any philosopher has died.
 * @param sim Pointer to the simulation structure.
 * @return 1 if a philosopher has died, 0 otherwise.
 */
static int	check_philosopher_death(t_simulation *sim)
{
	int		i;
	long	since_last_meal;

	i = 0;
	while (i < sim->num_philo)
	{
		pthread_mutex_lock(&sim->state_mutex);
		since_last_meal = get_timestamp() - sim->phil[i].last_meal;
		pthread_mutex_unlock(&sim->state_mutex);
		if (since_last_meal >= sim->time_to_die)
		{
			print_state(sim, sim->phil[i].id, "died");
			pthread_mutex_lock(&sim->state_mutex);
			sim->is_running = 0;
			pthread_mutex_unlock(&sim->state_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
 * @brief Checks if all philosophers have eaten the required number of times.
 * @param sim Pointer to the simulation structure.
 * @return 1 if all have eaten, 0 otherwise.
 */
static int	check_all_meals_eaten(t_simulation *sim)
{
	int	i;
	int	all_meals_eaten;

	i = 0;
	all_meals_eaten = 1;
	while (i < sim->num_philo)
	{
		pthread_mutex_lock(&sim->state_mutex);
		if (sim->num_meals != -1 && sim->phil[i].meal_count < sim->num_meals)
			all_meals_eaten = 0;
		pthread_mutex_unlock(&sim->state_mutex);
		i++;
	}
	if (sim->num_meals != -1 && all_meals_eaten)
	{
		pthread_mutex_lock(&sim->state_mutex);
		sim->is_running = 0;
		pthread_mutex_unlock(&sim->state_mutex);
		return (1);
	}
	return (0);
}

/*
 * @brief Monitors the philosophers to check if any have died.
 * @param arg Pointer to the simulation structure (cast to void*).
 * @return NULL when the simulation ends or a philosopher dies.
 */
void	*monitor_deaths(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (sim->is_running)
	{
		if (check_philosopher_death(sim))
			return (NULL);
		if (check_all_meals_eaten(sim))
			return (NULL);
	}
	return (NULL);
}
