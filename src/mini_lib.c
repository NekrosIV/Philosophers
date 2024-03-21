/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:27:37 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/21 18:49:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
		ft_error("Negative number not allowed\n");
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_error(char *s)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(s, 2);
	exit(1);
}
