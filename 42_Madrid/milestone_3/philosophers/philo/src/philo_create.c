/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:12:30 by frromero          #+#    #+#             */
/*   Updated: 2025/02/01 15:42:41 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * @brief Takes the forks (left and right) for a philosopher.
 * @param philo Pointer to the philosopher structure.
 */
void	take_forks(t_philosopher *philo)
{
	t_simulation	*sim;

	sim = philo->simulation;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&sim->forks[philo->left_fork]);
		print_state(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(&sim->forks[philo->right_fork]);
		print_state(sim, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&sim->forks[philo->right_fork]);
		print_state(sim, philo->id, "has taken a fork");
		pthread_mutex_lock(&sim->forks[philo->left_fork]);
		print_state(sim, philo->id, "has taken a fork");
	}
}

/*
 * @brief Main lifecycle of a philosopher: eat, sleep, think.
 * @param philo Pointer to the philosopher structure.
 */
void	phil_lifecycle(t_philosopher *philo)
{
	t_simulation	*sim;

	sim = philo->simulation;
	while (sim->is_running)
	{
		take_forks(philo);
		print_state(sim, philo->id, "is eating");
		pthread_mutex_lock(&sim->state_mutex);
		philo->last_meal = get_timestamp();
		philo->meal_count++;
		pthread_mutex_unlock(&sim->state_mutex);
		ft_usleep(sim->time_to_eat);
		pthread_mutex_unlock(&sim->forks[philo->left_fork]);
		pthread_mutex_unlock(&sim->forks[philo->right_fork]);
		print_state(sim, philo->id, "is sleeping");
		ft_usleep(sim->time_to_sleep);
		print_state(sim, philo->id, "is thinking");
		usleep(750);
	}
}

/*
 * @brief Main function for a philosopher thread.
 * Handles both the single philosopher case and the general case.
 * @param arg Pointer to the philosopher's structure (cast to void*).
 * @return NULL when the philosopher finishes.
 */
void	*phil(void *arg)
{
	t_philosopher	*philo;
	t_simulation	*sim;

	philo = (t_philosopher *)arg;
	sim = philo->simulation;
	if (sim->num_philo == 1)
	{
		pthread_mutex_lock(&sim->forks[philo->left_fork]);
		print_state(sim, philo->id, "has taken a fork");
		ft_usleep(sim->time_to_die);
		print_state(sim, philo->id, "died");
		pthread_mutex_unlock(&sim->forks[philo->left_fork]);
		return (NULL);
	}
	phil_lifecycle(philo);
	return (NULL);
}

/*
 * @brief Initializes philosopher properties and creates their threads.
 * @param sim Pointer to the simulation structure.
 * @return 0 on success, 1 on thread creation error.
 */
int	create_philos(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_philo)
	{
		sim->phil[i].id = i + 1;
		sim->phil[i].left_fork = i;
		sim->phil[i].right_fork = (i + 1) % sim->num_philo;
		sim->phil[i].simulation = sim;
		sim->phil[i].meal_count = 0;
		sim->phil[i].last_meal = get_timestamp();
		i++;
	}
	i = 0;
	while (i < sim->num_philo)
	{
		if (pthread_create(&sim->phil[i].thrd, NULL, phil, &sim->phil[i]) != 0)
			return (printf("Error creating the thread%d\n", i + 1), 1);
		i++;
	}
	return (0);
}
