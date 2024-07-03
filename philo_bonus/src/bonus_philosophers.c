/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:27:55 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/03 19:16:01 by kasingh          ###   ########.fr       */
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
		(*philo)[i].pid = -1;
		(*philo)[i].id = i + 1;
		(*philo)[i].num_eat = 0;
		(*philo)[i].last_eat = args->start;
		(*philo)[i].args = args;
		(*philo)[i].stop = false;
		pthread_mutex_init(&((*philo)[i].eat_mutex), NULL);
		i++;
	}
	return (0);
}
void	is_dead(t_philo *philo)
{
	sem_wait(philo->args->is_dead);
	if (philo->args->stop_simulation == 1)
		sem_post(philo->args->stop_simu);
	sem_post(philo->args->is_dead);
}

void	print_state(t_philo *philo, char *msg, char *color)
{
	long	current_time;

	current_time = current_time_ms() - philo->args->start;
	if (ft_strncmp(msg, "died", 4) == 0)
	{
		sem_wait(philo->args->print);
		printf("%s%ld %d %s%s\n", color, current_time, philo->id, msg, C_0);
		is_dead(philo);
	}
	else
	{
		sem_wait(philo->args->print);
		printf("%s%ld %d %s%s\n", color, current_time, philo->id, msg, C_0);
		sem_post(philo->args->print);
	}
}
void	close_semaphores(t_args *args)
{
	sem_close(args->forks);
	sem_unlink("/forks");
	sem_close(args->stop_simu);
	sem_unlink("/stop_simu");
	sem_close(args->print);
	sem_unlink("/print");
	sem_close(args->is_dead);
	sem_unlink("/is_dead");
	sem_close(args->eat);
	sem_unlink("/eat");
}

void	*monitor_dead(void *arg)
{
	t_philo	*philos;
	t_args	*args;
	int		i;

	i = 0;
	philos = (t_philo *)arg;
	args = philos->args;
	while (1)
	{
		sem_wait(philos->args->eat);
		if (philos->stop == false && current_time_ms()
			- philos->last_eat > args->time_to_die)
		{
			sem_wait(philos->args->is_dead);
			args->stop_simulation = 1;
			sem_post(philos->args->is_dead);
			sem_post(philos->args->eat);
			print_state(philos, "died", C_R);
			return (NULL);
		}
		else if (philos->stop == true)
			return (sem_post(philos->args->eat), NULL);
		sem_post(philos->args->eat);
		usleep(200);
	}
	return (NULL);
}
void	philo_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitor_dead, philo) != 0)
		ft_error(E, NULL, E_THREAD_C);
	if (pthread_detach(monitor_thread) != 0)
		ft_error(E, NULL, E_THREAD_J);
	philo->last_eat = philo->args->start;
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a left fork", C_M);
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a right fork", C_M);
		// Philosopher is eating
		sem_wait(philo->args->eat);
		philo->last_eat = current_time_ms();
		philo->num_eat++;
		if (philo->num_eat == philo->args->num_eat)
			philo->stop = true;
		sem_post(philo->args->eat);
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
	int	i;

	i = 0;
	philo->args->start = current_time_ms();
	while (i < philo->args->num_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
		{
			ft_error(E, NULL, E_INIT_STRUCT);
			exit(1);
		}
		if (philo[i].pid == 0)
		{
			philo_routine(&philo[i]);
			close_semaphores(philo->args);
			pthread_mutex_destroy(&philo[i].eat_mutex);
			free(philo);
			exit(0);
		}
		i++;
	}
}
void	monitor_routine(t_philo *philos)
{
	int	i;

	i = 0;
	sem_wait(philos->args->stop_simu);
	while (i < philos->args->num_philo)
	{
		if (philos[i].pid > 0)
			kill(philos[i].pid, SIGKILL);
		i++;
	}
	sem_post(philos->args->stop_simu);
	exit(0);
}

void	wait_all_child(t_philo *philo)
{
	pid_t	r_waitpid;
	int		status;
	int		i;

	i = 0;
	while (1)
	{
		r_waitpid = waitpid(-1, &status, 0);
		if (i + 1 == philo->args->num_philo)
		{
			if (philo->args->pid_killer > 0)
				kill(philo->args->pid_killer, SIGKILL);
		}
		if (r_waitpid == -1)
			break ;
		i++;
	}
}
void	fork_monitor(t_philo *philo)
{
	philo->args->pid_killer = fork();
	if (philo->args->pid_killer == -1)
	{
		ft_error(E, NULL, E_INIT_STRUCT);
		exit(1);
	}
	if (philo->args->pid_killer == 0)
	{
		sem_wait(philo->args->stop_simu);
		monitor_routine(philo);
		close_semaphores(philo->args);
		free(philo);
		exit(0);
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
	fork_monitor(philo);
	wait_all_child(philo);
	close_semaphores(&args);
	free(philo);
	return (0);
}
