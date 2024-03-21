/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:32:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/21 18:40:18 by kasingh          ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ft_parse_args(ac, av, &args) == -1)
		ft_error("Invalid arguments\n");
	ft_print_strcut(&args);
	return (0);
}
