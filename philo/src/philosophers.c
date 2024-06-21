/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:32:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/21 16:01:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_strcut(t_args *args)
{
	printf("num_philo = %d\n", args->num_philo);
	printf("time_to_die = %d\n", args->time_to_die);
	printf("time_to_eat = %d\n", args->time_to_eat);
	printf("time_to_sleep = %d\n", args->time_to_sleep);
	printf("num_eat = %d\n", args->num_eat);
	printf("start = %ld\n", args->start);
}

long	current_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

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
		if (i == args->num_philo - 1)
			(*philo)[i].right_fork = &((*philo)[0].left_fork);
		else
			(*philo)[i].right_fork = &((*philo)[i + 1].left_fork);
		i++;
	}
	return (0);
}

void	philo_wait(long time_ms)
{
	long	start_time;

	start_time = current_time_ms();
	while (current_time_ms() - start_time < time_ms)
		usleep(100);
}

void	ft_print_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->args->num_philo)
	{
		printf("id = %d\n", (*philo)[i].id);
		printf("num_eat = %d\n", (*philo)[i].num_eat);
		printf("last_eat = %ld\n", (*philo)[i].last_eat);
		printf("left_fork = %p\n", &(*philo)[i].left_fork);
		printf("right_fork = %p\n", (*philo)[i].right_fork);
		i++;
	}
}

void	print_state(t_philo *philo, char *msg)
{
	long	current_time;

	current_time = current_time_ms();
	pthread_mutex_lock(&philo->args->print_mutex);
	printf("%ld %d %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_mutex);
}
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->args->start_mutex);
	philo->args->start_count++;
	pthread_mutex_unlock(&philo->args->start_mutex);
	if (philo->id % 2 == 0)
	{
		while (1)
		{
			pthread_mutex_lock(&philo->args->start_mutex);
			if (philo->args->start_count >= philo->args->num_philo)
			{
				pthread_mutex_unlock(&philo->args->start_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->args->start_mutex);
			usleep(100);
		}
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = current_time_ms();
	pthread_mutex_unlock(&philo->eat_mutex);
	while (philo->args->stop_simulation != 1)
	{
		if (philo->args->stop_simulation)
			break ;
		pthread_mutex_lock(&philo->left_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (philo->args->stop_simulation)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(&philo->left_fork);
			break ;
		}
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->eat_mutex);
		philo->last_eat = current_time_ms();
		philo->num_eat++;
		if (philo->num_eat == philo->args->num_eat)
			philo->stop = true;
		pthread_mutex_unlock(&philo->eat_mutex);
		print_state(philo, "is eating");
		philo_wait(philo->args->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->args->stop_simulation || philo->stop == true)
		{
			pthread_mutex_unlock(&philo->eat_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		print_state(philo, "is sleeping");
		philo_wait(philo->args->time_to_sleep);
		if (philo->args->stop_simulation)
			break ;
		print_state(philo, "is thinking");
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_args	*args;
	int		i;
	int		stop;

	philos = (t_philo *)arg;
	args = philos[0].args;
	while (1)
	{
		i = 0;
		stop = 0;
		while (i < args->num_philo)
		{
			pthread_mutex_lock(&philos[i].eat_mutex);
			if (philos[i].stop == false && current_time_ms()
				- philos[i].last_eat > args->time_to_die)
			{
				print_state(&philos[i], "died");
				args->stop_simulation = 1;
				pthread_mutex_unlock(&philos[i].eat_mutex);
				return (NULL);
			}
			else
				stop++;
			pthread_mutex_unlock(&philos[i].eat_mutex);
			i++;
		}
		if (stop == args->num_philo)
			break ;
		usleep(200);
	}
	return (NULL);
}

int	ft_creat_thread(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	if (ft_creat_thread(philo) != 0)
		return (destroy_mutexes(philo), 1);
	if (pthread_create(&monitor_thread, NULL, monitor_routine, philo) != 0)
	{
		destroy_mutexes(philo);
		free(philo);
		return (ft_error(E, NULL, E_THREAD_C), 1);
	}
	if (ft_join_thread(philo, monitor_thread) != 0)
		return (destroy_mutexes(philo), 1);
	destroy_mutexes(philo);
	return (free(philo), 0);
}
