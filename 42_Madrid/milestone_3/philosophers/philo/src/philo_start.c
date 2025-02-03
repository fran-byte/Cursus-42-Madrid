/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:35:39 by frromero          #+#    #+#             */
/*   Updated: 2025/02/01 14:52:58 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * @brief Prints the current state of a philosopher.
 * @param sim Pointer to the simulation structure.
 * @param philo_id The ID of the philosopher.
 * @param state The state to print (e.g., "is eating", "is sleeping").
 */
void	print_state(t_simulation *sim, int philo_id, char *state)
{
	long	timestamp;

	timestamp = get_timestamp() - sim->start_time;
	pthread_mutex_lock(&sim->state_mutex);
	pthread_mutex_lock(&sim->print_mutex);
	if (sim->is_running)
		printf("%06ld %d %s\n", timestamp, philo_id, state);
	pthread_mutex_unlock(&sim->print_mutex);
	pthread_mutex_unlock(&sim->state_mutex);
}

/*
 * @brief Initializes the simulation, including memory allocation and mutex
 * initialization.
 * @param sim Pointer to the simulation structure.
 * @return 0 if initialization is successful, 1 otherwise.
 */
int	init_simulation(t_simulation *sim)
{
	int	i;

	sim->start_time = get_timestamp();
	sim->phil = malloc(sizeof(t_philosopher) * sim->num_philo);
	if (!sim->phil)
		return (1);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philo);
	if (!sim->forks)
	{
		free(sim->phil);
		return (1);
	}
	i = 0;
	while (i < sim->num_philo)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&sim->print_mutex, NULL);
	pthread_mutex_init(&sim->state_mutex, NULL);
	sim->is_running = 1;
	if (create_philos(sim) != 0)
		return (1);
	return (0);
}

/*
 * @brief Runs the simulation, including creating the monitor thread and
 * joining philosopher threads.
 * @param sim Pointer to the simulation structure.
 * @return 0 if the simulation runs successfully, 1 otherwise.
 */
int	run_simulation(t_simulation *sim)
{
	int	i;

	if (pthread_create(&sim->monitor_thread, NULL, monitor_deaths, sim) != 0)
	{
		printf("Error: Could not create monitoring thread\n");
		return (1);
	}
	i = 0;
	while (i < sim->num_philo)
	{
		pthread_join(sim->phil[i].thrd, NULL);
		i++;
	}
	pthread_join(sim->monitor_thread, NULL);
	i = 0;
	while (i < sim->num_philo)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->state_mutex);
	free(sim->forks);
	free(sim->phil);
	return (0);
}

/*
 * @brief Starts the simulation by initializing and running it.
 * @param sim Pointer to the simulation structure.
 * @return 0 if the simulation starts successfully, 1 otherwise.
 */
int	start_simulation(t_simulation *sim)
{
	if (init_simulation(sim) != 0)
		return (1);
	if (run_simulation(sim) != 0)
		return (1);
	return (0);
}

/*
 * Test cases for the philosophers program:
 * ./philo 5 800 200 200        no one should die
 * ./philo 5 600 150 150        no one should die
 * ./philo 4 410 200 200        no one should die
 * ./philo 100 800 200 200      no one should die
 * ./philo 105 800 200 200      no one should die
 * ./philo 200 800 200 200      no one should die
 * ./philo 3 310 100 100		no one should die *** (hard)
 * ./philo 3 310 103 103		no one should die *** (hard ++)
 *
 * ./philo 1 800 200 200        a philo should die
 * ./philo 4 310 200 100        a philo should die
 * ./philo 4 200 205 200        a philo should die
 *
 * ./philo -5 600 200 200       should error and not run (no crashing)
 * ./philo 4 -5 200 200         should error and not run (no crashing)
 * ./philo 4 600 -5 200         should error and not run (no crashing)
 * ./philo 4 600 200 -5         should error and not run (no crashing)
 * ./philo 4 600 200 200 -5     should error and not run (no crashing)
 *
 * Valgrind command to check for memory leaks:
 * Attention: Valgrind will increase delays, which will modify the timings,
 * and the philosophers will die.
 * We will only use it to check for errors, not to see how the project works.
 *
 * valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./philo
 */
