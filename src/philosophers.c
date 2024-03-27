/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:32:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/27 16:16:39 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_strcut(t_args *args)
{
	printf("num_philo = %ld\n", args->num_philo);
	printf("time_to_die = %ld\n", args->time_to_die);
	printf("time_to_eat = %ld\n", args->time_to_eat);
	printf("time_to_sleep = %ld\n", args->time_to_sleep);
	printf("num_eat = %ld\n", args->num_eat);
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
		pthread_mutex_init(&((*philo)[i].left_fork), NULL);
		if (i == args->num_philo - 1)
			(*philo)[i].right_fork = &((*philo)[0].left_fork);
		else
			(*philo)[i].right_fork = &((*philo)[i + 1].left_fork);
		i++;
	}
	return (0);
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
		printf("args->start = %ld\n", (*philo)[i].args->start);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philo;

	if (ft_parse_args(ac, av, &args) == -1)
		ft_error("Invalid arguments\n", NULL);
	ft_print_strcut(&args);
	if (init_philo(&args, &philo) == -1)
		ft_error("Init strcut philo failed\n", NULL);
	free(philo);
	return (0);
}
