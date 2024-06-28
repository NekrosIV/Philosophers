/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:32:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/28 15:37:58 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_args *args, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * args->num_philo);
	if (!(*philo))
		return (-1);
	i = 0;
	while (i < args->num_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].num_eat = 0;
		(*philo)[i].last_eat = args->start;
		(*philo)[i].args = args;
		(*philo)[i].stop = false;
		pthread_mutex_init(&((*philo)[i].eat_mutex), NULL);
		pthread_mutex_init(&((*philo)[i].left_fork), NULL);
		if (args->num_philo == 1)
			(*philo)[i].right_fork = NULL;
		else if (i == args->num_philo - 1)
			(*philo)[i].right_fork = &((*philo)[0].left_fork);
		else
			(*philo)[i].right_fork = &((*philo)[i + 1].left_fork);
		i++;
	}
	return (0);
}

int	ft_creat_thread(t_philo *philo, pthread_t *monitor_thread)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	philo->args->start = current_time_ms();
	while (i < philo->args->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine,
				&philo[i]) != 0)
		{
			ft_error(E, NULL, E_THREAD_C);
			free(philo);
			return (-1);
		}
		i++;
	}
	if (pthread_create(monitor_thread, NULL, monitor_routine, philo) != 0)
	{
		free(philo);
		return (ft_error(E, NULL, E_THREAD_C), -1);
	}
	return (0);
}

int	ft_join_thread(t_philo *philo, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
	{
		free(philo);
		ft_error(E, NULL, E_THREAD_J);
		return (-1);
	}
	while (i < philo->args->num_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			free(philo);
			ft_error(E, NULL, E_THREAD_J);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	destroy_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->args->print_mutex);
	pthread_mutex_destroy(&philo->args->start_mutex);
	pthread_mutex_destroy(&philo->args->stop_mutex);
	while (i < philo->args->num_philo)
	{
		pthread_mutex_destroy(&philo[i].left_fork);
		pthread_mutex_destroy(&philo[i].eat_mutex);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_args		args;
	t_philo		*philo;
	pthread_t	monitor_thread;

	if (ac < 5 || ac > 6)
	{
		ft_error(E, NULL, E_ARG);
		return (1);
	}
	if (ft_parse_args(ac, av, &args) == -1)
		return (1);
	if (init_philo(&args, &philo) == -1)
		return (ft_error(E, NULL, E_INIT_STRUCT), 1);
	if (ft_creat_thread(philo, &monitor_thread) != 0)
		return (destroy_mutexes(philo), 1);
	if (ft_join_thread(philo, monitor_thread) != 0)
		return (destroy_mutexes(philo), 1);
	destroy_mutexes(philo);
	return (free(philo), 0);
}
