/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:40 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/22 16:33:51 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	current_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	philo_wait(long time_ms)
{
	long	start_time;

	start_time = current_time_ms();
	while (current_time_ms() - start_time < time_ms)
		usleep(100);
}

int	wait_to_die(t_philo *philo, pthread_mutex_t *first_fork)
{
	while (1)
	{
		pthread_mutex_lock(&philo->args->stop_mutex);
		if (philo->args->stop_simulation)
		{
			pthread_mutex_unlock(&philo->args->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->args->stop_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(first_fork);
	return (1);
}
