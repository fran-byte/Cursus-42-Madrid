/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:28:48 by frromero          #+#    #+#             */
/*   Updated: 2025/02/01 14:55:43 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * @brief Displays an error message when the arguments are invalid.
 */
static void	error_msg_validate(void)
{
	printf("\nError. Invalid arguments:  ./philo [#1] [#2] [#3] [#4]\n");
	printf("\n#1: [Number of philosophers]\n#2: [Time to die] (ms)");
	printf("\n#3: [Time to eat] (ms)\n#4: [Time to sleep] (ms)\n\n");
}

/*
 * @brief Validates that the arguments passed to the program are valid numbers.
 * @param argc Number of arguments.
 * @param argv Arguments passed to the program.
 * @return 0 if the arguments are valid, 1 if they are not.
 */
static int	parse_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
 * @brief Validates the arguments and initializes the simulation parameters.
 * @param argc Number of arguments.
 * @param argv Arguments passed to the program.
 * @param sim Pointer to the simulation structure.
 * @return 0 if the arguments are valid and the simulation is initialized,
 * 1 otherwise.
 */
static int	validate_arguments(int argc, char **argv, t_simulation *sim)
{
	if ((argc != 5 && argc != 6) || parse_arguments(argc, argv) != 0)
		return (1);
	sim->num_philo = atoi_philo(argv[1]);
	sim->time_to_die = atoi_philo(argv[2]);
	sim->time_to_eat = atoi_philo(argv[3]);
	sim->time_to_sleep = atoi_philo(argv[4]);
	if (argc == 6)
		sim->num_meals = atoi_philo(argv[5]);
	else
		sim->num_meals = -1;
	if (sim->num_philo <= 0 || sim->time_to_die <= 0
		|| sim->time_to_eat <= 0 || sim->time_to_sleep <= 0)
		return (1);
	return (0);
}

/*
 * @brief Main function of the program.
 * @param argc Number of arguments.
 * @param argv Arguments passed to the program.
 * @return 0 if the program runs successfully, 1 otherwise.
 */
int	main(int argc, char **argv)
{
	t_simulation	*sim;

	sim = malloc(sizeof(t_simulation));
	if (!sim)
	{
		printf("\nmalloc Error\n");
		return (1);
	}
	if (validate_arguments(argc, argv, sim) != 0 || start_simulation(sim) != 0)
	{
		free(sim);
		error_msg_validate();
		return (1);
	}
	free(sim);
	return (0);
}
