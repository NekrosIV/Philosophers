/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:27:55 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/29 17:04:34 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	ft_print_strcut(t_args *args)
{
	printf("num_philo = %d\n", args->num_philo);
	printf("time_to_die = %d\n", args->time_to_die);
	printf("time_to_eat = %d\n", args->time_to_eat);
	printf("time_to_sleep = %d\n", args->time_to_sleep);
	printf("num_eat = %d\n", args->num_eat);
	printf("start = %ld\n", args->start);
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
		i++;
	}
	return (0);
}

void	print_state(t_philo *philo, char *msg, char *color)
{
	long	current_time;

	if (ft_strncmp(msg, "died", 4) == 0)
		usleep(500);
	current_time = current_time_ms() - philo->args->start;
	printf("%s%ld %d %s\n" C_0, color, current_time, philo->id, msg);
}
void	close_semaphores(t_args *args)
{
	sem_close(args->forks);
	sem_unlink("/forks");
}

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(9000);
	while (!philo->args->stop_simulation)
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a left fork", C_M);
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a right fork", C_M);
		// Philosopher is eating
		philo->last_eat = current_time_ms();
		philo->num_eat++;
		if (philo->num_eat == philo->args->num_eat)
			philo->stop = true;
		print_state(philo, "is eating", C_Y);
		philo_wait(philo->args->time_to_eat);
		// Philosopher puts down forks
		sem_post(philo->args->forks);
		sem_post(philo->args->forks);
		if (philo->stop == true)
			break ;
		// Philosopher is sleeping
		print_state(philo, "is sleeping", C_C);
		philo_wait(philo->args->time_to_sleep);
		print_state(philo, "is thinking", C_G);
	}
}

void	do_all_fork(t_philo *philo)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < philo->args->num_philo)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_error(E, NULL, E_INIT_STRUCT);
			exit(1);
		}
		if (pid == 0)
		{
			philo_routine(&philo[i]);
			close_semaphores(philo->args);
			free(philo);
			exit(0);
		}
		i++;
	}
}

void	wait_all_child(void)
{
	pid_t	r_waitpid;

	while (1)
	{
		r_waitpid = waitpid(-1, NULL, 0);
		if (r_waitpid == -1)
			break ;
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
	wait_all_child();
	close_semaphores(&args);
	free(philo);
	return (0);
}
