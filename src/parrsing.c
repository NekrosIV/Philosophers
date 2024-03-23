/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:48 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/22 16:09:59 by kasingh          ###   ########.fr       */
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
		ft_error("Negative number not allowed\n");
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
			ft_error("Invalid syntax\n");
		if (!is_good_int(av[i]))
			ft_error("Number is bigger than int max value\n");
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
	if (ac == 6)
		args->num_eat = ft_atoi(av[5]);
	else
		args->num_eat = -1;
	if (args->num_philo <= 0 || args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0 || args->num_eat < -1)
		return (-1);
	return (0);
}
