/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:27:05 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/06 15:06:34 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

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
			child(&philo[i], philo);
			close_semaphores(philo->args);
			free(philo);
			exit(0);
		}
		i++;
	}
}

void	kill_all_fork(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->num_philo)
	{
		if (philos[i].pid > 0)
			kill(philos[i].pid, SIGKILL);
		i++;
	}
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
		if (WEXITSTATUS(status) == 1)
			kill_all_fork(philo);
		if (r_waitpid == -1)
			break ;
		i++;
	}
}
