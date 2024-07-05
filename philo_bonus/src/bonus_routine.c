/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:44:54 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/05 18:41:32 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus_philosophers.h>

int	check_stop_simulation(t_philo *philo)
{
	sem_wait(philo->args->is_dead);
	if (philo->args->stop_simulation == 1)
	{
		sem_post(philo->args->is_dead);
		return (1);
	}
	sem_post(philo->args->is_dead);
	return (0);
}

void	eat(t_philo *philo)
{
	sem_wait(philo->args->eat);
	philo->last_eat = current_time_ms();
	philo->num_eat++;
	if (philo->num_eat == philo->args->num_eat)
		philo->stop = true;
	sem_post(philo->args->eat);
	print_state(philo, "is eating", C_Y);
	philo_wait(philo->args->time_to_eat);
}

void	put_down_forks(t_philo *philo)
{
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
}

void	sleep_and_think(t_philo *philo)
{
	print_state(philo, "is sleeping", C_C);
	philo_wait(philo->args->time_to_sleep);
	print_state(philo, "is thinking", C_G);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a left fork", C_M);
		sem_wait(philo->args->forks);
		if (check_stop_simulation(philo))
			return (NULL);
		print_state(philo, "has taken a right fork", C_M);
		if (check_stop_simulation(philo))
			return (NULL);
		eat(philo);
		if (check_stop_simulation(philo))
			return (NULL);
		put_down_forks(philo);
		if (check_stop_simulation(philo) || philo->stop == true)
			return (NULL);
		sleep_and_think(philo);
		if (check_stop_simulation(philo))
			return (NULL);
	}
	return (NULL);
}
