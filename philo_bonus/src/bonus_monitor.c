/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:04:40 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/06 14:02:57 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus_philosophers.h>

void	start_routine_thread(t_philo *philo, pthread_t *routine_thread)
{
	if (pthread_create(routine_thread, NULL, philo_routine, philo) != 0)
		ft_error(E, NULL, E_THREAD_C);
}

int	check_death(t_philo *philo)
{
	sem_wait(philo->args->eat);
	if (philo->stop == false && current_time_ms()
		- philo->last_eat > philo->args->time_to_die)
	{
		sem_wait(philo->args->is_dead);
		philo->args->stop_simulation = 1;
		sem_post(philo->args->is_dead);
		sem_post(philo->args->eat);
		print_state(philo, "died", C_R);
		return (1);
	}
	else if (philo->stop == true)
	{
		sem_post(philo->args->eat);
		return (2);
	}
	sem_post(philo->args->eat);
	return (0);
}

void	clean_exit(t_philo *philo, t_philo *philos, pthread_t routine_thread)
{
	sem_post(philo->args->forks);
	if (pthread_join(routine_thread, NULL) != 0)
		ft_error(E, NULL, E_THREAD_D);
	close_semaphores(philo->args);
	free(philos);
	exit(1);
}

void	child(t_philo *philo, t_philo *philos)
{
	pthread_t	routine_thread;
	int			death_status;

	if (philo->id % 2 == 0)
		usleep(500);
	philo->last_eat = philo->args->start;
	start_routine_thread(philo, &routine_thread);
	while (1)
	{
		death_status = check_death(philo);
		if (death_status == 1)
			clean_exit(philo, philos, routine_thread);
		else if (death_status == 2)
			break ;
		usleep(200);
	}
	if (pthread_join(routine_thread, NULL) != 0)
		ft_error(E, NULL, E_THREAD_J);
}
