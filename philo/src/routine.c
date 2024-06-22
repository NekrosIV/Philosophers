/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:48:30 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/22 16:32:46 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	lock_forks(pthread_mutex_t *first_fork, pthread_mutex_t *second_fork,
		t_philo *philo)
{
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(&philo->args->stop_mutex);
	if (philo->args->stop_simulation)
	{
		pthread_mutex_unlock(&philo->args->stop_mutex);
		pthread_mutex_unlock(first_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->stop_mutex);
	print_state(philo, "has taken a left fork");
	if (second_fork == NULL)
		return (wait_to_die(philo, first_fork));
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(&philo->args->stop_mutex);
	if (philo->args->stop_simulation)
	{
		pthread_mutex_unlock(&philo->args->stop_mutex);
		unlock_forks(first_fork, second_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->stop_mutex);
	print_state(philo, "has taken a right fork");
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = current_time_ms();
	philo->num_eat++;
	if (philo->num_eat == philo->args->num_eat)
		philo->stop = true;
	pthread_mutex_unlock(&philo->eat_mutex);
	print_state(philo, "is eating");
	philo_wait(philo->args->time_to_eat);
}

int	sleep_and_think(t_philo *philo)
{
	print_state(philo, "is sleeping");
	philo_wait(philo->args->time_to_sleep);
	pthread_mutex_lock(&philo->args->stop_mutex);
	if (philo->args->stop_simulation)
	{
		pthread_mutex_unlock(&philo->args->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->stop_mutex);
	print_state(philo, "is thinking");
	return (0);
}

void	loop_routine(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	while (1)
	{
		if (check_stop_simulation(philo))
			break ;
		if (lock_forks(first_fork, second_fork, philo))
			break ;
		eat(philo);
		unlock_forks(first_fork, second_fork);
		pthread_mutex_lock(&philo->eat_mutex);
		if (check_stop_simulation(philo) || philo->stop)
		{
			pthread_mutex_unlock(&philo->eat_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		if (sleep_and_think(philo))
			break ;
	}
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	philo = (t_philo *)arg;
	initialize_philo(philo);
	if (philo->args->num_philo == 1 || &philo->left_fork < philo->right_fork)
	{
		first_fork = &philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = &philo->left_fork;
	}
	loop_routine(philo, first_fork, second_fork);
	return (NULL);
}
