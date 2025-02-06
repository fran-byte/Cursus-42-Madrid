/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:45:07 by frromero          #+#    #+#             */
/*   Updated: 2025/01/31 01:16:55 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_simulation	t_simulation;

typedef struct s_philosopher
{
	int				id;
	int				left_fork;
	int				right_fork;
	pthread_t		thrd;
	long			last_meal;
	int				meal_count;
	t_simulation	*simulation;
}	t_philosopher;

typedef struct s_simulation
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				is_running;
	long			start_time;
	pthread_mutex_t	*forks;
	t_philosopher	*phil;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
	pthread_t		monitor_thread;
}	t_simulation;

int		atoi_philo(char *str);
size_t	strlen_philo(const char *str);
int		start_simulation(t_simulation *sim);
long	get_timestamp(void);
void	ft_usleep(long int time_in_ms);
void	*monitor_deaths(void *arg);
void	print_state(t_simulation *sim, int philo_id, char *state);
int		create_philos(t_simulation *sim);
#endif
