/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:27:55 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/05 18:48:21 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

int	init_philo(t_args *args, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * args->num_philo);
	if (!(*philo))
		return (-1);
	i = 0;
	while (i < args->num_philo)
	{
		(*philo)[i].pid = -1;
		(*philo)[i].id = i + 1;
		(*philo)[i].num_eat = 0;
		(*philo)[i].last_eat = args->start;
		(*philo)[i].args = args;
		(*philo)[i].stop = false;
		i++;
	}
	return (0);
}

void	print_state(t_philo *philo, char *msg, char *color)
{
	long	current_time;

	current_time = current_time_ms() - philo->args->start;
	if (ft_strncmp(msg, "died", 4) == 0)
	{
		sem_wait(philo->args->print);
		printf("%s%ld %d %s%s\n", color, current_time, philo->id, msg, C_0);
	}
	else
	{
		sem_wait(philo->args->print);
		printf("%s%ld %d %s%s\n", color, current_time, philo->id, msg, C_0);
		sem_post(philo->args->print);
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
	{
		ft_error(E, NULL, E_ARG);
		return (1);
	}
	if (ft_parse_args(ac, av, &args) == -1)
		return (1);
	if (init_philo(&args, &philo) == -1)
		return (ft_error(E, NULL, E_INIT_STRUCT), 1);
	do_all_fork(philo);
	wait_all_child(philo);
	close_semaphores(&args);
	free(philo);
	return (0);
}
