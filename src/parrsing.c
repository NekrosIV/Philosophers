/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:48 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/21 18:41:16 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_good_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9' || j > 10)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_args(int ac, char **av, t_args *args)
{
	// if (ac == 5 || ac == 6 || ft_is_good_args(av) == -1)
	// 	return (-1);
	args->num_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->num_eat = ft_atoi(av[5]);
	else
		args->num_eat = -1;
	if (args->num_philo <= 0 || args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0 || args->num_eat < -1)
		return (-1);
	return (0);
}
