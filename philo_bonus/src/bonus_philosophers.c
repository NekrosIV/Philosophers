/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:27:55 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/26 17:46:15 by kasingh          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_args	args;

	if (ac < 5 || ac > 6)
	{
		ft_error(E, NULL, E_ARG);
		return (1);
	}
	if (ft_parse_args(ac, av, &args) == -1)
		return (1);
	ft_print_strcut(&args);
	return (0);
}
