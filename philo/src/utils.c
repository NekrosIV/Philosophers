/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:47:09 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/22 15:51:30 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_stop_simulation(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->args->stop_mutex);
	stop = philo->args->stop_simulation;
	pthread_mutex_unlock(&philo->args->stop_mutex);
	return (stop);
}

void	print_state(t_philo *philo, char *msg)
{
	long	current_time;

	current_time = current_time_ms() - philo->args->start;
	pthread_mutex_lock(&philo->args->print_mutex);
	printf("%ld %d %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_mutex);
}

void	unlock_forks(pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

void	initialize_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->start_mutex);
	philo->args->start_count++;
	pthread_mutex_unlock(&philo->args->start_mutex);
	if (philo->id % 2 != 0)
	{
		while (1)
		{
			usleep(1000);
			pthread_mutex_lock(&philo->args->start_mutex);
			if (philo->args->start_count >= philo->args->num_philo)
			{
				pthread_mutex_unlock(&philo->args->start_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->args->start_mutex);
		}
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = current_time_ms();
	pthread_mutex_unlock(&philo->eat_mutex);
}
