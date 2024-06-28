/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:00:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/28 15:53:38 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	loop_monitor_routine(t_philo *philos, t_args *args, int stop, int i)
{
	while (i < args->num_philo)
	{
		pthread_mutex_lock(&philos[i].eat_mutex);
		if (philos[i].stop == false && current_time_ms()
			- philos[i].last_eat > args->time_to_die)
		{
			pthread_mutex_lock(&args->stop_mutex);
			args->stop_simulation = 1;
			pthread_mutex_unlock(&args->stop_mutex);
			print_state(&philos[i], "died", C_R);
			pthread_mutex_unlock(&philos[i].eat_mutex);
			return (1);
		}
		else if (philos[i].stop == true)
		{
			stop++;
			if (stop == args->num_philo && args->num_philo != 1)
				return (pthread_mutex_unlock(&philos[i].eat_mutex), 1);
		}
		pthread_mutex_unlock(&philos[i].eat_mutex);
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_args	*args;
	int		stop;
	int		i;

	philos = (t_philo *)arg;
	args = philos[0].args;
	wait_all_philo(philos);
	usleep(1000);
	while (1)
	{
		i = 0;
		stop = 0;
		if (loop_monitor_routine(philos, args, stop, i))
			break ;
		usleep(200);
	}
	return (NULL);
}
