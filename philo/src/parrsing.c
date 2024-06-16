/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:48 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/15 15:32:29 by kasingh          ###   ########.fr       */
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
	if (str[i] == '-')
		free_err_exit(E "%s : %e" E_neg, str, 1);
	int_limit = ft_itoa_nosigne(LONG_MAX);
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

int	is_good_time_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) + 3 > 10)
		return (-1);
	return (0);
}

int	ft_is_good_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_good_syntax(av[i]))
			free_err_exit(E "%s : %e" E_syntax, av[i], 1);
		if (!is_good_int(av[i]))
			free_err_exit(E "%s : %e" E_int, av[i], 1);
		if (i != 1 && is_good_time_int(av[i]) == -1)
			free_err_exit(E "%s : %e" E_time, av[i], 1);
		i++;
	}
	return (0);
}

int	ft_parse_args(int ac, char **av, t_args *args)
{
	if (ac < 5 || ac > 6 || ft_is_good_args(av) == -1)
		return (-1);
	args->num_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	printf("args->time_to_sleep = %d\n", args->time_to_sleep);
	if (ac == 6)
		args->num_eat = ft_atoi(av[5]);
	else
		args->num_eat = -1;
	pthread_mutex_init(&args->print_mutex, NULL);
	args->start = current_time_ms();
	if (args->num_philo <= 0 || args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0 || args->num_eat < -1)
		free_err_exit(E E_Iarg "%e", 1);
	return (0);
}
