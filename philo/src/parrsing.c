/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:48 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/22 12:32:13 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_good_int(char *str)
{
	int		len_str;
	char	*int_limit;
	int		max_len;
	int		i;

	i = 0;
	int_limit = ft_itoa_nosigne(INT_MAX);
	if (!int_limit)
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	max_len = ft_strlen(int_limit);
	len_str = ft_strlen(&str[i]);
	if (len_str > max_len)
		return (free(int_limit), 0);
	if (len_str == max_len)
		if (ft_strncmp(&str[i], int_limit, len_str) > 0)
			return (free(int_limit), 0);
	return (free(int_limit), 1);
}

int	is_good_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_good_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_good_syntax(av[i]))
		{
			ft_error(E, av[i], E_SYNTAX);
			return (-1);
		}
		if (av[i][0] == '-')
		{
			ft_error(E, av[i], E_NEG);
			return (-1);
		}
		if (!is_good_int(av[i]))
		{
			ft_error(E, av[i], E_INT);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_parse_args(int ac, char **av, t_args *args)
{
	if (ft_is_good_args(av) == -1)
		return (-1);
	args->num_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->num_eat = ft_atoi(av[5]);
	else
		args->num_eat = -1;
	args->start_count = 0;
	pthread_mutex_init(&args->start_mutex, NULL);
	pthread_mutex_init(&args->stop_mutex, NULL);
	pthread_mutex_init(&args->print_mutex, NULL);
	args->start = current_time_ms();
	args->stop_simulation = 0;
	if (args->num_philo <= 0 || args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0 || args->num_eat < -1)
	{
		ft_error(E, NULL, E_IARG);
		return (-1);
	}
	return (0);
}
